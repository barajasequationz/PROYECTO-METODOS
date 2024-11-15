#include <iostream>
#include <string>
using namespace std;

// Estructura para definir un producto
struct Producto {
    int id;
    string nombre;
    int cantidad;
    double precio;
};

// Arreglo de productos iniciales
Producto productosIniciales[100] = {
   {1, "Arroz", 100, 1.20}, {2, "Frijol", 80, 1.50}, {3, "Lentejas", 75, 1.30},
        {4, "Pasta de coditos", 120, 0.80}, {5, "Spaghetti", 110, 0.85},
        {6, "Harina", 90, 0.75}, {7, "Aceite", 70, 2.00}, {8, "Sal", 200, 0.40},
        {9, "Azúcar", 160, 0.60}, {10, "Leche", 140, 1.10}, {11, "Yogurt", 100, 1.30},
        {12, "Mantequilla", 80, 1.50}, {13, "Queso", 70, 2.20}, {14, "Huevos", 90, 1.60},
        {15, "Pan", 130, 0.90}, {16, "Cereal", 100, 2.10}, {17, "Jugo", 70, 1.70},
        {18, "Soda", 150, 1.20}, {19, "Agua", 200, 0.50}, {20, "Café", 80, 1.80},
        {21, "Té", 75, 1.40}, {22, "Chocolate", 90, 1.60}, {23, "Gelatina", 100, 0.70},
        {24, "Mermelada de fresa", 80, 1.10}, {25, "Catsup", 70, 1.30}, {26, "Mostaza", 90, 1.20},
        {27, "Mayonesa", 60, 1.10}, {28, "Salsa picante", 100, 0.90}, {29, "Vinagre", 110, 0.60},
        {30, "Ajo", 120, 0.20}, {31, "Cebolla", 130, 0.30}, {32, "Tomate", 100, 0.50},
        {33, "Zanahoria", 110, 0.40}, {34, "Pimiento", 80, 0.70}, {35, "Pepino", 75, 0.60},
        {36, "Calabaza", 90, 0.45}, {37, "Papas", 120, 0.80}, {38, "Maíz", 110, 0.75},
        {39, "Espinaca", 100, 0.50}, {40, "Lechuga", 140, 0.30}, {41, "Manzana", 130, 1.20},
        {42, "Plátano", 150, 0.40}, {43, "Naranja", 140, 0.50}, {44, "Limón", 110, 0.30},
        {45, "Fresa", 100, 1.50}, {46, "Mango", 90, 1.00}, {47, "Uvas", 80, 2.00},
        {48, "Sandía", 70, 0.90}, {49, "Melón", 75, 1.10}, {50, "Pera", 100, 1.30},
        {51, "Carne de res", 100, 4.50}, {52, "Pollo", 120, 3.00}, {53, "Pescado", 90, 3.50},
        {54, "Camarones", 80, 5.00}, {55, "Salchichas", 110, 2.10}, {56, "Tocino", 90, 2.30},
        {57, "Jamón", 100, 1.90}, {58, "Tortillas", 120, 0.60}, {59, "Galletas", 130, 1.20},
        {60, "Pastel", 80, 2.50}, {61, "Pizza", 60, 3.00}, {62, "Helado", 70, 1.80},
        {63, "Empanadas", 100, 1.70}, {64, "Chile verde", 110, 0.50}, {65, "Chicles", 150, 0.20},
        {66, "Refresco", 200, 1.20}, {67, "Vino", 50, 10.00}, {68, "Cerveza", 100, 1.60},
        {69, "Whiskey", 60, 15.00}, {70, "Vodka", 70, 12.00}, {71, "Smirnoff", 90, 9.00},
        {72, "Jengibre", 90, 0.90}, {73, "Cilantro", 110, 0.40}, {74, "Perejil", 100, 0.30},
        {75, "Romero", 80, 0.50}, {76, "Laurel", 70, 0.30}, {77, "Pasta dental", 120, 1.50},
        {78, "Shampoo", 100, 2.00}, {79, "Jabón", 130, 1.10}, {80, "Detergente", 90, 3.50},
        {81, "Limpiador", 100, 2.70}, {82, "Esponjas", 80, 0.70}, {83, "Papel higiénico", 150, 0.90},
        {84, "Toallas de papel", 120, 1.00}, {85, "Servilletas", 130, 0.50},
        {86, "Cucharas", 100, 0.30}, {87, "Tenedores", 90, 0.30}, {88, "Cuchillos", 80, 0.40},
        {89, "Galletas emperador de limon", 120, 0.80}, {90, "Vasos", 110, 0.70}, {91, "Dr pepper", 60, 5.50},
        {92, "Sartenes", 70, 4.50}, {93, "Bacardi", 90, 11.00}, {94, "Manteca", 100, 1.10},
        {95, "Hielo", 80, 0.20}, {96, "Carbón", 60, 2.30}, {97, "Palomitas", 90, 1.20},
        {98, "Almendras", 100, 3.10}, {99, "Nueces", 110, 3.50}, {100, "Cacahuates", 130, 1.90}
};



// Variables globales para el carrito
const int MAX_PRODUCTOS_CARRITO = 10;
string nombresCarrito[MAX_PRODUCTOS_CARRITO];
double preciosCarrito[MAX_PRODUCTOS_CARRITO];
int cantidadesCarrito[MAX_PRODUCTOS_CARRITO];
int numProductosCarrito = 0;

// Función para limpiar la consola
void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

double calcularTotal(double impuesto = 0.16, double descuento = 0.0) {
    double total = 0;
    for (int i = 0; i < numProductosCarrito; i++) {
        total += preciosCarrito[i] * cantidadesCarrito[i];
    }
    total += total * impuesto;  // Añadir impuestos
    total -= total * descuento;  // Aplicar descuento
    return total;
}

// Función para mostrar el inventario
void mostrarInventario() {
    clearConsole();
    cout << "\033[1;34mINVENTARIO DE PRODUCTOS:\033[0m" << endl;
    for (const auto& producto : productosIniciales) {
        cout << producto.id << ". " << producto.nombre << " - Cantidad: " << producto.cantidad
             << ", Precio: $" << producto.precio << endl;
    }
}

// Función para agregar un producto al carrito
void agregarAlCarrito(int id, int cantidad) {
    if (numProductosCarrito < MAX_PRODUCTOS_CARRITO) {
        nombresCarrito[numProductosCarrito] = productosIniciales[id - 1].nombre;
        preciosCarrito[numProductosCarrito] = productosIniciales[id - 1].precio;
        cantidadesCarrito[numProductosCarrito] = cantidad;
        cout << "\033[1;32m" << productosIniciales[id - 1].nombre << " agregado al carrito.\033[0m" << endl;
        numProductosCarrito++;
    } else {
        cout << "\033[1;31mCARRITO LLENO.\033[0m" << endl;
    }
}

// Función para mostrar los productos en el carrito
void mostrarCarrito() {
    clearConsole();
    cout << "\033[1;34mPRODUCTOS EN EL CARRITO:\033[0m" << endl;
    for (int i = 0; i < numProductosCarrito; i++) {
        cout << "- " << nombresCarrito[i] << ": $" << preciosCarrito[i] << " x" << cantidadesCarrito[i] << endl;
    }

    // Calcular y mostrar el total
    double total = calcularTotal();
    cout << "\nTotal: $" << total << endl;

    char opcionPAGAR;
    cout << "\nDESEAS PAGAR TU CARRITO? (S/N): ";
    cin >> opcionPAGAR;

    if (opcionPAGAR == 'S' || opcionPAGAR == 's') {
        clearConsole();

        int op;
        cout << "DE QUE FORMA QUIERES PAGAR?\n1. EFECTIVO EN TU TIENDA MAS CERCANA\n2. TARJETA DE CREDITO/DEBITO" << endl;
        cin >> op;

        switch (op) {
            case 1: {
                clearConsole();
                cout << "\033[1;32mTU ORDEN HA SIDO PROCESADA. TIENES 48 HORAS PARA PAGAR UN TOTAL DE $" << total << " EN EFECTIVO EN TU TIENDA MAS CERCANA; DE LO CONTRARIO, TU ORDEN SERA CANCELADA.\033[0m" << endl;
                break;
            }
            case 2: {
                clearConsole();

                string numTarj;
                int mes, year;

                // VALIDACION DEL NUMERO DE TARJETA
                cout << "INGRESE EL NUMERO DE TARJETA (16 DIGITOS): ";
                cin >> numTarj;

                while (numTarj.length() != 16) {
                    clearConsole();
                    cout << "\033[1;31mNUMERO INVALIDO. INGRESE UN NUMERO DE TARJETA VALIDO DE 16 DIGITOS:\033[0m ";
                    cin >> numTarj;
                }

                // FECHA DE VENCIMIENTO
                cout << "INGRESE EL MES DE VENCIMIENTO (MM): ";
                cin >> mes;
                cout << "INGRESE EL ANO DE VENCIMIENTO (AA): ";
                cin >> year;

                // CONFIRMACION DE PAGO
                cout << "\033[1;32mSE REALIZARA EL PAGO DE $" << total << " CON LA TARJETA QUE TERMINA EN " << numTarj.substr(12, 4) << "\033[0m" << endl;
                cout << "CONFIRMAR PAGO? (S/N): ";
                char confirm;
                cin >> confirm;

                if (confirm == 'S' || confirm == 's') {
                    clearConsole();
                    cout << "\033[1;32mCOMPRA CONFIRMADA. GRACIAS POR SU COMPRA!\033[0m" << endl;
                } else {
                    clearConsole();
                    cout << "\033[1;31mCOMPRA RECHAZADA, INTENTE DE NUEVO.\033[0m" << endl;
                }
                break;
            }

            default:
                cout << "\033[1;31mOPCION DE PAGO NO VALIDA.\033[0m" << endl;
                break;
        }
    } else {
        cout << "\033[1;33mVOLVIENDO AL MENU PRINCIPAL.\033[0m" << endl;
    }

    system("pause");  // PAUSA PARA QUE EL USUARIO VEA EL CARRITO Y EL TOTAL
}


// Función principal del menú
void mostrarMenu() {
    clearConsole();
    cout << "\033[1;34mMENU DE TIENDA\033[0m\n\n";
    cout << "1. INVENTARIO\n2. CARRITO DE COMPRAS \n3. SALIR" << endl;
}

// Programa principal
int main() {
    int opcion;
    bool salir = false;

    while (!salir) {
        mostrarMenu();
        cout << "\nSELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                mostrarInventario();
                int id, cantidad;

                cout << "\nIngrese el ID del producto para agregar al carrito: ";
                cin >> id;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;
                agregarAlCarrito(id, cantidad);
                system("pause");
                break;
            }
            case 2:
                mostrarCarrito();
                system("pause");
                break;
            case 3:
                clearConsole();
                cout << "\033[1;31mSALIENDO...\033[0m" << endl;
                salir = true;
                break;
            default:
                cout << "\033[1;31mOPCION NO VALIDA.\033[0m" << endl;
                system("pause");
        }
    }

    return 0;
}
