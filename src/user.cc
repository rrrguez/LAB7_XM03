/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Fundamentos de Ingenieria del Software (F.I.S.)
 * Curso: 2º
 * Practica 7: Desarrollo Agil (I)
 * @author FIS_E03 (Cristopher - Rebeca)
 * Correo: alu0101394763@ull.edu.es
 * @date 06/05/2022
 * 
 * @file User.cc
 * @brief Donde se desarrollan los metodos de la clase User contenida
 * en el archivo de cabecera User.h
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

#include "../include/user.h"

/**
 * @brief Construct a new User:: User object
 * 
 */
User::User() {
  user_name_ = "default_user_name";
  user_password_ = "password";
  Petition* created_petitions [0];
  created_petitions_ = created_petitions;
  Petition* supported_petitions [0];
  supported_petitions_ = supported_petitions;
}

/**
 * @brief Construct a new User:: User object
 * 
 * @param user_name 
 * @param user_password 
 */
User::User(const std::string& user_name, const std::string& user_password) {
  user_name_ = user_name;
  user_password_ = user_password;
  Petition* created_petitions [0];
  created_petitions_ = created_petitions;
  Petition* supported_petitions [0];
  supported_petitions_ = supported_petitions;
}

/**
 * @brief Construct a new User:: User object
 * 
 * @param user_name 
 * @param user_password 
 * @param created_petitions 
 * @param supported_petitions 
 */
User::User(const std::string& user_name, const std::string& user_password,
Petition**& created_petitions, Petition**& supported_petitions) {
  user_name_ = user_name;
  user_password_ = user_password;
  created_petitions_ = created_petitions;
  supported_petitions_ = supported_petitions;
}

/**
 * @brief 
 * 
 * @return const std::string& 
 */
const std::string& User::getUserName() const {
  return user_name_;
}

/**
 * @brief 
 * 
 * @return const std::string& 
 */
const std::string& User::getUserPassword() const {
  return user_password_;
}

/**
 * @brief Get the Created Petitions object
 * 
 * @return const std::vector<Petition>& 
 */
Petition** User::getCreatedPetitions() const {
  return created_petitions_;
}

/**
 * @brief Get the Supported Petitions object
 * 
 * @return const std::vector<Petition>& 
 */
Petition** User::getSupportedPetitions() const {
  return supported_petitions_;
}

/**
 * @brief 
 * 
 * @param user_name 
 */
void User::setUserName(const std::string& user_name) {
 user_name_ = user_name;
}

/**
 * @brief 
 * 
 * @param user_password 
 */
void User::setUserPassword(const std::string& user_password) {
  user_password_ = user_password;
}

/**
 * @brief 
 * 
 * @param created_petitions 
 */
void User::setCreatedPetitions(Petition** created_petitions) {
  created_petitions_ = created_petitions;
}

/**
 * @brief 
 * 
 * @param supported_petitions 
 */
void User::setSupportedPetitions(Petition** supported_petitions) {
  supported_petitions_ = supported_petitions;
}