#include <iostream>
#include <fstream>
#include <algorithm>
#include "calculoJacobi.h"


/*
//Dado Ax=B
//El input del programa debe ser de la forma
//calcular N_FILAS [CANT_COEF_FILAS] [B_DE_FILA] [COEF SEMILLA POS]
 */

int main(int argc, char * argv[]) {
    std::vector <dato> DATOS;
    lecturaDatos(DATOS);
    /*
    dato d1 = {1, 0, 0, 1.0, 5.5, 100.0, };
    dato d2 = {2, 0, 1, 0.5, 5.5, 100.0, };
    dato d3 = {3, 1, 0, 0.71428571429, 1.85714285714, 100.0, };
    dato d4 = {4, 1, 1, 1.0, 1.85714285714, 100.0, };
    DATOS.push_back(d1);
    DATOS.push_back(d2);
    DATOS.push_back(d3);
    DATOS.push_back(d4);
     */
    std::cout << DATOS.size() << std::endl;
    //Averiguamos primer y ultima fila
    auto resultado = std::minmax_element(DATOS.begin(),DATOS.end(),compararDatos);
    auto primer_fila = resultado.first->fila;
    auto ultima_fila = resultado.second->fila;
    auto cantidad_fila = ultima_fila - primer_fila + 1;
    std::cout << cantidad_fila << "\n";
    std::vector <double> RESULTADO_ACT;
    std::vector <double> RESULTADO_ANT;
    RESULTADO_ACT.reserve(cantidad_fila);
    RESULTADO_ANT.reserve(cantidad_fila);
    int count = 0;
    do{
        ++ count;
        RESULTADO_ACT.clear();
        RESULTADO_ANT.clear();
        calcular_fila(DATOS, RESULTADO_ANT);
        insertar_nueva_semilla(DATOS, RESULTADO_ANT);
        calcular_fila(DATOS, RESULTADO_ACT);
        //insertar_nueva_semilla(DATOS,RESULTADO_ACT);
        std::cout << "Iteracion: " << count << "\n";
    }while(!satisface(RESULTADO_ANT,RESULTADO_ACT));
    std::cout << "Resultados: " << "\n";
    std::ofstream archivo;
    archivo.open("resultado.txt");
    if(archivo){
        for (const auto &item : RESULTADO_ACT) {
            archivo << item << "\n";
        }
        archivo.close();
    }
    else {
        std::cout << "No se pudo crear el archivo!\n";
        return -1;
    }
    return 0;
}
