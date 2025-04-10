#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void independentThread(){
cout<< "Empezamos el hilo concurrente.\n";
 std::this_thread::sleep_for(std::chrono::seconds(2));
cout<<"saliendo del hilo concurrente.\n";
}

void threadCaller(){
    std::cout << "Empezando a llamar al hilo.\n";
    std::thread t(independentThread); // Lanza un nuevo hilo con la función anterior
    t.detach();                       // Desvincula el hilo, sigue ejecutándose solo
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Saliendo de la llamada al hilo.\n";
}
int main(){
    threadCaller(); // Llama a la función que lanza el hilo
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Espera 5 segundos
    return 0;
}
