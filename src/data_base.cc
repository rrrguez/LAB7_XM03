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
 * @file DataBase.cc
 * @brief Donde se desarrollan los metodos de la clase DataBase contenida
 * en el archivo de cabecera DataBase.h
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

#include "../include/data_base.h"

bool Data_base::AddUser(const std::string &name) {
  std::cout << "Introduzca el nombre de usuario que quiere" << std::endl;
  bool flag = false;
  while(!flag) {
    if(!FindUser(name)) {
      std::cerr << "Ese nombre no está disponinble" << std::endl;
    } else {
      flag = true;
    }
  }
  std::string passwd;
  std::cout << "Introduzca la contrasena que quiere" << std::endl;
  std::cin >> passwd;
  
}

/**
 * @brief Functions that allows to search for users
 * 
 * @param user 
 * @return true 
 * @return false 
 */
bool Data_base::FindUser(const std::string &user) {

  /// Search for a name in userfile.txt in data folder
  std::ifstream userfile;
  userfile.open("../data/userfile.txt");
  std::string line;
  while (std::getline(userfile, line)) {
    if (line == user) {
      return true;
    }
  }
  userfile.close();

  return true;
}