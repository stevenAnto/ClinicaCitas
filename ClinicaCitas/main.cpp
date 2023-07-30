#include <iostream>
#include ".h"

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
		crearMedH(29455646, "Hector", "Zarate",4567, "Cardiologia",turnosMes[i],"C1","D");
		crearMedH(71548246, "Anibal", "Torres",1258, "Medicina General",turnosMes[i],"M1","D");
		crearMedH(15982456, "Castillo", "Terrones",1598, "Gastroenterologia",turnosMes[i],"M1","D");
		crearMedH(45821478, "Dina", "Boluarte",8521, "Neumologia",turnosMes[i],"M1","D");
	}
	return 0;

}
