#include <iostream>
using namespace std;
int sumar (int a, int b);//aqui hay otro error.
int z = 0;
int main() {
int x = 7;
int y = 8;
int z = 0;//aqui esta el error deveria ser z. 
z = sumar(x, y);
cout << "z=" << z << endl;
return 0;
}
int sumar (int a, int b)//aqui tambien hay un error se deviria hacer int
{
int c = 0;
c = a + b;
return c;
}