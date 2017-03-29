/*##################################################################################
  ############ Programa creado por FDSoftware ######################################
  ############       codereactor.xyz          ######################################
  ##################################################################################
*/
/*
    Libreria encargada del control de movimiento del robot
*/
//valores de movimiento de servos copiados del "MePed v2"
//http://www.meped.io/mepedv2
#ifndef Movimientos_h
#define Movimientos_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

class Mov(){
public:
    Mov();
    int adelante(int pasos, int op, int var);
    int atras(int pasos1,int var2);
    void izquierda(int op);
    void derecha(int op2);
private:
  int var1 = 0;
  int varC = 0;
}

#endif
