/*##################################################################################
  ############ Programa creado por FDSoftware ######################################
  ############       codereactor.xyz          ######################################
  ##################################################################################
*/
/*
    Libreria encargada del control de movimiento del robot
*/
#ifndef Movimientos_h
#define Movimientos_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

class Mov(){
public:
    Mov();
    void adelante(int pasos);
    void atras(int pasos1);
    void izquierda(int op);
    void derecha(int op2);
private:
}

#endif
