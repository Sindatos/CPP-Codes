#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int numero) {
    if (numero < 2) return false;
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return false;
    }
    return true;
}

// Función para lanzar un dado (número aleatorio entre 1 y 6)
int lanzarDado() {
    return rand() % 6 + 1;
}

// Función para jugar una ronda
int jugarRonda() {
    int dado1 = lanzarDado();
    int dado2 = lanzarDado();
    int total = dado1 + dado2;

    cout << "Primer lanzamiento: " << dado1 << " y " << dado2 << " (Total: " << total << ")" << endl;

    // Reglas especiales
    if (dado1 == dado2) {
        // Dobles: lanzar 3 dados adicionales
        cout << "Dobles! Lanzando 3 dados adicionales..." << endl;
        for (int i = 0; i < 3; i++) {
            total += lanzarDado();
        }
        cout << "Nuevo total después de lanzar 3 dados adicionales: " << total << endl;
    } else if (total == 12) {
        // Preguntar si desea lanzar un dado adicional cuando el total es 12
        char opcion;
        cout << "Has sacado un total de 12! ¿Deseas lanzar un dado adicional? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            total += lanzarDado();
            cout << "Nuevo total después de lanzar 1 dado adicional: " << total << endl;
        }
    }

    return total;
}

// Función principal del juego
void jugar() {
    srand(time(0));
    char jugarDeNuevo = 's';

    while (jugarDeNuevo == 's' || jugarDeNuevo == 'S') {
        int totalJugador1 = 0, totalJugador2 = 0;
        bool empate = true;

        while (empate) {
            cout << "Jugador 1 juega:" << endl;
            totalJugador1 = jugarRonda();
            cout << "Jugador 2 juega:" << endl;
            totalJugador2 = jugarRonda();

            cout << "Jugador 1 total: " << totalJugador1 << " | Jugador 2 total: " << totalJugador2 << endl;

            // Verificar si hay empate
            if (totalJugador1 != totalJugador2) {
                empate = false;
            } else {
                cout << "Empate! Repitiendo la ronda..." << endl;
            }
        }

        // Determinar el ganador
        if (esPrimo(totalJugador1) && esPrimo(totalJugador2)) {
            if (totalJugador1 > totalJugador2) {
                cout << "Jugador 1 gana con un número primo!" << endl;
            } else {
                cout << "Jugador 2 gana con un número primo!" << endl;
            }
        } else if (esPrimo(totalJugador1)) {
            cout << "Jugador 1 gana con un número primo!" << endl;
        } else if (esPrimo(totalJugador2)) {
            cout << "Jugador 2 gana con un número primo!" << endl;
        } else if (totalJugador1 > totalJugador2) {
            cout << "Jugador 1 gana!" << endl;
        } else {
            cout << "Jugador 2 gana!" << endl;
        }

        // Preguntar si desean jugar de nuevo
        cout << "¿Quieres jugar de nuevo? (s/n): ";
        cin >> jugarDeNuevo;
    }
}

int main() {
    cout << "Bienvenido a Prime Jack o 23!" << endl;
    jugar();
    return 0;
}
