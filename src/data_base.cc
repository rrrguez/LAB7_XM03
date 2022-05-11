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

/**
 * @brief Functions that allows to search for users
 * 
 * @param user 
 * @return true if user is found, false otherwise
 * @return false 
 */
bool Data_base::FindUser(const std::string& user) {

  bool find = false;

  /// Due to userfile.txt sintax, we have to add "user:" first in 
  /// std::string& user
  std::string full_user_sintax = "user:" + user;

  /// Open the file in read mode
  std::ifstream userfile;
  userfile.open("../data/userfile.txt");
  std::string line;

  /// Search for a name in userfile.txt in data folder
  while (std::getline(userfile, line)) {
    if (line == full_user_sintax) {
      find = true;
      break;
    }
  }
  userfile.close();

  return true;
}