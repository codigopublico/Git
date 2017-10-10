/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 7 de octubre de 2017, 12:04
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <iostream>
/*
 * Este es un programa para leer el teclado....
 */
using namespace std;
static struct termios initial_settings, new_settings;
static int peek_character = -1;
void init_keyborad();
void close_keyborad();
int kbhit();
int readch();
void init_keyborad(){
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_cflag &= ~ICANON;
    new_settings.c_cflag &= ~ECHO;
    new_settings.c_cflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;

}
void close_keyborad(){
    tcgetattr(0, &initial_settings);
    tcsetattr(0, TCSANOW, &initial_settings);

}
int kbhit(){
    char ch;
    int nread;
    if(peek_character != -1 ) 
        return 1;
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &initial_settings);
    nread = read(0, &ch, 1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &initial_settings);
    if(nread == 1){
        peek_character = ch;
        return 1;
    }
    return 0;

}
int readch(){
    char ch;
    if(peek_character != -1){
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0, &ch, 1);
    return ch;
}
char* detectarpulsaciones(){
    int i = 0;
    int ii = 0;
    char *ch2 = new char[200];
    while(ch2[i] != 13){
        sleep(1);
        if(kbhit()){
            ch2[i] = readch();
            std::cout <<  ch2[i];
            i++;
        }
    }
    std::cout << "\n La palabra inroducida es ...\n";
    for(int i = 0; ch2[i] != 0; i++){
        std::cout << ch2[i];
    }
    close_keyborad();       
    return ch2;
}
void modificar(){
char ch;
char ch2[200];
int i = 1;
    while(ch != 13){
        sleep(0.5);
        if(kbhit()){
            ch = readch();
            i++;
            ch2[i] = ch;
            std::cout << ch;
        }
    }
    close_keyborad();
    std::cout << "\nLa lectura total es: \n";
    for(int i = 0; ch2[i] != 13; i++){
    std::cout << ch2[i];
}
    exit(0);
}

int main(int argc, char** argv) {
    std::cout << "\nEste es el retorno" <<detectarpulsaciones() << "\n";
    //modificar();
    return 0;
}

