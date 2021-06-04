#include <stdio.h>
#include <windows.h>

void mostrarmenu();


struct Datos
{
	char nomre[25], numero[13];
};


int main() {

	mostrarmenu();
	system("pause");

}

void mostrarmenu() {
	printf("\n\n\t\t\t Agenda bien mamalona");
	printf("\n\t\tElija una opcion");
	printf("\n\n\t\ta)\tAgregar contacto");
	//printf("\n\t\tb)\tModificar contacto");
	//printf("\n\t\tc)\tEliminar contacto");
	//printf("\n\t\td)\tbloquear contacto");
	//printf("\n\t\te)\tbuscar contacto");
	//printf("\n\t\tf)\tmostrar contactos");
	//printf("\n\t\tg)\tQuitar bloqueo a contacto");
	printf("\n\t\th)\tSalir\n\n");


}