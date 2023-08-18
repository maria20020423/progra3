#include "Rectangulo.h"
#include <iostream>
#include <vector>
using namespace std;

Rectangulo::Rectangulo() : numeros(nullptr), longitud(0), base(0), altura(0), areaMax(0) {}

Rectangulo::~Rectangulo() {
    delete[] numeros;
}

void Rectangulo::ingresarNumeros() {
    std::cout << "Ingrese la longitud del arreglo: ";
    std::cin >> longitud;

    numeros = new int[longitud];

    for (int i = 0; i < longitud; i++) {
        std::cout << "Ingrese el numero " << (i + 1) << ": ";
        std::cin >> numeros[i];
    }
}

int Rectangulo::obtenerAreaMaxima() {
    areaMax = 0;

    for (int left = 0, right = longitud - 1; left < right;) {
        int h = min(numeros[left], numeros[right]);
        int w = right - left;
        int area = h * w;

        if (area > areaMax) {
            base = w;
            altura = h;
            areaMax = area;
        }

        if (numeros[left] < numeros[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    return areaMax;
}

int Rectangulo::getBase() const {
    return base;
}

int Rectangulo::getAltura() const {
    return altura;
}

int Rectangulo::getAreaMaxima() const {
    return areaMax;
}