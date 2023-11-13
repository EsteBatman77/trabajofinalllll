# Acceleration Measurement System

Este proyecto implementa un sistema de medición de aceleración utilizando la plataforma mbed y varios componentes periféricos. El código está escrito en C++ y utiliza la biblioteca mbed para facilitar el desarrollo en placas compatibles.

## Descripción General

El sistema utiliza dos fotoresistencias (sensores de luz) conectadas a pines analógicos para medir cambios en la intensidad luminosa. La primera fotoresistencia, `fotoResistenciaInicial`, inicia la medición cuando su lectura cae por debajo de un umbral predefinido. La segunda fotoresistencia, `fotoResistenciaFinal`, detiene la medición cuando su lectura cae por debajo del mismo umbral.

Cuando se activa la medición, se inicia un temporizador (`timer`) para calcular el tiempo transcurrido entre las dos mediciones. Utilizando la altura predefinida (`height`), el sistema calcula la aceleración en función del tiempo y muestra el resultado en una pantalla LCD de 16x2 caracteres.

## Componentes Utilizados

- **Placa mbed**: La plataforma mbed es la base del sistema y proporciona la interfaz para interactuar con los periféricos.

- **TextLCD**: Se utiliza para mostrar información en una pantalla LCD de 16x2 caracteres.

- **UnbufferedSerial**: Configurado para la comunicación serial para la salida de información y depuración.

- **AnalogIn**: Se utilizan dos pines analógicos para leer las fotoresistencias.

- **DigitalOut**: Controla un LED para indicar el estado del sistema.

- **Timer**: Mide el tiempo transcurrido entre las dos mediciones de fotoresistencia.

## Funcionamiento

1. El sistema comienza con el LED encendido y muestra un mensaje de inicio por medio de la comunicación serial.

2. Cuando la lectura de `fotoResistenciaInicial` cae por debajo de `0.3f`, se inicia la medición. El LED se apaga, y el temporizador se reinicia y comienza a contar el tiempo.

3. La medición se detiene cuando la lectura de `fotoResistenciaFinal` cae por debajo de `0.3f`. El LED se enciende nuevamente, y se muestra en la pantalla LCD el tiempo transcurrido y la aceleración calculada.

4. El sistema espera a que se vuelva a cumplir la condición de inicio para realizar una nueva medición.

## Variables Importantes

- `startFlag` y `endFlag`: Banderas que controlan el inicio y fin de la medición.
- `timer`: Temporizador utilizado para medir el tiempo transcurrido.
- `mostrar`: Indica que información calculada que se debe mostrar en la pantalla LCD

## Observaciones

- Ajuste los umbrales según las características de sus fotoresistencias y las condiciones ambientales.
- El sistema asume una relación lineal entre la intensidad luminosa y el tiempo de caída.

Este proyecto es parte de un enfoque académico para comprender la interacción entre hardware y software en sistemas embebidos y puede ser ampliado para incluir más funcionalidades y adaptarse a aplicaciones específicas.
