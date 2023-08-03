#include "crudMediCoHorInterface.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
//archivo exclusivo para Pacientes en archivo.dat
const char* nombre_archivoMedH = "medicosH.dat";
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
std::vector<Estructura::FechaH> llenarTurnosMes(int anio, int mes) {
	cout << "entro fucnion" << endl;
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
		}
		else {
			ultimoDia = 28;
		}
	}
	else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
		// Meses con 30 días
		ultimoDia = 30;
	}
	else {
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

	while (fechaActual.dia <= fechaFin.dia) {
		// Agregar la fecha actual al vector
		if (esDomingo(fechaActual.dia, fechaActual.mes, fechaActual.anio)) {
			fechaActual.dia++;
			cout << "es domingo" << endl;
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
	FILE* archivo = fopen(nombre_archivoMedH, "rb");
	if (!archivo) {
		throw std::runtime_error("No se puede abrir el archivo");
		//cout << "No existe tal archivo" << endl;
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

void crearMedH(int cod, const char* nombreMed, const char* nombrePac, int medCmp, const char* medEsp, Estructura::FechaH f, const char* medConsultorio, char medEstadoDis) {//sin const no funciona al pasar puntero, estas
	//intentando modificar un dato que fijo como char[50]

	FILE* archivo = fopen(nombre_archivoMedH, "a+b");
	if (!archivo) {
		throw std::runtime_error("No se puede abrir el archivo");
		//cout << "No existe tal archivo" << endl;
	}
	char res;
	Estructura::MedicoH medico;
	fflush(stdin);//limpia buffer de entrada y salida
	medico.medCod = cod;
	strcpy(medico.medNom, nombreMed);
	strcpy(medico.pacNom, nombrePac);
	medico.medCmp = medCmp;
	strcpy(medico.medEsp, medEsp);
	medico.fechaCita = f;
	strcpy(medico.medConsultorio, medConsultorio);
	medEstadoDis = medEstadoDis;
	fwrite(&medico, sizeof(Estructura::MedicoH), 1, archivo);
	fclose(archivo);
}
