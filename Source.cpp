#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)

struct Datos
{
	char nombre[15], apellido[15], numero[15];
};

char mostrarmenu();
void agregarcontactos(Datos[], int *);
void mostrarcontactos(/*Datos[],*/ int);
void guardarlista(Datos[], int);


int main() {
	Datos pipol[10];
	char opc;
	int contador=0;

	do
	{
	opc = mostrarmenu();
	switch (opc)
	{
	case 'a':
		agregarcontactos(pipol,&contador);
		guardarlista(pipol, contador);
		break;
	case 'f':
		mostrarcontactos(/*pipol,*/ contador);
		break;
	case 'g':
		guardarlista(pipol, contador);
		break;
	default:
		if (opc!='h')
		{
		printf("\n\nOpcion no valida\n\n");
		system("pause");
		system("cls");
		break;
		}
	}
	} while (opc!='h');

	system("pause");

}

char mostrarmenu() {
	char a;
	printf("\n\n\t\t\t Agenda bien mamalona");
	printf("\n\t\tElija una opcion");
	printf("\n\n\t\ta)\tAgregar contacto");
	printf("\n\t\tb)\tModificar contacto");
	printf("\n\t\tc)\tEliminar contacto");
	printf("\n\t\td)\tBloquear contacto");
	printf("\n\t\te)\tBuscar contacto");
	printf("\n\t\tf)\tMostrar contactos");
	printf("\n\t\tg)\tQuitar bloqueo a contacto");
	printf("\n\t\th)\tSalir\n\n");
	scanf_s(" %c", &a, sizeof(a));
	system("cls");
	return a;
}

void agregarcontactos(Datos pipol[], int*cont)
{
	int a = *cont, b;
	printf("\n\n\tCuantos contactos desea ingresar?");
	scanf_s("%i", &b);
	system("cls");
	for (int i = 0; i < b; i++)
	{
		printf("\n\nNombre:\t\t");
		scanf_s(" %[^\n]s", &pipol[a].nombre, 25);
		printf("\n\nApellido:\t");
		scanf_s(" %[^\n]s", &pipol[a].apellido, 25);
		printf("\n\nNumero:\t\t");
		scanf_s(" %[^\n]s", &pipol[a].numero, 15);
		a++;
	}
	*cont = a;
	system("cls");
}


void mostrarcontactos(/*Datos pipol[],*/ int cont) {
	Datos pipol[10];

	printf("\n\n\t\tContactos guardados\n\n");
	int tamanio;
	FILE* lista;

		lista = fopen("C:\\Users\\pacol\\source\\repos\\agenda con arreglo struct y archivo fprintf\\agenda con arreglo struct y archivo fprintf\\Agenda telefonica binaria.h", "rb");

	fseek(lista, SEEK_END, 1);// lo manda al fin de archivo
	tamanio = ftell(lista);
	tamanio = tamanio / sizeof(lista);
	rewind(lista);// no siempre funciona

	printf("%-15s %-15s %-15s\n","Nombre","Apellido","Telefono");
	for (int i = 0; i < cont; i++)
	{
	fread(&pipol[i], 1 , sizeof(pipol),lista);
	printf("%-20s",pipol[i].nombre);
	printf("%-20s", pipol[i].apellido);
	printf("%-20s", pipol[i].numero);
	printf("\n");
	}
	printf("\n\n\n");
	system("pause");
	system("cls");
}

void guardarlista(Datos pipol[], int cont) {
	FILE* lista;
	lista = fopen("C:\\Users\\pacol\\source\\repos\\agenda con arreglo struct y archivo fprintf\\agenda con arreglo struct y archivo fprintf\\Agenda telefonica binaria.h","wb");
	//fprintf(lista,"\t\tContactos guardados");

	for (int i = 0; i < cont; i++)
	{
		fwrite(&pipol[i].nombre,sizeof(pipol),i,lista);
		fwrite(&pipol[i].apellido, sizeof(pipol), i, lista);
		fwrite(&pipol[i].numero, sizeof(pipol), i, lista);

	}

	fclose(lista);
	//printf("\n\n\n");
	//system("pause");
	//system("cls");
}