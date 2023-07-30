#include <iostream>
#include "crudPacientesInterface.h"

int main() {
  // Crear pacientes
  Crear(1, "Juan", "Perez", 123456789);
  Crear(2, "Maria", "Lopez", 987654321);

  // Leer pacientes
  std::vector<Estructura::Paciente> pacientes = Leer();

  // Imprimir pacientes
  imprimirVector(pacientes);

  // Actualizar un paciente
  Actualizar(1, "Juan Carlos", "Perez Gomez", 555555555);

  // Leer pacientes actualizados
  pacientes = Leer();

  // Imprimir pacientes actualizados
  imprimirVector(pacientes);

  // Borrar un paciente
  Borrar(2);

  // Leer pacientes después de borrar uno
  pacientes = Leer();

  // Imprimir pacientes después de borrar uno
  imprimirVector(pacientes);

  return 0;
}
