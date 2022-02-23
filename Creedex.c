/**
 * @file Creedex.c
 * @brief Videojuego
 * @details MINIGAMES
 *
 * @author Desarrolladores del proyecto
 *   Jose Pablo Montero C
 * @date Fecha de creaciòn
 *   02 de Marzo 2021
 *
 */

#include "definiciones.h"

/**@brief Prototipos de funcion*/
void limpiarEntradaDatos(void);
void mostrarInstrucciones(char[],char[]);
void mostrarMenuPrincipal(void);
int generarNumerosAleatorios(int inicio, int final);
void jugarG(void);
void jugarM(void);
void jugarP(void);

int main(void)
{
  char opcion1;
  
  mostrarInstrucciones("Creedex Entertainment","Minigames!");
  
  do
    {
     
      mostrarMenuPrincipal();
      printf("\n\tSelecciona una opcion: ");
      scanf(" %c", &opcion1);
      
      switch(opcion1)
	{
	case 'a':
	  
	 
	  jugarG();
	 	  
	  break;
	  
	case 'A':
	  
	 
	  jugarG();
	 	  				 	  
	  break;

	case 'b':
	   
	  jugarM();
	  
	  break;
	  
	case 'B':
	  
	  jugarM();
	  
	  
	  break;
	case 'C':
	  jugarP();

	  break;

	case 'c':
	  jugarP();
	  	  
	} //Cierra switch
      
    }while((opcion1 != 'S')&&(opcion1 != 's'));

  system("clear");
  printf("\n\n");
  return 0;
}



