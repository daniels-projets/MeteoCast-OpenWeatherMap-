//____________________________________________________________________________ 

void formatVent() {

     ventVitesse = int(dataWindSpeed * 3.6);

     Direction = dataWindBearing;
     if (Direction > 337.5 || Direction <= 22.5) { ventDirection = "Nord"; }
     if (Direction > 22.5 && Direction <= 67.5) { ventDirection = "N.Est"; }
     if (Direction > 67.5 && Direction <= 112.5) { ventDirection = "Est"; }
     if (Direction > 112.5 && Direction <= 157.5) { ventDirection = "S.Est"; }
     if (Direction > 157.5 && Direction <= 202.5) { ventDirection = "Sud"; }
     if (Direction > 202.5 && Direction <= 247.5) { ventDirection = "S.Ouest"; }
     if (Direction > 247.5 && Direction <= 292.5) { ventDirection = "Ouest"; }
     if (Direction > 292.5 && Direction <= 337.5) { ventDirection = "N.Ouest"; }  

}


//____________________________________________________________________________ 

void meteoIcone() {
           
     if (dataIcon == "01d") { iconeTft = 1; }
     if (dataIcon == "01n") { iconeTft = 2; }
     if (dataIcon == "02d") { iconeTft = 3; }
     if (dataIcon == "02n") { iconeTft = 4; }
     if (dataIcon == "03d" || dataIcon == "03n") { iconeTft = 5; }
     if (dataIcon == "04d" || dataIcon == "04n") { iconeTft = 6; }
     if (dataIcon == "09d" || dataIcon == "09n") { iconeTft = 7; }
     if (dataIcon == "10d") { iconeTft = 8; }
     if (dataIcon == "10n") { iconeTft = 9; }
     if (dataIcon == "11d") { iconeTft = 10; }
     if (dataIcon == "11n") { iconeTft = 11; }
     if (dataIcon == "13d" || dataIcon == "13n") { iconeTft = 12; }
     if (dataIcon == "50d" || dataIcon == "50n") { iconeTft = 13; }

}


//____________________________________________________________________________ 

void formatAir() {

     if (airQualite == "1") { airIcone = 1; }
     if (airQualite == "2") { airIcone = 2; }
     if (airQualite == "3") { airIcone = 3; }
     if (airQualite == "4") { airIcone = 4; }
     if (airQualite == "5") { airIcone = 5; }
  
}
