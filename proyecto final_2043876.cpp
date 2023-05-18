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
	int item, numunidades;
	float total, precio;
	string descripcion, consola, nombreart, status, genero, clase;
	float impuesto = .16;
};
int alta;
Articulo* TIENDA;//puntero en la estructura para hacer el progrma dinámico 
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();

int main()
{
	int op;
	printf("\t%c%c%c MEN%c DE OPCIONES %c%c%c \n", 3, 3, 3, 233, 3, 3, 3);
	printf("1.Alta de art%cculos\n2.Modificar\n3.Baja de art%cculos\n4.Lista de art%cculos\n5.Limpiar pantalla\n6.Salir\n", 161, 161, 161);
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
	printf("%cCu%Cntos registros desea dar de alta%c \n", 168, 160, 63);
	scanf_s("%d", &alta);
	TIENDA = new Articulo[alta]; // uso de new para hacer el arreglo dinamico
	for (int i = 0; i < alta; i++)
	{

		printf("%cIngrese el item del art%culo\n", 16, 161);
		scanf_s("%d", &TIENDA[i].item);
		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		printf("%cIngrese el nombre del art%culo \n", 16, 161);
		getline(cin, TIENDA[i].nombreart); //permite los espacios en el nombre
		printf("%cIngrese una descripci%cn del art%cculo \n", 16, 162, 161);
		getline(cin, TIENDA[i].descripcion);
		printf("%cIngrese el g%cnero del art%cculo \n", 16, 130, 161);
		getline(cin, TIENDA[i].genero);
		printf("%cIngrese la clasificaci%cn del art%cculo \n", 16, 162, 161);
		getline(cin, TIENDA[i].clase);
		printf("%cIngrese la consola del art%cculo \n", 16, 161);
		getline(cin, TIENDA[i].consola);
		printf("%cIngrese el precio\n", 16);
		scanf_s("%f", &TIENDA[i].precio);
		printf("%cIngrese el n%cmero de unidades del articulo\n",16,163);
		scanf_s("%d", &TIENDA[i].numunidades);
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
				printf("Ingrese un registro v%lido \n", 160);
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf("\t%cQu%c desea modificar%c\n1.-Item del art%cculo\n2.-Nombre del art%cculo\n3.-Descripci%cn\n4.-G%cnero\n5.-Clasificaci%cn\n6.-Consola\n7.-Precio\n8.-N%cmero de unidades\n", 168, 130, 63, 161, 161, 162, 130, 162, 163);
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			printf("%cIngrese el item del art%cculo\n", 9, 161);
			scanf_s("%d", &TIENDA[i].item);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
			printf("%cIngrese nombre del art%cculo\n", 9, 161);
			getline(cin, TIENDA[i].nombreart);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese la descripci%cn del art%cculo\n", 9,162, 161);
			getline(cin, TIENDA[i].descripcion);

		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese el g%cnero del art%cculo\n", 9,130, 161);
			getline(cin,TIENDA[i].genero);
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese la clasificaci%cn del art%cculo\n", 9, 162, 161);
			getline(cin,TIENDA[i].clase);
		}
		break;
	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese la consola del art%cculo\n", 9, 161);
			getline(cin,TIENDA[i].consola);
		}
		break;
	case 7:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese el precio art%cculo\n", 9, 161);
			scanf_s("%f", & TIENDA[i].precio);
		}
		break;
	case 8:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese el n%mero de unidades del art%cculo\n", 9, 163, 161);
			scanf_s("%d", & TIENDA[i].numunidades);
		}
		break;

	}


}
void eliminar()
{
	int j;
	printf("%cIngrese el  registro a eliminar\n", 31);
	scanf_s("%d", &j);
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("\tEliminando registro\n", j + 1);
		TIENDA[i].status = "ELIMINADO";
	}
}
void listas()
{
	for (int i = 0; i < alta; i++)
	{
		if (TIENDA[i].status == "ELIMINADO")
		{
			printf("\tREGISTRO ELIMINADO %d \n ", i + 1);
		}
		else
		{
			printf("\t Registro %d \n", i + 1);
			printf("%c Item:%d\n", 175, TIENDA[i].item);
			printf("%c Nombre del art%cculo:%s\n", 175,161, TIENDA[i].nombreart.c_str());
			printf("%c Descripci%cn:%s \n", 175,162, TIENDA[i].descripcion.c_str());
			printf("%c G%cnero: %s\n", 175,130, TIENDA[i].genero.c_str());
			printf("%c Clase:%s \n", 175, TIENDA[i].clase.c_str());
			printf("%c Precio: %f\n", 175, TIENDA[i].precio);
			printf("%c Unidades:%d \n", 175, TIENDA[i].numunidades);




		}
	}
}
void archivos()
{
	ofstream archivo; //clase ofstream para leer archivos
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
	archivo << "ITEM" << "\t\t";
	archivo << "NOMBRE" << "\t\t";
	archivo << "DESCRIPCION" << "\t\t   ";
	archivo << "GENERO" << "\t\t";
	archivo << "CLASIFICACION" << "\t\t";
	archivo << "CONSOLA" << "\t\t";
	archivo << "PIEZAS EXISTENTES" << "\t\t";
	archivo << "PRECIO" << "\t\t";
	archivo << "IVA" << "\t\t";
	archivo << "TOTAL CON IVA INCLUIDO" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (TIENDA[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i+1;
			archivo << texto2 << texto << "\n";
		}

		else
		{
			texto = TIENDA[i].item;
			archivo << texto << "\t\t";
			texto2 = TIENDA[i].nombreart;
			archivo << texto2 << "\t\t";
			texto2 = TIENDA[i].descripcion;
			archivo << texto2 << "\t\t";
			texto2 = TIENDA[i].genero;
			archivo << texto2 << "\t\t";
			texto2 = TIENDA[i].clase;
			archivo << texto2 << "\t\t";
			texto2 = TIENDA[i].consola;
			archivo << texto2 << "\t\t";  //averiguar como hacer que respete espacios
			texto = TIENDA[i].numunidades;
			archivo << texto << "\t\t";
			texto3 = TIENDA[i].precio;
			archivo << texto3 << "\t\t";
			texto3 = TIENDA[i].impuesto;
			archivo << texto3 << "\t\t";
			TIENDA[i].total = (TIENDA[i].precio * 1.16);
			texto3 = TIENDA[i].total;
			archivo << texto3 << "\n";

		}
	}


	archivo.close();
}

