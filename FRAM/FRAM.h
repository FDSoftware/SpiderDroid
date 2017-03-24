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
#ifndef SRAM_h
#define SRAM_h

#include <Arduino.h>
#include <Wire.h>

class SRAMControl(){
public:
  SRAMControl();
  void leer(int dir);
  void  grabar(float dato, int dir);
  void  format();
private:
  int _dir;
  float _dato;
};

#endif
