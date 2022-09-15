#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno
{
    char nombre[30];
    char apellido[20];
    int legajo;
    int dni;
    int fechaNacimiento;
};

void agregarunAlumno(char ruta_archivo[]);
void mostrarAlumnos(char ruta_archivo[]);
void buscarAlumnoLegajo(char ruta_archivo[], int legajo);
void buscarAlumnoDni(char ruta_archivo[], int dni);
void ordernarArchivoPorLegajo(char ruta_archivo[]);

int main()
{
    int legajo;
    int dni;

    FILE *archivo;
    int opcion;

    do
    {
        cout << "Ingrese una opcion del menu: " << endl;
        cout << "1. Ingresar datos de un alumno" << endl;
        cout << "2. Mostrar datos de todos los alumnos" << endl;
        cout << "3. Buscar alumno por legajo" << endl;
        cout << "4. Buscar alumno por dni" << endl;
        cout << "5. Ordenar archivo por legajo" << endl;
        cout << "6. Salir" << endl;

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            agregarunAlumno("alumnos.dat");
            break;
        case 2:
            mostrarAlumnos("alumnos.dat");
            break;
        case 3:
            cout << "Ingrese el legajo del alumno a buscar: " << endl;
            cin >> legajo;
            buscarAlumnoLegajo("alumnos.dat", legajo);
            break;
        case 4:
            cout << "Ingrese el dni del alumno a buscar: " << endl;
            cin >> dni;
            buscarAlumnoDni("alumnos.dat", dni);
            break;
        case 5:

            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } 
    while (opcion != 6);
}


void agregarunAlumno(char ruta_archivo[])
{

    Alumno alumno;
    FILE *archivo;
    archivo = fopen(ruta_archivo, "ab");
    cout << "Ingrese el nombre del alumno: " << endl;
    cin >> alumno.nombre;
    cout << "Ingrese el apellido del alumno: " << endl;
    cin >> alumno.apellido;
    cout << "Ingrese el legajo del alumno: " << endl;
    cin >> alumno.legajo;
    cout << "Ingrese el dni del alumno: " << endl;
    cin >> alumno.dni;
    cout << "Ingrese la fecha de nacimiento del alumno: " << endl;
    cin >> alumno.fechaNacimiento;
    fwrite(&alumno, sizeof(Alumno), 1, archivo);
    fclose(archivo);
}

void mostrarAlumnos(char ruta_archivo[])
{
    Alumno alumno;
    FILE *archivo;
    archivo = fopen(ruta_archivo, "rb");
    fread(&alumno, sizeof(Alumno), 1, archivo);
    while (!feof(archivo))
    {
        cout << "Nombre: " << alumno.nombre << endl;
        cout << "Apellido: " << alumno.apellido << endl;
        cout << "Legajo: " << alumno.legajo << endl;
        cout << "DNI: " << alumno.dni << endl;
        cout << "Fecha de nacimiento: " << alumno.fechaNacimiento << endl;
        cout << "---------------------------------" << endl;
        fread(&alumno, sizeof(Alumno), 1, archivo);
    }
    fclose(archivo);
}

void buscarAlumnoLegajo(char ruta_archivo[], int legajo)
{
    Alumno alumno;
    FILE *archivo;
    archivo = fopen(ruta_archivo, "rb");
    fread(&alumno, sizeof(Alumno), 1, archivo);
    while (!feof(archivo))
    {
        if (alumno.legajo == legajo)
        {
            cout << "Nombre: " << alumno.nombre << endl;
            cout << "Apellido: " << alumno.apellido << endl;
            cout << "Legajo: " << alumno.legajo << endl;
            cout << "DNI: " << alumno.dni << endl;
            cout << "Fecha de nacimiento: " << alumno.fechaNacimiento << endl;
        }
        fread(&alumno, sizeof(Alumno), 1, archivo);
    }
    fclose(archivo);
}

void buscarAlumnoDni(char ruta_archivo[], int dni)
{
    Alumno alumno;
    FILE *archivo;
    archivo = fopen(ruta_archivo, "rb");
    fread(&alumno, sizeof(Alumno), 1, archivo);
    while (!feof(archivo))
    {
        if (alumno.dni == dni)
        {
            cout << "Nombre: " << alumno.nombre << endl;
            cout << "Apellido: " << alumno.apellido << endl;
            cout << "Legajo: " << alumno.legajo << endl;
            cout << "DNI: " << alumno.dni << endl;
            cout << "Fecha de nacimiento: " << alumno.fechaNacimiento << endl;
        }
        fread(&alumno, sizeof(Alumno), 1, archivo);
    }
    fclose(archivo);
}
