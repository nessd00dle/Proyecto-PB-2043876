//segundo avance :)

#include <iostream>
#include <stdio.h>
#include <math.h> 
#include <conio.h>
#include <string.h>
#include <string>
#include <wchar.h>
#include <stdlib.h>
using  namespace std;

struct Articulo
{
    int item;
    float total, precio;
    char nart[20];
    char g[20];
    char c[10];
    string descripcion;
    string consola;
    float impuesto=1.16;
};


int main()
{
    Articulo alta[3];
    int op;

    do
    {
    printf("\t ***MENU DE OPCIONES***\n");

    printf("1.-Alta\n");
    printf("\n2.-Modificacion\n");
    printf("\n3-Baja\n");
    printf("\n4.-Lista\n"); 
    printf("\n5.-Limpiar Pantalla\n");
    printf(  "\n6.-Salir\n") ;
    scanf_s("%d", & op);
    switch (op)
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
            printf("Ingrese la clasificacion del articulo \n");
            gets_s(alta[i].c);
            printf("Ingrese la consola del articulo \n");
            getline(cin, alta[i].consola);
            printf("Ingrese el precio\n");
            scanf_s("%f", &alta[i].precio);
            alta[i].total = alta[i].precio * alta[i].impuesto;



        }
        system("pause");
        
        break;
    case 2:
        break;
    case 3:
        break;
    case 4://Lista
        for (int i = 0; i < 3; i++)
        {
            printf("Item del artculo % d \n", alta[i].item);
            printf("Nombre del articulo: %s \n", alta[i].nart);
            printf("Descripcion: %s \n", alta[i].descripcion.c_str());
            printf("Genero: %s \n", alta[i].g);
            printf("Clasificacion: %s \n", alta[i].c);
            printf("Consola: %s \n", alta[i].consola.c_str());
            printf("Precio %f \n", alta[i].precio);
            printf("Precio con impuesto %f \n", alta[i].total);

        }
    

        break;
    case 5:
        system("cls"); // limpiar pantalla
        
        break;
    case 6:
        printf( "adios :)\n ") ;
        exit(1); // cierra la pantalla
        break;
    default:
        printf("Opcion invalida\n" );
        system("cls");
       
        break;

    }
    } while (op != 6);

}