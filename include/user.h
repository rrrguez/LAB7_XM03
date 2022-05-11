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
 * @file User.h 
 * @brief Donde se aloja la declaración de la clase User y la declaracion
 * de sus metodos. La clase User es una clase que se encarga de todo lo
 * relacionado con los usuarios, define el objeto usuario (registrado) para
 * usarlo, y le permite crear peticiones, firmar otras peticiones que tengan
 * otros usuarios, etc...
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
#include <vector>

#ifndef _USER_
#define _USER_

class Petition;

class User {
  public:
    User();
    User(const std::string&, const std::string&);
    User(const std::string&, const std::string&, Petition**&, Petition**&);
    const std::string& getUserName() const;
    const std::string& getUserPassword() const;
    Petition** getCreatedPetitions() const;
    Petition** getSupportedPetitions() const;
    void setUserName(const std::string&);
    void setUserPassword(const std::string&);
    void setCreatedPetitions(Petition**);
    void setSupportedPetitions(Petition**);
  private:
    std::string user_name_;
    std::string user_password_;
    Petition** created_petitions_;
    Petition** supported_petitions_;
};

#endif