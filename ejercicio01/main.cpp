#include <iostream>
#include <thread>
using namespace std;

void saludo(){
cout<<"este es mi  primer hilo\n";
}
int main()
{
    thread t1(saludo);
    if(t1.joinable()){
        t1.join();
    }

    return 0;
}
