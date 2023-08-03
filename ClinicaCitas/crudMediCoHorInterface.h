#pragma once
#ifndef CRUD_MEDICOHOR_H
#define CRUD_MEDICOHOR_H
#include <vector>

namespace Estructura {
    struct FechaH {
        int minutos;
        int hora;
        int dia;
        int mes;
        int anio;
        FechaH() = default;
    };
    struct MedicoH {
        int medCod;//es su DNI
        char medNom[100];
        char pacNom[100];
        int medCmp; //Colegio Medico
        char medEsp[50]; //especialidad
        FechaH fechaCita;
        char medConsultorio[2];
        char medEstadoDis; //En que estado esta, disponible, ocupado
        char MedEstReg;
        MedicoH() = default;
    };
}
std::vector<Estructura::MedicoH> leerMedH();
void crearMedH(int cod, const char* nombreMed,const char* nombrePac, int medCmp, const char* medEsp, Estructura::FechaH f, const char* medConsultorio, char medEstadoDis);
#endif //