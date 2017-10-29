#include "libreria.hpp"
using namespace lib;
libro::libro(){
    dl.autor = "0";
    dl.titulo = "0";
    dl.categoria = 0;
}
libro::libro(string ia, string it, int ic){
     dl.autor = ia;
    dl.titulo = it;
    dl.categoria = ic;
}
libreria::libreria(){
    pvlibro = vlibro;
}