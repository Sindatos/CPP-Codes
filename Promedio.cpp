#include <iostream>
#include <cmath> 

using namespace std;

float promedio(float notas[], int numeronotas){
    float total = 0;
    for (int i = 0; i < numeronotas; i++){
        total += notas[i];
    }
    return total / numeronotas;
}

float desviacion(float notas[], int numeronotas){
    float prome = promedio(notas, numeronotas);
    float suma_diferencias_cuadrado = 0;
    for (int i = 0; i < numeronotas; i++){
        float diferencia = notas[i] - prome;
        suma_diferencias_cuadrado += diferencia * diferencia;
    }
    return sqrt(suma_diferencias_cuadrado / numeronotas);
}

float max(float notas[], int numeronotas){
    int max = notas[0];
    for(int i = 0; i < numeronotas; i ++){
        if (notas[i]>max){
            max = notas[i];
        }
    }
    return max;
}

float min(float notas[], int numeronotas){
    int min = notas[0];
    for(int i = 0; i < numeronotas; i ++){
        if (notas[i]<min){
            min = notas[i];
        }
    }
    return min;
}

void invertir(float notas[], int numeronotas) {
    for (int i = 0; i < numeronotas / 2; i++) {
        float aux = notas[i];
        notas[i] = notas[numeronotas - 1 - i];
        notas[numeronotas - 1 - i] = aux;
    }
}

int main()
{
    int numeronotas; 
    cout << "Ingrese el número de notas que desea ingresar: ";
    cin >> numeronotas;

    float notas[numeronotas];
    for (int i = 0; i < numeronotas; i++){
        cout << "Ingrese la nota #" << i + 1 << ": ";
        cin >> notas[i];
    }

    float resultado = promedio(notas, numeronotas); 
    cout << "El promedio es: " << resultado << endl;

    float desviacion_estandar = desviacion(notas, numeronotas);
    cout << "La desviación estándar es: " << desviacion_estandar << endl;
    
    float maximo = max(notas, numeronotas);
    cout << "El maximo es " << maximo << endl;
    
    float minimo = min(notas, numeronotas);
    cout << "El minimo es " << minimo << endl;
    
    invertir(notas, numeronotas);
    
    cout << "El array invertido es: ";
    for (int i = 0; i < numeronotas; i++) {
        cout << notas[i] << " ";
    }
    
    return 0;
}
