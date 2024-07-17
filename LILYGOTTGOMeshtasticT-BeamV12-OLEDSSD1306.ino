#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Dirección I2C de la pantalla OLED (ajusta según lo detectado)
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial); // Esperar a que el puerto serial esté listo
  
  // Inicializar la pantalla OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("No se pudo inicializar la pantalla OLED"));
    for(;;);
  }

  Serial.println("Pantalla OLED inicializada");

  // Limpiar la pantalla
  display.clearDisplay();

  // Configurar el tamaño del texto y color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Escribir en la pantalla
  display.setCursor(0, 0);
  display.println("Hola Mundo!");

  // Mostrar en la pantalla
  display.display();
}

void loop() {
  // No hay acción en el loop
}
