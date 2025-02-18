// Definición de pines
const int buttonPins[4] = {1, 2, 3, 4};  // Pines de los botones
const int buzzerPin = 9;                  // Pin del buzzer
const int redPin = 8;                    // Pin para el color rojo
const int greenPin = 7;                  // Pin para el color verde
const int bluePin = 6;                   // Pin para el color azul

// Frecuencias para cada combinación de tonos (9 combinaciones diferentes)
const int sequence[9][2] = {
  {262, 294},   // 1: Combinación 1 (Do y Re)
  {330, 349},   // 2: Combinación 2 (Mi y Fa)
  {392, 440},   // 3: Combinación 3 (Sol y La)
  {494, 523},   // 4: Combinación 4 (Si y Do)
  {587, 659},   // 5: Combinación 5 (Fa y Sol)
  {698, 784},   // 6: Combinación 6 (La y Si)
  {880, 988},   // 7: Combinación 7 (Do alto y Re alto)
  {1047, 1175}, // 8: Combinación 8 (Mi alto y Fa alto)
  {1319, 1397}  // 9: Combinación 9 (Sol alto y La alto)
};

// Colores para cada combinación de tonos (9 combinaciones diferentes)
const int colors[9][3] = {
  {255, 0, 0},    // 1: Rojo
  {0, 255, 0},    // 2: Verde
  {0, 0, 255},    // 3: Azul
  {255, 255, 0},  // 4: Amarillo
  {0, 255, 255},  // 5: Cian
  {255, 0, 255},  // 6: Magenta
  {255, 255, 255},// 7: Blanco
  {127, 0, 0},    // 8: Rojo oscuro
  {0, 127, 0}     // 9: Verde oscuro
};

void setup() {
  // Configuración de pines
  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Botones con resistencias internas
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int binaryNumber = 0;
  bool allButtonsPressed = true;
  bool anyButtonPressed = false;

  // Leer el estado de los botones y formar el número binario
  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      binaryNumber |= (1 << i);
      anyButtonPressed = true;  // Si al menos un botón está pulsado
    } else {
      allButtonsPressed = false;  // Si algún botón no está pulsado
    }
  }

  // Si los 4 botones están pulsados, generar secuencia de tonos
  if (allButtonsPressed) {
    generateSoundSequence();
  } else if (binaryNumber > 0 && binaryNumber <= 9) {
    // Emitir los dos tonos correspondientes a la combinación seleccionada
    tone(buzzerPin, sequence[binaryNumber - 1][0]);
    delay(300);  // Duración del primer tono
    tone(buzzerPin, sequence[binaryNumber - 1][1]);
    setColor(colors[binaryNumber - 1][0], colors[binaryNumber - 1][1], colors[binaryNumber - 1][2]);
  } else if (!anyButtonPressed) {
    // Apagar el sonido y el LED si no hay botones pulsados
    noTone(buzzerPin);
    setColor(0, 0, 0); // LED apagado
  }

  delay(100);
}

// Función para generar una secuencia de sonidos cuando los 4 botones están pulsados
void generateSoundSequence() {
  for (int i = 0; i < 9; i++) {
    tone(buzzerPin, sequence[i][0]);
    delay(300);  // Duración del primer tono
    tone(buzzerPin, sequence[i][1]);
    delay(300);  // Duración del segundo tono
  }
  noTone(buzzerPin);
  setColor(0, 255, 0);  // Cambiar el color del LED (ejemplo: verde cuando todos los botones están pulsados)
}

// Función para controlar el color del LED RGB
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);   // Control del color rojo
  analogWrite(greenPin, green); // Control del color verde
  analogWrite(bluePin, blue);  // Control del color azul
}
