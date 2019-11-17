//
// Created by Carlos Maceira Garcia Coni on 06/11/2019.
//

#ifndef COMP_DISTRIBUIDA_PERSISTENCIA_H
#define COMP_DISTRIBUIDA_PERSISTENCIA_H

#include <string>
#include <vector>
#include <sqlite3.h>

typedef struct Dato {
    int id;
    int fila;
    int pos;
    double coeficiente;
    double resultado;
    double semilla;

    double calcular() { return coeficiente * semilla; }

    bool operator==(double val) { return fila == val; }
} Dato;

typedef struct Solucion {
    int nro_variable;
    double resultado;
} Solucion;

int lecturaDatos(std::vector<Dato> &);

int escrituraDatos(std::vector<Solucion> &);

#endif //COMP_DISTRIBUIDA_PERSISTENCIA_H
