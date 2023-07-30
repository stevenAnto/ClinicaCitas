#include "crudPacientesInterface.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
//archivo exclusivo para Pacientes en archivo.dat
const char* nombre_archivo = "archivo.dat";
std::vector<Estructura::FechaH> turnosMes;


//La funcion Leer() devuevel un vector<Paciente> de los pacientes que hay en
//el fichero de Pacientes
std::vector<Estructura::Paciente> Leer() {
	//	system("cls"); //no necesario
	//FILE es un tipo de estructura de la biblioteca estandar
	//Soporta funciones de fopen,fwrite,fread,fclose
	FILE* archivo = fopen(nombre_archivo, "rb");
	if (!archivo) {
		cout << "No existe tal archivo" << endl;
	}
	std::vector<Estructura::Paciente> pacientes;
	Estructura::Paciente paciente;
	// indice o pocision del registro(fila) dentro del archivo
	//Almaceno en paciente, el dato  que se lee desde archivo
	while (fread(&paciente, sizeof(Estructura::Paciente), 1, archivo) == 1) {
		pacientes.push_back(paciente);
	}
	fclose(archivo);
	return pacientes;
}

void Crear(int cod, const char* nombre, const char* apellido, int fono) {//sin const no funciona al pasar puntero, estas
	//intentando modificar un dato que fijo como char[50]

	FILE* archivo = fopen(nombre_archivo, "a+b");
	char res;
	Estructura::Paciente paciente;
	fflush(stdin);//limpia buffer de entrada y salida
	paciente.PacCod = cod;
	strcpy(paciente.nombres, nombre);
	strcpy(paciente.apellidos, apellido);
	paciente.telefono = fono;
	fwrite(&paciente, sizeof(Estructura::Paciente), 1, archivo);
	fclose(archivo);
	//Leer();//solo para ver que se esta ingresando correctamente
}
/*Los registros tienen que coincidir su numero de registro con el numero de id*/
void Actualizar(int id, const char* nombre, const char* apellido, int fono) {

	id--;//Cuento desde 0
	FILE* archivo = fopen(nombre_archivo, "r+b");
	Estructura::Paciente paciente;
	//Los id tienen que ser secuenciales
	//Me ubico en el id correcto
	fseek(archivo, id * sizeof(Estructura::Paciente), SEEK_SET);
	paciente.PacCod = ++id;
	strcpy(paciente.nombres, nombre);
	strcpy(paciente.apellidos, apellido);
	paciente.telefono = fono;
	fwrite(&paciente, sizeof(Estructura::Paciente), 1, archivo);
	fclose(archivo);
	Leer();
}

void Borrar(int id) {
	const char* nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp, "w+b");
	FILE* archivo = fopen(nombre_archivo, "rb");
	Estructura::Paciente paciente;
	int id_n = 0;
	//Escribo en un archivo temporal los que no coinciden con el indice
	id--;
	while (fread(&paciente, sizeof(Estructura::Paciente), 1, archivo)) {
		if (id_n != id) {
			fwrite(&paciente, sizeof(Estructura::Paciente), 1, archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);

	archivo_temp = fopen(nombre_archivo_temp, "rb");
	archivo = fopen(nombre_archivo, "wb");
	//Regreso todos los registros en archivo_temp a archivo
	while (fread(&paciente, sizeof(Estructura::Paciente), 1, archivo_temp)) {
		fwrite(&paciente, sizeof(Estructura::Paciente), 1, archivo);

	}
	fclose(archivo);
	fclose(archivo_temp);
	Leer();
}








/*


   Otros ejemplos para busqueda por medio de PacCod indice etc


*/
void buscar_PacCod() {
	FILE* archivo = fopen(nombre_archivo, "rb");
	int pos = 0, indice = 0, cod = 0;
	cout << "Que PacCod desea ver: ";
	cin >> cod;

	Estructura::Paciente paciente;
	fread(&paciente, sizeof(Estructura::Paciente), 1, archivo);
	do {
		if (paciente.PacCod == cod) {
			cout << "PacCod: " << paciente.PacCod << endl;
			cout << "Nombres: " << paciente.nombres << endl;
			cout << "Apellidos: " << paciente.apellidos << endl;
			cout << "Telefono: " << paciente.telefono << endl;
		}
		fread(&paciente, sizeof(Estructura::Paciente), 1, archivo);
	} while (feof(archivo) == 0);



	fclose(archivo);
}
/*void buscar_PacCod(){

  FILE* archivo = fopen(nombre_archivo, "rb");

  int indice=0,pos=0,cod=0;
  cout<<"BUSCAR PacCod: ";
  cin>>cod;
  Paciente paciente;

  fread ( &paciente, sizeof(Paciente), 1, archivo );

  do{

  if (paciente.PacCod == cod){
  pos = indice;
  }

  fread ( &paciente, sizeof(Paciente), 1, archivo );
  indice += 1;
  } while (feof( archivo ) == 0);

  cout<<"------------------ "<<pos<<" ------------------"<<endl;
  fseek ( archivo,pos * sizeof(Paciente), SEEK_SET );
  fread ( &paciente, sizeof( Paciente ), 1, archivo );
  cout << "PacCod: " << paciente.PacCod << endl;
  cout << "Nombre: " << paciente.nombre << endl;
  cout << "Apellido: " << paciente.apellido << endl;
  cout << "Telefono: " << paciente.telefono << endl;
  cout << endl;

  fclose(archivo);
  system("PAUSE");
  }
  */

void buscar_indice() {
	FILE* archivo = fopen(nombre_archivo, "rb");

	int pos = 0;
	cout << "Que registro desea ver: ";
	cin >> pos;
	cout << "------------------ " << pos << " ------------------" << endl;
	fseek(archivo, pos * sizeof(Estructura::Paciente), SEEK_SET);

	Estructura::Paciente paciente;

	fread(&paciente, sizeof(Estructura::Paciente), 1, archivo);

	cout << "PacCod: " << paciente.PacCod << endl;
	cout << "Nombre: " << paciente.nombres << endl;
	cout << "Apellido: " << paciente.apellidos << endl;
	cout << "Telefono: " << paciente.telefono << endl;
	cout << endl;

	fclose(archivo);


}

void imprimirVector(vector<Estructura::Paciente> datos) {
	cout << "mostrando todos los registros de pacientes" << endl;
	cout << "tamanio " << datos.size() << endl;
	for (Estructura::Paciente dato : datos) {
		cout << dato.PacCod << "," << dato.nombres <<
			"," << dato.apellidos << "..." << endl;
	}
}
