//____________________________________________________________________________ 

void afficheAlerte() {

     Serial.print("Alerte info, ");
     Serial.print(OWOC.alert->startInfo);
     Serial.print(" fin prevue ");
     Serial.println(OWOC.alert->endInfo);
     Serial.print("Origine:     ");
     Serial.println(OWOC.alert->senderName);
     Serial.print("Evenement:   ");
     Serial.println(OWOC.alert->event);
     Serial.print("Description: ");
     Serial.println(OWOC.alert->summary);      

     tft.fillScreen(TFT_BLACK);
     tft.drawString("A L E R T E  M E T E O", 120, 20, 4);
     tft.drawString("Debut      " + String(OWOC.alert->startInfo), 80, 80, 4);
     tft.drawString("Fin            "  + String(OWOC.alert->endInfo), 80, 120, 4); 
     tft.drawString("Origine   " + String(OWOC.alert->senderName), 80, 160, 4);
     tft.drawString("Nature ", 80, 200, 4);
     tft.drawString((OWOC.alert->event), 80, 240, 4);
     tft.drawString((OWOC.alert->summary), 0, 280, 2);     
     delay(9000);
      
}
