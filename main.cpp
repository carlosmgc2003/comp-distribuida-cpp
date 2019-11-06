#include <iostream>
#include <cstdlib>
#include <cmath>
#include "lecturaDatos.h"
#define POS_CANT_FILAS 1
#define POS_CANT_COEFI 2

//Error permitido (Cantidad de decimales a los que aproxima la solucion)
double error = std::pow(10,-5);



/*
//Prototipos de funciones
double calcular_fila(std::vector <tripla> *, double &);
bool satisface_error(std::vector <double> &, std::vector <double> &);
void actualizar_semilla(std::vector <std::vector<tripla> *> &, std::vector<double> &);



//Dado Ax=B
//El input del programa debe ser de la forma
//calcular N_FILAS [CANT_COEF_FILAS] [B_DE_FILA] [COEF SEMILLA POS]
 */

int main(int argc, char * argv[]) {
    std::vector <dato> DATOS;
    lecturaDatos(DATOS);
    std::cout << DATOS.size() << std::endl;
    std::cout << DATOS.size() * sizeof(dato) << std::endl;
    return 0;
}

/*int cant_filas = atoi(argv[POS_CANT_FILAS]);//Primer argumento
std::vector <std::vector<tripla> *> filas;//Contiene coef y semilla
std::vector <int> cant_coef;//cant de coef y semillas por cada fila
std::vector <double> B; //Resultados de cada fila
std::vector <double> resultado1;
std::vector <double> resultado2;

//Parseamos los argumentos cant_coeficientes y B
for (auto i = POS_CANT_COEFI; i < cant_filas; i++){
    int coeficiente = atoi(argv[i]);
    double b_fila = strtod(argv[i + cant_filas],NULL);
    cant_coef.push_back(coeficiente);
    B.push_back(b_fila);
}

//Averiguamos los indices de donde comienza cada fila
std::vector <int> indices_coef;
indices_coef.push_back(2 * cant_filas + POS_CANT_COEFI);
for(auto i = 0; i < cant_filas; i++){
    indices_coef.push_back(indices_coef[i] + cant_coef[i]);
}

//Parseamos los valores de cada fila en la tripla.
for(auto i = 0; i < cant_filas; i ++){
    std::vector <tripla> nueva_fila;
    for(auto aux = indices_coef[i]; aux < aux + cant_coef[i]; aux ++){
        std::unique_ptr<tripla> nueva_tripla(new tripla);
        nueva_tripla->coeficiente = strtod(argv[aux],NULL);
        nueva_tripla->semilla = strtod(argv[aux ++], NULL);
        nueva_tripla->pos = atoi(argv[aux ++]);
        nueva_fila.push_back(* nueva_tripla);
    }
    filas.push_back(&nueva_fila);
}

//Calculo primer iteracion
std::vector <double> resultados_ant;
std::vector <double> resultados_act;
for(auto i = 0; i < cant_filas; i ++){
    resultados_act.push_back(calcular_fila(filas[i], B[i]));
}
do{
    //TODO:se debe copiar resultado act a ant
    actualizar_semilla(filas, resultados_ant);
    for(auto i = 0; i < cant_filas; i++){
        resultados_act.push_back(calcular_fila(filas[i], B[i]));
    }
} while(satisface_error(resultados_act,resultados_ant));
return 0;
}

double calcular_fila(std::vector<tripla> * fila, double &b) {
//Sumatoria de todos los resultados de Coef * Semilla, más B
double resultado = b;
for(auto num = fila->begin();num != fila->end(); num ++){
    resultado += num->calcular();
}
return resultado;
}

bool satisface_error(std::vector<double> & anterior, std::vector<double> & actual) {
//Devuelve true si la norma euclidea entre el vector solucion n-1 y el n es menor a error
double norma = 0.0;
auto ant = anterior.begin();
auto act = actual.begin();
for(;ant != anterior.end(); ant ++){
    norma += std::pow(*ant - *act,2);
    act ++;
}
return std::sqrt(norma) <= error;
}

void actualizar_semilla(std::vector<std::vector<tripla> *> & filas, std::vector<double> & resultados) {
//Coloca un semilla nueva en aquellos coeficientes que poseen un resultado local, el resto es ignorado
for(auto fila = filas.begin(); fila != filas.end(); fila ++){
    for(auto elem = (* fila)->begin(); elem != (* fila)->end(); elem ++){
        if(elem->pos > 0)
            elem->semilla = resultados[elem->pos];
    }
}
}*/



