#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6054)
//#pragma warning(disable : 0028)



struct Datos
{
	char nombre[15], apellido[20], numero[15];
	int status;
};

char mostrarmenu();
void agregarcontactos();
void mostrarcontactos_desbloqueados();
void modificarcontacto();
void creararchlimpio();
void bloquearcontacto();
void mostrarcontactos_bloqueados();
void desbloquearcontacto();
void eliminarcontacto();


int main() {
	char opc;

	do
	{
	opc = mostrarmenu();
	switch (opc)
	{
	case 'a':
		agregarcontactos();
		system("pause");
		system("cls");
		break;
	case 'b':
		system("cls");
		mostrarcontactos_desbloqueados();
		modificarcontacto();
		break;
	case 'c':
		system("cls");
		mostrarcontactos_desbloqueados();
		eliminarcontacto();
		break;
	case 'd':
		system("cls");
		mostrarcontactos_desbloqueados();
		bloquearcontacto();
		break;
	case 'f':
		mostrarcontactos_desbloqueados();
		system("pause");
		system("cls");
		break;
	case 'g':
			system("cls");
			mostrarcontactos_bloqueados();
			desbloquearcontacto();
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


}

char mostrarmenu() {
	char a;
	FILE* MENU = fopen("MENUgood.txt","r");
	int z;
	while ((z = fgetc(MENU)) != EOF) { putchar(z); }
	
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {73,14};
	SetConsoleCursorPosition(hconsole, coord);

	scanf_s(" %c", &a, sizeof(a));
	system("cls");
	return a;
}

void agregarcontactos()
{
	int a = 0, b;
	printf("\n\n\tCuantos contactos desea ingresar?");
	scanf_s("%i", &b);
	Datos pipol[10];
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
		pipol[a].status = 1;
		fwrite(&pipol[a], 1, sizeof(Datos), lista);
		a++;
	}
	fclose(lista);
	printf("\n\n\n\n");
}

void mostrarcontactos_desbloqueados() {

	printf("\n\n\t\tContactos guardados\n\n");
	int tamanio;
	Datos pipol[20];
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
	if (pipol[i].status==1) {
	printf("%-30s",pipol[i].nombre);
	printf("%-30s", pipol[i].apellido);
	printf("%-30s", pipol[i].numero);
	printf("\n");
	}
	}
	printf("\n\n\n");
	fclose(lista);
}

void mostrarcontactos_bloqueados() {

	printf("\n\n\t\tContactos bloqueados\n\n");
	int tamanio;
	Datos pipol[20];
	FILE* lista;

	lista = fopen("Agenda funcional.h", "rb");

	fseek(lista, 0, SEEK_END);// lo manda al fin de archivo
	tamanio = ftell(lista);
	tamanio = tamanio / sizeof(Datos);
	rewind(lista);// no siempre funciona

	printf("%-30s %-30s %-30s\n", "Nombre", "Apellido", "Telefono");
	for (int i = 0; i < tamanio; i++)
	{
		fread(&pipol[i], 1, sizeof(Datos), lista);
		if (pipol[i].status != 1) {
			printf("%-30s", pipol[i].nombre);
			printf("%-30s", pipol[i].apellido);
			printf("%-30s", pipol[i].numero);
			printf("\n");
		}
	}
	printf("\n\n\n");
	fclose(lista);
}

void bloquearcontacto() {
	FILE* lista = fopen("Agenda funcional.h", "r+b");
	Datos personas;

	int encontrado = 0;

	printf("\n\n\t\t\tIngrese el nombre del contacto que desea bloquear:\n");
	char nom_mod[20];
	printf("\n\t\t");
	scanf_s(" %[^\n]s", &nom_mod, sizeof(nom_mod));
	printf("\n\n\n");
	fread(&personas, sizeof(Datos), 1, lista);
	while (!feof(lista))
	{
		if (!strcmp(nom_mod, personas.nombre)&&personas.status==1) {
			printf("%-30s %-30s %-30s\n", "Nombre", "Apellido", "Telefono");
			printf("%-30s", personas.nombre);
			printf("%-30s", personas.apellido);
			printf("%-30s", personas.numero);

			int posicion = ftell(lista) - sizeof(personas);
			fseek(lista, posicion, SEEK_SET);

			personas.status = 0;
			fwrite(&personas, sizeof(Datos), 1, lista);

			encontrado++;
			break;
		}
		fread(&personas, sizeof(Datos), 1, lista);
	}
	if (encontrado == 0) {
		printf("\n\n\n\n\t\t\tContacto no encontrado\n\n\n");
	}
	else
	{
	printf("\n\n\n\n\t\t\tContacto bloqueado con exito.....\n\n\n");
	}
	fclose(lista);
			system("pause");
			system("cls");
}

void desbloquearcontacto() {
	FILE* lista = fopen("Agenda funcional.h", "r+b");
	Datos personas;

	int encontrado = 0;

	printf("\n\n\t\t\tIngrese el nombre del contacto que desea desbloquear:\n");
	char nom_mod[20];
	printf("\n\t\t");
	scanf_s(" %[^\n]s", &nom_mod, sizeof(nom_mod));
	printf("\n\n\n");
	fread(&personas, sizeof(Datos), 1, lista);
	while (!feof(lista))
	{
		if (!strcmp(nom_mod, personas.nombre) && personas.status != 1) {
			printf("%-30s %-30s %-30s\n", "Nombre", "Apellido", "Telefono");
			printf("%-30s", personas.nombre);
			printf("%-30s", personas.apellido);
			printf("%-30s", personas.numero);

			int posicion = ftell(lista) - sizeof(personas);
			fseek(lista, posicion, SEEK_SET);

			personas.status = 1;
			fwrite(&personas, sizeof(Datos), 1, lista);

			encontrado++;
			break;
		}
		fread(&personas, sizeof(Datos), 1, lista);
	}
	if (encontrado == 0) {
		printf("\n\n\n\n\t\t\tContacto no encontrado");
	}
	else
	{
	printf("\n\n\n\n\t\t\tContacto desbloqueado con exito.....\n\n\n");
	}
	fclose(lista);
	system("pause");
	system("cls");
}

void modificarcontacto() {

	FILE* lista = fopen("Agenda funcional.h","r+b");
	Datos personas;

	int encontrado=0;

	printf("\n\n\t\t\tIngrese el nombre del contacto a modificar:\n");
	char nom_mod[15]; 
	printf("\n\t\t");
	scanf_s(" %[^\n]s", &nom_mod, sizeof(nom_mod));
	system("cls");
	fread(&personas, sizeof(Datos), 1, lista);
	while (!feof(lista))
	{	
		if (!strcmp(nom_mod, personas.nombre) && personas.status==1) {
			printf("%-30s %-30s %-30s\n", "Nombre", "Apellido", "Telefono");
			printf("%-30s", personas.nombre);
			printf("%-30s", personas.apellido);
			printf("%-30s", personas.numero);

			int posicion = ftell(lista) - sizeof(personas);
			fseek(lista, posicion, SEEK_SET);

			printf("\n\nQue dato desea modificar?");
			printf("\n\t\t1)\tNombre");
			printf("\n\t\t2)\tApellido");
			printf("\n\t\t3)\tNumero\t");
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
			encontrado++;
			break;
		}
		fread(&personas, sizeof(Datos),1,lista);
	}

	if (encontrado == 0) {
		printf("\n\n\n\n\t\t\tContacto no encontrado");
	}

	fclose(lista);
	printf("\n\n\n");
	system("pause");
	system("cls");
}

void eliminarcontacto() {
	Datos pipol;
	FILE* lista =fopen("Agenda funcional.h", "r+b");
	FILE* listareservaxd = fopen("Agenda funcional.temp", "wb");
	char pipoltodelate[15]; int encontrado = 0;

	printf("\n\n\t\tIngrese el nombre de la persona que desea eliminar:\n\t\t\t");
	scanf_s(" %[^\n]s", &pipoltodelate, sizeof(pipoltodelate));
	printf("\n\n\n");

	while (fread(&pipol,sizeof(Datos),1,lista))
	{
		if (!strcmp(pipoltodelate, pipol.nombre) && pipol.status == 1) {
			printf("%-30s %-30s %-30s\n", "Nombre", "Apellido", "Telefono");
			printf("%-30s", pipol.nombre);
			printf("%-30s", pipol.apellido);
			printf("%-30s", pipol.numero);
		}

		if (strcmp(pipol.nombre, pipoltodelate)) {
			fwrite(&pipol, sizeof(Datos), 1, listareservaxd);
			encontrado++;
		}
	}
	fclose(lista);
	fclose(listareservaxd);

	FILE* listabuena = fopen("Agenda funcional.h", "wb");
	FILE* listareserva = fopen("Agenda funcional.temp", "rb");
	while (fread(&pipol, sizeof(Datos), 1, listareserva))
	{
			fwrite(&pipol, sizeof(Datos), 1, listabuena);
	}
	fclose(listabuena);
	fclose(listareserva);

	if (encontrado == 0)
	{
		printf("\n\nContacto no encontrado\n\n");
	}
	else {
		printf("\n\nContacto eliminado con exito......\n\n");
	}

	system("pause");
	system("cls");
}

void creararchlimpio() {
	FILE *lista = fopen("Agenda funcional.h", "wb");
	fclose(lista);
}