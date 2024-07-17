#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial); // Esperar a que el puerto serial esté listo
  Serial.println("\nEscaneando I2C...");
  scanI2C();
}

void loop() {
  // No hacemos nada en el loop
}

void scanI2C() {
  byte error, address;
  int nDevices = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo encontrado en dirección I2C 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
    delay(100); // Pequeña pausa entre escaneos
  }

  if (nDevices == 0)
    Serial.println("No se encontraron dispositivos I2C.");
  else
    Serial.println("Escaneo I2C completado.");
}


