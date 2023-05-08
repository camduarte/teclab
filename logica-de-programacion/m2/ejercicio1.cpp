/* Ejercicio 1
 * Escribir en lenguaje C un programa que nos indique si una letra es una vocal o
 * no.
 * 1. Pida por teclado una letra del abecedario.
 * 2. Muestre por pantalla:
 * a. “Es una vocal”.
 * b. “No es una vocal”.
 * Nota: Se pueden ingresar letras minúsculas y mayúsculas.
 */

#include <iostream>

using namespace std;

int main()
{
    char vocales[] = {'a','e','i','o','u','A','E','I','O','U'};
    char letra;
    cout << "Ingrese una letra: ";
    cin >> letra;

    for(char vocal : vocales) 
    {
        if(vocal == letra)
        {
            cout << "Es una vocal." << endl;
	    return 0;
        }
    }

    cout << "No es una vocal." << endl;
    return 0;
}
