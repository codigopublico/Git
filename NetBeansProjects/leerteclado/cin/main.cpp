/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 9 de octubre de 2017, 15:35
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
void fcin(){
    int max = 200;
    int aux = 1;
    char ch2[max][max];
    int ch;
    int i;
    for(; i < max; i++){
        if(aux == 0){
            break;
        }
    std::cin  >>  ch2[i] >> setbase(16) >> ch;
    std::cout << ch2[i] << "\n";
    for(int ii = 0; ii < i; ii++){
        for(int iii = 0; iii < max; iii++){
            if(ch2[ii][iii] == '1'){
            aux = 0;    
        }
        }
    }
    }
    for(int ii = 0; ii < i; ii++){
        //ch2[i] >> setbase(16) >> ch;
        std::cout << ch2[i] << "  ";
        std::cout << ch << "\n";
    }
    std::cout << "Decimal "<<ch << "\n";

}
int main(int argc, char** argv) {
    fcin();
    return 0;
}

