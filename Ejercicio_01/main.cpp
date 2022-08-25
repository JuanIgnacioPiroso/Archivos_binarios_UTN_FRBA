#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{

    FILE *arch = fopen("ArchivoValoresFloat.dat", "wb+");
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
    cout << "Los valores ingresados son: " << endl;
    fread(&numero, sizeof(float), 1, arch);
    while (!feof(arch))
    {

        cout << "Valor leido: " << numero << endl;
        fread(&numero, sizeof(float), 1, arch);
    }

    fclose(arch);

    return 0;
}