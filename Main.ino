#include <Servo.h>
// Declarmos todos los servos
Servo serv0;
Servo serv1;
Servo serv2;
Servo serv3;
Servo serv4;
Servo serv5;
Servo serv6;
Servo serv7;


void setup() {
  // Asiganamos los servos a las salidas del puerto "A"
  serv0.attach(A0);
  serv1.attach(A1);
  serv2.attach(A2);
  serv3.attach(A3);
  serv4.attach(A4);
  serv5.attach(A5);
  serv6.attach(A6);
  serv7.attach(A7);
}

void loop() {

}


void MoverAdelante(int pasos;){
  int var1;
  do{
    var1++;
  }while(var1 =! pasos);
}

void MoverAtras(int pasos1;){
  int var2;
  do{
  }while(var2 != pasos1);
}

void MoverIzquierda{
  
}

void MoverDerecha{
  
}

void Centrar{
  
}

void SensorUS{
  int valor;
  return valor;
}
