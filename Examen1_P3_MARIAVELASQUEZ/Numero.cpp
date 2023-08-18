#include "Numero.h"
#include <cstring>

Numero::Numero(int n) : num(n) {
    asignarLetras(n);
}

void Numero::asignarLetras(int digito) {
    switch (digito) {
    case 2: strcpy_s(letras, "abc"); break;
    case 3: strcpy_s(letras, "def"); break;
    case 4: strcpy_s(letras, "ghi"); break;
    case 5: strcpy_s(letras, "jkl"); break;
    case 6: strcpy_s(letras, "mno"); break;
    case 7: strcpy_s(letras, "pqrs"); break;
    case 8: strcpy_s(letras, "tuv"); break;
    case 9: strcpy_s(letras, "wxyz"); break;
    default: letras[0] = '\0';
    }
}

char* Numero::getLetras() {
    return letras;
}

std::vector<std::string> Numero::obtenerSecuencias(std::vector<Numero*> numeros, int index, std::string secuenciaActual) {
    std::vector<std::string> secuencias;

    if (index == numeros.size()) {
        secuencias.push_back(secuenciaActual);
        return secuencias;
    }

    char* letras = numeros[index]->getLetras();
    for (int i = 0; letras[i] != '\0'; i++) {
        std::vector<std::string> subsecuencias = obtenerSecuencias(numeros, index + 1, secuenciaActual + letras[i]);
        secuencias.insert(secuencias.end(), subsecuencias.begin(), subsecuencias.end());
    }

    return secuencias;
}
