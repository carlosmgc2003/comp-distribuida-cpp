//
// Created by Carlos Maceira Garcia Coni on 06/11/2019.
//
#include "persistencia.h"
int lecturaDatos(std::vector <dato> &ORIGEN) {
    sqlite3 *db = nullptr; //Puntero a la base de datos
    sqlite3_stmt *cursor; //Puntero a la fila devuelta por sqlite3_prepare_v2
    const char *tail; //No se usa por que tenemos un solo statement SQL
    int rc; //response code de cada operacion que hacemos
    const char *sql = "SELECT * from datos;";
    int cont = 0;
    rc = sqlite3_open("datos_esclavo.db", &db);
    if (rc) {
        printf("No se pudo abrir la Base de Datos: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    rc = sqlite3_prepare_v2(db, sql, 128, &cursor, &tail);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        printf("No se pueden levantar los datos: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    while (sqlite3_step(cursor) == SQLITE_ROW) {
        dato nuevo;
        nuevo.id = sqlite3_column_int(cursor, 0);
        nuevo.fila = sqlite3_column_int(cursor, 1);
        nuevo.pos = sqlite3_column_int(cursor, 2);
        nuevo.coeficiente = sqlite3_column_double(cursor, 3);
        nuevo.semilla = 0.0;
        nuevo.resultado = sqlite3_column_double(cursor, 4);
        ORIGEN.push_back(nuevo);
        cont++;
    }
    sqlite3_finalize(cursor);
    sqlite3_close(db);
    return 0;
}

int escrituraDatos(std::vector<dato> &ORIGEN){
    sqlite3 *db = nullptr; //Puntero a la base de datos
    sqlite3_stmt *cursor; //Puntero a la fila devuelta por sqlite3_prepare_v2
    const char *tail; //No se usa por que tenemos un solo statement SQL
    int rc; //response code de cada operacion que hacemos
    const char *sql = "SELECT * from datos;";
    int cont = 0;
    rc = sqlite3_open("datos_esclavo.db", &db);
    if (rc) {
        printf("No se pudo abrir la Base de Datos: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    rc = sqlite3_prepare_v2(db, sql, 128, &cursor, &tail);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        printf("No se pueden levantar los datos: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    while (sqlite3_step(cursor) == SQLITE_ROW) {
        dato nuevo;
        nuevo.id = sqlite3_column_int(cursor, 0);
        nuevo.fila = sqlite3_column_int(cursor, 1);
        nuevo.pos = sqlite3_column_int(cursor, 2);
        nuevo.coeficiente = sqlite3_column_double(cursor, 3);
        nuevo.semilla = 0.0;
        nuevo.resultado = sqlite3_column_double(cursor, 4);
        ORIGEN.push_back(nuevo);
        cont++;
    }
    sqlite3_finalize(cursor);
    sqlite3_close(db);
    return 0;
}
