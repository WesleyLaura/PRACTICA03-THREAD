#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std; // Para evitar escribir std:: en cada uso

mutex mtx; // Para sincronizar la impresión en consola

void proceso(const string& nombre, int repeticiones, int espera_ms) {
    for (int i = 1; i <= repeticiones; ++i) {
        this_thread::sleep_for(chrono::milliseconds(espera_ms)); // Espera simulada
        lock_guard<mutex> lock(mtx); // Bloqueo para impresión ordenada
        cout << "Proceso " << nombre
             << " - Iteración " << i
             << " - Espera: " << espera_ms << " ms" << endl;
    }
}

int main() {
    cout << "Iniciando los procesos..." << endl;

    // Crear tres hilos (procesos)
    thread t1(proceso, "A", 5, 500); // Proceso A, 5 veces, 500ms
    thread t2(proceso, "B", 7, 300); // Proceso B, 7 veces, 300ms
    thread t3(proceso, "C", 4, 700); // Proceso C, 4 veces, 700ms

    // Esperar que todos los hilos terminen
    t1.join();
    t2.join();
    t3.join();

    cout << "Todos los procesos han terminado." << endl;

    return 0;
}

