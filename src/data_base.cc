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
 * @brief Functions that store user data in the file /data/userfile.txt
 * 
 * @param name 
 */
void Data_base::AddUser(const std::string &name) {
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
  std::string txt = name + ".txt";
  std::ofstream user_file(txt);
  user_file << passwd << "\n" << "created_petitions: \n \n supported_petitions: \n";
  user_file.close();
}

/**
 * @brief Functions that allows to search for users
 * 
 * @param user 
 * @return true if user is found, false otherwise
 * @return false 
 */
bool Data_base::FindUser(const std::string& user) {

  bool find = false;
  /**
   * We store users in different txt files, one for each user, and we have to 
   * list all the files in the directory /data and then compare
   */
  std::string path = "../data";
    for (const auto & entry : std::filesystem::directory_iterator(path)){
      if (entry.path().filename() == user){
        find = true;
        break;
      }
    }

  return find;
}