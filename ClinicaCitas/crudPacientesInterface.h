#pragma once
#ifndef CRUD_PACIENTES_H
#define CRUD_PACIENTES_H
#include <vector>
#include <map>

namespace Estructura{
    struct FechaH{
        int minutos;
        int hora;
        int dia;
        int mes;
        int anio;
        FechaH()=default;
    };
    struct Paciente {
        int PacCod;
        char nombres[50];
        char apellidos[50];
        int telefono;
        FechaH fechaCita;
        Paciente() = default;
    };
}


std::map<int,Estructura::Paciente> Leer();
void Crear(int cod, const char* nombre, const char* apellido, int fono);
void Actualizar(int id, const char* nombre, const char* apellido, int fono);
void Borrar(int id);
void imprimirVector(std::vector<Estructura::Paciente>);
void imprimirMap(std::map<int,Estructura::Paciente>);

#endif // CRUD_PACIENTES_H
