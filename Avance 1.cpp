//segundo avance :)

#include <iostream>
#include <stdio.h>
#include <math.h> 
#include <conio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using  namespace std;
struct articulos
{
    char nart[20],g[20], c[10];
    string descripcion;
    string consola;
    int item;
    float total,impuesto=1.16,precio;

};
int main()
{
   articulos alta[3];
   int op;
    

    cout << "\t ***MENU DE OPCIONES***" << endl;
        
    cout<< "1.-Alta" << endl;
    cout<< "2.-Modificacion" << endl;
    cout<< "3-Baja" << endl;
    cout<< "4.-Lista" << endl;
    cout<< "5.-Limpiar Pantalla" << endl;
    cout<< "6.-Salir" << endl;
    cin>> op;
    switch(op)
    {
    case 1: //alta
        for (int i = 0; i < 3; i++)
        {
            printf("Item del articulo\n");
            scanf_s("%d", &alta[i].item);
            cin.ignore();
            printf("Ingrese nombre del articulo \n");
            gets_s(alta[i].nart);
            printf("Ingrese una descripcion del articulo \n");
            getline(cin, alta[i].descripcion);
            printf("Ingrese el genero del articulo \n");
            gets_s(alta[i].g);
            rintf("Ingrese la clasificacion del articulo \n");
            gets_s(alta[i].c);
            printf("Ingrese la consola del articulo \n");
            getline(cin, alta[i].consola);
            printf("Ingrese el precio\n");
            scanf_s("%f", &alta[i].precio);
            alta[i].total = alta[i].precio * alta[i].impuesto;
        
       
        
        }
         system("pause");
         return main();
         break;
    case 2:
        break;
    case 3:
        break;
    case 4:

        break;
    case 5:
        system("cls"); // limpiar pantalla
        return main();
        break;
    case 6:
        cout << "adios :)" << endl;
        exit(1); // cierra la pantalla
        break;
    default:
        cout << "Opcion invalida" << endl;
        system("cls");
            return main();
            break;

    }


}

