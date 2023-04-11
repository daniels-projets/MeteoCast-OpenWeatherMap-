//____________________________________________________________________________ 

void localTime() {
  
     Serial.println("Connexion time");
     struct tm timeinfo;
     if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
        return;
       }

     Serial.println();
     Serial.println("Time variables");
     char timeWeekDay[10];
     strftime(timeWeekDay,10, "%A", &timeinfo);
     Serial.println(timeWeekDay);
     char timeHour[3];
     strftime(timeHour,3, "%H", &timeinfo);
     timeHourData = String(timeHour).toInt();     
     
     Serial.print(timeHour); Serial.print(":");
     char timeMinute[3];
     strftime(timeMinute,3, "%M", &timeinfo);
     Serial.println(timeMinute);    
     
     char timeInfoDay[2];
     strftime(timeInfoDay,2, "%u", &timeinfo);    
     timeDay = String(timeInfoDay).toInt();     
     char timeInfoJour[3];
     strftime(timeInfoJour,3, "%e", &timeinfo);    
     timeJour = String(timeInfoJour).toInt();    
     char timeInfoMois[3];
     strftime(timeInfoMois,3, "%m", &timeinfo);     
     timeMois = String(timeInfoMois).toInt();     

     tft.fillRect(185, 255, 295, 65, TFT_BLACK);
     tft.drawRoundRect(185, 256, 295, 55, 4, TFT_LIGHTGREY);
     tft.drawRoundRect(186, 257, 293, 55, 4, TFT_LIGHTGREY); // pour l'épaisseur
     tft.setTextColor(TFT_LIGHTGREY);     
     dateTxt = ((jourTab[timeDay]) + " " + (String(timeJour)) + " " + (moisTab[timeMois]));
     tft.drawCentreString(dateTxt , 330, 263, 4);         
     heureTxt =  (String(timeHour) + "h " + String(timeMinute));
     tft.drawCentreString(heureTxt , 330, 287, 4);
     
}
