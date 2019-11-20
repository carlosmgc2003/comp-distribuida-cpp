#include <fstream>
#include <algorithm>
#include "calculoJacobi.h"
#include "persistencia.h"



int main(int argc, char *argv[]) {
    std::vector<Dato> DATOS;
    lecturaDatos(DATOS);
    //Averiguamos primer y ultima fila
    auto resultado = std::minmax_element(DATOS.begin(), DATOS.end(), compararDatos);
    auto primer_fila = resultado.first->fila;
    auto ultima_fila = resultado.second->fila;
    auto cantidad_fila = ultima_fila - primer_fila + 1;
    std::vector<Solucion> RESULTADO_ACT;
    std::vector<Solucion> RESULTADO_ANT;
    RESULTADO_ACT.reserve(cantidad_fila);
    RESULTADO_ANT.reserve(cantidad_fila);
    int count = 0;
    do {
        RESULTADO_ACT.clear();
        RESULTADO_ANT.clear();
        calcular_fila(DATOS, RESULTADO_ANT);
        insertar_nueva_semilla(DATOS, RESULTADO_ANT);
        calcular_fila(DATOS, RESULTADO_ACT);
        //insertar_nueva_semilla(DATOS, RESULTADO_ACT);
    } while (!satisface(RESULTADO_ANT, RESULTADO_ACT));
    std::ofstream archivo;
    archivo.open("resultado.txt");
    archivo << "Resultados: " << "\n";
    if (archivo) {
        for (const auto &item : RESULTADO_ACT) {
            archivo << item.resultado << "\n";
        }
        archivo.close();
    } else {
        std::cout << "No se pudo crear el archivo!\n";
        return -1;
    }
    escrituraDatos(RESULTADO_ACT);
    return 0;
}
