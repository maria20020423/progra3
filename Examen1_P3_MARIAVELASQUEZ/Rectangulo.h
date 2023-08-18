#pragma once
class Rectangulo {
private:
    int* numeros;
    int longitud;
    int base;
    int altura;
    int areaMax;

public:
    Rectangulo();
    ~Rectangulo();

    void ingresarNumeros();
    int obtenerAreaMaxima();

    int getBase() const;
    int getAltura() const;
    int getAreaMaxima() const;
};
