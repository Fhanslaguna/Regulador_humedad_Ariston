Regulador de humedad Ariston
El modelo de aire acondicionado no viene un regulador automatico de humedad, por o que decidí crear este para controlar
la humedad existente en mi casa

Creado para un Arduino mega, una pantalla oled de 128 x 64, un emisor infrarrojo, un sensor de humeda y temperatura DHT22 y un pulsador

Hay que orientar el infrarrojo para que se vea con el aire a controlar.
El programa se encarga de leer la humedad y la temperatura mostrandola en el display

Al enchufar arduino, el rgb estrá en rojo.
Pulsando el boton externo se pone en verde el RGB indicandonos que la regulación está activa
Si la humedad sube del parametro fijado el dispositivo enviará la orden de encender el aire y seguidamente la orden de ponerlo en silencio. También pondrá el RGB en azul
Cuando pase el tiempo que le programamos al arduino, el dispositivo apagará el aire y pondrá en RGB en verde.
Para apagar la regulacion pulsaremos una vez el boton hasta que el RGB se ponga en rojo.
Si queremos apagar todo el dispositivo, estando el RGB en rojo dejaremos apretado durante cinco segundos el pulsador.

El dispositivo está hecho para controlar un poco la humedad, no para regularla del todo, esto nos llevaría tener el aire acondicionado encendido un 65 % del día, aproximadamente.
