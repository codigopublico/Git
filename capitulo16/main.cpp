/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 14 de noviembre de 2017, 19:13
 */

#include <cstdlib>
#include <mia/no_renderizadas/sql/sqlite3.h>
#include <iostream>
#include <mia/no_renderizadas/qt/platilla1/platilla1.h>
using namespace std;

/*
 * Este es del ejercio 16
 */

void sql(){
    int rc; 
    sqlite3 *db;
    //Abrir la base de datos..
    rc = sqlite3_open("biblioteca.db", &db);//aqui no se puede..................
        if(SQLITE_OK != rc) {
                cout << "Error: No se puede abrir la base de datos" << endl;
        }
// Cerrar base de datos
sqlite3_close(db);
}
int main(int argc, char** argv) {

    return 0;
}

