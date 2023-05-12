#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
using  namespace std;
struct Articulo
{
    int item;
    float total, precio;
    char  genero[20],clase[20];
    string descripcion, consola,nombreart,status;
    float impuesto = .16;
};
int alta;
Articulo* TIENDA;
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();

int main()
{
    int op;
	printf("\t%c%c%c MEN%c DE OPCIONES %c%c%c \n",3,3,3,233, 3,3,3);
    printf("1.Alta de art%cculos\n2.Modificar\n3.Baja de art%cculos\n4.Lista de art%cculos\n5.Limpiar pantalla\n6.Salir\n",161,161,161);
	scanf_s("%d", &op);
    switch (op)
    {
    case 1:
        Alta();
        return main();
        break;
	case 2:
		modificar();
		return main();
		break;

	case 3:
		eliminar();
		return main();
		break;
		

	case 4:
		listas();
		return main();
		break;

	case 5:
		system("cls"); //system("clear");
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}
void Alta()
{
	printf("%cCu%Cntos registros desea dar de alta%c \n",168,160,63);
	scanf_s("%d", &alta);
	TIENDA = new Articulo[alta]; // uso de new para hacer el arreglo dinamico
	for (int i = 0; i < alta; i++)
	{

		printf("%cIngrese el item del art%culo\n",16,161); 
		scanf_s("%d", &TIENDA[i].item); 
		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		printf("%cIngrese el nombre del art%culo \n",16,161);
		getline(cin, TIENDA[i].nombreart); //permite los espacios en el nombre
		printf("%cIngrese una descripci%cn del art%cculo \n",16,162,161);
		getline(cin,TIENDA[i].descripcion);
		printf("%cIngrese el g%cnero del art%cculo \n",16,130,161);
		gets_s(TIENDA[i].genero);
		printf("%cIngrese la clasificaci%cn del art%cculo \n",16,162,161);
		gets_s(TIENDA[i].clase);
		printf("%cIngrese la consola del art%cculo \n",16,161);
		getline(cin, TIENDA[i].consola);
		printf("%cIngrese el precio\n",16);
		scanf_s("%f", &TIENDA[i].precio);
	}

}
void modificar()
{
	int j, opcion, op2;
	do
	{
		printf("Ingrese el n%cmero del registro a modificar:", 163);
		scanf_s("%d", &j);
		j = j - 1; // esto debido a que i inicia en 0

		for (int i = j; i == j; i++)
		{
			if ((TIENDA[i].status == "ELIMINADO"))
			{
				printf("REGISTRO ELIMINADO", i + 1);
				printf("Ingrese un registro v%lido \n",160);
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf("%cQu%c desea modificar%c\n 1.-Item del art%cculo\n2.-Nombre del art%cculo\n3.- Descripci%cn\n4.-G%cnero\n5.-Clasificaci%cn\n6.Consola\n7.Precio\n",168,130,63,161,161,162,130,162);
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("%cIngrese el item del art%cculo\n",9,161);
			scanf_s("%d", &TIENDA[i].item);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("%cIngrese nombre del art%cculo\n",9,161);
			getline(cin, TIENDA[i].nombreart);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			printf("%cIngrese la descripcion del art%cculo\n",9,161);
			scanf_s("%f", &TIENDA[i].descripcion);
		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			printf("%cIngrese el genero art%cculo\n",9,161);
			scanf_s("%f", &TIENDA[i].genero);
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			printf("%cIngrese la clasificaci%cn del art%cculo\n",9,162,161);
			scanf_s("%f", &TIENDA[i].clase);
		}
		break;
	case 6:
		for (int i = j; i == j; i++)
		{
			printf("%cIngrese la consola del art%cculo\n",9,161);
			scanf_s("%f", &TIENDA[i].consola);
		}
		break;
	case 7:
		for (int i = j; i == j; i++)
		{
			printf("%cIngrese el precio art%cculo\n",9,161);
			scanf_s("%f", &TIENDA[i].precio);
		}
		break;

	}


}
void eliminar()
{
	int j;
	printf("%cIngrese el  registro a eliminar\n", 15);
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando registro", j + 1);
		TIENDA[i].status = "ELIMINADO";	
    }
}
void listas()
{
	for (int i = 0; i < alta; i++)
	{
		if (TIENDA[i].status == "ELIMINADO")
		{
			printf("REGISTRO ELIMINADO %d \n ", i + 1);
		}
		else
		{
			printf("Registro %d \n",i+1);
			printf("%c%d\n",175, TIENDA[i].item);
			printf("%c%s\n",175, TIENDA[i].nombreart.c_str());
			printf("%c%s\n",175, TIENDA[i].descripcion.c_str());
			printf("%c%s\n",175, TIENDA[i].genero);
			printf("%c%s\n", 175, TIENDA[i].clase);
			printf("%c%f\n",175, TIENDA[i].precio);




		}
	}
}
void archivos()
{
	ofstream archivo; //clase ifstream para leer archivos
	string nombrearchivo;
	int texto;
	float texto3; //preguntar si es correcto declarar un tercer texto para datos flotantes
	string texto2;

	nombrearchivo = "TiendaVidJuegos.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO\n");
		exit(1);
	}
	//preguntar el como poner acentos y figuras en esta parte del código
	archivo << "ITEM" <<"\t";
	archivo << "NOMBRE" << "\t  ";
	archivo << "DESCRIPCIÓN" <<"\t   ";
	archivo << "GÉNERO" <<"\t";
	archivo << "CLASIFICACIÓN" <<"\t";
	archivo << "CONSOLA" << "\t";
	archivo << "PRECIO" << "\t";
	archivo << "IVA" << "\t";
	archivo << "TOTAL CON IVA INCLUIDO" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (TIENDA[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i;
			archivo << texto2 << texto << "\n";
		}
		
		else
		{
			texto = TIENDA[i].item;
			archivo << texto << "\t" ;
			texto2 = TIENDA[i].nombreart;
			archivo << texto2 << "\t  " ;
			texto2 = TIENDA[i].descripcion;
			archivo << texto2 << "\t   ";
			texto2 = TIENDA[i].genero;
			archivo << texto2 << "   \t" ;
			texto2 = TIENDA[i].clase;
			archivo << texto2 << "    \t" ;
			texto2 = TIENDA[i].consola;
			archivo << texto2 << "    \t" ;  //averiguar como hacer que respete espacios
			texto3 = TIENDA[i].precio;
			archivo << texto3 << "    \t" ;
			texto3= TIENDA[i].impuesto;
			archivo << texto3 << "    \t " ;
			TIENDA[i].total = (TIENDA[i].precio * 1.16);
			texto3 = TIENDA[i].total;
			archivo << texto3 << " \n ";
			
		}
	}


	archivo.close();
}



