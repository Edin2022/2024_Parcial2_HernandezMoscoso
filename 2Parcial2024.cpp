/*
 Crear  una una funcion que pregunte al usuario cuantos archivos desea crear, si la cantidad de archivos a crear es par
 los archivos debe almacenarlos en el direcotrio de "Escritorio" y subcarpeta "par", de lo contrario directorio si el numero proporcionado por el usuario es impar los
 archivos debe almacernarlos en el mismo directorio en una carpeta llamada "impar", los archivos deben de tener el nombre con el siguiente formatio file1, file2



 C:\Users\rexyr\OneDrive\Escritorio\par

 C:\Users\rexyr\OneDrive\Escritorio\impar


 */



#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

string obtenerDirectorio(int cantidadArchivos) {
    string directorioBase = "C:/Users/rexyr/OneDrive/Escritorio/";
    if (cantidadArchivos % 2 == 0) {
        return directorioBase + "par";
    } else {
        return directorioBase + "impar";
    }
}

void crearDirectorio(const string& directorio) {
    if (!fs::exists(directorio)) {
        fs::create_directories(directorio);
    }
}

void crearArchivo(const string& directorio, int numero) {
    string nombreArchivo = directorio + "/file" + to_string(numero) + ".txt";
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << "Contenido del archivo " << numero << endl;
        archivo.close();
        cout << "Se ha creado el archivo '" << nombreArchivo << "'" << endl;
    } else {
        cerr << "Error al crear el archivo: " << nombreArchivo << endl;
    }
}

void crearArchivos() {
    int cantidadArchivos;
    cout << "¿Cuántos archivos desea crear? ";
    cin >> cantidadArchivos;

    string directorio = obtenerDirectorio(cantidadArchivos);
    crearDirectorio(directorio);

    for (int i = 1; i <= cantidadArchivos; ++i) {
        crearArchivo(directorio, i);
    }

    cout << "Se han creado " << cantidadArchivos << " archivos en el directorio '" << directorio << "'." << endl;
}

void mostrarMenu() {
    cout << "Menu:\n";
    cout << "1. Crear archivos\n";
    cout << "2. Salir\n";
    cout << "Ingrese el número de la opción que desee: ";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1:
                crearArchivos();
                break;
            case 2:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
        }
    } while (opcion != 2);

    return 0;
}