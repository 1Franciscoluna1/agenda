#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)

struct Datos
{
	char nomre[25], numero[13];
};

char mostrarmenu();
void agregarcontactos(Datos[], int *);
void mostrarcontactos(Datos[], int);
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
			break;
	case 'f':
		mostrarcontactos(pipol, contador);
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
	//printf("\n\t\tb)\tModificar contacto");
	//printf("\n\t\tc)\tEliminar contacto");
	//printf("\n\t\td)\tbloquear contacto");
	//printf("\n\t\te)\tbuscar contacto");
	printf("\n\t\tf)\tMostrar contactos");
	printf("\n\t\tg)\tGuardar lista");
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
		scanf_s(" %[^\n]s", &pipol[a].nomre, 25);
		printf("\n\n Numero:\t\t");
		scanf_s(" %[^\n]s", &pipol[a].numero, 15);
		a++;
	}
	*cont = a;
	system("cls");
}


void mostrarcontactos(Datos pipol[], int cont) {
	printf("\n\n\t\tContactos guardados");

	for (int i = 0; i < cont; i++)
	{
	printf("\n\nNombre:%s",pipol[i].nomre);
	printf("\nNumero:%s", pipol[i].numero);

	}
	printf("\n\n\n");
	system("pause");
	system("cls");
}

void guardarlista(Datos pipol[], int cont) {
	FILE* lista;
	lista = fopen("C:\\Users\\pacol\\source\\repos\\agenda con arreglo struct y archivo fprintf\\agenda con arreglo struct y archivo fprintf\\Agenda telefonica.txt","w");
	fprintf(lista,"\t\tContactos guardados");

	for (int i = 0; i < cont; i++)
	{
		fprintf(lista,"\n\nNombre:%s", pipol[i].nomre);
		fprintf(lista,"\nNumero:%s", pipol[i].numero);

	}

	fclose(lista);
	printf("\n\n\n");
	system("pause");
	system("cls");
}