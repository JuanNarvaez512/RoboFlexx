# Explicación del Código de Control por Botones

Este código permite controlar los **5 servomotores** del brazo robótico utilizando **botones físicos**. Cada botón está asignado a un servo y, cuando se presiona, el servo se mueve a una posición predefinida. Cuando el botón se suelta, el servo vuelve a su posición original.

## 1️⃣ **Definición de Pines y Variables**

```cpp
#include <Servo.h>
```
Este código incluye la biblioteca **Servo.h**, que facilita el control de los servomotores.

### **Pines de los Servos y Botones**
Cada servo y botón están conectados a un pin específico del Arduino:

```cpp
const int pinServo1 = 3;
const int pinServo2 = 5;
const int pinServo3 = 9;
const int pinServo4 = 6;
const int pinServo5 = 10;

const int botonServo1 = 2;
const int botonServo2 = 4;
const int botonServo3 = 8;
const int botonServo4 = 7;
const int botonServo5 = 11;
```
- **Los servos están conectados a los pines 3, 5, 9, 6 y 10.**
- **Los botones están conectados a los pines 2, 4, 8, 7 y 11.**

### **Creación de los Objetos Servo**
```cpp
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
```
Se crean cinco objetos **Servo** para controlar cada dedo del brazo.

### **Rango de Movimiento de Cada Servo**
```cpp
int rangoServo1Min = 20,  rangoServo1Max = 180;
int rangoServo2Min = 20,  rangoServo2Max = 180;
int rangoServo3Min = 25,  rangoServo3Max = 180;
int rangoServo4Min = 25,  rangoServo4Max = 180;
int rangoServo5Min = 20,  rangoServo5Max = 180;
```
Cada servo tiene un **rango de movimiento en grados (0° a 180°)**.

### **Estado de los Servos y Botones**
```cpp
bool estadoServo1 = false;
bool estadoServo2 = false;
bool estadoServo3 = false;
bool estadoServo4 = false;
bool estadoServo5 = false;
```
Estas variables almacenan si el servo está **abierto o cerrado**.

```cpp
int botonEstadoAnterior1 = HIGH;
int botonEstadoAnterior2 = HIGH;
int botonEstadoAnterior3 = HIGH;
int botonEstadoAnterior4 = HIGH;
int botonEstadoAnterior5 = HIGH;
```
Cada variable almacena el estado anterior del botón correspondiente.

## 2️⃣ **Configuración Inicial (`setup()`)**

```cpp
void setup() {
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  servo4.attach(pinServo4);
  servo5.attach(pinServo5);
```
Los servos se **asignan a sus pines correspondientes**.

```cpp
servo1.write(rangoServo1Max);
servo2.write(rangoServo2Max);
servo3.write(rangoServo3Max);
servo4.write(rangoServo4Max);
servo5.write(rangoServo5Max);
```
Cada servo se inicializa en la **posición abierta**.

```cpp
delay(1000);
```
Se espera un segundo para que los servos se acomoden.

```cpp
pinMode(botonServo1, INPUT_PULLUP);
pinMode(botonServo2, INPUT_PULLUP);
pinMode(botonServo3, INPUT_PULLUP);
pinMode(botonServo4, INPUT_PULLUP);
pinMode(botonServo5, INPUT_PULLUP);
```
Se configuran los botones como **entradas con resistencias pull-up**.

```cpp
Serial.begin(115200);
Serial.println("Sistema listo. Presiona los botones para cambiar la posición de los servos.");
```
Se inicializa la comunicación **Serial** para depuración.

## 3️⃣ **Bucle Principal (`loop()`)**

Cada botón se lee y, si se ha presionado, se cambia el estado del servo.

```cpp
int boton1 = digitalRead(botonServo1);
if (boton1 == HIGH && botonEstadoAnterior1 == LOW) { 
  estadoServo1 = !estadoServo1;
  servo1.write(estadoServo1 ? rangoServo1Min : rangoServo1Max);
  Serial.println(estadoServo1 ? "Servo 1: Posición de piano" : "Servo 1: Abierto");
}
botonEstadoAnterior1 = boton1;
```
- **Lee el estado del botón** (`digitalRead`).
- **Si el botón ha cambiado de estado**, invierte el estado del servo.
- **Mueve el servo** a la nueva posición.
- **Imprime el estado en el monitor serial**.

Este proceso se repite para **cada uno de los servos**.

## 4️⃣ **Modificaciones y Mejoras**
Si deseas **modificar el código**, aquí hay algunas opciones:

### **🔹 Ajustar el rango de los servos**
Cambia los valores de `rangoServoXMin` y `rangoServoXMax`.
```cpp
int rangoServo1Min = 10,  rangoServo1Max = 170;  // Ajusta los ángulos
```

### **🔹 Cambiar los pines de los servos o botones**
Si necesitas usar otros pines:
```cpp
const int pinServo1 = 6;  // Cambia el pin
```

### **🔹 Agregar más servos**
Añade más objetos y botones siguiendo el mismo patrón.

### **🔹 Mejorar la respuesta del botón**
Agregar **debounce** para evitar lecturas erróneas:
```cpp
delay(50);  // Pequeño retraso para evitar rebotes
```

## 5️⃣ **Conclusión**
Este código es una forma sencilla y efectiva de controlar **un brazo robótico con botones físicos**. Permite modificaciones fáciles para ajustar la sensibilidad de los servos, cambiar los pines o mejorar el código con más funcionalidades. 🚀🤖
