# MeteoCast-OpenWeatherMap-

https://user-images.githubusercontent.com/126287326/231193817-78d30a32-304c-4a13-8b60-fe92800b0b7d.mp4

Station Météo exploitant les données OpenWeatherCas avec la librairie OpenWeatherOneCall

Ce projet est un dérivé de mon ancien projet Horloge Météo avec les mêmes sources d'inspiration

La variante de ce projet tient à l'utilisation d'un écran tactile pour naviguer entre les 3 menus

Menu 1: Meteo courante avec indication de:
 
        L'icone météo

        Température réelle
     
        Température ressentie
       
        Taux d'humidité
   
        Index de qualité de l'air (de 1 à 5)
     
        La pression atmosphérique
     
        Vitesse et direction du vent 
        
        Et la descripition
 
        
Menu 2: Previsions pour les 6 prochaines heures de: 

        L'icone météo 
        
        Température prévue 
        
        Température ressentie 
        
        La description 
        
        
Menu 3: Prévision pour les 3 prochains jours 

        L'icone météo 
        
        Les températures maxi et mini prévues 
        
        Le taux d'humidité 
        
        La description 
        
        Et la vitesse et direction du vent 
        
         
Matériel utilisé: Esp32 DevKit et Tft Touch de 3,5' ILI9488 

         Pour l'Esp32, adaptation de la mémoire SPIFFS 
         
                       afin de gagner de l'espace pour les images 
                       
                       No Ota 2Mo applis et 2Mo SPIFFS 
                       
 
En cas d'alerte météo, indication par icone sur touche météo courante

Et indication de la nature et durée sur un écran affiché de façon temporaire 
 
 
 
Schéma de connection de l'afficheur  


![Esp32 ILI9488_Touch copie](https://user-images.githubusercontent.com/126287326/231236152-1e4a359f-b6f9-4e60-970b-76f13b8d5a03.jpg)

        
Copie d'écran pour organisation du programme avec les différents sous-programmes



<img width="1226" alt="Capture d’écran 2023-04-12 à 11 21 37" src="https://user-images.githubusercontent.com/126287326/231416092-5caaf179-db45-4d78-9014-d179c523344d.png">




Et la structure des fichier dans le dossier

Il y a aussi le fichier User_Setup pour TFT_eSPI

Bonne bidouille à vous...

