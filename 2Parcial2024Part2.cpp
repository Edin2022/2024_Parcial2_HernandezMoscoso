/*
 crear una funcion que agrue texto a los archivos creadps, los archivos deben de tener la misma cantidad de lineas segun
 su numero de archivos


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

void crearArchivo(const string& directorio, int numero, int lineasPorArchivo) {
    string nombreArchivo = directorio + "/file" + to_string(numero) + ".txt";
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (int i = 0; i < lineasPorArchivo; ++i) {
            archivo << "Línea " << i+1 << " del archivo " << numero << endl;
        }
        archivo.close();
        cout << "Se ha creado el archivo '" << nombreArchivo << "' con " << lineasPorArchivo << " líneas." << endl;
    } else {
        cerr << "Error al crear el archivo: " << nombreArchivo << endl;
    }
}

void crearArchivos() {
    int cantidadArchivos;
    cout << "¿Cuántos archivos desea crear? ";
    cin >> cantidadArchivos;

    int lineasPorArchivo;
    cout << "¿Cuántas líneas debe tener cada archivo? ";
    cin >> lineasPorArchivo;

    string directorio = obtenerDirectorio(cantidadArchivos);
    crearDirectorio(directorio);

    for (int i = 1; i <= cantidadArchivos; ++i) {
        crearArchivo(directorio, i, lineasPorArchivo);
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