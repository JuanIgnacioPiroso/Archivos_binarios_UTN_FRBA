#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void guardarEnArchivo(FILE *arch);
void leerArchivo(FILE *arch);

int main()
{

    FILE *arch;

    guardarEnArchivo(arch);
    leerArchivo(arch);

    return 0;
}

void guardarEnArchivo(FILE *arch)
{
    arch = fopen("ArchivoValoresFloat3.dat", "wb");

    int n = 0;
    int i = 0;
    float numero = 0;

    cout << "Ingrese el numero de valores float que desea ingresar " << endl;
    cin >> n;

    while (i < n)
    {
        cout << "Ingrese un valor float " << endl;
        cin >> numero;

        fwrite(&numero, sizeof(float), 1, arch);
        i++;
    }

    rewind(arch);
    fclose(arch);
}

void leerArchivo(FILE *arch)
{
    arch = fopen("ArchivoValoresFloat2.dat", "rb");
    float numero;
    cout << "Los valores ingresados son: " << endl;
    fread(&numero, sizeof(float), 1, arch);

    while (!feof(arch))
    {

        cout << "Valor leido: " << numero << endl;
        fread(&numero, sizeof(float), 1, arch);
    }

    fclose(arch);
}