#pragma once
#ifndef CRUD_PACIENTES_H
#define CRUD_PACIENTES_H
#include <vector>

namespace Estructura{
    struct Paciente {
        int PacCod;
        char nombres[50];
        char apellidos[50];
        int telefono;

        Paciente() = default;
    };
}


std::vector<Estructura::Paciente> Leer();
void Crear(int cod, const char* nombre, const char* apellido, int fono);
void Actualizar(int id, const char* nombre, const char* apellido, int fono);
void Borrar(int id);
void imprimirVector(std::vector<Estructura::Paciente>);

#endif // CRUD_PACIENTES_H
