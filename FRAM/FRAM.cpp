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

FRAM::FRAMControl(){
    Wire.begin();
}

void FRAMControl::leer(int dir,int pagina){
  _dir = dir;
  dirfinal = dirFRAM|pagina|1; //encontrar otra manera
  Wire.beginTransmission(dirfinal);
  Wire.send(_dir);
  Wire.endTransmission();
  Wire.requestFrom(dirfinal,8,true);
  while(Wire.available()){
      unionFB.datoF = 0.0;
      unionFB.datoB[indice] = Wire.receive();
      indice++;
  }
  indice = 0;
  dirfinal = 0;
  return unionFB.datoF;
}

void FRAMControl::grabar(int dir1, int pagina1, int dato){
      dirfinal = dirFRAM|pagina1|0;
      Wire.beginTransmission(dirfinal);
      Wire.send(dir1);
      Wire.send(dato);
      Wire.endTransmission();
}

void SRAMControl::format(){
    //implementar luego
}

union Float_Byte{
float datoF;
byte  datoB[8];
}unionFB;
