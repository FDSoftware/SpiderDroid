/*##################################################################################
  ############ Programa creado por FDSoftware ######################################
  ############       codereactor.xyz          ######################################
  ##################################################################################
#valores de movimiento de servos copiados del "MePed v2"#
#############http://www.meped.io/mepedv2###############
*/
/*
    Libreria encargada del control de movimiento del robot
*/
#include <Arduino.h>
#include<Wire.h>
#include<Movimientos.h>
Adafruit_PWMServoDriver servo = Adafruit_PWMServoDriver(0x40);
const uint8_t freq     = 50;
const uint8_t MinTicks = 102;//ticks minimos del servo
const uint8_t MaxTicks = 512;//ticks maximos del servo
const uint8_t Vel = 10;//velocidad de movimiento de los servos
//del mepedv2
// calibration
int da =  -12,  // Left Front Pivot
    db =   10,  // Left Back Pivot
    dc =  -18,  // Right Back Pivot
    dd =   12;  // Right Front Pivot

// servo initial positions + calibration
int a90  = (90  + da),
    a120 = (120 + da),
    a150 = (150 + da),
    a180 = (180 + da);

int b0   = (0   + db),
    b30  = (30  + db),
    b60  = (60  + db),
    b90  = (90  + db);

int c90  = (90  + dc),
    c120 = (120 + dc),
    c150 = (150 + dc),
    c180 = (180 + dc);

int d0   = (0   + dd),
    d30  = (30  + dd),
    d60  = (60  + dd),
    d90  = (90  + dd);
  //nada mas del mepedv2 :,V
Movimientos::Mov(){
    servo.begin();
    servo.setPWMfreq(freq);
}

Movimientos::adelante(int pasos, int op, int var){
    //pasos == numero de pasos a mover
    //op == suma o resta la variable "var" (1/0)
    //var == variable de ubicacion, devulve al final
    do {
    //de aca para abajo me lo afane :,V
      // Left Front Pivot
 a90 = (90 + da),
 a120 = (120 + da),
 a150 = (150 + da),
 a180 = (180 + da);

 // Left Back Pivot
 b0 = (0 + db),
 b30 = (30 + db),
 b60 = (60 + db),
 b90 = (90 + db);

 // Right Back Pivot
 c90 = (90 + dc),
 c120 = (120 + dc),
 c150 = (150 + dc),
 c180 = (180 + dc);

 // Right Front Pivot
 d0 = (0 + dd),
 d30 = (30 + dd),
 d60 = (60 + dd),
 d90 = (90 + dd);

 // set servo positions and speeds needed to walk forward one step
 // (LFP,  LBP, RBP,  RFP, LFL, LBL, RBL, RFL, S1, S2, S3, S4)
 serv(a180, b0 , c120, d60, 42,  33,  33,  42);
 serv( a90, b30, c90,  d30, 6,   33,  33,  42);
 serv( a90, b30, c90,  d30, 42,  33,  33,  42);
 serv(a120, b60, c180, d0,  42,  33,  6,   42);
 serv(a120, b60, c180, d0,  42,  33,  33,  42);
 serv(a150, b90, c150, d90, 42,  33,  33,  6);
 serv(a150, b90, c150, d90, 42,  33,  33,  42);
 serv(a180, b0,  c120, d60, 42,  6,   33,  42);
 //ya termino el robo :,v
      var1++;
      if (op == 1) {var++;}
      if (op == 0) {var--;}
    } while(var1 <= pasos);
}

Movimientos::atras(int pasos1,int var2){
  do {
    serv(180, 0,  120, 60, 42, 33, 33, 42);
    serv(150, 90, 150, 90, 42, 18, 33, 42);
    serv(150, 90, 150, 90, 42, 33, 33, 42);
    serv(120, 60, 180, 0,  42, 33, 33, 6);
    serv(120, 60, 180, 0,  42, 33, 33, 42);
    serv(90,  30, 90,  30, 42, 33, 18, 42);
    serv(90,  30, 90,  30, 42, 33, 33, 42);
    serv(180, 0,  120, 60, 6,  33, 33, 42);
    var2--;
    varC++;
  } while(varC <= pasos1);
  varC = 0;
  return var2
}

Movimientos::izquierda(int opcion){
  serv(150,  90, 90,  30, 42, 6,  33, 42);
  serv(150,  90, 90,  30, 42, 33, 33, 42);
  serv(120,  60, 180, 0,  42, 33, 6,  42);
  serv(120,  60, 180, 0,  42, 33, 33, 24);
  serv(90,   30, 150, 90, 42, 33, 33, 6);
  serv(90,   30, 150, 90, 42, 33, 33, 42);
  serv(180,  0,  120, 60, 6,  33, 33, 42);
  serv(180,  0,  120, 60, 42, 33, 33, 33);
}
Movimientos::derecha(int opcion1){
  serv( 90, 30, 150, 90, 6,  33, 33, 42);
  serv( 90, 30, 150, 90, 42, 33, 33, 42);
  serv(120, 60, 180, 0,  42, 33, 33, 6);
  serv(120, 60, 180, 0,  42, 33, 33, 42);
  serv(150, 90, 90,  30, 42, 33, 6,  42);
  serv(150, 90, 90,  30, 42, 33, 33, 42);
  serv(180, 0,  120, 60, 42, 6,  33, 42);
  serv(180, 0,  120, 60, 42, 33, 33, 42);
}

Movimientos::centrar(){
    serv(90,90,90,90,90,90,90);
  }
void serv(int ser1, int serv2,int serv3, int serv4, int serv5,int serv6, int serv7) {
//es muy posible que el servo no funcione bien si se cambia de
// 180 a 0 de golpe, luego hacer ciclo para cambiar de posicion
//de a pasos
  pwm.setPWM(0, 0, conversor(ser1));.
  delay(10);
  pwm.setPWM(1, 0, conversor(ser2));
  delay(10);
  pwm.setPWM(2, 0, conversor(ser3));
  delay(10);
  pwm.setPWM(3, 0, conversor(ser4));
  delay(10);
  pwm.setPWM(4, 0, conversor(ser5));
  delay(10);
  pwm.setPWM(5, 0, conversor(ser6));
  delay(10);
  pwm.setPWM(6, 0, conversor(ser7));
}
int conversor(int grados){ //convierte los grados a ticks
    int varG = map(grados, 0, 180,MinTicks,MaxTicks);
    return varG;
}
