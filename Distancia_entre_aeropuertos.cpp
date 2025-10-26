#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Crear una matriz dinámica
void crearMatriz(int*** matriz, int filas, int columnas){
    *matriz=new int*[filas];{
        for(int i=0;i<filas;i++){
            (*matriz)[i]=new int[columnas];
        }
    }
}

// Liberar la memoria de una matriz dinámica
void liberarMatriz(int** matriz, int filas){
    for(int i=0;i<filas;i++){
        delete[]matriz[i];
    }
    delete[]matriz;
}

//Llenar una matriz dinámica con valores aleatorios
void llenarMatriz(int** matriz, int filas, int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matriz[i][j]=100 + rand()%1401; // Valores aleatorios entre 100 y 1500
        }
    }
}

// Muestre una matriz dinámica
void mostrarMatriz(int** matriz, int filas, int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Calcular la distancia promedio entre aeropuertos
double distanciaPromedio(int** matriz, int filas, int columnas){
    double suma=0.0;
    int contador=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            suma+=matriz[i][j];
            contador++;
        }
    }
    return suma/contador;
}

// Mostrar el aeropuerto con menor distancia promedio
void aeropuertoMenorDistancia(int** matriz, int filas, int columnas){
    double menorPromedio=distanciaPromedio(matriz, filas, columnas);
    int aeropuertoMenor=0;
    for(int i=1;i<filas;i++){
        double promedioActual=0.0;
        for(int j=0;j<columnas;j++){
            promedioActual+=matriz[i][j];
        }
        promedioActual/=columnas;
        if(promedioActual<menorPromedio){
            menorPromedio=promedioActual;
            aeropuertoMenor=i;
        }
    }
    cout<<"El aeropuerto con menor distancia promedio es el aeropuerto "<<aeropuertoMenor<<" con una distancia promedio de "<<menorPromedio<<endl;
}


int main(){

    srand(time(NULL));

    int filas; // Número de aeropuertos
    int columnas; // Número de destinos por aeropuerto
    int** matriz;
    cout << "Ingrese el número de aeropuertos: ";
    cin >> filas;
    columnas=filas;

    crearMatriz(&matriz, filas, columnas);
    llenarMatriz(matriz, filas, columnas);
    cout<<"Matriz de distancias entre aeropuertos:"<<endl;
    mostrarMatriz(matriz, filas, columnas);

    double promedio=distanciaPromedio(matriz, filas, columnas);
    cout<<"La distancia promedio entre aeropuertos es: "<<promedio<<endl;

    aeropuertoMenorDistancia(matriz, filas, columnas);

    liberarMatriz(matriz, filas);
    return 0;

}