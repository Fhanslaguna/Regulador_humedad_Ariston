//Meter un contador que incremente mi variable cada vez que el temporal sume 100000; Esto lo hace independiente al resto de cosas

//Incluyo todas las librerias necesarias
#include <Arduino.h>
#include <IRremote.h>
#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

IRsend irsend(3);  // Pin donde está el LED emisor
#define DHTPIN 2    // Pin al que se conecta el sensor de temperatura y humedad
#define DHTTYPE DHT22 //Defino el sensor de humedad y temperatura que estoy usando
DHT dht(DHTPIN, DHTTYPE); //Declaro el sensor


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET    -1 // Reset de la OLED que con -1 es el mismo que el del Arduino
#define SCREEN_ADDRESS 0x3C // Replace with 0x3D if necessary ???
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaro la pantalla

// Reemplaza `rawData` con los valores capturados
unsigned int Encendido[] = {4388, 4400, 528, 1624, 528, 548, 528, 1624, 528, 1620, 532, 544, 532, 544, 532, 1620, 528, 548, 528, 544, 532, 1620, 532, 544, 532, 544, 532, 1620, 532, 1620, 528, 548, 528, 1624, 528, 544, 532, 544, 532, 544, 532, 1620, 532, 1620, 528, 1624, 528, 1620, 532, 1620, 532, 1620, 528, 1624, 528, 1624, 528, 548, 528, 544, 532, 544, 532, 544, 532, 544, 532, 544, 532, 1620, 528, 548, 528, 548, 528, 544, 532, 1620, 532, 544, 532, 544, 532, 1620, 528, 548, 532, 1620, 532, 1620, 528, 1620, 532, 544, 532, 1620, 532, 1620, 528, 5216, 4388, 4400, 532, 1620, 532, 544, 532, 1620, 532, 1620, 532, 540, 532, 544, 532, 1620, 532, 544, 528, 548, 528, 1624, 528, 548, 528, 544, 528, 1624, 528, 1624, 528, 548, 528, 1628, 520, 552, 524, 552, 524, 552, 524, 1648, 500, 1652, 500, 1652, 500, 1652, 496, 1656, 496, 1656, 468, 1684, 468, 1684, 476, 600, 468, 608, 492, 584, 492, 584, 488, 612, 464, 608, 468, 1684, 468, 608, 468, 608, 468, 608, 468, 1684, 468, 608, 452, 624, 444, 1708, 464, 612, 464, 1688, 456, 1696, 440, 1736, 416, 660, 416, 1732, 416, 1736, 416};
unsigned int Apagado[] = {4388, 4404, 528, 1620, 532, 544, 532, 1620, 532, 1620, 528, 548, 528, 544, 532, 1624, 528, 544, 532, 544, 532, 1620, 532, 544, 528, 548, 528, 1624, 528, 1620, 532, 544, 532, 1620, 532, 544, 532, 1620, 528, 1624, 528, 1620, 536, 1616, 532, 544, 532, 1620, 532, 1620, 528, 1620, 532, 544, 532, 544, 532, 544, 528, 548, 528, 1624, 528, 548, 528, 548, 528, 1620, 532, 1620, 532, 1620, 532, 544, 532, 544, 532, 544, 532, 544, 528, 544, 532, 544, 532, 544, 532, 544, 528, 1624, 528, 1624, 528, 1624, 524, 1624, 528, 1624, 528, 5220, 4380, 4428, 504, 1648, 500, 576, 500, 1652, 500, 1652, 500, 576, 496, 580, 496, 1656, 468, 608, 492, 584, 484, 1668, 492, 584, 492, 584, 488, 1684, 452, 1700, 468, 584, 492, 1688, 464, 584, 492, 1684, 452, 1700, 464, 1684, 468, 1684, 468, 608, 468, 1684, 468, 1684, 468, 1684, 464, 612, 464, 608, 468, 608, 468, 608, 448, 1704, 468, 608, 468, 608, 464, 1688, 464, 1688, 440, 1712, 464, 608, 444, 636, 440, 632, 444, 632, 444, 656, 420, 656, 416, 660, 416, 660, 416, 1736, 416, 1736, 416, 1736, 416, 1736, 416, 1732, 416};
unsigned int Silencio[] = {4388, 4400, 532, 1620, 532, 544, 532, 1616, 532, 1620, 532, 544, 532, 1620, 528, 548, 532, 1620, 528, 548, 528, 1624, 528, 544, 532, 544, 532, 1620, 532, 544, 532, 1620, 528, 548, 528, 1620, 532, 1620, 532, 1620, 532, 1620, 528, 548, 528, 1620, 532, 544, 532, 1620, 532, 544, 532, 544, 532, 544, 532, 544, 528, 1620, 532, 544, 532, 1620, 532, 544, 532, 1620, 532, 544, 528, 1624, 528, 1620, 532, 544, 532, 1620, 532, 1620, 528, 548, 528, 548, 528, 1620, 532, 544, 532, 544, 532, 1620, 532, 544, 528, 548, 528, 1624, 528, 5216, 4388, 4400, 532, 1620, 528, 544, 532, 1624, 528, 1620, 532, 544, 528, 1624, 528, 548, 528, 1624, 528, 548, 528, 1620, 532, 544, 532, 544, 532, 1620, 532, 544, 532, 1616, 532, 544, 532, 1620, 532, 1620, 528, 1624, 528, 1624, 528, 548, 524, 1628, 524, 548, 528, 1628, 524, 548, 524, 552, 524, 552, 524, 552, 524, 1648, 504, 552, 520, 1652, 500, 576, 500, 1652, 500, 576, 500, 1652, 496, 1656, 492, 584, 468, 1680, 472, 1680, 496, 584, 492, 580, 492, 1684, 468, 584, 492, 584, 492, 1684, 460, 592, 488, 588, 492, 1680, 468};
unsigned int SubirT[] = {4384, 4400, 532, 1624, 528, 544, 532, 1620, 532, 1620, 532, 544, 532, 544, 528, 1624, 528, 544, 532, 544, 532, 1620, 532, 544, 532, 544, 532, 1620, 528, 1624, 528, 544, 532, 1620, 532, 544, 532, 544, 528, 548, 528, 1620, 532, 1620, 532, 1620, 532, 1620, 528, 1624, 528, 1620, 532, 1620, 532, 1620, 532, 544, 528, 548, 528, 544, 532, 544, 532, 544, 532, 544, 532, 1620, 532, 544, 532, 544, 528, 548, 528, 1624, 528, 544, 532, 544, 532, 1620, 532, 544, 532, 1620, 528, 1624, 528, 1620, 532, 544, 532, 1620, 532, 1620, 528, 5216, 4388, 4404, 528, 1620, 528, 544, 532, 1620, 532, 1620, 532, 544, 532, 544, 528, 1624, 528, 548, 528, 548, 528, 1620, 532, 544, 532, 544, 532, 1620, 532, 1620, 532, 544, 532, 1616, 532, 544, 532, 544, 532, 544, 532, 1620, 528, 1624, 528, 1624, 528, 1620, 528, 1624, 528, 1624, 528, 1624, 524, 1628, 524, 548, 528, 548, 528, 548, 524, 552, 524, 552, 524, 552, 524, 1648, 500, 576, 500, 576, 500, 576, 500, 1652, 500, 576, 496, 580, 472, 1680, 468, 608, 472, 1680, 492, 1660, 492, 1684, 468, 584, 468, 1704, 468, 1684, 468};
unsigned int BajarT[] = {4388, 4404, 528, 1620, 532, 544, 532, 1620, 532, 1620, 528, 548, 528, 544, 532, 1624, 528, 544, 532, 544, 532, 1620, 532, 544, 528, 544, 532, 1624, 528, 1620, 532, 544, 532, 1620, 532, 544, 528, 552, 524, 548, 528, 1624, 528, 1620, 532, 1620, 528, 1624, 504, 1648, 504, 1644, 508, 1644, 508, 1644, 508, 596, 504, 568, 508, 568, 508, 544, 532, 544, 532, 540, 536, 1616, 560, 516, 536, 1616, 560, 516, 532, 1616, 536, 540, 532, 544, 532, 1620, 532, 544, 528, 1624, 528, 548, 528, 1624, 528, 544, 528, 1624, 528, 1624, 528, 5220, 4380, 4428, 500, 1652, 500, 576, 500, 1652, 496, 1652, 500, 580, 496, 576, 496, 1656, 472, 604, 472, 608, 492, 1660, 468, 604, 492, 584, 492, 1684, 468, 1684, 464, 612, 468, 1680, 468, 608, 468, 608, 468, 608, 468, 1684, 468, 1684, 468, 1684, 464, 1688, 464, 1684, 468, 1684, 468, 1684, 464, 1688, 440, 636, 464, 612, 444, 632, 440, 636, 440, 632, 444, 660, 416, 1732, 416, 660, 416, 1736, 416, 660, 416, 1740, 412, 660, 416, 660, 416, 1736, 416, 656, 420, 1760, 388, 688, 388, 1760, 392, 684, 392, 1764, 384, 1792, 360};

//RGB con anodo comun (comun a +5V)
int led_r = 5;
int led_g = 6;
int led_b = 7;

int estado = 0; // Etapas
int ant = 0; // Antiguo valor del pulsador
int act = 1; // Valor actual del pulsador
int actuando;
int pulsador = 4; // Pulsador pulsado
int encendido = 0; // Si esta funcionando la regulacion de humedad
float Set_humedad_alta = 68;
float Set_humedad_baja = 58;
unsigned long tiempo0 = 0;
unsigned long t_fin_etapa = 2000;
float humedad;
unsigned long t_funcionamiento0 = 0.00;
unsigned long t_funcionamiento_temp = 0.00;
unsigned long t_funcionamiento = 0.00;
bool yaApagado = false;
unsigned long reloj_apagado0;
unsigned long reloj_apagado;
unsigned long reloj_todo_apagado0;

void setup() {
  //Serial.begin(9600); // Inicio el serial. Estará comentado si no es necesario
  pinMode (pulsador,INPUT_PULLUP); //Declaro la entrada del pulsador
  pinMode (led_r,OUTPUT);
  pinMode (led_g,OUTPUT);
  pinMode (led_b,OUTPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { //Inicializo el display
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  dht.begin(); //Inicializo el sensor de humedad y temperatura
  
  display.clearDisplay(); //Limpio el display
}

void loop() {
 

  if (act == 0){
    if ((millis() - reloj_todo_apagado0) > 5000){
      estado = 8;
    }
  }

  act = digitalRead (pulsador); // Leo el pulsador
  if (act == 0 && ant == 1){
    actuando = !actuando;
  }
  ant = act;
  humedad = dht.readHumidity(); // Leo la humedad
  int humedad_alta = Set_humedad_alta;
  int humedad_baja = Set_humedad_baja;

  //Transicion 4
  if (estado >= 1 && estado <= 8){
    if (actuando == 0 && estado !=0){
      estado =0;
    }
  }

  switch (estado){
    
    case 0: //Etapa 0
        display.ssd1306_command(SSD1306_DISPLAYON);
        if (!yaApagado) { // Solo envía la señal si aún no se ha enviado
        digitalWrite(led_b, 1);
        digitalWrite(led_g, 1);
        analogWrite(led_r, 253);
        irsend.sendRaw(Apagado, sizeof(Apagado) / sizeof(Apagado[0]), 38);
        yaApagado = true; // Marca como enviado
        }
        estado = 1; // Transición al siguiente estado
         reloj_todo_apagado0 = millis();
        break;

    case 1: //Transición 0
        if (actuando == 1) {
        yaApagado = false; // Resetea la bandera cuando se activa
        estado = 2; 
        break;      
        }
        break;

    case 2://Etapa 1
        reloj_apagado0 = millis();
        digitalWrite(led_r,1);
        digitalWrite(led_b,1);
        analogWrite(led_g,253);
        estado = 3;
        break;
    
    case 3://Transicion 1
        /*
        if ((millis() - reloj_apagado0) > 3600000){// Temporizador para bajar los setpoints si ha pasado un tiempo parado el aire y la humedad es alta
          if (Set_humedad_baja > 56){
          Set_humedad_alta = Set_humedad_alta - 1;
          Set_humedad_baja = Set_humedad_baja - 1;
          reloj_apagado0 = millis();
          }
        }
        */
        if (humedad > Set_humedad_alta){
        estado =4;
        break;
        }
        break;
    
    case 4: //Etapa 2:
        digitalWrite(led_r,1);
        digitalWrite(led_g,1);
        analogWrite(led_b,253);
        irsend.sendRaw(Encendido, sizeof(Encendido) / sizeof(Encendido[0]), 38);
        tiempo0 = millis(); //Pongo a cero el contador
        t_funcionamiento0 = millis(); //Pongo a 0 el contador de tiempo de funcionamiento
        estado = 5;
        break;
      
    case 5: //Transicion 2
        if ((millis() - tiempo0) > t_fin_etapa){
          estado = 6;
          break;
        }
        break;
    case 6: //Etapa 3
          reloj_apagado0 = millis();
          irsend.sendRaw(Silencio, sizeof(Silencio) / sizeof(Silencio[0]), 38);
          estado = 7;
          break;
        
    case 7: // Transicion 3  
          /*
          if ((millis() - reloj_apagado0) > 900000){// Temporizador para subir los setpoints si ha pasado un tiempo funcionando el aire
            if (Set_humedad_alta < 71){
            Set_humedad_alta = Set_humedad_alta + 1;
            Set_humedad_baja = Set_humedad_baja + 1;
            reloj_apagado0 = millis();
              }
          }
          */
          t_funcionamiento_temp = millis() - t_funcionamiento0; //Cuento el tiempo que está en la etapa 7
          if (t_funcionamiento_temp > 60000){ // cada vez que se cumple un minuto se lo sumo al tiempo de funcionamiento
            t_funcionamiento ++;
            t_funcionamiento0 = millis();//Reinicio el temporizador
          }
          if (humedad < Set_humedad_baja){ //etapa 4
            irsend.sendRaw(Apagado, sizeof(Apagado) / sizeof(Apagado[0]), 38);
            estado = 2;
            break;
          }
          break;
    case 8: //Todo apagado
          digitalWrite(led_r,1);
          digitalWrite(led_g,1);
          digitalWrite(led_b,1);
          display.ssd1306_command(SSD1306_DISPLAYOFF);
          t_funcionamiento = 0;
          break; 

   }
  
  if(estado != 8){
  display.clearDisplay(); // Limpio el display
  display.setTextSize(2);      // Escala de 1:1
  display.setTextColor(SSD1306_WHITE); // Color del texto el blanco
  display.setCursor(20,5);     // Posicion del cursor
  display.print(humedad); //Escribo la humedad
  display.println(" %"); 
  display.setCursor(20,30);
  display.print(dht.readTemperature());
  display.println(" g");
  display.setCursor(5,50);
  display.print(t_funcionamiento);
  display.print(" m ");
  display.print(humedad_alta);
  display.print("/");
  display.println(humedad_baja);
  display.display();
}
  //Si todo va bien esto deberia estar comentado
  /*
    Serial.print("Estado: ");
    Serial.println (estado);
    Serial.print("actuando: ");
    Serial.println (actuando);
    Serial.print ("millis: ");
    Serial.println (millis());
    Serial.print ("Tiempo0: ");
    Serial.println(t_funcionamiento0);
    Serial.print("Tiempo_encendido temporal: ");
    Serial.println(t_funcionamiento_temp);
    Serial.print("T_funcionamiento: ");
    Serial.println(t_funcionamiento);
    Serial.print("pulsador: ");
    Serial.println(act);
    Serial.print("humedad: ");
    Serial.println(humedad);
    delay (500);
    */
}