#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <random>
#include <chrono>

using namespace std;

int MAX_DISTANCIA;  // Lo vamos a pedir por pantalla (metros)
int TOTAL_AUTOS;    // Lo pediremos por pantalla (cantidad de autos N = NUmero de threads)

vector<int> progreso;  // Se inicializa dinámicamente después de obtener N autos

mutex carreraMutex;

void correrAuto(int autoId) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> avanceAleatorio(1, 10);
    uniform_int_distribution<> pausaAleatoria(500, 1000);  // Pausa más larga para ver las hebras

    while (progreso[autoId] < MAX_DISTANCIA) {
        int avance = avanceAleatorio(gen);
        this_thread::sleep_for(chrono::milliseconds(pausaAleatoria(gen)));

        lock_guard<mutex> lock(carreraMutex);
        progreso[autoId] += avance;
        cout << "Auto " << autoId << " avanza " << avance << " metros (total: " << progreso[autoId] << " metros)\n";
    }
}

int main() {
    // Pedir al usuario la cantidad de metros y autos
    cout << "Ingrese la cantidad de metros que debe recorrer cada auto (M): ";
    cin >> MAX_DISTANCIA;
    cout << "Ingrese la cantidad de autos (N): ";
    cin >> TOTAL_AUTOS;

    // Inicializar el vector de progreso con N autos
    progreso = vector<int>(TOTAL_AUTOS, 0);

    // Crear y lanzar las hebras para cada auto
    vector<thread> hilos;
    for (int i = 0; i < TOTAL_AUTOS; ++i) {
        hilos.emplace_back(correrAuto, i); 
    }

    // Unir las hebras
    for (auto& hilo : hilos) {
        hilo.join();
    }

    cout << "¡La carrera ha terminado!\n";
    return 0;
}

// By_ Francisco Farias y Benjamin cataldo : Universidad del BioBio  
