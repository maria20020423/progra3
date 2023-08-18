// LAB5_EXAMEN1_MARIAVELASQEUZ.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Numero.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

void mostrarMenu() {
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1. Ejercicio 1 - Secuencias posibles" << endl;
        cout << "2. Ejercicio 2 - Area Maxima" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            char cadena[3];
            cout << "Ingrese la cadena de digitos: ";
            cin >> cadena;

            vector<Numero*> numeros;
            for (int i = 0; i < 2; i++) {
                int digito = cadena[i] - '0';
                if (digito >= 2 && digito <= 9) {
                    Numero* num = new Numero(digito);
                    numeros.push_back(num);
                }
                else {
                    cerr << "Error: Los digitos deben estar entre 2 y 9." << endl;
                    for (Numero* num : numeros) {
                        delete num;
                    }
                    numeros.clear();
                    break;
                }
            }

            if (!numeros.empty()) {
                vector<string> secuencias = Numero::obtenerSecuencias(numeros);

                cout << "Secuencias posibles:" << endl;
                for (const string& secuencia : secuencias) {
                    cout << secuencia << " ";
                }
                cout << endl;

                for (Numero* num : numeros) {
                    delete num;
                }
            }
            break;
        }
        case 2: {
            Rectangulo rectangulo;
            rectangulo.ingresarNumeros();

            int areaMaxima = rectangulo.obtenerAreaMaxima();
            if (areaMaxima == 0) {
                break;
            }

            std::cout << "Base: " << rectangulo.getBase() << std::endl;
            std::cout << "Altura: " << rectangulo.getAltura() << std::endl;
            std::cout << "Area maxima: " << rectangulo.getAreaMaxima() << std::endl;

            break;
        }
        case 3: {
            cout << "Saliendo del programa." << endl;
            break;
        }
        default: {
            cout << "Opcion invalida. Intente nuevamente." << endl;
            break;
        }
        }
    } while (opcion != 3);
}

int main() {
    mostrarMenu();
    return 0;
}
