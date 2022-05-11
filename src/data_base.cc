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
#include "../include/user.h"

namespace fs = std::filesystem;

/**
 * @brief Construct a new Data_base::Data_base object
 * 
 */
Data_base::Data_base() {
  /// Create all user files in /users/ folder

  /// Read a file from /users/ folder
  std::vector<std::string> users_path;
  std::string path = "../users";
  for (const auto & entry : fs::directory_iterator(path)) {
    std::string file_name = entry.path().string();
    users_path.emplace_back(file_name);
    file_name.clear();
  }

  for (int i {0}; i < users_path.size(); i++) {
    std::ifstream file(users_path[i]);
    std::string line;

    std::string name;
    std::string password;

    name = line.erase(0, 9);
    name.erase(name.size() - 4, name.size());

    /// Coger y leer el nombre y la contraseña de cada persona e ir creado los
    // usuaios para luego meterlos en el vector de usuarios
    // mismo comportamiento para las peticiones 
    
  }


}

/**
 * @brief Functions that store user data in the file /data/userfile.txt
 * 
 * @param name 
 * @param passwd
 */
void Data_base::AddUser(const std::string &name, const std::string &passwd) {
  bool flag = false;
  while(!flag) {
    if(!FindUser(name)) {
      std::cerr << "Ese nombre no está disponinble" << std::endl;
    } else {
      flag = true;
    }
  }
  std::string txt = "../data/users/" + name + ".txt";
  std::ofstream user_file(txt);
  user_file << passwd << "\n" << "created_petitions: \n \n supported_petitions: \n";
  user_file.close();
  User new_user(name, passwd);
  users_.emplace_back(new_user);
}

void Data_base::AddPetition(const std::string &title, const std::string &description, int signatures, int money, const std::string &user_name) {
  int i;
  for(i = 0; i < users_.size(); i++) {
    if(users_[i].getUserName() == user_name) {
      break;
    }
  }
  Petition(title, users_[i], signatures, description, money);
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
  std::string path = "../users";
    for (const auto & entry : std::filesystem::directory_iterator(path)){
      if (entry.path().filename() == user){
        find = true;
        break;
      }
    }

  return find;
}

/**
 * @brief Functions that allows to search for petitions
 * 
 * @param petition
 * @return true if petition is found, false otherwise
 * @return false 
 */
bool Data_base::FindUser(const std::string& petition) {

  bool find = false;
  /**
   * We store users in different txt files, one for each user, and we have to 
   * list all the files in the directory /data and then compare
   */
  std::string path = "../petitions";
    for (const auto & entry : std::filesystem::directory_iterator(path)){
      if (entry.path().filename() == petition){
        find = true;
        break;
      }
    }

  return find;
}
