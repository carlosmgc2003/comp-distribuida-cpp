//
// Created by Carlos Maceira Garcia Coni on 08/11/2019.
//

#include "calculoJacobi.h"
void calcular_fila(std::vector<dato> &datos, std::vector<double> &b) {
    std::stack<dato> pila_datos;
    auto it = datos.begin();
    while(it != datos.end()) {
        if(it->pos == it-> fila) {
            //std::cout << "Elemento de la diagonal\n";
            it++;
            if(it == datos.end()){
                double acumulador = 0.0;
                double resultado_fila = pila_datos.top().resultado;
                while(!pila_datos.empty()){
                    acumulador += pila_datos.top().calcular();
                    pila_datos.pop();
                    //std::cout << "Saco Elemento\n";
                }
                b.push_back(resultado_fila - acumulador);
                //std::cout << "Escribo el resultado en el vector\n";
            }
        }
        else if(pila_datos.empty() || pila_datos.top().fila == it->fila ){
            //std::cout << "Meto Elemento\n";
            pila_datos.push(*it);
            it++;
        }
        else {
            double acumulador = 0.0;
            double resultado_fila = pila_datos.top().resultado;
            while(!pila_datos.empty()){
                acumulador += pila_datos.top().calcular();
                pila_datos.pop();
                //std::cout << "Saco Elemento\n";
            }
            b.push_back(resultado_fila - acumulador);
            //std::cout << "Escribo el resultado en el vector\n";
        }
    }
    //std::cout << b.size() << "\n";
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