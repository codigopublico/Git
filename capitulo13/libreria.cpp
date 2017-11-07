#include "libreria.hpp"
using namespace lib;
using namespace std;
string cat[2] ={"terror", "poesia"};
libro::libro(){
    uno.autor = "0";
    uno.titulo = "0";
    uno.categoria = 0;
    uno.id = 0;
    uno.stock = 0;
};
libro::libro(string ia, string it, int ic){
     uno.autor = ia;
    uno.titulo = it;
    uno.categoria = ic;
    uno.id = 0;
    uno.stock = 0;
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
    string aux;
    if(total < 0){
        total = 0;
    }
    for(int i = 0; i < total; i++){
        std::cout << "\n";
        std::cout << "\n";
        std::cout <<"  " << vlibro[i].titulo << "  titulo  ";
        std::cout <<"  " << vlibro[i].autor << "   autor   ";
        if(vlibro[i].categoria == 1){
            aux = cat[1];
        }else{
            aux = cat[0];
        }
        std::cout <<"  " << aux << "   categoria  ";
        std::cout <<"  " << vlibro[i].id << "   id   ";
        std::cout <<"  " << vlibro[i].stock << "   stock   ";
        std::cout << "\n";
        if(vlibro[i].categoria == 0){
            c++;
        }
    }
    std::cout << "Hay " << c << "errres\n";
}
int libreria::eliminar(string l){
    /*for(int i = 0; i < total; i++){
        *pvlibro--;
    }*/
    int c = 0;
    for(int e = 0;e < total; e++){
        if(vlibro[e].titulo == l){
            //std::cout << "Encontre el libro1 " << vlibro[e].titulo << "\n";
            vlibro[e].autor = "0";
            vlibro[e].categoria = 0;
            vlibro[e].id = 0;
            vlibro[e].titulo = "0";
            vlibro[e].stock = 0;
            c++;
        }
    }
    int max = 100;
    int c2 = 0;
    int c3 = 0;
    while(c2 < 10 * c){//aqui se tiene que hacer una comprovacion bien echa.
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
            
            vlibro[max].stock = vlibro[e+1].stock;
            vlibro[e+1].stock = vlibro[e].stock;
            vlibro[e].stock = vlibro[max].stock;
            //std::cout << "titulo a mover: " << c2 << "  " << vlibro[e].titulo << "\n";
            c3++;
        }
    }
    }
    total = total - c;
        if(total < 0){
        total = 0;
    }
    if(c3 > 0){
        return 1;
    }else{
        return 0;
    }
}
int libreria::Buscar_libro(string in){
    int n = 0;
    for(int i = 0; i < total; i++){
        if(vlibro[i].titulo == in){
            std::cout << "Encontre el libro con el titulo:   " << vlibro[i].titulo << " referencia( " << vlibro[i].id << ")\n";
            n = 1;
        }
    }
    return n;
}
int libreria::Buscar_libro(int in){//esta es pase por referncia al libro
    int n = 0;
    for(int i = 0; i < total; i++){
        if(vlibro[i].id == in){
            std::cout << "Encontre el libro con el titulo:   " << vlibro[i].titulo << " referencia( " << vlibro[i].id << ")\n";
            n = 1;
        }
    }
    return n;
}
void libreria::stock(int in, int ia){ // in es es la referncia a poner i ia es la es el numero a poner.
    for(int i = 0; i < total; i++){
        if(vlibro[i].id == in){
            vlibro[i].stock = ia;
            std::cout <<  "\n stock " <<  vlibro[i].stock << "libro  " <<  vlibro[i].titulo << " id   " << vlibro[i].id <<"\n";
        }
    }
    
}
void libreria::astock(int in, int ia){ // in es es la referncia a poner i ia es la es el numero a poner.
    for(int i = 0; i < total; i++){
        if(vlibro[i].id == in){
            vlibro[i].stock = vlibro[i].stock + ia;
        }
    }
    
}

void libreria::vender(int in){
    for(int i = 0; i < total; i++){
        if(vlibro[i].id == in){
            if(vlibro[i].stock > 0){
            vlibro[i].stock--;
            }
        }
    }
}
void libreria::vender(string in){
    for(int i = 0; i < total; i++){
        if(vlibro[i].titulo == in){
            if(vlibro[i].stock > 0){
            vlibro[i].stock--;
            }
        }
    }
}