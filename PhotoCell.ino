void getLight(){
  int photocellReading;
  
  photocellReading = analogRead(0);
  
  strLogline += photocellReading;
  strLogline += ';';
  
}

