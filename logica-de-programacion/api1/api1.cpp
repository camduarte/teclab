/*
 * File: api1.cpp
 *
 * Carrera: Tecnicatura Superior en Programación
 * Materia: Lógica de Programación
 * Módulo : 1
 * Título : Actividad Práctica Integradora 1 
 * 
 * Autor  : Christian Ariel Modesto Duarte
 * Fecha  : 27/04/2023
 */

#include <iostream>
#include <random>

using namespace std;

void swap(int* xp, int* yp);

/*
 * Funcion para realizar Selection Sort. Ordena un array de forma ascendente.
 * @param arr El array.
 * @param n El tamaño del array.
 */
void selectionSort(int arr[], int n);

/*
 * Verifica si el número ya fue ingresado por el usuario.
 * @param arr El array con los números ingresados por el usuario.
 * @param tamano El tamaño del array.
 * @param num El número ingresado por el usuario.
 * @return true si el número ingresado por el usuario ya había sido ingresado.
 */
bool verificarNumIngresado(int arr[], int tamano, int num);

/*
 * Juego de adivinanza de números.
*/
int main()
{
    int limiteInferior;
    int limiteSuperior;
    int maxIntentos;
    int numAleatorio;
    int intentosJugados = 0;
    int intentosRestantes;
    int numUsuario;

    cout << endl << "¡Juego de adivinanzas de números!" << endl << endl;

    cout << "Ingrese el límite inferior: ";
    cin >> limiteInferior;

    cout << "Ingrese el límite superior: ";
    cin >> limiteSuperior;

    cout << "Ingrese la cantidad máxima de intentos: ";
    cin >> maxIntentos;

    // Genera el numero aleatorio.
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(limiteInferior, limiteSuperior);
    numAleatorio = distrib(gen);

    // almacena los numeros jugados por el usuario.
    int numJugados[maxIntentos];
    
    // Inicializo la cantidad de intentos restantes
    intentosRestantes = maxIntentos;

    do 
    {
        cout << endl << "¿Cuál es el número secreto?: ";
        cin >> numUsuario;

        // Verifico si el número ingresado ya fue jugado.
        if (!verificarNumIngresado(numJugados, intentosJugados, numUsuario))
        {
            numJugados[intentosJugados] = numUsuario; // Guardo los numeros jugados por el usuario.

            if (numUsuario == numAleatorio)
            {
                cout << "¡Correcto! el número secreto es " << numAleatorio << endl;
                break;
            } else if (numUsuario > numAleatorio)
            {
                cout << "Incorrecto ¡El número secreto es menor!" << endl;
            } else
            {
                cout << "Incorrecto ¡El número secreto es mayor!" << endl;
            }

            intentosJugados++;
            intentosRestantes--;
            cout << "Intentos jugados: " << intentosJugados << endl;
            cout << "Intentos restantes: " << intentosRestantes << endl;

            // Muestro los números jugados por el usuario en orden ascendente.
            selectionSort(numJugados, intentosJugados);
            cout << "Números jugados: ";
            for (int i = 0; i < intentosJugados; i++)
            {
                cout << numJugados[i] << " ";
            }
            cout << endl;       
        } else
        {
            cout << "¡Número ya jugado!" << endl;
        }

    } while (intentosRestantes != 0);

    if (intentosRestantes == 0)
    {
        cout << "¡Perdiste! El número secreto es " << numAleatorio << endl;
    }

    return 0;
}

bool verificarNumIngresado(int arr[], int tamano, int num)
{
    for(int i = 0; i < tamano; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
  
        swap(&arr[min_idx], &arr[i]);
    }
}