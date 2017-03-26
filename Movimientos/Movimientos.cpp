/*##################################################################################
  ############ Programa creado por FDSoftware ######################################
  ############       codereactor.xyz          ######################################
  ##################################################################################
*/
/*
    Libreria encargada del control de movimiento del robot
*/
#include <Arduino.h>
#include<Wire.h>
#include<Movimientos.h>
Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver(0x40);
const uint8_t freq     = 50;
const uint8_t MinTicks = 102;
const uint8_t MaxTicks = 512;
const uint8_t Escala[179];
Movimientos::Mov(){
    servo.begin();
    servo.setPWMfreq(freq);
}

Movimientos::adelante(int pasos, int op, int var){
    //pasos == numero de pasos a mover
    //op == suma o resta la variable "var" (1/0)
    //var == variable de ubicacion, devulve al final
}

Movimientos::atras(int pasos1){
    //se resta Y
}

Movimientos::izquierda(int opcion){

}
Movimientos::derecha(int opcion1){

}

Movimientos::centrar(){

}
