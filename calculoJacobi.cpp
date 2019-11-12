//
// Created by Carlos Maceira Garcia Coni on 08/11/2019.
//

#include "calculoJacobi.h"
void calcular_fila(std::vector<dato> &datos, std::vector<double> &b) {
// Sumatoria de todos los resultados de Coef * Semilla, más B
    std::stack<dato> pila_fila;
    double resultado_fila;
    double acum = 0.0;
    for(const auto &elem : datos){
        if(pila_fila.empty() || pila_fila.top().fila == elem.fila) {
            pila_fila.push(elem);
            std::cout << "Metimos: " << elem.fila << "de: " << elem.pos << "\n";
        }
        else{
            resultado_fila = pila_fila.top().resultado;
            while(!pila_fila.empty()){
                acum += pila_fila.top().calcular();
                pila_fila.pop();
            }
            resultado_fila -= acum;
            std::cout << "Vaciamos pila" << "\n";
            b.push_back(resultado_fila);
            pila_fila.push(elem);
            std::cout << "#Metimos: " << elem.fila << "de: " << elem.pos << "\n";
        }
    }
    acum = 0.0;
    resultado_fila = pila_fila.top().resultado;
    while(!pila_fila.empty()){
        acum += pila_fila.top().calcular();
        pila_fila.pop();
    }
    resultado_fila -= acum;
    b.push_back(resultado_fila);
    std::cout << "Vaciamos pila final!" << "\n";
}

bool compararDatos(const dato a, const dato b){
    return a.fila < b.fila;
}

void insertar_nueva_semilla(std::vector<dato> &datos, std::vector<double> &resultados){
    for (auto &item : datos) {
        if(item.pos < resultados.size())
            item.semilla = resultados.at(item.pos);
    }
}

bool satisface(std::vector<double> & anterior, std::vector<double> & actual) {
//Devuelve true si la norma euclidea entre el vector solucion n-1 y el n es menor a error
    double error = std::pow(10,-5);
    double norma = 0.0;
    auto ant = anterior.begin();
    auto act = actual.begin();
    for(;ant != anterior.end(); ant ++){
        norma += std::pow(*ant - *act,2);
        act ++;
    }
    std::cout << std::sqrt(norma) << " <= " << error << "\n";
    return std::sqrt(norma) <= error;
}