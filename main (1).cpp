#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

const int MAX_PRODUCTOS = 10; // CAPACIDAD MAXIMA DEL CARRITO

string nombres[MAX_PRODUCTOS];  // NOMBRES DE LOS PRODUCTOS
double precios[MAX_PRODUCTOS];  // PRECIOS DE LOS PRODUCTOS
int cantidades[MAX_PRODUCTOS];  // CANTIDADES DE CADA PRODUCTO
int numProductos = 0;           // NUMERO ACTUAL DE PRODUCTOS EN EL CARRITO

// AGREGAR UN PRODUCTO AL CARRITO
void agregarProducto(string nombre, double precio, int cantidad) {
    if (numProductos < MAX_PRODUCTOS) {
        nombres[numProductos] = nombre;
        precios[numProductos] = precio;
        cantidades[numProductos] = cantidad;
        cout << "\033[1;32m" << nombre << " AGREGADO AL CARRITO.\033[0m" << endl;
        numProductos++;
    } else {
        cout << "\033[1;31mCARRITO LLENO.\033[0m" << endl;
    }
}

// ELIMINAR UN PRODUCTO DEL CARRITO POR SU NOMBRE
void eliminarProducto(string nombre) {
    for (int i = 0; i < numProductos; i++) {
        if (nombres[i] == nombre) {
            cout << "\033[1;31m" << nombres[i] << " ELIMINADO DEL CARRITO.\033[0m" << endl;
            for (int j = i; j < numProductos - 1; j++) {
                nombres[j] = nombres[j + 1];
                precios[j] = precios[j + 1];
                cantidades[j] = cantidades[j + 1];
            }
            numProductos--;
            return;
        }
    }
    cout << "\033[1;33mPRODUCTO NO ENCONTRADO.\033[0m" << endl;
}

// MOSTRAR PRODUCTOS EN EL CARRITO
void mostrarCarrito() {
    cout << "\033[1;34mPRODUCTOS EN EL CARRITO:\033[0m" << endl;
    for (int i = 0; i < numProductos; i++) {
        cout << "- " << nombres[i] << ": $" << precios[i] << " x" << cantidades[i] << endl;
    }
}

// CALCULAR EL TOTAL CON IMPUESTO Y DESCUENTO
double calcularTotal(double impuesto = 0.16, double descuento = 0.0) {
    double total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i] * cantidades[i];
    }
    total += total * impuesto;
    total -= total * descuento;
    return total;
}

// MOSTRAR EL MENU PRINCIPAL
void mostrarMenu() {
    clearConsole();
    cout << "\033[1;34mMENU DE TIENDA\033[0m\n\n";
    cout << "1. CARRITO DE COMPRAS\n2. INVENTARIO\n3. SALIR" << endl;
}

int main() {
    int opcion = 0;
    bool salir = false;

    while (!salir) {
        mostrarMenu();
        cout << "\n\nSELECCIONE UNA OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                clearConsole();
                agregarProducto("MANZANA", 1.50, 3);
                agregarProducto("LECHE", 2.30, 1);
                mostrarCarrito();

                double total = calcularTotal(0.16, 0.10);
                cout << "\033[1;32mTOTAL DE SU COMPRA EN BARAJAS SHOP: $" << total << "\033[0m" << endl;

                eliminarProducto("MANZANA");
                mostrarCarrito();

                // CONFIRMACION DE PAGO
                char opcionPAGAR;
                cout << "DESEAS PAGAR TU CARRITO? (S/N): ";
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
                break;
            }
            case 3: {
                clearConsole();
                cout << "\033[1;31mSALIENDO...\033[0m" << endl;
                salir = true;
                break;
            }
            default: {
                clearConsole();
                cout << "\033[1;31mOPCION NO VALIDA, POR FAVOR SELECCIONA UNA OPCION VALIDA.\033[0m" << endl;
                system("pause");
            }
        }
    }

    return 0;
}
