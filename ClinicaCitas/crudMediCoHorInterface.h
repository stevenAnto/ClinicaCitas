#pragma once
#ifndef CRUD_MEDICOHOR_H
#define CRUD_MEDICOHOR_H
#include <vector>

namespace Estructura{
    struct FechaH{
        int minutos;
        int hora;
        int dia;
        int mes;
        int anio;
        FechaH()=default;
    };
    struct MedicoH {
        int medCod;//es su DNI
        char medNom[50];
        char medApe[50];
        int medCmp; //Colegio Medico
        char medEsp[50]; //especialidad
        FechaH fechaCita;
        char medConsultorio[2];
        char medEstadoDis; //En que estado esta, disponible, ocupado
        char MedEstReg;
        MedicoH()=default;
    };
}

#endif //
