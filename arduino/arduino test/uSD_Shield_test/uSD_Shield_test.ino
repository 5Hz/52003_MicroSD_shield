#include <SD.h> //requerido para escribir en la memoria SD

const int chipSelect = 10;
File myFile;

void setup()
{
  Serial.begin(9600); //Inicializa comunicacion serial
  
  // asegurarse que el pin chip select esté configurado 
  // como salida, aunque no se utilice:
  pinMode(10, OUTPUT);
  
  // checa si hay una tarjeta y si puede inicializarse:
  if (!SD.begin(chipSelect)) {
    Serial.println("Error en SD");
    return;
  }
  Serial.println("SD inicializada");
  FilePrint();
  FileRead();
}

void loop(){} //No se hace nada en el loop

//*************************************************************************************

void FilePrint()
{
  myFile = SD.open("TEST5HZ.txt", FILE_WRITE);
  
  // Si el archivo se abrio correctamente, escribir en el:
  if (myFile) {
    Serial.print("escribiendo sobre TEST5HZ.txt...");
    myFile.println("Baruc estuvo aqui :P");
	// close the file:
    myFile.close();
    Serial.println("hecho");
  } else {
    // Si el archivo no pudo abrirse imprimir error:
    Serial.println("error abriendo TEST5HZ.txt");
  }
}

//*************************************************************************************

void FileRead()
{
  myFile = SD.open("TEST5HZ.txt"); //por default configurado para leer archivo
  if (myFile) {
    Serial.println("TEST5HZ.txt:");
    
    // Lee del archivo hasta que no hay nada mas en el:
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
  	// Si el archivo no pudo abrirse imprimir error:
    Serial.println("error abriendo TEST5HZ.txt");
  }  
}

