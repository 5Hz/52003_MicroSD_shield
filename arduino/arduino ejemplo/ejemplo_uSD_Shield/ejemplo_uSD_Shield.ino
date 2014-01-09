/******************************************************************
** Código creado en Electrónica 5Hz                              **
** www.5hz-electronica.com                                       **
** Por: Rafael Almaguer                                          **
**                                                               **
** Descripción del código:                                       **
**                                                               **
** Ejemplo para el uSD Shield:                                   **
** Este programa escribe y lee en la memoria uSD                 **
** Escribe sobre un archivo llamado SDTEST el string             **
** "Probando... 1, 2, 3..."                                      **
** para despues leer el contenido del archivo e imprimirlo       **
** en el puerto Serial                                           **
** (el programa escribe al final del archivo, si ya tenia algo   **
** escrito se escribe despues de eso)                            **
*******************************************************************
Conexiones:
UNO   uSD Shield

10    Chip Select (memoria uSD)
11    MOSI (master Out - Slave In)
12    MISO (master In - Slave Out)
13    SCK (serial Clock)
*/

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
  myFile = SD.open("SDTEST.txt", FILE_WRITE);
  
  // Si el archivo se abrio correctamente, escribir en el:
  if (myFile) {
    Serial.print("escribiendo sobre SDTEST.txt...");
    myFile.println("Probando... 1, 2, 3...");
	// close the file:
    myFile.close();
    Serial.println("hecho");
  } else {
    // Si el archivo no pudo abrirse imprimir error:
    Serial.println("error abriendo SDTEST.txt");
  }
}

void FileRead()
{
  myFile = SD.open("SDTEST.txt"); //por default configurado para leer archivo
  if (myFile) {
    Serial.println("SDTEST.txt:");
    
    // Lee del archivo hasta que no hay nada mas en el:
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
  	// Si el archivo no pudo abrirse imprimir error:
    Serial.println("error abriendo SDTEST.txt");
  }  
}

