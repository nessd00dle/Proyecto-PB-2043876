#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
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
	int item, numunidades, lanzamiento;
	float total, precio;
	string descripcion, consola, nombreart, status, genero, clase, carac;
	float impuesto = .16;
};
int alta;
Articulo* TIENDA;//puntero en la estructura para hacer el programa dinámico 
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();
void validItem(int nuevoItem, bool& Repetido, int nArticulos);// función para poder validar el item que no se repita

int main()
{
	int op;
	printf("\t%c%cTienda de video juegos%c%c\n", 177, 177, 177, 177);
	printf("\t%c%c%c MEN%c DE OPCIONES %c%c%c \n", 3, 3, 3, 233, 3, 3, 3);
	printf("1.Alta de art%cculos\n2.Modificar\n3.Baja de art%cculos\n4.Lista de art%cculos\n5.Limpiar pantalla\n6.Salir\n", 161, 161, 161);
	printf("%cBienvendido %c,favor de elegir una opci%cn\n", 16, 01, 162);
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
		system("cls"); //Limpia pantalla
		return main();
		break;

	case 6:
		archivos();
		break;
	default:

		printf("Ingrese una opci%cn v%clida", 162, 160);
		return main();
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
		printf("\tArt%Cculo %d\n", 161, i + 1);
		// Se crean dos variables
		int nuevoItem; //Almacena el nuevo ittem
		bool Repetido; //Almacena la respuesta a la funcion.

		do
		{
			printf("%cIngrese el item del art%cculo:\n", 16, 161);
			scanf_s("%d", &nuevoItem); //Guarda el nuevo item, sin guardarlo en la estructura dinamica

			validItem(nuevoItem, Repetido, i); //aplica la funcion,aquí se piden los parametros entero,booleano e "i" que significa el número de registro

		} while (Repetido); //Valida que la funcion no este repetido

		TIENDA[i].item = nuevoItem; //Al salir del do while aseguramos que es valido el item, por lo tanto asignamos a la estructura dinamica.

		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		printf("%cIngrese el nombre del art%culo \n", 16, 161);
		getline(cin, TIENDA[i].nombreart); //permite los espacios en el nombre

		do
		{
			printf("%cIngrese el a%co de lanzamiento \n", 16, 164);
			scanf_s("%d", &TIENDA[i].lanzamiento);

		} while (TIENDA[i].lanzamiento > 2024 || TIENDA[i].lanzamiento < 1970);

		while (getchar() != '\n');
		printf("%cIngrese una descripci%cn del art%cculo \n", 16, 162, 161);
		getline(cin, TIENDA[i].descripcion);
		printf("%cIngrese el g%cnero del art%cculo \n", 16, 130, 161);
		getline(cin, TIENDA[i].genero);
		printf("%cIngrese la clasificaci%cn del art%cculo \n", 16, 162, 161);
		getline(cin, TIENDA[i].clase);
		printf("%cIngrese las caracteristicas del art%cculo \n", 16, 161);
		getline(cin, TIENDA[i].carac);
		printf("%cIngrese la consola del art%cculo \n", 16, 161);
		getline(cin, TIENDA[i].consola);
		printf("%cIngrese el precio\n", 16);
		scanf_s("%f", &TIENDA[i].precio);
		printf("%cIngrese el n%cmero de unidades del articulo\n", 16, 163);
		scanf_s("%d", &TIENDA[i].numunidades);
		printf("\t%c%c%c Se a guardado exitosamente la informaci%cn %c%c%c\n", 176, 176, 176, 162, 176, 176, 176);
	}

}
void modificar()
{
	int j, opcion, op2;

	do
	{
		printf("Ingrese el n%cmero del registro a modificar:", 163);
		scanf_s("%d", &j);
		j = j - 1; // esto debido a que i inicia en 0 y el usuario va ingresar número mayor que 0

		for (int i = j; i == j; i++)
		{
			if ((TIENDA[i].status == "ELIMINADO"))
			{
				printf("REGISTRO ELIMINADO\n", i + 1);
				printf("Ingrese un registro valido \n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
	printf("\t%cQu%c desea modificar%c\n1.Item\n2.Nombre\n3.A%co de lanzamiento\n4.Descripcion\n5.Genero\n6.Clasificacion\n7.Caracteristicas\n8.Consola\n9.Precio\n10.Unidades\n", 168, 130, 63, 164);
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
			do
			{
				printf("%cIngrese el a%co de lanzamiento \n", 16, 164);
				scanf_s("%d", &TIENDA[i].lanzamiento);

			} while (TIENDA[i].lanzamiento > 2024 || TIENDA[i].lanzamiento < 1970);

		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese la descripci%cn del art%cculo\n", 9, 162, 161);
			getline(cin, TIENDA[i].descripcion);

		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese el g%cnero del art%cculo\n", 9, 130, 161);
			getline(cin, TIENDA[i].genero);

		}
		break;
	case 6:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese la clasificaci%cn del art%cculo\n", 9, 162, 161);
			getline(cin, TIENDA[i].clase);

		}
		break;
	case 7:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese las caracteristicas del art%cculo \n", 9, 161);
			getline(cin, TIENDA[i].carac);

		}
		break;
	case 8:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese la consola del art%cculo \n", 9, 161);
			getline(cin, TIENDA[i].consola);

		}
		break;
	case 9:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese el precio\n", 9);
			scanf_s("%f", &TIENDA[i].precio);

		}
		break;
	case 10:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("%cIngrese el n%cmero de unidades del articulo\n", 9, 163);
			scanf_s("%d", &TIENDA[i].numunidades);

		}
		break;
	default:
		printf("%cIngrese una opcion valida\n", 9);
		return modificar();
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
			printf("%c Nombre del art%cculo:%s\n", 175, 161, TIENDA[i].nombreart.c_str());
			printf("%c A%co de lanzamiento:%d\n", 175, 164, TIENDA[i].lanzamiento);
			printf("%c Descripci%cn:%s\n", 175, 162, TIENDA[i].descripcion.c_str());
			printf("%c G%cnero:%s\n", 175, 130, TIENDA[i].genero.c_str());
			printf("%c Clase:%s\n", 175, TIENDA[i].clase.c_str());
			printf("%c Caracteristicas:%s\n", 175, TIENDA[i].carac.c_str());
			printf("%c Consola:%s\n", 175, TIENDA[i].consola.c_str());
			printf("%c Unidades:%d\n", 175, TIENDA[i].numunidades);
			printf("%c Precio: %f\n", 175, TIENDA[i].precio);
			printf("%c IVA: %f\n", 175, TIENDA[i].impuesto);
			TIENDA[i].total = TIENDA[i].precio * 1.16;
			printf("%c Total:%f\n", 175, TIENDA[i].total);




		}
	}
}
void archivos()
{
	ofstream archivo; //clase ofstream para leer archivos
	string nombrearchivo;
	int texto;
	float texto3;
	string texto2;

	nombrearchivo = "TiendaVidJuegos.txt";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE PUDO CREAR EL ARCHIVO\n");
		exit(1);
	}

	archivo << "│ITEM" << "\t\t│";
	archivo << "NOMBRE" << "\t\t│";
	archivo << "AÑO DE LANZAMIENTO" << "\t\t│";
	archivo << "DESCRIPCION" << "\t\t│";
	archivo << "GENERO" << "\t\t│";
	archivo << "CLASIFICACION" << "\t\t│";
	archivo << "Caracteristicas" << "\t\t│";
	archivo << "CONSOLA" << "\t\t│";
	archivo << "PIEZAS EXISTENTES" << "\t\t│";
	archivo << "PRECIO" << "\t\t│";
	archivo << "IVA" << "\t\t│";
	archivo << "TOTAL CON IVA INCLUIDO" << "\n";

	for (int i = 0; i < alta; i++)
	{
		if (TIENDA[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = i + 1;
			archivo << texto2 << texto << "\n";
		}

		else
		{
			texto = TIENDA[i].item;
			archivo<<"│" << texto << "\t\t│";
			texto2 = TIENDA[i].nombreart;
			archivo << texto2 << "\t\t│";
			texto = TIENDA[i].lanzamiento;
			archivo << texto << "\t\t\t│";
			texto2 = TIENDA[i].descripcion;
			archivo << texto2 << "\t\t\t│";
			texto2 = TIENDA[i].genero;
			archivo << texto2 << "\t\t│";
			texto2 = TIENDA[i].clase;
			archivo << texto2 << "\t\t│";
			texto2 = TIENDA[i].carac;
			archivo << texto2 << "\t\t│";
			texto2 = TIENDA[i].consola;
			archivo << texto2 << "\t\t│";  //averiguar como hacer que respete espacios
			texto = TIENDA[i].numunidades;
			archivo << texto << "\t\t\t│";
			texto3 = TIENDA[i].precio;
			archivo << texto3 << "\t\t\t│";
			texto3 = TIENDA[i].impuesto;
			archivo << texto3 << "\t\t\t│";
			TIENDA[i].total = (TIENDA[i].precio * 1.16);
			texto3 = TIENDA[i].total;
			archivo << texto3 << "│\n";

		}
	}
	printf("Adios,vuelva pronto:)");

	archivo.close();
}
void validItem(int nuevoItem, bool& Repetido, int nArticulos) //Validamos el ITEM necesita 3 parámetros enteros,booleano y el número de articulos
{
	for (int i = 0; i < nArticulos; i++)
	{
		if (nuevoItem == TIENDA[i].item)
		{
			Repetido = true; // Item repetido
			printf("El numero de item ya existe.Favor de ingresar otro.\n");
			return;
		}
	}
	Repetido = false; // Item no repetido
}
