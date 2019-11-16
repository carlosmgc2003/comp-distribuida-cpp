//
// Created by Carlos Maceira Garcia Coni on 08/11/2019.
//

#include "calculoJacobi.h"
void calcular_fila(std::vector<dato> &datos, std::vector<double> &b) {
    std::stack<dato> pila_datos;
    auto it = datos.begin();
    while(it != datos.end()) {
        if(it->pos == it-> fila) {
            it++;
            if(it == datos.end()){
                double acumulador = 0.0;
                double resultado_fila = pila_datos.top().resultado;
                while(!pila_datos.empty()){
                    acumulador += pila_datos.top().calcular();
                    pila_datos.pop();
                }
                b.push_back(resultado_fila - acumulador);
            }
        }
        else if(pila_datos.empty() || pila_datos.top().fila == it->fila ){
            pila_datos.push(*it);
            it++;
        }
        else {
            double acumulador = 0.0;
            double resultado_fila = pila_datos.top().resultado;
            while(!pila_datos.empty()){
                acumulador += pila_datos.top().calcular();
                pila_datos.pop();
            }
            b.push_back(resultado_fila - acumulador);
        }
    }
}
bool compararDatos(const dato a, const dato b){
    return a.fila < b.fila;
}

void insertar_nueva_semilla(std::vector<dato> &datos, std::vector<double> &resultados){
    for (auto &item : datos) {
        item.semilla = resultados[item.pos];
    }
}

bool satisface(std::vector<double> & anterior, std::vector<double> & actual) {
//Devuelve true si la norma euclidea entre el vector solucion n-1 y el n es menor a error
    double error = std::pow(10,-14);
    double norma = 0.0;
    auto ant = anterior.begin();
    auto act = actual.begin();
    for(;ant != anterior.end(); ant ++){
        norma += std::pow(*ant - *act,2);
        act ++;
    }
    double raiz_norma = std::sqrt(norma);
    std::cout << raiz_norma << " <= " << error << "\n";
    return raiz_norma <= error;
}