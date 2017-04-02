/*##################################################################################
  ############ Programa creado por FDSoftware ######################################
  ############       codereactor.xyz          ######################################
  ##################################################################################
*/
#include <Arduino.h>
#include <SRAM.h>
#include <Movimientos.h>
//variables para usar sensor ultrasonido
long tiempo;
int disparador =  PB8;   // triger
int entrada = PB9;     // echo
float distancia;
float distancia2;
//variables para ubicacion
float X;
float Y;
//variable para determinar la posicion del robot
int posicion;
//variables para guardar objetos
float obstaculo[3][200];
int indice1 = 0;
int indice2 = 0;
int var4;
//Variables para control de bateria
int var5 = 0;
int var6 = 0;
int var7 = 0;
//inciar libreria movimiento
Movimientos mov();
//iniciar libreria FRAM
FRAMControl mem1();
//variable para ciclo FRAM
int ciclo = 0;
void setup() {
  //centrar servos
  mov.centrar();
  posicion = 0;
  //declarar pins para control bateria
  pinMode(PB5,INPUT);
  pinMode(PB6,INPUT);
  pinMode(PB7,INPUT);
  recuperVarFRAM();//leemos las variables de la FRAM
}

void loop() {
  ciclo++;
  distancia2 = SensorUS
  var5 = digitalRead(PB5);
  var6 = digitalRead(PB6);
  var7 = digitalRead(PB6);

  if(var7 == HIGH || var6 == HIGH){//cuando la bateria sea mayor al 25% rutina comun

	if (distancia2 =- 5 || distancia2 == 5)
	{
		//guardamos el obstaculo en el array
		//esta mal hay que convertir la distancia del sensor de ultrasonido
		//a cordenadas antes de guardar las coordenadas
		//prox guardar datos en FRAM externa
		obstaculo[indice1][indice2] = var4; //guardamos el ID del objeto
		var4++
		indice1++
		obstaculo[indice1][indice2] = X; //guardamos cordenadas X del objeto
		indice1++
		obstaculo[indice1][indice2] = Y; //guardamos cordenadas Y del objeto
		indice1 = 0;
		indice2++

	}else{
	  MoverAdelante(2);//mover adelante 2 pasos.
	}
  }
  if(var5 == HIGH){
	  //poner rutina para encontrar la estacion de carga
  }
  if(ciclo == 10){
    ciclo = 0;
    guardarFRAM();//hacemos copia de variables a la FRAM
  }
}


void MoverAdelante(int pasos;){
	if (posicion == 0){
    Y = mov.adelante(pasos, 1, Y);
  }
    if (posicion == 1){
      Y = mov.adelante(pasos, 0, Y);
    }
	if (posicion == 2){
      X = mov.adelante(pasos, 0, X);
  }
	if (posicion == 3){
      X = mov.adelante(pasos, 1, X);
  }
}

void MoverAtras(int pasos1;){
  posicion = 1;
  Y = mov.atras(pasos1, Y);
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

guardarFRAM(){
  for (int i = 0; i < 200; i++) {
    mem1.grabar(i,1,obstaculo[0,i]);
  }
  for (int i2 = 0; i2 < 200; i2++) {
    mem1.grabar(i,2,obstaculo[1,i2]);
  }
  for (int i3 = 0; i3 < 200; i3++) {
    mem1.grabar(i,3,obstaculo[2,i3]);
  }
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
