#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno
{
    char nombre[30];
    char apellido[30];
    int legajo;
    int dni;
    int fechaNacimiento;
};

int main()
{
    FILE *arch = fopen("alumnos.dat", "wb");
    Alumno alumn;
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese nombre: ";
        cin.getline(alumn.nombre, 30);
        cout << "Ingrese apellido: ";
        cin.getline(alumn.apellido, 30);
        cout << "Ingrese legajo: ";
        cin >> alumn.legajo;
        cout << "Ingrese dni: ";
        cin >> alumn.dni;
        cout << "Ingrese fecha de nacimiento: ";
        cin >> alumn.fechaNacimiento;
        cin.ignore();
        fwrite(&alumn, sizeof(Alumno), 1, arch);
    }

    
    fclose(arch);

    arch = fopen("alumnos.dat", "rb");

    while (fread(&alumn, sizeof(Alumno), 1, arch))
    {
        cout << alumn.nombre << endl;
        cout << alumn.apellido << endl;
        cout << alumn.legajo << endl;
        cout << alumn.dni << endl;
        cout << alumn.fechaNacimiento << endl;
        cout << "-----------------" << endl;
    }

}