//
// Created by Carlos Maceira Garcia Coni on 08/11/2019.
//

#ifndef COMP_DISTRIBUIDA_CALCULOJACOBI_H
#define COMP_DISTRIBUIDA_CALCULOJACOBI_H

#include "persistencia.h"
#include <stack>
#include <iostream>
#include <cmath>


void calcular_fila(std::vector<Dato> &, std::vector<Solucion> &);

void insertar_nueva_semilla(std::vector<Dato> &, std::vector<Solucion> &);

bool compararDatos(Dato, Dato);

bool satisface(std::vector<Solucion> &, std::vector<Solucion> &);

#endif //COMP_DISTRIBUIDA_CALCULOJACOBI_H
