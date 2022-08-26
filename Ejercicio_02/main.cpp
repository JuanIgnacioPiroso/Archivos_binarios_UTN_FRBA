#include <iostream>
#include <string>
#include <string.h>
using namespace std;

void guardarEnArchivo(FILE *arch);
void leerArchivo(FILE *arch);
void modificarNumero(FILE *arch);

int main()
{

    FILE *arch;

    // guardarEnArchivo(arch);
     leerArchivo(arch);
    // modificarNumero(arch);

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
    arch = fopen("ArchivoValoresFloat3.dat", "rb");
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

void modificarNumero(FILE *arch)
{
    arch = fopen("ArchivoValoresFloat3.dat", "rb+");
    float numero;
    cout << "Ingrese el numero que desea modificar " << endl;
    cin >> numero;
    fseek(arch, sizeof(float) * numero, SEEK_SET);
    fseek(arch, sizeof(float) * (-1), SEEK_CUR);
    cout << "Ingrese el nuevo valor " << endl;
    cin >> numero;
    fwrite(&numero, sizeof(float), 1, arch);
    fclose(arch);
}