#include "mbed.h"
#include "TextLCD.h"
#include <iostream>
using namespace std::chrono;
UnbufferedSerial serial(USBTX, USBRX, 9600);

// Initialize a pins to perform analog input and digital output fucntions
TextLCD lcd (D2, D3, D4, D5, D6, D7, TextLCD::LCD16x2);
AnalogIn   fotoResistenciaInicial(A0);
AnalogIn   fotoResistenciaFinal(A1);
DigitalOut led(LED1);
Timer timer;

int main(void){
    led = 1;
    cout << "Inicio" <<endl;
    bool mostrar, endFlag = false, startFlag = true;
    float speed = 0, aceleration = 0;
    const float height = 0.14; //metros
    while(true){
        // cout << "valor:" << fotoResistenciaInicial.read() << endl;
        if(fotoResistenciaInicial.read() < 0.3f && startFlag){
            cout << "Fotoresistencia inicial" << endl;
            led = 0;
            timer.reset();
            timer.start();
            endFlag = true;
            startFlag = false;
        }else if(endFlag && fotoResistenciaFinal.read() < 0.3f){
            cout << "Fotoresistencia final" << endl;
            led = 1;
            mostrar = true;
            endFlag = false;
            startFlag = true;
            timer.stop();
        }

        if (mostrar) {
            float time= duration_cast<milliseconds>(timer.elapsed_time()).count();
            time /= 1000;
            printf("El recorrido tomó %llu .segundos\n", time);
            aceleration = 2*height/(time*time);
            cout << "Aceleration: " << aceleration << endl;
            lcd.cls();
            lcd.locate(0, 0);
            lcd.printf("La aceleración es: ");
            lcd.locate(0, 1);
            lcd.printf("%llu .m/s", aceleration);
            mostrar = false;
        }
    
    }
}
