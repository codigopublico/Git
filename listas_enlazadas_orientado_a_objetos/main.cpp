/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 14 de diciembre de 2017, 17:13
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include<stdlib.h> //esta es la libreria de random
using namespace std;

/*
 *este es un ejemplo wur lurgo di finvions dr pasara a la practica......... 
 */
class Data{
private:
    int nivel;
    int duracion;
    string titulo;
    string autor;
    bool sig;
    int lista;//este es el numero al que pertence cada cancion de la base de datos global
public:
    Data(int Iv){ nivel = Iv; }
    Data(int Iv, int In){  nivel = Iv; duracion = In; }
    Data(int Iv, int in, string iH){
        nivel = Iv;
        duracion = in;
        titulo = iH;
    }
    Data(int Iv, int in, string iH, string Ia, bool Isig, int Ili){
        nivel = Iv;
        duracion = in;
        titulo = iH;
        autor = Ia;
        sig = Isig;
        lista = Ili;
    }
    Data(const Data &a){
        this->nivel = a.nivel;
        this->autor = a.autor;
        this->sig = a.sig;
        this->lista = a.lista;
        this->titulo = a.titulo;
        this->duracion = a.duracion;
    }
    ~Data (){}
    int compare(const Data&);
    void nlista(string It, int Ia);
    void show(){ 
        std::cout << "Dato:         :" << nivel << "\n";  
        std::cout << "Duracion      :"<< duracion << "\n";
        std::cout << "titulo        :" << titulo  << "\n";
        std::cout << "autor         :" << autor << "\n";
        std::cout << "Numero_lista  :"  << lista<< "\n"; 
    //aqui se usara el booleano para hacer lo de la lista adeamas se puede usar un show espcial para mostar todos.
    }
    void Bshow(int a){
        if(lista == a){
        std::cout << "Dato:         :" << nivel << "\n";  
        std::cout << "Duracion      :"<< duracion << "\n";
        std::cout << "titulo        :" << titulo  << "\n";
        std::cout << "autor         :" << autor << "\n";
        std::cout << "Numero_lista  :"  << lista<< "\n"; 
        }
    }
    int eliminar(string Ia){//aqui falta un operando para comparar si es el titulo
        int r = 0;
        if(Ia == titulo){
        nivel = 0;
        duracion = 0;
        titulo = "0";
        autor = "0";
        sig = "0";
        lista = 0;
        r = 1;
        }//se tiene que hacer igual que nlista vale tengo que retornar si es 0 o 1 i ponerlo a null el nodo.
        return r;
    }
};//estos son los datos. A ver voy a provar de poner mas.
int Data::compare(const Data& other){
    if(nivel < other.nivel){
        return 0;
    }
    if(nivel > other.nivel){
        return 1;
    }
    else
        return 2;
}//tengo que hacer otro para crear listas en base a un dato. booleano
void Data::nlista(string It, int Ia){
    if(It == titulo){
        this->lista = Ia;
    }
    //return this;
}
class Node;
class HeadNode;
class TailNode;
class InternalNode;
class Node{
public:
    Node() {}
    virtual ~Node() {}
    virtual Node* insert(Data* data) = 0;
    virtual Node* list(string It, int Ia) = 0;
    virtual Node* eliminar(string Ia) = 0;
    virtual void show() = 0;
    virtual void Bshow(int a) = 0;
private:
};
class InternalNode : public Node{
private: 
    Data* data;
    Node* next;
public:
    InternalNode(Data*, Node*);
    virtual ~InternalNode() { delete next; delete data;}; //este tiene un error
    virtual Node* insert(Data* data);
    virtual Node* list(string It, int Ia);
    virtual Node* eliminar(string Ia);
    virtual void show(){
        std::cout << "Show:Internalnode";
        data->show(); next->show();
    }
    virtual void Bshow(int a){
        //std::cout << "Show:Internalnode";
        data->Bshow(a); next->Bshow(a);
    }
    
};
    InternalNode::InternalNode(Data* newdata, Node* newnext){
        InternalNode::data = newdata;
        InternalNode::next = newnext;
    };
    Node* InternalNode::insert(Data* other){
        int result = data->compare(*other);
        switch(result)
        {  
            case 2: //esto hace que no siga adelante
            case 1:
            {
                InternalNode* dataNode = new InternalNode(other, this);
                return dataNode;
            }
            case 0: 
            {
                next = next->insert(other);
                return this;
            }
        }
        return this;
    }
    Node* InternalNode::list(string It, int Ia){
        data->nlista(It, Ia);
        next->insert(data);
        data->nlista(It, Ia);
        return this;
    }
    Node* InternalNode::eliminar(string Ia){
        int r;
        r = data->eliminar(Ia);
        next->insert(data);
        if(r == 1){
            data == NULL;
        }
        next->insert(data);//porque no me sale
        return this;
    }
    class TailNode : public Node{
    public:
        TailNode() {}
        virtual ~TailNode() {}
        virtual Node* insert (Data* data);
        virtual Node* list(string It, int Ia) { }
        virtual Node* eliminar(string Ia) { }
        virtual void show() { }
        virtual void Bshow(int a) { }
    private:
    };
    Node* TailNode::insert(Data* data)
    {
        InternalNode* dataNode = new InternalNode(data, this);
        return dataNode;
    }
    class HeadNode : public Node {
    private:
        Node* next;
    public:
        HeadNode();
        virtual ~HeadNode(){ delete next;}
        virtual Node* insert(Data* data);
        virtual Node* list(string Ia, int It){ next->list(Ia, It); }
        virtual Node* eliminar(string Ia){ next->eliminar(Ia); }
        virtual void show(){
            std::cout << "HeadNode:    ";
            next->show();
        }
        virtual void Bshow(int a){
            //std::cout << "HeadNode:   ";
            next->Bshow(a);
        }
    };
    HeadNode::HeadNode(){
        next = new TailNode;
    }
    Node* HeadNode::insert(Data* data){
        next = next->insert(data);
        return this;
    }
    class LinkedList{
    private:
        HeadNode* head;
    public:
        LinkedList();
        ~LinkedList(){ delete head; }
        void insert(Data* data);
        void list(string It, int Ia){
            head->list(It, Ia);//esto esta mal molaria sin tener que poner lo pdata porque lo que hace es insertar uno 
        }//esto funcionara
        void showall(){head->show();}
        void Bshowall(int a){ head->Bshow(a); } 
        void eliminar(string Ia){ head->eliminar(Ia); } //aqui falta una variable para la elecion de la eliminacion 
    };
    LinkedList::LinkedList(){
        head = new HeadNode;
    }
    void LinkedList::insert(Data* pData){
        head->insert(pData);
    }
    
    Data menu(){
        int nivel;
        int duracion;
        string titulo;
        string autor;
        string sig;
        bool Bsig;
        int lista;
        std::cout << "Dime el titulo de la cancion:\n";
        std::cin >> titulo;
        std::cout << "Dime el nivel del sonido\n";
        std::cin >> nivel;
        std::cout << "Dime la duracion de la cancion\n";
        std::cin >> duracion;
        std::cout << "Dime el autor de la cancion\n";
        std::cin >> autor;
        std::cout << "Es un single s/n\n";
        std::cin >> sig;
        if(sig == "s"){
            Bsig = true;
        }
        if(sig == "n"){
            Bsig = false;
        }
        else{
            Bsig = false;
        }
        for(int i = 0; i < 10; i++){
            std::cout << ".\n";
        }
        lista = 0;
        Data res(nivel, duracion, titulo, autor, Bsig, lista);
        return res;
    }
    void lista(LinkedList *b){
        string Ia;
        while(Ia != "0"){
        b->showall();
        std::cout << "Dime que titulo quieres poner en la lista ?";
        std::cin >> Ia;
        b->list(Ia, 1);
        }
    }
int main(int argc, char** argv){
    Data* pData;
    int val;
    LinkedList a;
    while (true)//tengo que hacer un menu mejor
    {
        std::cout << "Dame un numero(0 para salir)?";
        std::cin >> val;
        if(!val)
            break;
        pData = new Data(menu());
        a.insert(pData);
        //a.list("a", 0);
    }
    a.showall();
    std::cout << "Show alternativo \n.";
    lista(&a);
    std::cout << "Espacio\n";
    a.Bshowall(1);
    std::cout << "Eliminar los titulos de a\n";
    a.eliminar("a");
    a.showall();
    return 0;
}