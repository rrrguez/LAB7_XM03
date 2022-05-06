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
 * @file main_functions.h 
 * @brief Donde se aloja la declaración de las funciones del archivo cliente
 * de nuestro programa.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 06/05/2022 - Creacion (primera version) del codigo:
 *              Solo creamos el archivo, pusimos el comentario de
 *              cabecera y declarado los #include necesarios.
 * 
 * 08/05/2022 - Archivo terminado.
 */

#include <iostream>
#include <vector>
#include <string>

void HelpMessage(const std::string& kProgramName, 
                 const std::string& kHelp);
void WrongNumberOfArguments(const std::string& kProgramName, 
                            const std::string& kHelp);
void Usage(const int& argc, char* argv[]);
