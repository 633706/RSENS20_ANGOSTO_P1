# RSENSE20_ANGOSTO_P1

Estrcutra de proyecto basada en: [ESP-IDF template](https://github.com/espressif/esp-idf-template).
Repositorio para la práctica P1 de redes de sensores.

## Entregable 1 :
Commit b91e12c, Hardware timer interrupt cada 10s para print por puerto serie lectura ADC.
### Montaje
![Entregable1FotoMontaje](./documentation/Entregable1_FotoMontaje.png/)

### Captura Terminal con lectura ADC cada 10 segundos.
![CapturaTerminalCOM](./documentation/Entregable1_TerminalCOM.png/)

[Entregable 1 video demostración](https://vimeo.com/526973582).

## Entregable 2 :
Commit e439851, implementación comandos ADC, ADC(x) y PWM(x).
### Montaje
![Entregable2FotoMontaje](./documentation/Entregable2_FotoMontaje.png/)

### Captura osciloscopio señal PWM.
![CapturaOsciloscopioLED](./documentation/Entregable2_señalPWM.png/)

### Captura terminal con diferentes comandos
![CapturaTerminalCOM](./documentation/Entregable2_TerminalCOM.png/)

[Entregable 2 video demostración](https://vimeo.com/526984683).

## Entregable 3 :
Commit 23d7205, lectura IMU cada 100 ms, trasmiste por puerto serie cada 1 segundo y encide led durante 200ms.
Durante el encendido del LED continúa la lectura de la IMU, debido a un problema con la gestión de ISR por parte de esp32, la comunicación con la IMU es continúa y cada 100 ms es toma el valor. Se itenta usar IRAM_ATTR para asegurar que las funciones de la ISR estén en la IRAM y por lo tanto sean accesibles pero no se consigue.
### Montaje
![FotoMontaje](./documentation/Entregable3_FotoMontaje.png/)

### Captura osciloscopio señal LED.
![CapturaOsciloscopioLED](./documentation/Entregable3_señalLED.png/)

### Captura terminal con la información de acelereación.
![CapturaTerminalCOM](./documentation/Entregable3_TerminalCOM.png/)

[Entregable 3 video demostración](https://vimeo.com/526954389).
---
## Bibliografía:
* [ESP-IDF template](https://github.com/espressif/esp-idf-template).
* [ESP32 developer](https://esp32developer.com/category/programming-in-c-c).
* [Espressif API reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/index.html).
---
David Angosto Latorre, 633706
