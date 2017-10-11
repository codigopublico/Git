/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 11 de octubre de 2017, 14:20
 */

#include <cstdlib>
#include <mysql/mysql.h>
using namespace std;

/*
 * 
 */
void p1(){
    mysql_read_query_result();
    st_mysql_field.db = "base";
}
int main(int argc, char** argv) {
    p1();
    return 0;
}

