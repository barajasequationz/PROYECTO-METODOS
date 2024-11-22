#include <iostream>
#include <string>
using namespace std;


#ifndef LIBRERIA_TIENDA_H_INCLUDED
#define LIBRERIA_TIENDA_H_INCLUDED
// Estructura para definir un producto
struct Producto {
    int id;
    string nombre;
    int cantidad;
    double precio;
};


// Arreglo de productos de la tienda

const int sizeproductos = 100;
Producto productosTienda[sizeproductos] = {
   {1, "Agua Mineral", 100, 25.00}, {2, "Agua Tonica", 80, 30.00}, {3, "Cafe", 75, 30.00},
        {4, "Coca Cola", 120, 20.00}, {5, "Red Bull", 110, 45.00},
        {6, "Monster Mango Loco", 90, 48.00}, {7, "Fanta de Naranja", 70, 22.00}, {8, "Fanta de Fresa", 200, 22.00},
        {9, "Jugo de Arandano", 160, 47.00}, {10, "Jugo de Mango", 140, 24.00}, {11, "Jugo de Piña", 100, 46.00},
        {12, "Jugo de Naranja", 80, 46.00}, {13, "Jaggermeister", 70, 550}, {14, "Limonada", 90, 23.00},
        {15, "Smirnoff", 130, 230.00}, {16, "Te Helado", 100, 20.00}, {17, "Te Verde", 70, 20.00},
        {18, "Powerade", 150, 24.00}, {19, "Arizona Sandia", 200, 18.00}, {20, "Hidromiel", 80, 260.00},
        {21, "Kg. Aguacate", 75,45.00}, {22, "Kg. Arandano", 90, 120.00}, {23, "Kg. Banana", 100, 22.70},
        {24, "Kg. Brocoli", 80, 69.00}, {25, "Kg. Calabaza", 70, 34.30}, {26, "Frasco Cerezas 300g", 90, 31.20},
        {27, "Durazno en Almibar", 60, 59.99}, {28, "Manojo de Esparrago", 100, 49.90}, {29, "Kg. Fresa", 110, 160.00},
        {30, "Kg. Granada", 120, 50.00}, {31, "Kg. Kiwi", 130, 92.00}, {32, "Kg. Tomate", 100, 54.50},
        {33, "Kg. Zanahoria", 110, 29.40}, {34, "Kg. Pimiento", 80, 27.70}, {35, "Kg. Pepino", 75, 36.60},
        {36, "Kg. Papaya", 90, 20.00}, {37, "Kg. Papas", 120, 45.80}, {38, "Pera", 110, 60.00},
        {39, "Kg. Espinaca", 100, 20.00}, {40, "Pz. Lechuga", 140, 26.00}, {41, "Aceite de Cocina", 130, 55.00},
        {42, "Avena", 150, 38.00}, {43, "Azucar", 140, 50.00}, {44, "Cafe Instantaneo", 110, 65.00},
        {45, "Canela en Polvo", 100, 35.00}, {46, "Corn Flakes", 90, 56.00}, {47, "Chocomilk", 80, 37.00},
        {48, "Kg. Frijoles", 70, 46.00}, {49, "Kg. Garbanzos", 75, 43.00}, {50, "Kg. Harina de Maiz", 100, 21.30},
        {51, "Harina de Trigo", 100, 18.50}, {52, "Kg. Lentejas", 120, 83.00}, {53, "Maicena", 90, 23.50},
        {54, "Kg. Nueces", 80, 250.00}, {55, "Espaguetis", 110, 32.10}, {56, "Pimienta", 90, 22.30},
        {57, "Sal", 100, 21.90}, {58, "Sopa Maruchan", 120, 10.60}, {59, "Galletas Emperador de Limon", 130, 21.20},
        {60, "Almendras", 80, 2.50}, {61, "Carne de Cerdo", 60, 3.00}, {62, "Carne de Res", 70, 1.80},
        {63, "Kg. Carne Molida", 100, 81.70}, {64, "Chorizo Pza.", 110, 20.50}, {65, "Crema", 150, 25.20},
        {66, "Kg. Filete de Pescado", 200, 81.20}, {67, "Huevos Pza.", 50, 6.00}, {68, "Jamon", 100, 41.60},
        {69, "Galon de Leche", 60, 55.00}, {70, "Mantequilla Pza.", 70, 22.00}, {71, "Kg. Pechuga de Pollo", 90, 99.00},
        {72, "Piernas de Pollo", 90, 0.90}, {73, "Nuggets de Pollo", 110, 0.40}, {74, "Queso Monterrey", 100, 0.30},
        {75, "Salchichas", 80, 50.50}, {76, "Tocino", 70, 80.30}, {77, "Kg. Pavo", 120, 121.50},
        {78, "Yogur", 100, 2.00}, {79, "Yakult", 130, 1.10}, {80, "Danonino", 90, 3.50},
        {81, "Detergente", 100, 152.70}, {82, "Esponjas", 80, 9.70}, {83, "Papel higienico 20 rollos", 150, 99.90},
        {84, "Toallas de papel", 120, 31.00}, {85, "Servilletas", 130, 30.50},
        {86, "Jabon de Tocador Pza", 100, 9.30}, {87, "Fabuloso", 90, 45.30}, {88, "Pinol", 80, 38.40},
        {89, "Jabon para Trastes", 120, 30.80}, {90, "Shampoo", 110, 89.70}, {91, "Suavitel", 60, 75.50},
        {92, "Pasta Dental", 70, 74.50}, {93, "Limpiador Multiusos", 90, 41.00}, {94, "Trapeador", 100, 51.10},
        {95, "Clorox", 80, 20.20}, {96, "Cepillos de Dientes", 60, 92.30}, {97, "Guantes para limpieza", 90, 21.20},
        {98, "Escoba", 100, 63.10}, {99, "10 Bolsas de Basura", 110, 13.50}, {100, "Trapos Pza.", 130, 11.90}
};








//Limpiar la consola
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcion para mostrar el inventario
void mostrarInventario() {
    moztrarinventario:
    clearConsole();
    cout << "\033[1;34mSeleccione el pasillo que quiere visitar: \033[0m" << endl;
    cout << "1. Bebidas \n2. Frutas y verduras \n3. Despensa seca \n4. Productos Frescos \n5. Productos del Hogar" << endl;

    int pasillo;
    cin >> pasillo;
    if (cin.fail()) {
    cin.clear(); // Limpia el estado de error
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Comando de validacion de datos
    cout << "\033[1;31mENTRADA INVALIDA, INTENTALO DE NUEVO" << endl;
}


    switch(pasillo) {
        case 1: {
    cout << "\033[1;34mPasillo 1: Bebidas:\033[0m" << endl;

    size_t bebidas = sizeproductos - 80;
    for (size_t i = 0; i < bebidas; i++) {
            const auto& producto = productosTienda[i]; //const auto usa el objeto sin copiarlo, se usa para desplegar cada objeto del 1 al 20 del contenedor productos tienda sin copiarlo
        cout << producto.id << ". " << producto.nombre << " - Cantidad: " << producto.cantidad // se imprimen los primeros 20 productos
             << ", Precio: $" << producto.precio << endl;
            }
            break;
    }
        case 2:
            {
    cout << "\033[1;34mPasillo 2: Frutas y Verduras:\033[0m" << endl;

    size_t frutyverd = sizeproductos - 60;
    for (size_t i = 20; i < frutyverd; i++) {
            const auto& producto = productosTienda[i];
        cout << producto.id << ". " << producto.nombre << " - Cantidad: " << producto.cantidad
             << ", Precio: $" << producto.precio << endl;

                                            }
            break;
            }

        case 3:
            {
            cout << "\033[1;34mPasillo 3: Despensa Seca:\033[0m" << endl;

    size_t despensaSeca = sizeproductos - 40;
    for (size_t i = 40; i < despensaSeca; i++) {
            const auto& producto = productosTienda[i];
        cout << producto.id << ". " << producto.nombre << " - Cantidad: " << producto.cantidad
             << ", Precio: $" << producto.precio << endl;

                     }
                     break;
}

         case 4:
            {
            cout << "\033[1;34mPasillo 4: Productos Frescos:\033[0m" << endl;

    size_t productosFrescos = sizeproductos - 20;
    for (size_t i = 60; i < productosFrescos; i++) {
            const auto& producto = productosTienda[i];
        cout << producto.id << ". " << producto.nombre << " - Cantidad: " << producto.cantidad
             << ", Precio: $" << producto.precio << endl;

                     }
                     break;
}

         case 5:
            {
            cout << "\033[1;34mPasillo 5: Productos del Hogar:\033[0m" << endl;

    size_t productosHogar = sizeproductos ;
    for (size_t i = 80; i < productosHogar; i++) {
            const auto& producto = productosTienda[i];
        cout << producto.id << ". " << producto.nombre << " - Cantidad: " << producto.cantidad
             << ", Precio: $" << producto.precio << endl;

                     }
                     break;
}
default:

                system("pause");
                 goto moztrarinventario;
}
}



// Funcion para mostrar el menu
void mostrarMenu() {
    clearConsole();
    cout << "\033[1;34mBIENVENIDO A BART MART\033[0m\n\n";
    cout << "1. INVENTARIO\n2. CARRITO DE COMPRAS \n3. SALIR" << endl;
}









#endif // LIBRERIA_TIENDA_H_INCLUDED
