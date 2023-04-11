//____________________________________________________________________________ 

void dailyDatas() {

     Serial.println();
     Serial.println("PREVISIONS POUR LES 7 PROCHAINS JOURS");
     tft.fillRect(0, 0, 480, 255, TFT_BLACK); dayLigne = 15;
     for (castDay = 1; castDay <= 3; castDay = castDay + 1) {
          Serial.println();
          Serial.println("Prevision pour " + String(OWOC.forecast[castDay].weekDayName));
          tempJour = String(OWOC.forecast[castDay].weekDayName);
          traductionJour();
          Serial.print("Temperature max: "); Serial.println(OWOC.forecast[castDay].temperatureHigh);
          tempMaxi = String(OWOC.forecast[castDay].temperatureHigh).toInt();
          Serial.print("Temperature min: "); Serial.println(OWOC.forecast[castDay].temperatureLow);
          tempMini = String(OWOC.forecast[castDay].temperatureLow).toInt();
          Serial.print("Humidite       : "); Serial.println(OWOC.forecast[castDay].humidity);
          tempHumid = String(OWOC.forecast[castDay].humidity).toInt();
          Serial.print("Pression       : "); Serial.println(OWOC.forecast[castDay].pressure);
          dataWindSpeed = (OWOC.forecast[castDay].windSpeed);
          dataWindBearing = (OWOC.forecast[castDay].windBearing);
          formatVent();
          Serial.print("Vent vitesse   : "); Serial.print(ventVitesse); Serial.println( " Km/h");    
          Serial.print("Vent direction : "); Serial.println(ventDirection);     
          Serial.print("Meteo code ID  : "); Serial.println(OWOC.forecast[castDay].id);
          Serial.print("Meteo          : "); Serial.println(OWOC.forecast[castDay].main);
          Serial.print("Meteo details  : "); Serial.println(OWOC.forecast[castDay].summary);
          tempDetail = String(OWOC.forecast[castDay].summary);
          Serial.print("Meteo icone    : "); Serial.println(OWOC.forecast[castDay].icon);
          Serial.println("----------------------------------------------------------");
          dataIcon = String(OWOC.forecast[castDay].icon);
          meteoIcone();
          petiteTftIcone = petiteIconeBmp[iconeTft];
          drawBmp(petiteTftIcone, 0, dayLigne);
          tft.drawString(jourTraduit, 70, dayLigne - 5, 4); 
          drawBmp("/mmaxi.bmp", 200, dayLigne - 5); tft.drawRightString((String(tempMaxi) + " C"), 280, dayLigne - 5, 4);
          drawBmp("/mmini.bmp", 300, dayLigne - 5); tft.drawRightString((String(tempMini) + " C"), 380, dayLigne - 5, 4);
          drawBmp("/mhumid.bmp", 400, dayLigne - 5); tft.drawRightString((String(tempHumid) + " %"), 480, dayLigne - 5, 4);
          tft.drawString(tempDetail, 70, dayLigne + 25, 4);
          tft.drawRightString("=> " + String(ventVitesse) + "km/h " + String(ventDirection), 480, dayLigne + 25, 4);
          dayLigne = dayLigne + 80;        
         }

}
