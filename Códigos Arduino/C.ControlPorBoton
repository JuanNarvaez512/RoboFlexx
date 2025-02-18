#include <Servo.h>

// Definición de los pines para los servos y botones
const int pinServo1 = 3;
const int pinServo2 = 5;
const int pinServo3 = 9;
const int pinServo4 = 6;
const int pinServo5 = 10; // Nuevo servo

const int botonServo1 = 2;
const int botonServo2 = 4;
const int botonServo3 = 8; // Meñique
const int botonServo4 = 7;
const int botonServo5 = 11; // Nuevo botón

// Creación de los objetos Servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5; // Nuevo servo

// Rango de movimiento de cada dedo (en grados)
int rangoServo1Min = 20,  rangoServo1Max = 180;  // Pulgar
int rangoServo2Min = 20,  rangoServo2Max = 180;  // Índice
int rangoServo3Min = 25,  rangoServo3Max = 180;  // Medio
int rangoServo4Min = 25,  rangoServo4Max = 180;  // Anular
int rangoServo5Min = 20,  rangoServo5Max = 180;  // Meñique

// Variables para rastrear el estado de los servos (true = cerrado, false = abierto)
bool estadoServo1 = false;
bool estadoServo2 = false;
bool estadoServo3 = false;
bool estadoServo4 = false;
bool estadoServo5 = false;

// Variables para almacenar el estado anterior de cada botón
int botonEstadoAnterior1 = HIGH;
int botonEstadoAnterior2 = HIGH;
int botonEstadoAnterior3 = HIGH;
int botonEstadoAnterior4 = HIGH;
int botonEstadoAnterior5 = HIGH;

void setup() {
  // Asociar los servos a los pines correspondientes
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  servo4.attach(pinServo4);
  servo5.attach(pinServo5); 

  // Llevar todos los servos a la posición abierta (mano abierta)
  servo1.write(rangoServo1Max);
  servo2.write(rangoServo2Max);
  servo3.write(rangoServo3Max);
  servo4.write(rangoServo4Max);
  servo5.write(rangoServo5Max);

  // Esperar a que los servos lleguen a su posición inicial
  delay(1000);

  // Configurar los botones como entradas con resistencias pull-up
  pinMode(botonServo1, INPUT_PULLUP);
  pinMode(botonServo2, INPUT_PULLUP);
  pinMode(botonServo3, INPUT_PULLUP);
  pinMode(botonServo4, INPUT_PULLUP);
  pinMode(botonServo5, INPUT_PULLUP);

  // Inicializar la comunicación serial
  Serial.begin(115200);
  Serial.println("Sistema listo. Presiona los botones para cambiar la posición de los servos.");
}

void loop() {
  // Control del Servo 1
  int boton1 = digitalRead(botonServo1);
  if (boton1 == HIGH && botonEstadoAnterior1 == LOW) { 
    estadoServo1 = !estadoServo1; 
    servo1.write(estadoServo1 ? rangoServo1Min : rangoServo1Max);
    Serial.println(estadoServo1 ? "Servo 1: Posición de piano" : "Servo 1: Abierto");
  }
  botonEstadoAnterior1 = boton1; 

  // Control del Servo 2
  int boton2 = digitalRead(botonServo2);
  if (boton2 == HIGH && botonEstadoAnterior2 == LOW) { 
    estadoServo2 = !estadoServo2; 
    servo2.write(estadoServo2 ? rangoServo2Min : rangoServo2Max);
    Serial.println(estadoServo2 ? "Servo 2: Posición de piano" : "Servo 2: Abierto");
  }
  botonEstadoAnterior2 = boton2;

  // Control del Servo 3
  int boton3 = digitalRead(botonServo3);
  if (boton3 == HIGH && botonEstadoAnterior3 == LOW) { 
    estadoServo3 = !estadoServo3; 
    servo3.write(estadoServo3 ? rangoServo3Min : rangoServo3Max);
    Serial.println(estadoServo3 ? "Servo 3: Posición de piano" : "Servo 3: Abierto");
  }
  botonEstadoAnterior3 = boton3; 

  // Control del Servo 4
  int boton4 = digitalRead(botonServo4);
  if (boton4 == HIGH && botonEstadoAnterior4 == LOW) { 
    estadoServo4 = !estadoServo4; 
    servo4.write(estadoServo4 ? rangoServo4Min : rangoServo4Max);
    Serial.println(estadoServo4 ? "Servo 4: Posición de piano" : "Servo 4: Abierto");
  }
  botonEstadoAnterior4 = boton4; 

  // Control del Servo 5
  int boton5 = digitalRead(botonServo5);
  if (boton5 == HIGH && botonEstadoAnterior5 == LOW) { 
    estadoServo5 = !estadoServo5; 
    servo5.write(estadoServo5 ? rangoServo5Min : rangoServo5Max);
    Serial.println(estadoServo5 ? "Servo 5: Posición de piano" : "Servo 5: Abierto");
  }
  botonEstadoAnterior5 = boton5; 

  delay(50);
}
