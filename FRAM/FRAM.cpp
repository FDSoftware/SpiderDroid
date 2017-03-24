/*##################################################################################
  ############ Programa creado por FDSoftware ######################################
  ############       codereactor.xyz          ######################################
  ##################################################################################
*/
/*Libreria para control de memoria FRAM por i2c (FM24CL16)
Funciones:
  guarda variable en memoria
  recupera la informacion como variable
  borra todos los datos de la memoria
*/

#include <Arduino.h>
#include <FRAM.h>
#include <Wire.h>
int dirSRAM = 0;  // poner luego en SRAM.H
int indice = 0;
FRAMControl::FRAMControl(){

}

void FRAMControl::leer(int dir){
  _dir = dir;
  Wire.beginTransmission(dirSRAM);
  Wire.send(_dir);
  Wire.endTransmission();
  Wire.requestFrom(dirSRAM,8,true);
  while(Wire.available()){
      datoB[indice] = Wire.receive();
      indice++;
  }
  indice = 0;
}

union Float_Byte{
float datoF;
byte  datoB[8];
}unionFB;

void FRAMControl::grabar(){

}

void SRAMControl::format(){

}
