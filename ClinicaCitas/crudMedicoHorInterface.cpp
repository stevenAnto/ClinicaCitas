#include "crudMediCoHorInterface.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
//archivo exclusivo para Pacientes en archivo.dat
const char* nombre_archivo = "medicosH.dat";
//std::vector<Estructura::FechaH> turnos;
bool esDomingo(int dia, int mes, int anio) {
	if (mes < 3) {
		mes += 12;
		anio--;
	}
	int k = anio % 100;
	int j = anio / 100;
	int diaSemana = (dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 - 2 * j) % 7;
	return (diaSemana == 1);
}
std::vector<Estructura::FechaH> llenarTurnosMes(int anio, int mes){
	cout<<"entro fucnion"<<endl;
	std::vector<Estructura::FechaH> turnosMes;
	//Fecha de inicio
	Estructura::FechaH fechaInicio;
	fechaInicio.minutos = 0;
	fechaInicio.hora = 9;
	fechaInicio.dia = 1;
	fechaInicio.mes = mes;
	fechaInicio.anio = anio;
	//ultimo dia
	int ultimoDia;
	if (mes == 2) {
		// Febrero
		if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
			ultimoDia = 29;  // Año bisiesto
		} else {
			ultimoDia = 28;
		}
	} else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		// Meses con 30 días
		ultimoDia = 30;
	} else {
		// Meses con 31 días
		ultimoDia = 31;
	}
	// Definir la fecha de fin: último día del mes a las 5:00 pm
	Estructura::FechaH fechaFin;
	fechaFin.minutos = 0;
	fechaFin.hora = 17;
	fechaFin.dia = ultimoDia;
	fechaFin.mes = mes;
	fechaFin.anio = anio;
	// Recorrer las fechas y agregar los turnos al vector
	Estructura::FechaH fechaActual = fechaInicio;

	while (fechaActual.dia<=fechaFin.dia) {
		// Agregar la fecha actual al vector
		if(esDomingo(fechaActual.dia,fechaActual.mes,fechaActual.anio)){
			fechaActual.dia++;
			cout<<"es domingo"<<endl;
			continue;
		}
		turnosMes.push_back(fechaActual);

		// Avanzar 30 minutos para el próximo turno
		fechaActual.minutos += 30;
		if (fechaActual.minutos >= 60) {
			fechaActual.minutos -= 60;
			fechaActual.hora++;
		}

		// Verificar si se pasa al día siguiente (después de las 5:00 pm)
		if (fechaActual.hora >= 17) {
			fechaActual.hora = 9;  // Comenzar de nuevo a las 9:00 am
			fechaActual.dia++;    // Pasar al siguiente día
		}
	}

	return turnosMes;
	//En el mes de Agosto hay 432 turnos
}
//La funcion Leer() devuevel un vector<Paciente> de los pacientes que hay en
//el fichero de Pacientes
std::vector<Estructura::MedicoH> leerMedH() {
	//	system("cls"); //no necesario
	//FILE es un tipo de estructura de la biblioteca estandar
	//Soporta funciones de fopen,fwrite,fread,fclose
	FILE* archivo = fopen(nombre_archivo, "rb");
	if (!archivo) {
		cout << "No existe tal archivo" << endl;
	}
	std::vector<Estructura::MedicoH> medicosH;
	Estructura::MedicoH medicoH;
	// indice o pocision del registro(fila) dentro del archivo
	//Almaceno en paciente, el dato  que se lee desde archivo
	while (fread(&medicoH, sizeof(Estructura::MedicoH), 1, archivo) == 1) {
		medicosH.push_back(medicoH);
	}
	fclose(archivo);
	return medicosH;
}

void crearMedH(int cod, const char* nombre, const char* apellido, int medCmp, const char* medEsp,Estructura:: FechaH f, const char*medConsultorio, char medEstadoDis){//sin const no funciona al pasar puntero, estas
	//intentando modificar un dato que fijo como char[50]

	FILE* archivo = fopen(nombre_archivo, "a+b");
	char res;
	Estructura::MedicoH medico;
	fflush(stdin);//limpia buffer de entrada y salida
	medico.medCod = cod;
	strcpy(medico.medNom, nombre);
	strcpy(medico.medApe, apellido);
	medico.medCmp = medCmp;
	strcpy(medico.medEsp, medEsp);
	medico.fechaCita = f;
	strcpy(medico.medConsultorio, medConsultorio);
	medEstadoDis = medEstadoDis;
	fwrite(&medico, sizeof(Estructura::MedicoH), 1, archivo);
	fclose(archivo);
}
/*Los registros tienen que coincidir su numero de registro con el numero de id*/
/*void Actualizar(int id, const char* nombre, const char* apellido, int fono) {

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
*/

int main() {
	cout<<"entro main"<<endl;
	int mes = 8; // Agosto
	int anio = 2023;

	std::vector<Estructura::FechaH> turnosMes = llenarTurnosMes(anio, mes);

	// Imprimir los turnos del mes de agosto de 2023
	for (const auto& turno : turnosMes) {
		std::cout << turno.dia << "/" << turno.mes << "/" << turno.anio << " ";
		cout << turno.hora << ":" << (turno.minutos == 0 ? "00" : "30") <<endl;
	}
	for(int i = 0;i<turnosMes.size(); i++){
		crearMedH(29455646, "Hector", "Zarate",4567, "Cardiologia",turnosMes[i],"C1",'D');
		crearMedH(71548246, "Anibal", "Torres",1258, "Medicina General",turnosMes[i],"M1",'D');
		crearMedH(15982456, "Castillo", "Terrones",1598, "Gastroenterologia",turnosMes[i],"M1",'D');
		crearMedH(45821478, "Dina", "Boluarte",8521, "Neumologia",turnosMes[i],"M1",'D');
	}
	vector<Estructura::MedicoH> medicosLeidos = leerMedH();
	for (const auto& medico : medicosLeidos) {
		std::cout << medico.medCod << ":" << medico.medNom << ":" << medico.medCmp << " ";
		std::cout << medico.fechaCita.dia << "/" << medico.fechaCita.mes << "/" << medico.fechaCita.anio << " ";
		cout << medico.fechaCita.hora << ":" << (medico.fechaCita.minutos == 0 ? "00" : "30") <<endl;
	}
	cout<<"tamanio of  vector medicosLeidos "<<medicosLeidos.size()<<endl;

	return 0;
}






/*


	 Otros ejemplos para busqueda por medio de PacCod indice etc


*/

/*
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
void buscar_PacCod(){

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
}*/
