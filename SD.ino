
File myFile;

void WriteSD()
{
  
  
  if (!SD.begin(SD_CHIPSELECT)) {
    Serial.println("initialization failed!");
    return;
  }
  
  myFile = SD.open("DATALOG.TXT", FILE_WRITE);
  
  if (myFile) {
    myFile.println(strLogline);
    myFile.close();
    Serial.print("Skriver: ");
    Serial.println(strLogline);
  } else {
    Serial.println("error opening test.txt");
  }
}

