//____________________________________________________________________________ 

void hourlyDatas() {

     Serial.println();
     Serial.println("PREVISIONS POUR LES 24 HEURES A VENIR, PALIER DE 1 HEURES");
     tft.fillRect(0, 0, 480, 255, TFT_BLACK); hourLigne = 30; collFlag = false;
     for (castHour = 1; castHour <= 6; castHour = castHour + 1) {
          Serial.println();
          Serial.println("Prevision pour " + String(castHour) + " heures");
          Serial.print("Temperature    : "); Serial.println(OWOC.hour[castHour].temperature);
          tempHeure = String(OWOC.hour[castHour].temperature).toInt();
          Serial.print("Ressenti       : "); Serial.println(OWOC.hour[castHour].apparentTemperature);
          tempRessenti= String(OWOC.hour[castHour].apparentTemperature).toInt();
          Serial.print("Humidite       : "); Serial.println(OWOC.hour[castHour].humidity);
          Serial.print("Pression       : "); Serial.println(OWOC.hour[castHour].pressure);
          dataWindSpeed = (OWOC.hour[castHour].windSpeed);
          dataWindBearing = (OWOC.hour[castHour].windBearing);
          formatVent();
          Serial.print("Vent vitesse   : "); Serial.print(ventVitesse); Serial.println( " Km/h");    
          Serial.print("Vent direction : "); Serial.println(ventDirection);     
          Serial.print("Meteo code ID  : "); Serial.println(OWOC.hour[castHour].id);
          Serial.print("Meteo          : "); Serial.println(OWOC.hour[castHour].main);
          Serial.print("Meteo details  : "); Serial.println(OWOC.hour[castHour].summary);
          tempDetail = String(OWOC.hour[castHour].summary);
          Serial.print("Meteo icone    : "); Serial.println(OWOC.hour[castHour].icon);
          Serial.println("----------------------------------------------------------");
          dataIcon = String(OWOC.hour[castHour].icon);
          meteoIcone();
          petiteTftIcone = petiteIconeBmp[iconeTft];

          timeCast = castHour + timeHourData;            
          if (timeCast > 24) { timeCast = timeCast - 24; }
           
          if ((castHour <= 3) & (collFlag == false)) { 
              drawBmp(petiteTftIcone, 0, hourLigne);

              tft.drawString("A " + String(timeCast) + " heure(s)", 55, hourLigne - 10, 2);              
              drawBmp("/mthermometre.bmp", 55, hourLigne + 10); tft.drawRightString((String(tempHeure) + " C"), 130, hourLigne + 10, 4);
              drawBmp("/mressenti.bmp", 140, hourLigne + 10); tft.drawRightString((String(tempRessenti) + " C"), 230, hourLigne + 10, 4);              
              tft.drawString(tempDetail, 50, hourLigne + 40, 4);
              hourLigne = hourLigne + 80;
             }
          if (castHour == 3) { collFlag = true; hourLigne = 30; }
          if ((castHour > 3) & (collFlag == true)) { 
              drawBmp(petiteTftIcone, 240, hourLigne);
              tft.drawString("A " + String(timeCast) + " heure(s)", 295, hourLigne - 10, 2);              
              drawBmp("/mthermometre.bmp", 295, hourLigne + 10); tft.drawRightString((String(tempHeure) + " C"), 370, hourLigne + 10, 4);
              drawBmp("/mressenti.bmp", 380, hourLigne + 10); tft.drawRightString((String(tempRessenti) + " C"), 470, hourLigne + 10, 4);              
              tft.drawString(tempDetail, 290, hourLigne + 40, 4);              
              hourLigne = hourLigne + 80;
             }    
         }

}
