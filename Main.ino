#include <Servo.h>
#include <Arduino.h>
// Declarmos todos los servos
Servo serv0;
Servo serv1;
Servo serv2;
Servo serv3;
Servo serv4;
Servo serv5;
Servo serv6;
Servo serv7;
//Para usar sensor ultrasonido
long tiempo;
int disparador = B8;   // triger
int entrada = B9;     // echo
float X;
float Y;
int posicion;
float distancia;
float distancia2;
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
  posicion = 0;
}

void loop() {
  distancia2 = SensorUS
  if (distancia2 =- 5 || distancia2 == 5)
  {
	  
  }
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
	serv2.write(90);
	delay(50);
    serv3.write(90);
    delay(50);
	if (posicion == 0){Y++}
    if (posicion == 1){Y--}
	if (posicion == 2){X--}
	if (posicion == 3){X++}
    var1++
  }while(var1 =! pasos);
  var1 = 0;
}

void MoverAtras(int pasos1;){
  posicion = 1;
  int var2;
  do{
	serv3.write(180);
    delay(200);
    serv2.write(180);
    delay(200);
    serv1.write(0);
    delay(200);
    serv0.write(0);
    delay(200);
    serv3.write(90);
    delay(50);
    serv2.write(90);
    delay(50);
	 serv1.write(90);
	 delay(50);
    serv0.write(90);
    delay(50);
    Y++
	  var2++
  }while(var2 != pasos1);
}

void MoverIzquierda(int op){
	posicion = 2;
	float var3;
   if (op == 0){
	var3 = X;
	X = var30 - 0.5;
	var3 = Y;
	Y = var3 + 0.5;
	//colocar movimiento a 45° a la izquierda
   }else {
	 var3 = X;
	X = var30 - 1;
	var3 = Y;
	Y = var3 + 1;  
	//colocar movimiento a 90° a la derecha
   }
}

void MoverDerecha(int op2){
	posicion = 3;
  float var3;
   if (op == 0){
	var3 = X;
	X = var30 - 0.5;
	var3 = Y;
	Y = var3 + 0.5;
	//colocar movimiento a 45° a la derecha
   }else {
	 var3 = X;
	X = var30 - 1;
	var3 = Y;
	Y = var3 + 1;  
	//colocar movimiento a 90° a la derecha
	}
}

void Centrar{
	serv0.write(90);
	serv1.write(90);
	serv2.write(90);
	serv3.write(90);
	serv4.write(45);
	serv5.write(45);
	serv6.write(45);
	serv7.write(45);
}

void SensorUS{
  // activamos el sensor
  digitalWrite(disparador, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparador, LOW);
  
  // medimos el pulso de respuesta
  tiempo = (pulseIn(entrada, HIGH)/2);
  distancia2 = float(tiempo * 0.0343);
  return distancia2;
}