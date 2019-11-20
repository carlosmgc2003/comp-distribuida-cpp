//
// Created by Carlos Maceira Garcia Coni on 08/11/2019.
//

#include "calculoJacobi.h"

void calcular_fila(std::vector<Dato> &datos, std::vector<Solucion> &b) {
    std::stack<Dato> pila_datos;
    auto it = datos.begin();
    while (it != datos.end()) {
        if (it->pos == it->fila) {
            it++;
        } else if (pila_datos.empty() || pila_datos.top().fila == it->fila) {
            pila_datos.push(*it);
            it++;
        } else {
            Solucion nueva;
            double acumulador = 0.0;
            double resultado_fila = pila_datos.top().resultado;
            nueva.nro_variable = pila_datos.top().fila;
            while (!pila_datos.empty()) {
                acumulador += pila_datos.top().calcular();
                pila_datos.pop();
            }
            nueva.resultado = resultado_fila - acumulador;
            b.push_back(nueva);
        }
    }
    if (it == datos.end()) {
        Solucion nueva;
        double acumulador = 0.0;
        double resultado_fila = pila_datos.top().resultado;
        nueva.nro_variable = pila_datos.top().fila;
        while (!pila_datos.empty()) {
            acumulador += pila_datos.top().calcular();
            pila_datos.pop();
        }
        nueva.resultado = resultado_fila - acumulador;
        b.push_back(nueva);
    }
}

bool compararDatos(const Dato a, const Dato b) {
    return a.fila < b.fila;
}

void insertar_nueva_semilla(std::vector<Dato> &datos, std::vector<Solucion> &resultados) {
    for (auto &item : datos) {
        item.semilla = resultados[item.pos].resultado;
    }
}

bool satisface(std::vector<Solucion> &anterior, std::vector<Solucion> &actual) {
//Devuelve true si la norma euclidea entre el vector solucion n-1 y el n es menor a error
    double error = std::pow(10, -14);
    double norma = 0.0;
    auto ant = anterior.begin();
    auto act = actual.begin();
    for (; ant != anterior.end(); ant++) {
        norma += std::pow(ant->resultado - act->resultado, 2);
        act++;
    }
    double raiz_norma = std::sqrt(norma);
    return raiz_norma <= error;
}