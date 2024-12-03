#include <iostream>
#include <string>
#include <limits>
using namespace std;


//Limpiar la consola
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcion para mostrar el menu
void mostrarMenu() {
    clearConsole();
    cout << "\033[1;34mBIENVENIDO A BART MART\033[0m\n\n";
    cout << "1. INVENTARIO\n2. CARRITO DE COMPRAS \n3. SALIR" << endl;
}


