/**
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Fundamentos de Ingenieria del Software (F.I.S.)
 * Curso: 2º
 * Practica 7: Desarrollo Agil (I)
 * @author FIS_E03 (Fernando - Pablo)
 * Correo: alu0101394763@ull.edu.es
 * @date 06/05/2022
 * 
 * @file main_menu.cc (programa cliente)
 * @brief Programa que nos permite usar una implementacion de una plataforma de
 * recogida de firmas la cual te permite hacer una serie de acciones que toda
 * plataforma como este podria hacer como permitirte registrarte como usuario
 * crear peticiones, firmar peticiones de otros usuarios, etc...
 * 
 * Si quiere saber mas detalles sobre como usar el programa ejecutable,
 * ejecute: ./main_menu --help
 * para mas informacion.
 * 
 * @bug No hay bugs conocidos
 * 
 * Referencias:
 * @see https://www.change.org/es
 * @see https://www.ipetitions.com/
 * @see https://www.causes.com/
 * 
 * @copyright Copyright (c) 2022
 * @version 1.0.0
 * @brief Historial de Revisiones 
 * 06/05/2022 - Creacion (primera version) del codigo:
 *              Solo creamos el archivo, pusimos el comentario de
 *              cabecera y declarado los #include necesarios.
 * 08/05/2022 - Archivo terminado.
 */

/// Donde declaramos las funciones del main_menu.cc y las librerías necesarias
#include "../include/main_functions.h"
#include "../include/data_base.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv); ///< Comprobamos los argumentos del programa
  Data_base Data_base;
  bool user_in_list = false;
  bool sesion = false;
  char  donative, option = 'A';
  std::string search_word,user_name,user_passwd,user_passwd2,title,description;
  int money, total_signature;
  std::cout<<"¡Bienvenido! ¿Qué desea hacer?" << std::endl;
  while (option!='X') {
    if (sesion==false){
      std::cout<< "[B]uscar Peticiones\n [F]Mostrar información de una petición\n [I]niciar Sesión\n [C]rear Usuario\n [X]Salir"<<std::endl;
      std::cin >> option;
      switch (option) {
        case 'B':
          std::cout << "Inserte la palabra a usar como filtro en la búsqueda" << std::endl;
          std::cin >> search_word;
          //Busqueda en la clase; porfa que el mismo metodo imprima la lista
          Data_base.SearchMotor(search_word);
          std::cout << "Para apoyar dichas peticiones, no te olvides de iniciar sesión" << std::endl;
          break;
        case 'I':
          std::cout << "Para iniciar sesión debe introducir el usuario y la contraseña" << std::endl; 
          std::cout << "Introduzca el nombre de usuario" << std::endl;
          std::cin >> user_name;
          std::cout << "Introduzca la contraseña" << std::endl;
          std::cin >> user_passwd;
          user_in_list = Data_base.FindUser(user_name);
          //Igualarlo a la funcion que devuelve si se ha iniciado sesion correctamente, user_in_list
          if (user_in_list == true) {
            std::cout << "La sesión se ha inicidado correctamente" << std::endl;
            sesion = true;
          }
          else {
            std::cout << "Se han introducido los datos de manera incorrecta" << std::endl;
          }
          break;
        case 'C':
          std::cout << "Para crear un nuevo usuario deberá introducir sus datos." << std::endl;
          std::cout << "Introduzca el nombre de usuario" << std::endl;
          std::cin >> user_name;
          std::cout << "Introduzca la contraseña a utilizar" << std::endl;
          std::cin >> user_passwd;
          std::cout << "vuelva a introducir la contraseña" << std::endl;
          std::cin >> user_passwd2;
          if(user_passwd!=user_passwd2){
          std::cout << "se han puesto mal las contraseñas\n por favor intentelo otra vez"<<std::endl;
          }
          else{
            //Igualarlo a la funcion que devuelve si se ha encontrado un usuario con nombre igual, user_in_list
            Data_base.AddUser(user_name, user_passwd);
            std::cout << "Usuario creado de manera correcta, ya puede iniciar sesión" << std::endl;
          }
          break;
        case 'F':
          std::cout << "Introduzca el nombre de la  petición a mostrar su información" << std::endl;
          std::cin >> title;
          Data_base.ReadPetition(title);
  /*bool existe el titulo
  si el titulo exite se mostraria la info y en este caso avisar que inicie sesion
  si no coincide: "el titulo que se ha colocado no esta en la base de peticiones,
  si crees que el titulo esta incompleto pruebe a buscar para saberlo con exactitud"
  */
          break;
        default:
          std::cout << "No se ha encontrado ninguna opción que corresponda con ese carácter\n"
          << "Por favor, inténtelo de nuevo" << std::endl;
          break;
      }
    }
  //--------------------------------------------------------------------------------------------------------------------------------
  //de aqui hasta abajo es menu con perfil de sesion iniciada
  //--------------------------------------------------------------------------------------------------------------------------------
    else {
  std::cout<< "[B]uscar Peticiones\n [C]rear Petición\n [M]is peticiones creadas\n [F]Mostrar información de una petición\n"
  << " [A]poyar Petición\n [S]Cerrar Sesión\n [X]Salir"<<std::endl;
      std::cin >> option;
      switch (option) {
          case 'B':
          std::cout << "Inserte la palabra a usar como filtro en la búsqueda" << std::endl;
          std::cin >> search_word;
          Data_base.SearchMotor(search_word);
            //Busqueda en la clase; porfa que el mismo metodo imprima la lista
          break;
          case 'C':
          std::cout << "Introduzca titulo de la peticion que desea crear"<<std::endl;
          std::cin >> title;
          while(Data_base.FindPetition(title)) {
            std::cout << "Nombre de peticion ya en uso, elija otro" << std::endl;
            std::cin >> title;
          }
          std::cout << "Introduzca una breve descripcion"<<std::endl;
          std::cin >> description;
          std::cout << "Introduzca total de firmas a recaudar"<<std::endl;
          std::cin >> total_signature;
          std::cout << "¿quieres que se recojan donativos?(S/N)"<<std::endl;
          std::cin >> donative;
          if (donative == 'S') {
            std::cout << "¿Qué cantidad quiere recaudar?" << std::endl;
            std::cin >> money;
          }
          else{
            money=0;
          }
          Data_base.AddPetition(title, description, total_signature, money, user_name);
          break;
        case 'S':
          std::cout << "Se ha cerrado la sesión de manera correcta" << std::endl;
          sesion = false;
          break;
        case 'M':
          std::cout << "Ahora mismo usted tiene creada las peticiones: " << std::endl;
          // Mostrar las listas
          // std::cout <<  Data_base.GetUser(user_name).getCreatedPetitions()[0].getTitle() << std::endl;
          Data_base.PrintUserPetitions(user_name);
          break;
        case 'A':
          std::cout << "¿Qué petición quiere apoyar?" << std::endl;
          std::cin >> search_word;
          if(Data_base.FindPetition(search_word)) {
            Data_base.getPetition(search_word).AddFirm();
            std::cout << "¿Quiere hacer un donativo a dicha petición [S/N]" << std::endl;
            std::cin >> donative;
            if (donative == 'S') {
              std::cout << "¿Qué cantidad quiere introducir para realizar el donativo?" << std::endl;
              std::cin >> money;
              Data_base.getPetition(search_word).Donate(money);
            } else {
              std::cerr << "Nombre de peticion no es correcto" << std::endl;
            }
          }
          break;
        case 'F':
          std::cout << "Introduzca el nombre de la  petición a mostrar su información" << std::endl;
          std::cin >> title;
          /*bool existe el titulo
          si el titulo exite se mostraria la info
          si no coincide: "el titulo que se ha colocado no esta en la base de peticiones,
            si crees que el titulo esta incompleto pruebe a buscar para saberlo con exactitud"
          */
          break;
        default:
          std::cout << "No se ha encontrado ninguna opción que corresponda con ese carácter\n"
          << "Por favor, inténtelo de nuevo" << std::endl;
          break;
      }
    }
  }
  return 0;
}