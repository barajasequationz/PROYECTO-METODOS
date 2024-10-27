#include <iostream>

using namespace std;

int main()
{
    int op;
    cout << "De que forma quieres pagar? \n 1. Efectivo en tu Tienda mas cercana \n 2. Tarjeta de credito / debito " << endl;
    cin >> op;

   switch(op){
   case 1:
       cout << "Tu orden ha sido procesada. Tienes 48 horas para pagar un total de " << /*total*/ << " en efectivo en tu tienda mas cercana, de lo contrario, tu orden sera cancelada. ";
       break;

   case 2:

       int mes;
       int numTarj;
       int year;
        cout << "Ingrese el numero de tarjeta"; // hacer un cilo para que el numero ingresado forzosamente sean de 16 digitos

        cout << "Ingrese fecha de vencimiento con el formato MM/AA" << endl;
        cout << "Ingrese el mes" << endl; // agregar un if statement o un ciclo para verificar que se ingrese un mes y año correctos
        cin >> mes;
        cout << "Ingrese el año" << endl;
        cin >> year;

        cout << "Se realizara el pago de " << /*total*/ << " con la tarjeta que termina en los numeros " /* ultimos 4 num */ << endl; // hallar la forma de que tomar los ultimos 4 digitos del numero que ingrese el usuario
        cout << " Confirmar pago? s/n" << endl;
        char confirm;
        cin >> confirm;
        switch(confirm){
            case 's':
      cout <<  "Compra confirmada. Muchas gracias por su compra.";
            break;
            case 'n':
               cout << "Compra rechazada, intente de nuevo";
                break;




        }

   }
/* hacer todo esto un ciclo*/






    return 0;

}
