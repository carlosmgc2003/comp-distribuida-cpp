//
// Created by Carlos Maceira Garcia Coni on 06/11/2019.
//

#ifndef COMP_DISTRIBUIDA_LECTURADATOS_H
#include <vector>
#include <sqlite3.h>
typedef struct dato{
    int id;
    int fila;
    int pos;
    double coeficiente;
    double resultado;
    double semilla;
    double calcular() {return coeficiente * semilla;}
    bool operator==(double val) {return fila == val;}
} dato;

int lecturaDatos(std::vector <dato> &ORIGEN);
#define COMP_DISTRIBUIDA_LECTURADATOS_H

#endif //COMP_DISTRIBUIDA_LECTURADATOS_H
