#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{

    FILE* arch1 = fopen("arch1.data", "wb");
    FILE* arch2 = fopen("arch2.data", "wb");

    int v[] = { 2, 45, 1, 10, 120 };

    fwrite(v, sizeof(int), 5, arch1);
    fclose(arch1);

    int w[] = { 12, 3, 7 };

    fwrite(w, sizeof(int), 3, arch2);
    fclose(arch2);


    arch1 = fopen("arch1.data", "rb");
    arch2 = fopen("arch2.data", "rb");
    FILE* arch3 = fopen("arch3.data", "wb");
    int numero1, numero2;

    while (fread(&numero1, sizeof(int), 1, arch1) && fread(&numero2, sizeof(int), 1, arch2))
    {
        fwrite(&numero1, sizeof(int), 1, arch3);
        fwrite(&numero2, sizeof(int), 1, arch3);
    }
    while (!feof(arch1))
    {
        fwrite(&numero1, sizeof(int), 1, arch3);
        fread(&numero1, sizeof(int), 1, arch1);
    }
    while (!feof(arch2))
    {
        fwrite(&numero2, sizeof(int), 1, arch3);
        fread(&numero2, sizeof(int), 1, arch2);
    }

    fclose(arch1);
    fclose(arch2);
    rewind(arch3);
    fclose(arch3);

    arch3 = fopen("arch3.data", "rb");
    while (fread(&numero1, sizeof(int), 1, arch3))
    {
        cout << "Valor leido: " << numero1 << endl;
    }

    fclose(arch3);
    
    return 0;
}

