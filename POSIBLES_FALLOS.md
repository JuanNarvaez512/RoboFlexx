# Posibles Fallos y Soluciones en el Brazo Robótico

En el desarrollo y uso del **brazo robótico controlado por Bluetooth y botones**, es posible que ocurran algunos errores o fallos técnicos. Aquí recopilamos los problemas más comunes y su solución para garantizar un correcto funcionamiento del proyecto.

## **Error al Cargar el Código en el Arduino o ESP32**
### **Posible fallo:**
- Si al intentar cargar el código en el **ESP32 o Arduino** aparece un error de comunicación.

### **Solución:**
- **Desconectar los pines RX y TX** antes de subir el código. Estos pines se utilizan para la comunicación serie, y si están conectados al módulo Bluetooth o a otro dispositivo, pueden interferir en la carga del programa.
- Una vez cargado el código, puedes volver a conectar los cables RX y TX.

---

## **Los Servos No Responden o No Se Mueven Correctamente**
### **Posible fallo:**
- Algunos servos no giran o lo hacen de manera errática.
- Se escuchan ruidos extraños, pero no hay movimiento.

### **Solución:**
- **Revisar las conexiones**: Asegurarse de que los servos están correctamente conectados a sus respectivos pines del Arduino.
- **Verificar la alimentación**: Los servos necesitan suficiente corriente. Si el brazo tiene muchos servos, usa una fuente de alimentación externa en lugar de alimentar los servos directamente desde el Arduino.
- **Comprobar la configuración de los servos en el código**: Cada servo tiene un rango de movimiento de **0° a 180°**. Si el código intenta moverlos fuera de este rango, podrían quedar bloqueados.
- **Verificar la posición de los servos**: Asegurarse de que los servos no se choque con la carcasa.

---

## **Montaje Incorrecto de la Mano Robótica**
### **Posible fallo:**
- La mano no se mueve correctamente o los dedos no cierran bien.

### **Solución:**
- **Revisar el montaje de los dedos**: Asegúrate de que las piezas están bien ensambladas y alineadas.
- **Comprobar las gomas tensadas**: Si las gomas están demasiado flojas, los dedos no volverán a su posición original. Si están demasiado tensas, el servo puede no tener suficiente fuerza para cerrar la mano.
- Ajustar la tensión hasta encontrar un equilibrio que permita un movimiento fluido de los dedos.

---

## **Los LED de la Caja RGB No Funcionan**
### **Posible fallo:**
- Los LED RGB no encienden o muestran colores incorrectos.

### **Solución:**
- **Revisar las conexiones**: Asegúrate de que los cables están conectados en los pines correctos.
- **Verificar la polaridad de los LED**: Los LED RGB tienen **una pata más larga (ánodo común) o pueden ser de cátodo común**. Comprueba el tipo de LED y conecta correctamente el pin de alimentación y tierra.

---

## **El Buzzer No Suena o Suena Distorsionado**
### **Posible fallo:**
- No se escucha ningún sonido o el sonido es extraño.

### **Solución:**
- **Verificar la polaridad del buzzer**: Un buzzer activo tiene un **polo positivo (+) y un polo negativo (-)**. Si está conectado al revés, no funcionará.
- **Comprobar la frecuencia del sonido**: En el código, revisa que la frecuencia generada para el buzzer sea correcta. Valores muy altos pueden hacer que no suene correctamente.
- **Asegurar la alimentación adecuada**: Si el buzzer no recibe suficiente corriente, el sonido puede ser débil o distorsionado.

---

### **Consejo Final**
Antes de realizar pruebas, **revisa todas las conexiones**, **verifica el montaje mecánico** y **asegúrate de que la alimentación sea suficiente**. Con estas precauciones, reducirás la posibilidad de errores y mejorarás el rendimiento del brazo robótico.
