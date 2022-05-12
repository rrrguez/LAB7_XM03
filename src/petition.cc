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
 * @file Petition.cc
 * @brief Donde se desarrollan los metodos de la clase Petition contenida
 * en el archivo de cabecera Petition.h
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

#include "../include/petition.h"

/**
 * @brief Construct a new Petition:: Petition object
 * 
 * @param title 
 * @param creator 
 * @param firms 
 * @param description 
 */
Petition::Petition(const std::string& title, const User& creator, const int& firms, const std::string& description, const int& money) {
  title_ = title;
  creator_ = creator;
  firms_ = firms;
  signatures_ = 0;
  description_ = description;
  goal_money_ = money;
  money_ = 0;
}

/**
 * @brief Title getter
 * 
 * @return const std::string& 
 */
const std::string& Petition::getTitle() const {
  return title_;
}

/**
 * @brief Creator getter
 * 
 * @return const User& 
 */
const User& Petition::getCreator() const {
  return creator_;
}

/**
 * @brief Signatures getter
 * 
 * @return const int& 
 */
const int& Petition::getFirms() const {
  return signatures_;
}

/**
 * @brief Description getter
 * 
 * @return const std::string& 
 */
const std::string& Petition::getDescription() const {
  return description_;
}

/**
 * @brief Money getter
 * 
 * @return const int& 
 */
const int& Petition::getMoney() const {
  return money_;
}

/**
 * @brief Money goal getter
 * 
 * @return const int& 
 */
const int& Petition::getGoalMoney() const {
  return goal_money_;
}

/**
 * @brief Title setter
 * 
 */
void Petition::setTitle(const std::string& title) {
  title_ = title;
}

/**
 * @brief Creator setter
 * 
 * @param creator 
 */
void Petition::setCreator(const User& creator) {
  creator_ = creator;
}

/**
 * @brief Firms setter
 * 
 * @param firms 
 */
void Petition::setFirms(const int& firms) {
  firms_ = firms;
}

/**
 * @brief Description setter
 * 
 * @param description 
 */
void Petition::setDescription(const std::string& description) {
  description_ = description;
}

/**
 * @brief Adds a signature to petition
 * 
 */
void Petition::AddFirm() {
  signatures_ = signatures_ + 1;
}

/**
 * @brief Adds amount of money donated to total
 * 
 * @param donative 
 */
void Petition::Donate(const int &donative) {
  money_ = money_ + donative;
}
