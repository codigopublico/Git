/* 
 * File:   main.cpp
 * Author: iper
 *
 * Created on 14 de diciembre de 2017, 17:13
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 *este es un ejemplo wur lurgo di finvions dr pasara a la practica......... 
 */
class Data{
private:
    int value;
public:
    Data(int Iv): value(Iv) {}
    Data(const Data &a){
        this->value = a.value;
    }
    ~Data (){}
    int compare(const Data&);
    void show(){ std::cout << "Dato: " << value << "\n"; }
};
int Data::compare(const Data& other){
    if(value < other.value){
        return 0;
    }
    if(value > other.value){
        return 1;
    }
    else
        return 2;
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
    virtual void show() = 0;
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
    virtual void show(){
        std::cout << "Show:Internalnode";
        data->show(); next->show();
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
    class TailNode : public Node{
    public:
        TailNode() {}
        virtual ~TailNode() {}
        virtual Node* insert (Data* data);
        virtual void show() { }
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
        virtual void show(){
            std::cout << "HeadNode:    ";
            next->show();
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
        void showall(){head->show();}
    };
    LinkedList::LinkedList(){
        head = new HeadNode;
    }
    void LinkedList::insert(Data* pData){
        head->insert(pData);
    }
int main(int argc, char** argv){
    Data* pData;
    int val;
    LinkedList a;
    while (true)
    {
        std::cout << "What value (0 to stop)?";
        std::cin >> val;
        if(!val)
            break;
        pData = new Data(val);
        a.insert(pData);
    }
    a.showall();
    return 0;
}