#include "definiciones.h"

void delay(int number_of_seconds);

extern void limpiarEntradaDatos(void)
  {
    int limpiar;

        while((limpiar = getchar()) != '\n' && limpiar != EOF) { }

        return;
  }



/**
 *@fn Procedimiento Muestra las instrucciones del programa.
 */
extern void mostrarInstrucciones(char autores[], char instrucciones[])
{
  system("clear");
  printf("\n\t\tCreedex Minigames\n\n");
  printf("Desarrollada por:\n");
  printf("\t%s\n\n", autores);
  printf("Descripcion del programa:\n");
  printf("\t%s\n\n", instrucciones);
  printf("Presiona la tecla enter para continuar:\n");
  getchar();

  system("clear");


  return;

}

/**
*@fn Funcion que muestra el menu principal.
*/

extern void mostrarMenuPrincipal(void)
{
  printf("\n\t\tMINIGAMES!\n\n");
  printf("\n\t\t[A]\tGuess.it");
  printf("\n\t\t[B]\tMastermind");
  printf("\n\t\t[C]\tPiedra Papel o Tijera");
  printf("\n\n\t\t[S]\tSalir\n");

  return;
}

int aleatorio(int rand) 
{
  
  int random, inicio=0, final=5;
  long int tiempo;
  
  random = inicio + rand % final;
  
  return random;
}


extern void jugarG(void)
{
  int numeroA,numU, intentos = 0, numI;
  time_t inicio, fin, res;
  char opcion, nombre[30], nombreN[30];
  FILE *fp;

  do
    {
      system("clear");

      
      fp = fopen("recordGuessIt.txt", "r");
      if(fp == NULL)
	{
	  printf("\nArchivo no disponible.\n");
	  exit(1);
	}
      fscanf(fp," %[^\t]%d", nombre,&numI);
      fclose(fp);
      srand(time(NULL));
      numeroA = rand () % 1000 + 1;
      
      printf("\tHay un numero oculto entre el numero 1 y el numero 1000, crees poder adivinarlo???\n");
      printf("\tRecord Actual: %s con %d Intentos!!\n\n", nombre, numI);
      
      inicio = time(0);
      do
	{
	  printf("Ingresa un numero: ");
	  scanf(" %d", &numU);
	  
	  if(numU < numeroA)
	    {
	      printf("\n\n\tMuy bajo!, intenta con uno mayor.\n");
	      intentos++;
	      
	    }
	  else if(numU > numeroA)
	    {
	      printf("\n\n\tMuy alto!, intenta con uno menor.\n");
	      intentos++;
	    }
	}while(numU != numeroA);
      
      fin = time(0);
      res = fin - inicio;
      
      system("clear");
      printf("\n\nCorrecto!, El numero oculto era %d y lo adivinaste en: %d Intentos!.\n\n", numeroA, intentos);
      printf("Tardaste: [%ld] segundos!!!\n", res);
      if(intentos < numI)
	{
	  printf("\nExcelente trabajo! El record anterior de %s era de %d y tu lo superaste con %d intentos!\n", nombre, numI, intentos);
	  printf("Con que nombre desearias grabar tu record?: ");
	  scanf(" %[^\n]", nombreN);
	  printf("\nFelicidades %s, haz establecido un nuevo record de %d intentos!\n\n", nombreN, intentos);
	  fp = fopen("recordGuessIt.txt", "w");
	  fprintf(fp," %s\t%d", nombreN, intentos);
	  fclose(fp);
	}
      else printf("\nUfff, estuviste cerca de vencer el record de %s, que tenia %d intentos, tal vez la proxima...\n\n", nombre, numI); 
	
      printf("Quieres intentar otra vez? [S]Si [N]No: ");
      scanf(" %c", &opcion);
      intentos = 0;
      
    }while(opcion != 'n' && opcion !='N');
    
  system("clear");
  
    return;
}

void delay(int number_of_seconds)
{
  int milli_seconds = 1000 * number_of_seconds;

  clock_t start_time = clock();

  while(clock() < start_time + milli_seconds);
}

extern void jugarM(void)
{
  srand(time(NULL));
  int lon, n,i=0,j=0,k=0;
  int random;
  int  arr[10]={0};
  char palabras[6][20] = {{"Negro"},{"Azul"},{"Verde"},{"Aguamarina"},{"Rojo"}};
  char colores[6][20] = {{"color 0F"},{"color 1F"},{"color 2F"},{"color 3F"},{"color 4F"}};
  char temp[10];
  char revancha, nombreA[30], nombre[30], nombreN[30];
  FILE *fp;
  int record, Nrecord;
  
  

  fp = fopen("recordMasterMind.txt", "r");
  if(fp == NULL)
    {
      printf("\nArchivo no disponible.\n");
      exit(1);
    }
  fscanf(fp," %[^\t]%d", nombreA,&record);
  fclose(fp);
  //system("color F0");
  system("clear");
  printf("\n\n\t\t\t\t\tMASTERMIND\n");
  
  
  printf("\n\tSe mostrara colores en pantalla, tendra que memorizarlos y despues imprimirlos.\n");
  printf("\tRecord Actual: %s con %d PUNTOS!\n", nombreA, record);
  printf("\nPresiona la tecla 'ENTER' para comenzar!\n");
  limpiarEntradaDatos();
  getchar();
  
  for(i=1; i<10; i++)
    {
      printf("\n\t\t\t\t\tNivel %d.\n",i);
      for (j = 0; j < i; j++) 
	{
	  random = aleatorio(rand());
	  
	  //printf("\tSu numero aleatorio %d es %d: \n", j + 1, random);
	  
	  arr[j] = random;
	  // system(colores[arr[j]]);
	  
	  printf("\tSu color es es %s: \n", palabras[arr[j]]);
	  sleep(1);
	  //delay(3);
	  //system("color F0");
	  //delay(1);
	  
	  
	  
	}

      //system("color F0");
      
      for(k=0; k < i; k++)
	{
	  system("clear");
	  printf("\t\nEscribe el color(es) en el orden en el que los viste (Presiona ENTER despues de cada color):\n\t");
	  scanf(" %s", temp);
	 	  
	  if (strcmp(temp, palabras[arr[k]]) == 0) 
	    {
	      printf("\tCorrecto pasa al siguiente nivel\n");
	    }else
	    {
	      // printf("\n\n\tEres tonto\n");
	      printf("\tLlegaste al nivel %d\n",i);
	      if(i > record)
		{
		  printf("\n\tFELICIDADES! EL RECORD ERA %d y lo superaste!\n", record);
		  printf("\tIngresa tu nombre para registrarte!: ");
		  scanf(" %[^\n]", nombre);
		  printf("\n\tNuevo Record! Felicidades %s\n", nombre);
		  fp = fopen("recordMasterMind.txt", "w");
		  fprintf(fp,"%s\t%d",nombre, i);
		  fclose(fp);
		}
	      fp = fopen("recordMasterMind.txt", "r");
	      fscanf(fp," %[^\t]%d",nombreN, &Nrecord);
	      fclose(fp);
	      printf("\n\n\tEl record lo tiene %s con un total de %d NIVELES!\n\n", nombreN, Nrecord);
	      printf("\tGracias por jugar MASTERMIND\n\n");
	      printf("Jugar otra vez? [S]Si [N]No: ");
	      scanf(" %c", &revancha);
	      if(revancha == 's' || revancha == 'S') return jugarM();
	      else exit(1);
     	      
	    }
	}	
      
    }
  
}

void jugarP(void)
{

  char opc[3][7] = {"ROCA","PAPEL","TIJERA"};
  char decision, opcion;
  int numeroA, puntosU = 0, puntosC = 0, ronda, i = 0, j = 0;
  
  do
    {
      system("clear");
      printf("\tBIENVENIDO A ROCA PAPEL O TIJERA!\n");
      printf("\nCuantas rondas quieres jugar?: ");
      scanf(" %d", &ronda);
      
      do
	{
	  srand(time(NULL));
	  numeroA = rand () % 3;
	  
	  system("clear");
	  printf("Ronda: %d/%d", ++j, ronda);
	  printf("\n[R]Roca\t[P]Papel\t[T]Tijera\n\n");
	  printf("Escoge una de las 3 opciones: ");
	  scanf(" %c", &decision);
	  printf("\n");
	  
	  //Eleccion del usuario
	  if((decision == 'R') || (decision == 'r'))printf("Escogiste: ROCA");
	  else if((decision == 'P') || (decision == 'p'))printf("Escogiste: PAPEL");
	  else if((decision == 'T') || (decision == 't'))printf("Escogiste: TIJERA");
	  //CPU
	  printf("\nJuan escogio: %s\n\n", opc[numeroA]);
	  sleep(1);
	  
	  //Piedra
	  if((decision == 'R')||(decision == 'r'))
	    {
	      if(numeroA == 2)
		{
		  printf("Excelente! ganaste");
		  puntosU++;
		}
	      else if(numeroA == 0)
		{
		  printf("Empate...");
		}
	      else if(numeroA == 1)
		{
		  printf("JAJAJAJA Perdiste!");
		  puntosC++;
		} 
	    }
	  //Papel
	  if((decision == 'P')||(decision == 'p'))
	    {
	      if(numeroA == 2)
		{
		  printf("JAJAJAJAJA Perdiste!");
		  puntosC++;
		}
	      else if(numeroA == 0)
		{
		  printf("Excelente! ganaste!");
		  puntosU++;
		}
	      else if(numeroA == 1)
		{
		  printf("Empate...");
		}
	    }
	  //Tijera
	  if((decision == 'T')||(decision == 't'))
	    {
	      if(numeroA == 2)
		{
		  printf("Empate...");
		}
	      else if(numeroA == 0)
		{
		  printf("JAJAJAJA Perdiste!");
		  puntosC++;
		}
	      else if(numeroA == 1)
		{
		  printf("Excelente! ganaste!");
		  puntosU++;
		}
	      
	    }
	  
	  //Seguimiento de ronda
	  printf("\tPuntuacion --> Jugador: %d.\tJuan: %d", puntosU, puntosC);
	  i++;
	  if(i < ronda)
	    {
	      limpiarEntradaDatos();
	      printf("\n\nPresiona la tecla ENTER para pasar a la siguiente ronda.\n");
	      getchar();
	      
	    }//Ultima ronda
	  else if (i <= ronda)
	    {
	      limpiarEntradaDatos();
	      printf("\n\nPresiona la tecla ENTER para ver los resultados finales...\n");
	      getchar();
	    }
	  
	  system("clear");
	  
	  
	}while(i < ronda);
      
      
      system("clear");
      printf("\tGRACIAS POR JUGAR!\n\nPuntuacion final:\tJugador: %d.\tJuan: %d.\n\n", puntosU, puntosC);
      
      if(puntosU >= puntosC)
	{
	  printf("\n\nFELICIDADES GANASTE %d-%d.!\n\n", puntosU, puntosC);
	}
      else if(puntosU < puntosC)
	{
	  printf("Lastima, suerte a la proxima :(\n\n");
	}
      
      puntosU = 0;
      puntosC = 0;
      i = 0;
      ronda = 0;
      j = 0;
      printf("\n\nRevancha? [S]Si\t[N]No: ");
      scanf(" %c", &opcion);
    }while((opcion == 's')||(opcion == 'S'));

  system("clear");
  printf("Saliendo...\n\n");
  sleep(1);
  system("clear");
  
}

extern void GenerarEquipos(void)
{
	
}
