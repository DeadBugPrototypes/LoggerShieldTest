void getVolt(){
  int VoltReading;
  
  VoltReading = analogRead(A3);
  
  strLogline += VoltReading;
  strLogline += ';';
  
}

boolean underVoltage(){
  boolean OK = false;
  int VoltReading;
  
  VoltReading = analogRead(A3);
  
  if (VoltReading < 355) OK = true;  // batteristrøm lav
  
  if (VoltReading < 300) OK = false;  // batteristrøm ikke koblet på..
  
  return OK;
}
