void GetDate()
{
  Wire.begin(DS1307_ADDRESS);
  //String dato = "";
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write((byte) 0);	
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);
  uint8_t ss = bcd2bin(Wire.read());
  uint8_t mm = bcd2bin(Wire.read());
  uint8_t hh = bcd2bin(Wire.read());
  Wire.read();
  uint8_t d = bcd2bin(Wire.read());
  uint8_t m = bcd2bin(Wire.read());
  uint16_t y = bcd2bin(Wire.read()) + 2000;

  if (d < 10) strLogline += '0';
  strLogline += d;
  strLogline += '.';
  if (m < 10) strLogline += '0';
  strLogline += m;
  strLogline += '.';
  strLogline += y;
  strLogline += ' ';
  if (hh < 10) strLogline += '0';
  strLogline += hh;
  strLogline += ':';
  if (mm < 10) strLogline += '0';
  strLogline += mm;
  strLogline += ':';
  if (ss < 10) strLogline += '0';
  strLogline += ss;
  strLogline += ';';
  
  //return dato;

}

void SetAlarm()
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write((byte) 7);
  Wire.write(bin2bcd(29));     // Alarm 1 sekunder
  Wire.write(0b10000000);      // Alarm 1 minutter
  Wire.write(0b10000000);      // Alarm 1 timer (flagg satt)
  Wire.write(0b10000000);      // Alarm 1 dato (flagg satt)
  Wire.write(0b10000000);      // Alarm 2 minutter
  Wire.write(0b10000000);      // Alarm 2 timer (flagg satt)
  Wire.write(0b10000000);      // Alarm 2 dato (flagg satt)
  Wire.write(0b00011111);      // skru av ocillator og enable alarm 1 & 2
  Wire.write((byte) 0);        // Nullstill alt
  Wire.endTransmission();
}

void AlarmOff()
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write((byte) 7);
  Wire.write(0b10000000);      // Alarm 1 sekunder
  Wire.write(0b10000000);      // Alarm 1 minutter
  Wire.write(0b10000000);      // Alarm 1 timer (flagg satt)
  Wire.write(0b10000000);      // Alarm 1 dato (flagg satt)
  Wire.write(0b10000000);      // Alarm 2 minutter
  Wire.write(0b10000000);      // Alarm 2 timer (flagg satt)
  Wire.write(0b10000000);      // Alarm 2 dato (flagg satt)
  Wire.write(0b00011100);      // skru av ocillator og enable alarm 1 & 2
  Wire.write((byte) 0);        // Nullstill alt
  Wire.endTransmission();
}


// utility functions
static uint8_t bcd2bin (uint8_t val) { 
  return val - 6 * (val >> 4); 
}
static uint8_t bin2bcd (uint8_t val) { 
  return val + 6 * (val / 10); 
}

