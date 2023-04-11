//____________________________________________________________________________ 

void currentDatas() {

     Serial.println();
     Serial.println("METEO ACTUELLE MISE A JOUR TOUTES LES 15 MINUTES");
     Serial.print("Temperature    : "); Serial.println(OWOC.current->temperature);
     tempHeure = String(OWOC.current->temperature).toInt();
     Serial.print("Ressenti       : "); Serial.println(OWOC.current->apparentTemperature);
     tempRessenti = String(OWOC.current->apparentTemperature).toInt();
     Serial.print("Humidite       : "); Serial.println(OWOC.current->humidity);
     tempHumid = String(OWOC.current->humidity).toInt();
     Serial.print("Pression       : "); Serial.println(OWOC.current->pressure);
     tempPression = String(OWOC.current->pressure).toInt();
     dataWindSpeed = (OWOC.current->windSpeed);
     dataWindBearing = (OWOC.current->windBearing);
     formatVent();
     Serial.print("Vent vitesse   : "); Serial.print(ventVitesse); Serial.println( " Km/h");    
     Serial.print("Vent direction : "); Serial.println(ventDirection);     
     Serial.print("Meteo code ID  : "); Serial.println(OWOC.current->id);
     Serial.print("Meteo          : "); Serial.println(OWOC.current->main);
     Serial.print("Meteo details  : "); Serial.println(OWOC.current->summary);
     Serial.print("Meteo icone    : "); Serial.println(OWOC.current->icon);
     dataIcon = String(OWOC.current->icon);
     meteoIcone();
     grandeTftIcone = grandeIconeBmp[iconeTft];
     Serial.print("Air data    : "); Serial.println(OWOC.quality->aqi);
     airQualite = String(OWOC.quality->aqi);
     formatAir();
     airTftIcone = airIconeBmp[airIcone];
     
//   Affichage des datas
     tft.fillRect(0, 0, 480, 255, TFT_BLACK);
     drawBmp(grandeTftIcone, 40, 0);
     drawBmp("/thermometre.bmp", 222, 5);
     drawBmp("/pressenti.bmp", 225, 65);
     drawBmp("/celsius.bmp", 370, 0);
     drawBmp("/celsius.bmp", 370, 60);     
     tft.drawRightString(String(tempHeure), 370, 5, 7); 
     tft.drawRightString(String(tempRessenti), 370, 65, 7); 
     drawBmp("/humid.bmp", 10, 130);     
     tft.drawRightString(String(tempHumid) + " %", 125, 145, 4); 
     drawBmp("/air.bmp", 140, 130);
     drawBmp(airTftIcone, 225, 130);
     tft.drawString(String(airIcone), 243, 140, 4);
     drawBmp("/pression.bmp", 300, 130);
     tft.drawRightString(String(tempPression) + " hPa", 470, 145, 4);
     drawBmp("/vent.bmp", 10, 190);
     tft.drawString(String(ventVitesse) + "km/h " + String(ventDirection), 70, 205, 4);
     tft.drawRightString(OWOC.current->summary, 470, 205, 4);
          
}
