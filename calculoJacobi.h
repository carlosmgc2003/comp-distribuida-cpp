//
// Created by Carlos Maceira Garcia Coni on 08/11/2019.
//

#ifndef COMP_DISTRIBUIDA_CALCULOJACOBI_H
#define COMP_DISTRIBUIDA_CALCULOJACOBI_H
#include "lecturaDatos.h"
#include <stack>
#include <iostream>
#include <cmath>



void calcular_fila(std::vector<dato> &, std::vector<double> &);
void insertar_nueva_semilla(std::vector<dato> &, std::vector<double> &);
bool compararDatos(dato, dato);
bool satisface(std::vector<double> &, std::vector<double> &);
#endif //COMP_DISTRIBUIDA_CALCULOJACOBI_H
