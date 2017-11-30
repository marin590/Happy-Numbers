/*
Autor : Eduardo Rodriguez Marin
Universidad de Guadalajara
Computacion Tolerante a Fallos
Practica 1
*/
#include <iostream>
#include <stack>
#include <math.h>
#include <ctime>
#include <fstream>


using namespace std;

/*Clase principal*/
class programa
{

public:
    void principal();
    void menu();
    unsigned long long int funcionFeliz(stack<unsigned long long int> pila);
    int ultimoDigito(unsigned long long int numero);
    int cantidadDigitos(stack<unsigned long long int> pila);
    bool calculaTiempo(stack<unsigned long long int> pila);
    bool validaResultado(stack<unsigned long long int> resultados, int numero);
    int regresaNumero(int numero);
    bool validaEntrada(stack<unsigned long long int> entrada);
    stack<unsigned long long int> separaDigitos(unsigned long long int numero);
    bool validaOpcion(int opcion);
};

/*Valida la entrada de las opciones del menu*/
bool programa::validaOpcion(int opcion){
    stack<int> pilaEnteros;
    while(opcion > 0){
        opcion /= 10;
        pilaEnteros.push(opcion);
    }
    if(pilaEnteros.size() > 1) return false;
    return true;
}

/*Separa el resultado de cada iteracion en digitos*/
stack<unsigned long long int> programa::separaDigitos(unsigned long long int numero)
{
    stack<unsigned long long int> pilaEnteros;
    while (numero > 0)
    {
        int digito = numero%10;
        numero /= 10;
        pilaEnteros.push(digito);
    }
    return pilaEnteros;
}

/*Valida la entrada del usuario*/
bool programa::validaEntrada(stack<unsigned long long int> entero)
{
    while(!entero.empty())
    {
        if(entero.top() == -1)
        {
            cout << "Debe escribir una opcion valida"<<endl;
            return false;
        }
        if(entero.size() == 1 && entero.top() == 0)
        {
            cout << "Debe escribir una opcion valida"<<endl;
            return false;
        }
        entero.pop();
    }
    return true;
}

/*Regresa el caracter del numero que inserta*/
int programa::regresaNumero(int numero)
{
    if(numero == 48) return 0;
    if(numero == 49) return 1;
    if(numero == 50) return 2;
    if(numero == 51) return 3;
    if(numero == 52) return 4;
    if(numero == 53) return 5;
    if(numero == 54) return 6;
    if(numero == 55) return 7;
    if(numero == 56) return 8;
    if(numero == 57) return 9;
    if(numero == 10) return -2;
    return -1;
}


/*valida el resultado en la pila de resultados*/
bool programa::validaResultado(stack<unsigned long long int> resultado, int numero)
{
    while(!resultado.empty())
    {
        if(resultado.top() == numero)
            return false;
        resultado.pop();
    }
    return true;
}

/*Menu de la aplicacion*/
void programa::menu()
{
    int opc;
    stack<int> pilaEnteros;
    do
    {
        cout << "\nSelecciona la opcion deseada" << endl;
        cout << "1 - Verificar si un numero es feliz" << endl;
        cout << "2 - Salir" << endl;
        //Todo esto solo para validar el menu
        opc = getchar();
        opc = regresaNumero(opc);
        if(opc != -2)
            pilaEnteros.push(opc);
        do
        {
            opc = regresaNumero(getchar());
            if(opc != -2)
                pilaEnteros.push(opc);
        }
        while(opc != -2);


        if(pilaEnteros.size() > 1)
        {
            while(!pilaEnteros.empty()) pilaEnteros.pop();
            cout<<"Inserta una de las opciones mostradas" <<endl;
            continue;
        }
        else
            opc = pilaEnteros.top();

            switch(opc)
            {
            case 1:
                principal();
                while(!pilaEnteros.empty()) pilaEnteros.pop();
                break;
            case 2:
                break;
            default:
                cout << "Elija una opcion correcta" << endl;
                opc = 0;
                break;
            }

    }
    while(opc != 2);

}

/*Calcula la cantidad de digitos*/
int programa::cantidadDigitos(stack<unsigned long long int> pila)
{
    return pila.size();
}
/*Obtiene el la cantidad */
bool programa::calculaTiempo(stack<unsigned long long int> pila)
{
    int opcion;
    time_t inicio = time(0);
    int totalDigitos = pila.size();
    stack<int> pilaEnteros;
    //Calculo el estimado de las iteraciones
    while(totalDigitos < 0) totalDigitos--;

    time_t fin = time(0);
    cout << "\nTiempo total estimado: ";
    cout.precision(2);
    cout << (double)((fin - inicio)*1000.0)<< " sec" << endl;
    do
    {
        cout << "Desea continuar? 1.- Si 2.- No" << endl;
        opcion = getchar();
        opcion = regresaNumero(opcion);
        if(opcion != -2)
            pilaEnteros.push(opcion);
        do
        {
            opcion = regresaNumero(getchar());
            if(opcion != -2)
                pilaEnteros.push(opcion);
        }
        while(opcion != -2);


        if(pilaEnteros.size() > 1)
        {
            while(!pilaEnteros.empty()) pilaEnteros.pop();
            cout<<"Inserta una de las opciones" <<endl;
            continue;
        }
        else
            opcion = pilaEnteros.top();


        if(opcion == 1)
            return true;
        if(opcion == 2)
            return false;
    }
    while(opcion != 2);
    return false;
}

/*Obtiene el ultimo digito de un numero*/
int programa::ultimoDigito(unsigned long long int numero)
{
    return numero % 10;
}

/*Separa los digitos entrados*/
unsigned long long int programa::funcionFeliz(stack<unsigned long long int> pila)
{
//Separamos los digitos del numero y lo metemos a la pila

    unsigned long long int totalSuma = 0;

    while(!pila.empty())
    {
        totalSuma += pow(pila.top(),2);
        pila.pop();
    }

    return totalSuma;
}


/*Funcion principal del programa*/
void programa::principal()
{
    //captamos el numero que se quiere calcular
    unsigned long long int numero = 1;
    int aux;
    stack<unsigned long long int> pilaEnteros;

    do
    {
        while(!pilaEnteros.empty())
        {
            pilaEnteros.pop();
        }
        cout << "Escribe el numero que quieras saber si es feliz" << endl;
        aux = getchar();
        aux = regresaNumero(aux);
        if(aux != -2)
            pilaEnteros.push(aux);
        //Obtenemos todas las entradas hasta el dar el ENTER
        do
        {
            aux = regresaNumero(getchar());
            if(aux != -2)
                pilaEnteros.push(aux);
        }
        while(aux != -2);

    }
    while(!validaEntrada(pilaEnteros));


    //Calculamos el tiempo que tardara el algoritmo
    if (!calculaTiempo(pilaEnteros))
        return;

    bool bandera = true;
    stack<unsigned long long int> resultados;

    cout << "Resultados por iteracion: ";
    do
    {
        numero = funcionFeliz(pilaEnteros);
        cout << numero << " ";
        bandera = validaResultado(resultados, numero);
        resultados.push(numero);
        pilaEnteros = separaDigitos(numero);
    }
    while(ultimoDigito(numero) != 1 && bandera);

    if(!bandera)
        cout << "\nEfectivamente es un numero infeliz :(" << endl;
    else
        cout << "\nEfectivamente es un numero feliz :D" << endl;
}

/*Funcion principal*/
int main()
{
    programa p;
    p.menu();
    return 0;
}
