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
 * @file Petition.h 
 * @brief Donde se aloja la declaración de la clase Petition y la declaracion
 * de sus metodos. La clase Petition es una clase que se encarga de gestionar
 * el objeto Peticion, en nuestra plataforma, los usuarios tienen asociadas
 * peticiones, las cuales pueden ser creadas y firmadas, todo lo relacionado
 * con las peticiones se encarga esta clase.
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

#include <iostream>

#include "./user.h"

#ifndef _PETITION_
#define _PETITION_

class User;

class Petition {
  public:
    Petition(const std::string&, const User&, const int&, const std::string&, const int&);
    const std::string& getTitle() const;
    const User& getCreator() const;
    const int& getFirms() const;
    const std::string& getDescription() const;
    const int& getMoney() const;
    void setTitle(const std::string&);
    void setCreator(const User&);
    void setFirms(const int&);
    void setDescription(const std::string&);
    //
    void AddFirm();
  private:
    std::string title_;
    User creator_;
    int firms_;
    int signatures_;
    int goal_money_;
    int money_;
    std::string description_;
};

#endif