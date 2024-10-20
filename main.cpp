/* Sergio Jr. Barajas Montes y Emiliano Coronel Regalado
Calculadora del Indice de Masa Corporal
30/09/24 */

#include <iostream>

using namespace std;

int main()
{
    //INICIALIZAR VARIABLES
    float peso = 0;
    float altura = 0;
    float imc = 0;


    std::cout << "Calcula tu IMC: " << std::endl;
    std::cout << "Ingresa tu altura en METROS: " << std::endl;
    std::cin >> altura;
    std::cout << "Ingresa tu peso en KG: " << std::endl;
    std::cin >> peso;

//calcular imc
    imc = peso / (altura * altura);

    if(imc < 18.5){
        std::cout << "Tu imc es: " << imc << " Come mas bro, vas a desaparecer" <<std::endl;
    }else
        if(imc < 25){
        std::cout << "Tu imc es: " << imc << " Felicidades, estas balanceado!" <<std::endl;
    }else
        if(imc < 30){
        std::cout << "Tu imc es: " << imc << " Baja un poco mas, tu puedes!" <<std::endl;
    }else{
        std::cout << "Tu imc es: " << imc << " Echale ganas, hay que bajarle un poco a las de harina" <<std::endl;
    }


    return 0;
}
