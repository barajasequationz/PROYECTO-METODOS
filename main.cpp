#include <iostream>
#include <string>
#include <limits>
#include "libreria_tienda.h"
using namespace std;





// Variables globales para el carrito
const int MAX_PRODUCTOS_CARRITO = 10;
string nombresCarrito[MAX_PRODUCTOS_CARRITO];
double preciosCarrito[MAX_PRODUCTOS_CARRITO];
int cantidadesCarrito[MAX_PRODUCTOS_CARRITO];
int numProductosCarrito = 0;



double calcularTotal(double impuesto = 0.16, double descuento = 0.0) {
    double total = 0;
    for (int i = 0; i < numProductosCarrito; i++) {
        total += preciosCarrito[i] * cantidadesCarrito[i];
    }
    total += total * impuesto;  // A�adir impuestos
    total -= total * descuento;  // Aplicar descuento
    return total;
}


// Funcion para mostrar los productos en el carrito y elegir si quieres pagar o no
void mostrarCarrito() {
    clearConsole();
    cout << "\033[1;34mPRODUCTOS EN EL CARRITO:\033[0m" << endl;
    for (int i = 0; i < numProductosCarrito; i++) {
        cout << "- " << nombresCarrito[i] << ": $" << preciosCarrito[i] << " x" << cantidadesCarrito[i] << endl;
    }

    // Calcular y mostrar el total
    double total = calcularTotal();
    cout << "\nTotal: $" << total << endl;
    // Opcion de pago
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

// Funcion para agregar un producto al carrito
void agregarAlCarrito(int id, int cantidad) {
    if (numProductosCarrito < MAX_PRODUCTOS_CARRITO) {
        nombresCarrito[numProductosCarrito] = productosTienda[id - 1].nombre;
        preciosCarrito[numProductosCarrito] = productosTienda[id - 1].precio;
        cantidadesCarrito[numProductosCarrito] = cantidad;
        cout << "\033[1;32m" << productosTienda[id - 1].nombre << " agregado al carrito.\033[0m" << endl;
        numProductosCarrito++;
    } else {
        cout << "\033[1;31mCARRITO LLENO.\033[0m" << endl;
    }
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
                char opcionAGREGAR;



                cout << "\nDESEAS AGREGAR UN PRODUCTO A TU CARRITO? (S/N): ";
    cin >> opcionAGREGAR;
    if (opcionAGREGAR == 'S' || opcionAGREGAR == 's') {

        }
        else { break;}


                cout << "\nIngrese el ID del producto para agregar al carrito: ";
                cin >> id;
                cout << "Ingrese la cantidad: ";
                cin >> cantidad;
                agregarAlCarrito(id, cantidad);
                system("pause");
                break;
            }
            case 2:{
                mostrarCarrito();

              break;  }

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
