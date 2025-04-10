#include <iostream>
#include <thread>
using namespace std;
void mensaje(string a){
cout<<"esta funcion thread ";
cout<<"recibe como mensaje = "<<   a <<  "\n";
}
int main()
{
    string m = "hola a todos";
    thread t(mensaje,m);
    cout<< "el mensaje principal para thread es = "<< m<< "\n";
        t.join();
    return 0;
}
