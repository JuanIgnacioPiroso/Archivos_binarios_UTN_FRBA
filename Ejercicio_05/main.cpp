#include <iostream>
#include <stdio.h>
using namespace std;

void apareoDescendente(char namefile1[], char namefile2[], char namefileout[]);
void burbujaDescendenteArchivos(char ruta_archivo[], int cant);

int main()
{
    FILE *arch1;
    FILE *arch2;
    int x1, x2;

    // ARCHIVO 1

    arch1 = fopen("arch1.dat", "wb");
    int v[] = {2, 8, 11, 86};
    fwrite(v, sizeof(int), 4, arch1);
    fclose(arch1);

    // ARCHIVO 2

    arch2 = fopen("arch2.dat", "wb");
    int w[] = {3, 50, 100};
    fwrite(w, sizeof(int), 3, arch2);
    fclose(arch2);

    FILE *salida;
    burbujaDescendenteArchivos("arch1.dat", 4);
    burbujaDescendenteArchivos("arch2.dat", 3);
    apareoDescendente("arch1.dat", "arch2.dat", "salida.dat");

    FILE *arch4;

    arch4 = fopen("salida.dat", "rb");
    while (fread(&x1, sizeof(int), 1, arch4))
    {
        cout << x1 << endl;
    }

    return 0;
}

void burbujaDescendenteArchivos(char ruta_archivo[], int cant)
{
    FILE *arch;
    arch = fopen(ruta_archivo, "rb+");
    int aux;
    int num1, num2;
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < cant - 1; j++)
        {
            fseek(arch, j * sizeof(int), SEEK_SET);
            fread(&num1, sizeof(int), 1, arch);
            fread(&num2, sizeof(int), 1, arch);
            if (num1 < num2)
            {
                fseek(arch, (-2) * sizeof(int), SEEK_CUR);
                fwrite(&num2, sizeof(int), 1, arch);
                fwrite(&num1, sizeof(int), 1, arch);
            }
        }
    }
    fclose(arch);
}

void apareoDescendente(char ruta_archivo1[], char ruta_archivo2[], char ruta_archivosalida[])
{
    FILE *f1, *f2, *salida;
    f1 = fopen(ruta_archivo1, "rb");
    f2 = fopen(ruta_archivo2, "rb");
    salida = fopen(ruta_archivosalida, "wb");
    int num1, num2;
    while (fread(&num1, sizeof(int), 1, f1) && fread(&num2, sizeof(int), 1, f2))
    {
        if (num1 > num2)
        {
            fwrite(&num1, sizeof(int), 1, salida);
            fseek(f2, (-1) * sizeof(int), SEEK_CUR);
        }
        else
        {
            fwrite(&num2, sizeof(int), 1, salida);
            fseek(f1, (-1) * sizeof(int), SEEK_CUR);
        }
    }
    while (!feof(f1))
    {
        fread(&num1, sizeof(int), 1, f1);
        fwrite(&num1, sizeof(int), 1, salida);
    }
    while (!feof(f2))
    {
        fread(&num2, sizeof(int), 1, f2);
        fwrite(&num2, sizeof(int), 1, salida);
    }
    fclose(f1);
    fclose(f2);
    fclose(salida);
}