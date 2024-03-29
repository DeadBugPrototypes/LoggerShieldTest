void getTemp(){
  pinMode(ONE_WIRE_BUS, OUTPUT);
  OneWire ds(ONE_WIRE_BUS);

  char strTemp[10]; 
  byte data[12];
  byte addr[8];
  

  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      Serial.println("Finner ingen sensor!");
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {;
      Serial.print("Device is not recognized");
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end
  delay(1000);
  byte present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); // Read Scratchpad

  
  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }
  
  ds.reset_search();
  
  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;
  
  dtostrf(TemperatureSum,1,2,strTemp); 
  strLogline += strTemp;
  strLogline += ';';
  //return strTemp;
  
}

