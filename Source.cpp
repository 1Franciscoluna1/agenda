#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6054)


struct Datos
{
	char nombre[15], apellido[20], numero[15];
};

char mostrarmenu();
void agregarcontactos(Datos[], int *);
void mostrarcontactos(Datos[], int);
void modificarcontacto();
void creararchlimpio();


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
		system("pause");
		system("cls");
		break;
	case 'f':
		mostrarcontactos(pipol, pos);
		system("pause");
		system("cls");
		break;
	case 'b':
		system("cls");
		mostrarcontactos(pipol, pos);
		modificarcontacto();
		break;
	case 'z':
		creararchlimpio();
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

void creararchlimpio() {
	FILE *lista = fopen("Agenda funcional.h", "wb");
	fclose(lista);
}

void modificarcontacto() {
	//system("cls");

	FILE* lista = fopen("Agenda funcional.h","r+b");
	Datos personas;



	printf("\n\n\t\t\tIngrese el nombre del contacto a modificar:\n");
	char nom_mod[15]; 
	printf("\n\t\t");
	scanf_s(" %[^\n]s", &nom_mod, sizeof(nom_mod));
	system("cls");

	while (!feof(lista))
	{
		if (!strcmp(nom_mod, personas.nombre)) {
			printf("%-30s %-30s %-30s\n", "Nombre", "Apellido", "Telefono");
			printf("%-30s", personas.nombre);
			printf("%-30s", personas.apellido);
			printf("%-30s", personas.numero);

			int posicion = ftell(lista) - sizeof(personas);
			fseek(lista, posicion, SEEK_SET);

			printf("\n\nQue dato desea modificar?");
			printf("\n\t\t1)\tNombre");
			printf("\n\t\t2)\tApellido");
			printf("\n\t\t3)\tNumero");
			int opc;
			scanf_s(" %i",&opc);

			if (opc==1)
			{
				printf("\n\nIngrese el nuevo nombre a guardar :\t");
				scanf_s(" %[^\n]s", &personas.nombre,sizeof(personas.nombre));
				fwrite(&personas,sizeof(Datos),1,lista);
				printf("\n\nInformacion guardada.......");
			}

			if (opc==2)
			{
				printf("\n\nIngrese el nuevo apellido a guardar :\t");
				scanf_s(" %[^\n]s", &personas.apellido, sizeof(personas.apellido));
				fwrite(&personas,sizeof(Datos),1,lista);
				printf("\n\nInformacion guardada.......");
			}

			if (opc==3)
			{
				printf("\n\nIngrese el nuevo numero a guardar :\t");
				scanf_s(" %[^\n]s", &personas.numero, sizeof(personas.numero));
				fwrite(&personas, sizeof(Datos), 1, lista);
				printf("\n\nInformacion guardada.......");
			}

			break;
		}
		fread(&personas, sizeof(Datos),1,lista);
	}

	fclose(lista);
	printf("\n\n\n");
	system("pause");
	system("cls");
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
	//system("cls");
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
	fclose(lista);
}

