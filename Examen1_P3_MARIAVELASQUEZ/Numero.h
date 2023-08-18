#pragma once
#include <vector>
#include <string>

class Numero {
private:
    int num;
    char letras[5];

public:
    Numero(int n);

    void asignarLetras(int digito);

    char* getLetras();

    static std::vector<std::string> obtenerSecuencias(std::vector<Numero*> numeros, int index = 0, std::string secuenciaActual = "");
};
