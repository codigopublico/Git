#include "libreria.hpp"
using namespace lib;
libro::libro(){
    uno.autor = "0";
    uno.titulo = "0";
    uno.categoria = 0;
    uno.id = 0;
};
libro::libro(string ia, string it, int ic){
     uno.autor = ia;
    uno.titulo = it;
    uno.categoria = ic;
    uno.id = 0;
};
libreria::libreria(){
    pvlibro = vlibro;
    total = 0;
    uno.id = 0; 
}
void libreria::intro_libro(libro vl){
    pvlibro->autor = vl.uno.autor;
    pvlibro->categoria = vl.uno.categoria;
    pvlibro->titulo = vl.uno.titulo;
    pvlibro->id = total + 1;
    total++;
    *pvlibro++;
}
void libreria::mostrar(){
    int c = 0;
    for(int i = 0; i < total; i++){
        std::cout <<"\n " << vlibro[i].titulo << "  titulo\n";
        std::cout <<"\n " << vlibro[i].autor << "   autor\n";
        std::cout <<"\n " << vlibro[i].categoria << "   categoria\n";
        std::cout <<"\n " << vlibro[i].id << "   id\n";
        if(vlibro[i].categoria == 0){
            c++;
        }
    }
    std::cout << "Hay " << c << "errres\n";
}
void libreria::eliminar(string l){
    /*for(int i = 0; i < total; i++){
        *pvlibro--;
    }*/
    int c = 0;
    for(int e = 0;e < total; e++){
        if(vlibro[e].autor == l){
            std::cout << "Encontre el libro1 " << vlibro[e].titulo << "\n";
            vlibro[e].autor = "0";
            vlibro[e].categoria = 0;
            vlibro[e].id = 0;
            vlibro[e].titulo = "0";
            c++;
        }
    }
    int max = 100;
    int c2 = 0;
    int c3 = 0;
    while(c2 < 10){//aqui se tiene que hacer una comprovacion bien echa.
                c2++;
                c3 = 0;
    for(int e = 0; e < total; e++){
        if(vlibro[e].categoria == 0){
            vlibro[max].autor = vlibro[e].autor;
            vlibro[e].autor = vlibro[e+1].autor;
            vlibro[e+1].autor = vlibro[max].autor;
            
            vlibro[max].categoria = vlibro[e].categoria;
            vlibro[e].categoria = vlibro[e+1].categoria;
            vlibro[e+1].categoria = vlibro[max].categoria;
            
            vlibro[max].id = vlibro[e].id;
            vlibro[e].id = vlibro[e+1].id;
            vlibro[e+1].id = vlibro[max].id;
            
            vlibro[max].titulo = vlibro[e+1].titulo;
            vlibro[e+1].titulo = vlibro[e].titulo;
            vlibro[e].titulo = vlibro[max].titulo;
            std::cout << "titulo a mover: " << c2 << "  " << vlibro[e].titulo << "\n";
            c3++;
        }
    }
    }
    total = total - c3;
}