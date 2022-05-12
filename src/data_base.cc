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
  User u{"admin","admin"};
  users_.emplace_back(u);

  // /// Create all user files in /users/ folder

  // /// Read a file from /users/ folder
  // std::vector<std::string> users_path;
  // std::string u_path = current_path();
  // u_path += "/users/";
  // for (const auto & entry : fs::directory_iterator(u_path)) {
  //   std::string file_name = entry.path().string();
  //   users_path.emplace_back(file_name);
  //   file_name.clear();
  // }

  // for (ulong i {0}; i < users_path.size(); i++) {
  //   std::ifstream file(users_path[i]);
  //   std::string line;

  //   std::string name;
  //   std::string password;

  //   name = line.erase(0, 9);
  //   name.erase(name.size() - 4, name.size());

  //   /// Coger y leer el nombre y la contraseña de cada persona e ir creado los
  //   // usuaios para luego meterlos en el vector de usuarios
  //   // mismo comportamiento para las peticiones 
    
  // }

}

/**
 * @brief Functions that store user data in the file /data/userfile.txt
 * 
 * @param name 
 * @param passwd
 */
void Data_base::AddUser(const std::string &name, const std::string &passwd) {

  if(FindUser(name)) {
    std::cerr << "Ese nombre no está disponinble" << std::endl;
  } else {
    User new_user(name, passwd);
    users_.emplace_back(new_user);
  }
  // std::string txt = "../users/" + name + ".txt";
  // std::ofstream user_file(txt);
  // user_file << passwd << "\n" << "created_petitions: \n \n supported_petitions: \n";
  // user_file.close();
}



/**
 * @brief Functions that allows to add petitions
 * 
 * @param title
 * @param description
 * @param signatures
 * @param money
 * @param user_name
 */
void Data_base::AddPetition(const std::string &title, const std::string &description, int signatures, int money, const std::string &user_name) {
  ulong i;
  for(i = 0; i < users_.size(); i++) {
    if(users_[i].getUserName() == user_name) {
      break;
    }
  }
  Petition petition(title, users_[i], signatures, description, money);
  petitions_.emplace_back(petition);
  // std::string txt = "../petitions/" + title + ".txt";
  // std::ofstream petition_file(txt);
  // petition_file << title << "\n Creador: " << user_name << "\n Meta de firmas: " << signatures << " Firmas actuales: 0 \n";
  // petition_file << "Meta de donaciones: " << money << "Donaciones actuales: 0€ \n" << description << "\n";
  // petition_file.close();
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
  for(ulong i = 0; i < users_.size(); i++) {
    if(users_[i].getUserName() == user) {
      find = true;
    }
  }
  return find;
}

/**
 * @brief Functions that searchs for a petition with a specific name
 * 
 * @param petition
 * @return true if petition is found, false otherwise
 * @return false 
 */
bool Data_base::FindPetition(const std::string& petition) {

  bool find = false;
  for(ulong i = 0; i < petitions_.size(); i++) {
    if(petitions_[i].getTitle() == petition) {
      find = true;
      break;
    }
  }
  return find;
}

/**
 * @brief Functions that allows to search for multiple petitions with names that start the same
 * 
 * @param petition
 */
void Data_base::SearchMotor(const std::string &title) {
  if (title.empty()) {
    for (int i {0}; i < petitions_.size(); i++) {
      std::cout << petitions_[i].getTitle() << std::endl;
    }
  } else {
    int aux;
    for(ulong i = 0; i < petitions_.size(); i++) {
      aux = title.compare(petitions_[i].getTitle());
      if(aux >= 0) {
        std::cout << petitions_[i].getTitle() << std::endl;
      }
    }
  }
}


/**
 * @brief visulize petition data
 * 
 */
void Data_base::ReadPetition(const std::string &title) {
  ulong i;
  for(i = 0; i < petitions_.size(); i++) {
    if(petitions_[i].getTitle() == title) {
      break;
    }
  }
  std::cout << petitions_[i].getTitle() << std::endl << std::endl;
  std::cout << "Creador: " << petitions_[i].getCreator().getUserName() << std::endl;
  std::cout << "Firmas: " << petitions_[i].getFirms() << std::endl;
  int money = petitions_[i].getGoalMoney();
  if(money != 0) {
    std::cout << "Dinero recaudado: " << petitions_[i].getMoney() << "€" << std::endl;
  }
  std::cout << petitions_[i].getDescription() << std::endl << std::endl;
}

/**
 * @brief returns petition object with the same name
 * 
 * @param title 
 * @return Petition 
 */
Petition Data_base::getPetition(const std::string &title) {
  ulong i = 0;
  for(i; i < petitions_.size(); i++) {
    if(petitions_[i].getTitle() == title) {
      break;
    }
  }
  return petitions_[i];
}