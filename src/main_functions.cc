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
 * @file main_functions.cc
 * @brief Donde se aloja el desarrollo y la implementación de las funciones
 * de nuestro archivo cliente.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0.0
 * @brief Historial de Revisiones 
 * 06/05/2022 - Creacion (primera version) del codigo:
 *              Solo creamos el archivo, pusimos el comentario de
 *              cabecera y declarado los #include necesarios.
 * 
 * 08/05/2022 - Archivo terminado.
 */

#include "../include/main_functions.h"

/// nos permite usar std::cout y std::cerr usando cout y cerr directamente
/// sin usar malas practicas como "using namespace std"
using std::cout;
using std::cerr;

/**
 * @brief Función que solo muestra un mensaje de ayuda por pantalla cuando se
 * introduce la palabra clave para pedir instrucciones más detalladas sobre
 * como usar el programa.
 * 
 * @param kProgramName Es el nombre del actual programa, usado por el mensaje
 * @param kHelp palabra clave para pedir instrucciones más detalladas
 */
void HelpMessage(const std::string& kProgramName,
                 const std::string& kHelp) {
  cout << "\n" << kProgramName << " (" <<  kHelp << ")\n\n";
  cout << "--help ==> Palabra clave para pedir indicaciones sobre como\n";
  cout << "usar el programa\n\n";
  cout << "Este programa simula a una plataforma de recogida de firmas en\n";
  cout << "el que podemos crear usuarios, peticiones, firmar peticiones de\n";
  cout << "otro usuarios, etc..., para ejecutar el programa basta con\n";
  cout << "llamarlo sin parametros, y el unico parametro que acepta el\n";
  cout << "programa es \"" << kHelp << "\" para mostrar este mensaje\n";
  cout << "pero si se introduce otro comando no se aceptara.\n";
  cout << "Por ultimo, todo el funcionamiento del programa se desarrolla\n";
  cout << "cuando se esta ejecutando, a la hora de crear usuarios\n";
  cout << "peticiones, firmarlas, etc... es todo en el programa.\n\n";
}

/**
 * @brief Función que informa al usuario de que ha introducido un numero
 * incorrecto de argumentos.
 * 
 * @param kProgramName Nombre del programa.
 * @param kHelp Palabra clave para pedir instrucciones específicas al programa.
 */
void WrongNumberOfArguments(const std::string& kProgramName, 
                            const std::string& kHelp) {
  cerr << "Warning!, se ha pasado al programa un número incorrecto de ";
  cerr << "argumentos";
  cerr << "\nPruebe: '" << kProgramName << " " << kHelp << "' ";
  cerr << "para mas información\n";
}

/**
 * @brief funcion que comprueba que los argumentos de entrada al programa son
 * correctos
 * 
 * @param argc numero de argumentos dados al programa (incluyendo el nombre)
 * @param argv doble puntero de caracteres a los argumentos del programa
 */
void Usage(const int& argc, char* argv[]) {
  const std::string kProgramName{argv[0]};
  const std::string kHelp{"--help"};
  if (argc != 1) {
    const std::string kHelpUser{argv[1]};
    if ((argc == 2) && (kHelp == kHelpUser)) {
      HelpMessage(kProgramName, kHelp);
      exit(EXIT_SUCCESS);
    } else {
      WrongNumberOfArguments(kProgramName, kHelp);
      exit(EXIT_FAILURE);
    }
  }
}
