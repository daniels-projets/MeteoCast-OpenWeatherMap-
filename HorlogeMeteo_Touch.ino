
//        Esp32  ILI9488_Touch  MeteoCast
//        V01-M00  2023/04/12

//        Source de reference
//        https://github.com/JHershey69/OpenWeatherOneCall


#include "FS.h"
#include "SPIFFS.h"  // For ESP32 only
#define   FS_NO_GLOBALS

//____________________________________________________________________________ 
#include <SPI.h>
#include <TFT_eSPI.h>
          TFT_eSPI tft = TFT_eSPI();

//____________________________________________________________________________ 
#define   nbrBoutons 3
          TFT_eSPI_Button bouton[nbrBoutons];
          uint16_t calData[5] = { 351, 3476, 310, 3384, 7 };
          uint8_t calDataOK = 0;
          int numero, numeroChoix;      

//____________________________________________________________________________
#include <WiFi.h>
#include <WiFiMulti.h>
#include <WiFiUdp.h>
    const char *ssid     = "@@@@@@@@@@";
    const char *password = "&&&&&&&&&&";
          WiFiMulti WiFiMulti; 
      int TryNum = 0;

//____________________________________________________________________________      
#include "time.h"
const char* ntpServer = "de.pool.ntp.org";
const long  gmtOffset_sec = 3600 * 1;
const int   daylightOffset_sec = 3600 * 0;
     bool firstTimeCall = true;
      int timeCall = (55)*1000;// pour 55 secondes en microsecondes
 unsigned long lastTimeCall;
   String mmTxt, hhTxt, dateTxt, heureTxt;
      int jourSemaine, jourDate, moisDate;
   String jourTab[8] = { "_", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche" };
   String moisTab[13] = {"", "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
//   String moisTab[13] = {"", "Jan", "Fev", "Mars", "Avr", "Mai", "Juin", "Juil", "Aout", "Sept", "Oct", "Nov", "Dec"};
      int hh, mm, timeCast;
      int timeHourData, timeInfoDay, timeDay, timeInfoJour, timeJour, timeInfoMois, timeMois;
          
//____________________________________________________________________________      
#include <OpenWeatherOneCall.h>
#define   ONECALLKEY "############################"
//    float myLATITUDE = 48.4769;//   ICHTRATZHEIM
    float myLATITUDE = 48.489901;//   FEGERSHEIM
//    float myLONGITUDE = 7.67806;//  ICHTRATZHEIM
    float myLONGITUDE = 7.679958;//   FEGERSHEIM
//      int myCITYID = 2857798;  
      int myUNITS = METRIC; 
      int myHISTORY = NULL;
//      int myEXCLUDES = EXCL_D+EXCL_H+EXCL_M+EXCL_A;
          OpenWeatherOneCall OWOC; 
      int oneCall = (15*60)*1000;// pour 15 minutes en microsecondes
//      int oneCall = (3)*1000;// pour secondes en microsecondes
 unsigned long lastCall;
     bool firstCall = true;
     bool foreCast = false;
     bool meteoCall = true;
     bool flag = false;
      int castHour, castDay; 
      int iconeTft, dayLigne, hourLigne, hourColl;
     bool collFlag;
   String iconeCast, dataIcon;
    float dataWindSpeed, dataWindBearing, Direction;
      int ventVitesse;
   String tempJour, jourTraduit, tempDetail, ventDirection, airQualite;
      int tempMaxi, tempMini, tempHumid, tempPression, tempHeure, tempRessenti, airIcone;
const char* petiteIconeBmp[16] = { "_",
                                   "/p01d.bmp", "/p01n.bmp", "/p02d.bmp", "/p02n.bmp", 
                                   "/p03dn.bmp", "/p04dn.bmp", "/p04dn.bmp",
                                   "/p10d.bmp", "/p10n.bmp"," /p11d.bmp",  "/p11n.bmp",
                                   "/p13dn.bmp", "/p50dn.bmp", 
                                   "/pmaxi.bmp", "/pmini.bmp" };
const char* petiteTftIcone;
const char* grandeIconeBmp[16] = { "_",
                                   "/01d.bmp", "/01n.bmp", "/02d.bmp", "/02n.bmp", 
                                   "/03dn.bmp", "/04dn.bmp", "/04dn.bmp",
                                   "/10d.bmp", "/10n.bmp"," /11d.bmp",  "/11n.bmp",
                                   "/13dn.bmp", "/50dn.bmp", 
                                   "/maxi.bmp", "/mini.bmp" };
const char* grandeTftIcone; 
const char* airIconeBmp[6] = { "_",
                               "/Q_1.bmp", "/Q_2.bmp", "/Q_3.bmp", "/Q_4.bmp", 
                               "/Q_5.bmp" };
const char* airTftIcone;
         
//____________________________________________________________________________ 


void connectWifi() {
  
     Serial.print("Connection .");
     tft.drawString("Connection WiFi", 135, 100, 4); 
     WiFiMulti.addAP(ssid, password);
     while (WiFiMulti.run() != WL_CONNECTED) {
            Serial.print ( "." );
            delay ( 50 );
            TryNum++;
            if (TryNum > 20) {
                Serial.print("\nConnection impossible !\n");
                tft.drawString("Erreur connection !", 140, 180, 4); 
                if (WiFi.status() != WL_CONNECTED) {
                    ESP.restart();
                   }
                delay(50);
                for (;;);
               }
           }
     Serial.print("\nconnecte a "); Serial.println(ssid);
     tft.drawString("WiFi connecte ", 150, 180, 4); 
     
} 

//____________________________________________________________________________ 


void setup() {

     Serial.begin(115200); Serial.println(); Serial.println();

     tft.init();
     tft.setRotation(3);
     tft.fillScreen(TFT_BLACK);
     tft.setTextColor(TFT_BLACK); 

     if (!SPIFFS.begin()) {
         Serial.println("SPIFFS initialisation failed!");
         tft.drawString("Erreur SPIFFS !", 135, 160, 4);
         while (1) yield();
        }
     Serial.println("\r\nSPIFFS Ok");
     tft.drawString("SPIFFS OK", 170, 160, 4);    

     drawBmp("/fond.bmp", 0, 0); delay(500);  
     tft.setTextColor(TFT_CYAN); 
     tft.drawString("Initialisation systeme", 115, 140, 4);   
     tft.drawString("Calibration ecran ", 135, 180, 4);

     while (WiFi.status() != WL_CONNECTED) {
            connectWifi();
           }   

     tft.setTextColor(TFT_WHITE);   
     tft.fillScreen(TFT_BLACK);  
     bouton[0].initButton(&tft, 445, 285, 50, 50, TFT_TRANSPARENT, TFT_TRANSPARENT, TFT_TRANSPARENT, "", 2);
     drawBmp("/ici_70.bmp", 0, 250); //      !!! image depart gauche,  mais bouton depart à droite !!!
     bouton[1].initButton(&tft, 385, 285, 50, 50, TFT_TRANSPARENT, TFT_TRANSPARENT, TFT_TRANSPARENT, "", 2);
     drawBmp("/heures_70.bmp", 61, 249);
     bouton[2].initButton(&tft, 325, 285, 50, 50, TFT_TRANSPARENT, TFT_TRANSPARENT, TFT_TRANSPARENT, "", 2);
     drawBmp("/jours_70.bmp", 120, 250);

     configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
     configTzTime("CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00", ntpServer);

     OWOC.setOpenWeatherKey(ONECALLKEY);
     OWOC.setLatLon(myLATITUDE, myLONGITUDE);
//     OWOC.setLatLon(myCITYID); 
     OWOC.setUnits(myUNITS);
     
}


void loop() {

     if (WiFi.status() != WL_CONNECTED) {
         ESP.restart();
        }
     delay(50);
     
     uint16_t t_x = 0, t_y = 0;                  // coordonnées touchées par l'utilisateur
     boolean pressed = tft.getTouch(&t_y, &t_x); // vrai si contact avec l'écran !!! INVERSE !!!

//   On vérifie si la position du contact correspond à celle d'un bouton
     for (numero = 0; numero < nbrBoutons; numero++) {
          if (pressed && bouton[numero].contains(t_y, t_x)) {
              bouton[numero].press(true);
              flag = true;
              Serial.print("Bouton nr: "); Serial.println(numero);
              numeroChoix = numero;
              meteoCall = true;               
             } else {
              bouton[numero].press(false);  
             }
         }
     delay(100); // anti-rebond       

     if (((millis() - lastTimeCall) > timeCall) || (firstTimeCall == true)) {
         lastTimeCall = millis();
         firstTimeCall = false;
         localTime();
        }

     if (((millis() - lastCall) > oneCall) || (firstCall == true)) {
         lastCall = millis();
         firstCall = false;
         OWOC.parseWeather();
         meteoCall = true;
        }       

     if (OWOC.alert) {
         drawBmp("/alerte.bmp", 2, 258);
         if (flag == true) {
             afficheAlerte();
             localTime();
             flag = false;           
            }              
        }     
     
     if ((numeroChoix == 0) & (meteoCall == true)) {
         Serial.println("Routine ICI");
         meteoCall = false;
         drawBmp("/iciactif_70.bmp", 0, 250); drawBmp("/heures_70.bmp", 61, 249); drawBmp("/jours_70.bmp", 120, 250);                         
         currentDatas();
        }
     if ((numeroChoix == 1) & (meteoCall == true)) {
         Serial.println("Routine HEURES");
         meteoCall = false;
         drawBmp("/ici_70.bmp", 0, 250); drawBmp("/heuresactif_70.bmp", 61, 249); drawBmp("/jours_70.bmp", 120, 250);                           
         hourlyDatas();
        }
     if ((numeroChoix == 2) & (meteoCall == true)) {
         Serial.println("Routine JOURS");
         meteoCall = false;
         drawBmp("/ici_70.bmp", 0, 250); drawBmp("/heures_70.bmp", 61, 249); drawBmp("/joursactif_70.bmp", 120, 250);                         
         dailyDatas(); 
        }    
                                  
}
