#include <iostream>
#include <string>
using namespace std;
string abc[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u",  "v", "w", "x", "y", "z"};
string cod[] = {"41", "42", "43", "44", "45", "46", "47", "48", "49", "4D1", "4D2", "4D3", "4D4", "4d5", "4d6", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5d6" };
string desc(string a){
int i = 0;
for (; i < 26; i++){
if(a == abc[i]) break;

}
return cod[i];
}
int main(){
string a;
while (a != "0"){
std::cout << "             \n";
std::cin >> a;
std::cout << desc(a) << "\n";
}
std::cout << "sortida\n";
}
