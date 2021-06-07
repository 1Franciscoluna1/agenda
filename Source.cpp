#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)

struct Datos
{
	char nombre[15], apellido[20], numero[15];
};

char mostrarmenu();
void agregarcontactos(Datos[], int *);
void mostrarcontactos(Datos[], int);


int main() {
	Datos pipol[10];
	char opc;
	int pos=0;

	do
	{
	opc = mostrarmenu();
	switch (opc)
	{
	case 'a':
		agregarcontactos(pipol,&pos);
		break;
	case 'f':
		mostrarcontactos(pipol, pos);
		break;
	case 'g':
		//guardarlista(pipol, pos);
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

	//system("pause");

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
	FILE* lista = fopen("Agenda funcional.h", "ab");
	for (int i = 0; i < b; i++)
	{
		printf("\n\nNombre:\t\t");
		scanf_s(" %[^\n]s", &pipol[a].nombre, 25);
		printf("\n\nApellido:\t");
		scanf_s(" %[^\n]s", &pipol[a].apellido, 25);
		printf("\n\nNumero:\t\t");
		scanf_s(" %[^\n]s", &pipol[a].numero, 15);
		fwrite(&pipol[a], 1, sizeof(Datos), lista);
		a++;
	}
	*cont = a+1;
	system("cls");
	fclose(lista);
}


void mostrarcontactos(Datos pipol[], int cont) {
	//Datos pipol[10];

	printf("\n\n\t\tContactos guardados\n\n");
	int tamanio;
	FILE* lista;

		lista = fopen("Agenda funcional.h", "rb");

	fseek(lista,0,SEEK_END);// lo manda al fin de archivo
	tamanio = ftell(lista);
	tamanio = tamanio / sizeof(Datos);
	rewind(lista);// no siempre funciona

	printf("%-30s %-30s %-30s\n","Nombre","Apellido","Telefono");
	for (int i = 0; i <tamanio; i++)
	{
	fread(&pipol[i],1,sizeof(Datos) ,lista);
	printf("%-30s",pipol[i].nombre);
	printf("%-30s", pipol[i].apellido);
	printf("%-30s", pipol[i].numero);
	printf("\n");
	}
	printf("\n\n\n");
	system("pause");
	system("cls");
	fclose(lista);
}

