/* Ivan Rodriguez, Consulta de inventario*/
#include <iostream> <strings>


using namespace std;

int main()
{ const int MAX_PRODUCTOS = 100;

struct Producto {
    int id;
    string nombre;
    int cantidad;
    double precio;
};
Producto inventario[MAX_PRODUCTOS];
int totalProductos = 0;


void agregarProducto(); {
    if (totalProductos >= MAX_PRODUCTOS) {
        cout << "Inventario lleno, no se puede agregar más productos." << endl;

        return


    //cout << "Ingrese ID del producto: ";
    cin >> inventario[totalProductos].id;
    cout << "Ingrese nombre del producto: ";
    cin >> inventario[totalProductos].nombre;
    cout << "Ingrese cantidad del producto: ";
    cin >> inventario[totalProductos].cantidad;
    cout << "Ingrese precio del producto: ";
    cin >> inventario[totalProductos].precio;

    totalProductos++;
    cout << "Producto agregado correctamente." << endl;
}
void eliminarProducto() {
    int id;
    cout << "Ingrese ID del producto a eliminar: ";
    cin >> id;

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].id == id) {
            for (int j = i; j < totalProductos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            totalProductos--;
            cout << "Producto eliminado correctamente." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void modificarProducto() {
    int id;
    cout << "Ingrese ID del producto a modificar: ";
    cin >> id;

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].id == id) {
            cout << "Ingrese nuevo nombre del producto: ";
            cin >> inventario[i].nombre;
            cout << "Ingrese nueva cantidad del producto: ";
            cin >> inventario[i].cantidad;
            cout << "Ingrese nuevo precio del producto: ";
            cin >> inventario[i].precio;
            cout << "Producto modificado correctamente." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

    void consultarInventario() {
    if (totalProductos == 0) {
        cout << "Inventario vacío." << endl;
        return;
    }

    cout << "ID\tNombre\tCantidad\tPrecio" << endl;
    for (int i = 0; i < totalProductos; i++) {
        cout << inventario[i].id << "\t" << inventario[i].nombre << "\t"
             << inventario[i].cantidad << "\t" << inventario[i].precio << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "\n1. Agregar producto\n2. Eliminar producto\n3. Modificar producto\n4. Consultar inventario\n5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

      switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                eliminarProducto();
                break;
            case 3:
                modificarProducto();
                break;
            case 4:
                consultarInventario();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);



    return 0;
}
