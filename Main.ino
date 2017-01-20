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
  //centrar servos de las patas
  serv0.write(90);
  serv1.write(90);
  serv2.write(90);
  serv3.write(90);
}

void loop() {

}


void MoverAdelante(int pasos;){
  int var1;
  do{ //Movimiento para adelante con servos principales
    serv0.write(180);
    delay(200);
    serv1.write(180);
    delay(200);
    serv2.write(0);
    delay(200);
    serv3.write(0);
    delay(200);
    serv0.write(90);
    delay(50);
    serv1.write(90);
    delay(50);
    serv3.write(90);
    delay(50);
    
    var1++
  }while(var1 =! pasos);
  var1 = 0;
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
