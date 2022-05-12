/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Fundamentos de Ingenieria del Software (F.I.S.)
 * Curso: 2º
 * Practica 7: Desarrollo Agil (I)
 * @author FIS_E03 (Sergio - Julio)
 * Correo: alu0101394763@ull.edu.es
 * @date 06/05/2022
 * 
 * @file DataBase.h 
 * @brief Donde se aloja la declaración de la clase DataBase y la declaracion
 * de sus metodos. La clase DataBase es una clase que se encarga de todo lo
 * relacionado con los datos que deben ser almacenados por nuestra plataforma,
 * todos los usuarios, peticiones, etc... nuestra base de datos se debe ocupar
 * de guardar esos datos y permitir acceder a ellos por el resto del programa
 * cuanto este los necesite.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0.0
 * @brief Historial de Revisiones 
 * 06/05/22 - Creacion (primera version) del codigo:
 *            Creamos el archivo, le pusimos el comentario de
 *            cabecera y declarado los #include necesarios.
 * 
 * 08/05/22 - Archivo terminado.
 */

#ifndef _DATABASE_
#define _DATABASE_

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
using std::filesystem::current_path;  
#include "../include/petition.h"
#include "../include/user.h"


class Data_base {
 public:
  Data_base();
  ~Data_base(){};
  void AddUser(const std::string&, const std::string &);
  void AddPetition(const std::string&, const std::string&, const int, const int, const std::string&);
  bool FindUser(const std::string&);
  User& GetUser(const std::string&);
  bool FindPetition(const std::string&);
  void SearchMotor(const std::string&);
  void ReadPetition(const std::string&);
  Petition getPetition(const std::string&);
  void PrintUserPetitions(std::string user);
 private:
  std::vector<User> users_;
  std::vector<Petition> petitions_;
};




#endif // _DATABASE_