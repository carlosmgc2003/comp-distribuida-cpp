//
// Created by Carlos Maceira Garcia Coni on 06/11/2019.
//
#include "persistencia.h"

int lecturaDatos(std::vector<Dato> &ORIGEN) {
    sqlite3 *db = nullptr; //Puntero a la base de datos
    sqlite3_stmt *cursor; //Puntero a la fila devuelta por sqlite3_prepare_v2
    const char *tail; //No se usa por que tenemos un solo statement SQL
    int rc; //response code de cada operacion que hacemos
    const char *sql = "SELECT * from datos;";
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
        Dato nuevo;
        nuevo.id = sqlite3_column_int(cursor, 0);
        nuevo.fila = sqlite3_column_int(cursor, 1);
        nuevo.pos = sqlite3_column_int(cursor, 2);
        nuevo.coeficiente = sqlite3_column_double(cursor, 3);
        nuevo.resultado = sqlite3_column_double(cursor, 4);
        nuevo.semilla = sqlite3_column_double(cursor, 4);
        ORIGEN.push_back(nuevo);
    }
    sqlite3_finalize(cursor);
    sqlite3_close(db);
    return 0;
}


int escrituraDatos(std::vector<Solucion> &SOLUCION) {
    sqlite3 *db = nullptr; //Puntero a la base de datos
    int rc; //response code de cada operacion que hacemos
    rc = sqlite3_open("datos_esclavo.db", &db);
    if (rc) {
        printf("No se pudo abrir la Base de Datos: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    std::string SQL = {"DROP TABLE IF EXISTS solucion;"};
    rc = sqlite3_exec(db, SQL.c_str(), NULL, NULL, NULL);
    if (rc) {
        printf("No se pudo eliminar la tabla solucion %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return (1);
    }
    SQL.clear();
    SQL = "CREATE TABLE solucion(variable INTEGER, solucion REAL);";
    rc = sqlite3_exec(db, SQL.c_str(), NULL, NULL, NULL);
    if (rc) {
        printf("No se pudo crear la Tabla Solucion\n");
        sqlite3_close(db);
        return (1);
    }
    for (const auto &item : SOLUCION) {
        SQL.clear();
        SQL.append("INSERT INTO solucion(variable, solucion) VALUES (");
        SQL.append(std::to_string(item.nro_variable));
        SQL.append(", ");
        SQL.append(std::to_string(item.resultado));
        SQL.append(");");
        rc = sqlite3_exec(db, SQL.c_str(), NULL, NULL, NULL);
        if (rc) {
            printf("No se pudo meter el valor de la variable");
            sqlite3_close(db);
            return (1);
        }
    }
    sqlite3_close(db);
    return 0;
}

