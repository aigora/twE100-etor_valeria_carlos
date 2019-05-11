#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declaración de estructura definida para USUARIOS
typedef struct 
{
	int num_usuario;
	char DNI[100];
	char nombre[100];
	char apellido[100];
	char email[100];
} Usuario;

// Declaración de estructura definida para LIBROS
typedef struct 
{
	int num_libro;	
	char ISBN[100];
	char titulo[100];
	char genero[100];
	char autor[100];	
} Libro;

// Declaración de estructura definida para PRESTAMOS
typedef struct 
{
	int num_prestamo;
	char DNI[100];
	char ISBN[100];
	char fecha_prestamo[100];
	char fecha_devolucion[100];	
} Prestamo;


// Declaración de prototipos de funciones
void menu_general(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[]);
void menu_usuarios(Usuario mis_usuarios[], Prestamo mis_prestamos[]);
void menu_libros(Libro mis_libros[], Prestamo mis_prestamos[]);
void menu_prestamos(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[]);
void alta_usuario(Usuario mis_usuarios[]);
void listado_usuarios_por_apellido(Usuario mis_usuarios[]);
void grabar_usuarios_fichero(Usuario mis_usuarios[]);
void leer_usuarios_fichero (Usuario mis_usuarios[]);
void eliminar_espacios (char sLiteral[]);
void ordenar_usuarios (Usuario mis_usuarios[]);
int busqueda_usuarios(Usuario mis_usuarios[]);
void modificacion_usuarios(Usuario mis_usuarios[], Prestamo mis_prestamos[]);
void baja_usuarios(Usuario mis_usuarios[], Prestamo mis_prestamos[]);
int comprobar_email(char email[]);
void alta_libro(Libro mis_libros[]);
void listado_libros_ordenado (Libro mis_libros[], int iOpcion);
void grabar_libros_fichero(Libro mis_libros[]);
void leer_libros_fichero (Libro mis_libros[]);
void ordenar_libros_titulo (Libro mis_libros[]);
void ordenar_libros_autor (Libro mis_libros[]);
void ordenar_libros_genero (Libro mis_libros[]);
int busqueda_libros(Libro mis_libros[]);
void modificacion_libros(Libro mis_libros[], Prestamo mis_prestamos[]);
void baja_libros(Libro mis_libros[], Prestamo mis_prestamos[]);
void leer_prestamos_fichero (Prestamo mis_prestamos[]);
void grabar_prestamos_fichero(Prestamo mis_prestamos[]);
void prestamo_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[]);
void listado_prestamos_por_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[]);
void ordenar_prestamos (Prestamo mis_prestamos[]);
void devolucion_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[]);
void consulta_prestamos_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[]);
void consulta_prestamos_usuario(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[]);



//***********************************************************
//**                                                       **
//**                  FUNCION MAIN                         **
//**                                                       **
//***********************************************************
int main()
{
	// Declaración de estructuras de Usuarios, Libros y Préstamos.  Estas estructuras se pasan en argumentos por referencia a las funciones que los necesitan
    Usuario mis_usuarios[100];
    Libro mis_libros[100]; 
	Prestamo mis_prestamos[100];   
    
    // Carga inicial de las estructuras a partir de los datos almacenados en los ficheros correspondientes
    leer_usuarios_fichero (mis_usuarios);
    leer_libros_fichero (mis_libros);
    leer_prestamos_fichero (mis_prestamos);    
    
    // Llamada al menú general
    menu_general(mis_usuarios, mis_libros, mis_prestamos);
    
    // En lugar de cerrarse el programa, espera que se pulse una tecla para finalizar
    system("pause");
    
    return 0;
}



//***********************************************************
//**                                                       **
//**                  FUNCION MENU_GENERAL                 **
//**                                                       **
//***********************************************************
void menu_general(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[])
{   
int iOpcion;

	
	do{
       
    	// ciclo DO-WHILE hasta que se introduzca un número de opción válido
        do {
			system("cls");
			printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	    	printf("\n_______________________MENU PRINCIPAL______________________________\n\n");
        	printf("\n1. Gestion de Usuarios.");
        	printf("\n2. Gestion de Libros.");
        	printf("\n3. Gestion de Prestamos.");
	        printf("\n4. Salir.");
    	    printf("\n___________________________________________________________________\n");
        	printf("\n\n\nIntroduzca su opcion: ");
    		fflush(stdin);        	
        	scanf("%d",&iOpcion);
        	printf("\n");
        } while(iOpcion < 1 || iOpcion > 4);
        
        // Según la opción elegida, se llama a una u otra función.  A este nivel tan solo menús de usuarios, libros y préstamos
        switch (iOpcion)
		{
            case 1:
                
				menu_usuarios(mis_usuarios, mis_prestamos);
                
            break;
            
            case 2:
            	
	            menu_libros(mis_libros, mis_prestamos);
				
            break;
            
            case 3:
            	
                menu_prestamos(mis_usuarios, mis_libros, mis_prestamos);
				
            break;	
                        	
			case 4:
                
				printf("\nSaliendo del programa.\n");
				
			break;				
          
            default:
                printf("\nOpcion no valida\n");
             
        
		}
    } while (iOpcion!= 4);
    
			
}


//***********************************************************
//**                                                       **
//**                  FUNCION MENU_USUARIOS                **
//**                                                       **
//***********************************************************
void menu_usuarios(Usuario mis_usuarios[], Prestamo mis_prestamos[])
{   
int iOpcion;
int iResultado;

	
	do{
       
        // ciclo DO-WHILE hasta que se introduzca un número de opción válido
        do {
			system("cls");
			printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	    	printf("\n_______________________MENU USUARIOS_______________________________\n\n");
        	printf("\n1. Alta de Usuario.");
        	printf("\n2. Modificar datos de un Usuario.");
        	printf("\n3. Borrar Usuario.");
        	printf("\n4. Busqueda de Usuarios.");
	        printf("\n5. Listado de Usuarios ordenado por Apellido.");
 	        printf("\n6. Volver a menu general.");
    	    printf("\n___________________________________________________________________\n");
        	printf("\n\n\nIntroduzca su opcion: ");
			fflush(stdin);        	
        	scanf("%d",&iOpcion);
        	printf("\n");
        } while(iOpcion < 1 || iOpcion > 6);

        // Según la opción elegida, se llama a una u otra función.  A este nivel tan solo funciones relacionadas con gestión de USUARIOS        
        switch (iOpcion)
		{
            case 1:
                
				alta_usuario(mis_usuarios);
				// se graba en fichero cuando hay un alta, una modificación o una baja de usuarios
				grabar_usuarios_fichero (mis_usuarios);
                
            break;
            
            case 2:
            	
				modificacion_usuarios(mis_usuarios, mis_prestamos);
				// se graba en fichero cuando hay un alta, una modificación o una baja de usuarios				
				grabar_usuarios_fichero (mis_usuarios);
				
            break;	
                        
			case 3:
				
				baja_usuarios(mis_usuarios, mis_prestamos);
				// se graba en fichero cuando hay un alta, una modificación o una baja de usuarios
				grabar_usuarios_fichero (mis_usuarios);
			
			break;	
			
			case 4:
                
				iResultado = busqueda_usuarios(mis_usuarios);
                system("pause");				

			break;	
			
			case 5:
                
				listado_usuarios_por_apellido(mis_usuarios);
				// se graba en fichero cuando se reordena la estructura de usuarios por apellido				
				grabar_usuarios_fichero (mis_usuarios);				
				
            break;
					
			case 6:
                
				printf("\n7. Volver a menu general.\n");
				
			break;				
          
            default:
                printf("\nOpcion no valida\n");
                system("pause");                
        
		}
    } while (iOpcion!= 6);
    
			
}


//***********************************************************
//**                                                       **
//**                  FUNCION MENU_LIBROS                  **
//**                                                       **
//***********************************************************
void menu_libros(Libro mis_libros[], Prestamo mis_prestamos[])
{   
int iOpcion;
int iResultado;

	
	do{
       
        // ciclo DO-WHILE hasta que se introduzca un número de opción válido
        do {
			system("cls");
			printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	    	printf("\n_______________________MENU LIBROS_________________________________\n\n");
        	printf("\n1. Alta de Libro.");
        	printf("\n2. Modificar datos de un Libro.");
        	printf("\n3. Borrar Libro.");
        	printf("\n4. Consulta de datos de un Libro.");
	        printf("\n5. Listado de Libros ordenado por Titulo.");
    	    printf("\n6. Listado de Libros ordenado por Autor."); 
    	    printf("\n7. Listado de Libros ordenado por Genero."); 					 
	        printf("\n8. Volver a menu general.");
    	    printf("\n___________________________________________________________________\n");
        	printf("\n\n\nIntroduzca su opcion: ");
        	fflush(stdin);        	
        	scanf("%d",&iOpcion);
        	printf("\n");
        } while(iOpcion < 1 || iOpcion > 8);

        // Según la opción elegida, se llama a una u otra función.  A este nivel tan solo funciones relacionadas con gestión de LIBROS             
        switch (iOpcion)
		{
            case 1:
                
				alta_libro (mis_libros);
				// se graba en fichero cuando hay un alta, una modificación o una baja de libros				
				grabar_libros_fichero (mis_libros);
                
            break;
            
            case 2:
            	
				modificacion_libros (mis_libros, mis_prestamos);
				// se graba en fichero cuando hay un alta, una modificación o una baja de libros					
				grabar_libros_fichero (mis_libros);
				
            break;	
                        
			case 3:
				
				baja_libros (mis_libros, mis_prestamos);
				// se graba en fichero cuando hay un alta, una modificación o una baja de libros					
				grabar_libros_fichero (mis_libros);
			
			break;	
			
			case 4:
                
				iResultado = busqueda_libros (mis_libros);
                system("pause");

			break;	
			
			case 5:
                
                listado_libros_ordenado (mis_libros, 1);
				// se graba en fichero cuando se reordena la estructura de libros     
				grabar_libros_fichero (mis_libros);		
				
            break;
			
			case 6:
                
                listado_libros_ordenado (mis_libros, 2);
				// se graba en fichero cuando se reordena la estructura de libros                    
				grabar_libros_fichero (mis_libros);	                
				
			break;
			
			case 7:
                
                listado_libros_ordenado (mis_libros, 3);
				// se graba en fichero cuando se reordena la estructura de libros                    
				grabar_libros_fichero (mis_libros);	                
				
			break;					
				
			case 8:
                
				printf("\n7. Volver a menu general.\n");
				
			break;				
          
            default:
                printf("\nOpcion no valida\n");
                system("pause");                
        
		}
    } while (iOpcion!= 8);
    
			
}


//***********************************************************
//**                                                       **
//**                  FUNCION MENU_PRESTAMOS               **
//**                                                       **
//***********************************************************
void menu_prestamos(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[])
{   
int iOpcion;

	
	do{
       
        // ciclo DO-WHILE hasta que se introduzca un número de opción válido
        do {
			system("cls");
			printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	    	printf("\n_______________________MENU PRESTAMOS______________________________\n\n");
        	printf("\n1. Prestamo de Libro.");
        	printf("\n2. Devolucion de Libro.");
        	printf("\n3. Consulta de estado de prestamo de un Libro.");
	        printf("\n4. Consulta de prestamos de un Usuario.");
    	    printf("\n5. Listado de prestamos ordenado por libro."); 		 
	        printf("\n6. Volver a menu general.");
    	    printf("\n___________________________________________________________________\n");
        	printf("\n\n\nIntroduzca su opcion: ");
        	fflush(stdin);        	
        	scanf("%d",&iOpcion);  	
        	printf("\n");
        } while(iOpcion < 1 || iOpcion > 6);
  
        // Según la opción elegida, se llama a una u otra función.  A este nivel tan solo funciones relacionadas con gestión de PRESTAMOS            
        switch (iOpcion)
		{
            case 1:
                
				prestamo_libro(mis_usuarios, mis_libros, mis_prestamos);
				// se graba en fichero cuando hay un préstamo o una devolución					
				grabar_prestamos_fichero (mis_prestamos);				
                system("pause");				
                
            break;
            
            case 2:
            	
				devolucion_libro(mis_usuarios, mis_libros, mis_prestamos);
				// se graba en fichero cuando hay un préstamo o una devolución							
				grabar_prestamos_fichero (mis_prestamos);
				
            break;	
                        
			case 3:
				
				consulta_prestamos_libro(mis_usuarios, mis_libros, mis_prestamos);
			
			break;	
			
			case 4:
                
				consulta_prestamos_usuario(mis_usuarios, mis_libros, mis_prestamos);

			break;	
			
			case 5:
                
                listado_prestamos_por_libro (mis_usuarios, mis_libros, mis_prestamos);
				// se graba en fichero cuando se reordena la estructura de préstamos
				grabar_prestamos_fichero (mis_prestamos);
				
            break;
			
				
			case 6:
                
				printf("\n6. Volver a menu general.\n");
                //system("pause");				
				
			break;				
          
            default:
                printf("\nOpcion no valida\n");
                system("pause");                
        
		}
    } while (iOpcion!= 6);
    
			
}

//***********************************************************
//**                                                       **
//**                  FUNCION ALTA_USUARIO                 **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_USUARIOS par dar de alta un nuevo usuario.
//
// El nuevo usuario se añade al final del vector de estructura de usuarios. --> para ello se hace un recorrido hasta el último registro.
// Se controla que el DNI del nuevo usuario no exista ya, en caso contrario pide de nuevo del DNI hasta introducir uno válido.
// Al introducir el EMAIL, se llama a la función comprobar_email para verificar el formato introducido (que tenga un @ y un . posterior).
// Da un mensaje indicando que se ha dado correctamente el usuario.
//
void alta_usuario(Usuario mis_usuarios[])
{   
int iOpcion;


 	int i; 
    int longitud;
    int x=0;
    int iContador;
    int iResultado;
    int iMaxRegistros;
    char sDNI[100];
    
    // Recorrido de la estructura de USUARIOS para determinar el número de registros
	for(iMaxRegistros = 0 ; (strcmp(mis_usuarios[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++);
       
	// num_usuario es un campo de valor único (no se repite) y se usa en modificación y borrado de Usuarios       
	// Se asigna a num_usuario el siguiente número secuencial según el número de registro
	mis_usuarios[iMaxRegistros].num_usuario = iMaxRegistros;
	
	system("cls");
	printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	printf("\n_____________________ALTA DE USUARIOS______________________________\n\n");

	// bucle DO-WHILE para verificar que no se duplica el DNI (no se puede repetir).  No sale del bucle hasta que se introduce un DNI no duplicado.
    do
	{
     	printf("Numero de DNI: ");
		fflush(stdin); 
		fgets(sDNI, 10, stdin);
		eliminar_espacios(sDNI);
 	 	// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
		for(iContador = 0 ; ( (strcmp(mis_usuarios[iContador].DNI, sDNI)!=0) && (iContador <= iMaxRegistros ) ); iContador++);
		// Si el recorrido anterior ha finalizado por haber encontrado el DNI duplicddo, se avisa y se vuelve a pedir
		if (iContador <= iMaxRegistros)
			printf("\nEl DNI %s corresponde a otro Usuario existente (no puede haber duplicados).\n\n", mis_usuarios[iContador].DNI);	
	} while ( iContador <= iMaxRegistros );   
	strcpy (mis_usuarios[iMaxRegistros].DNI, sDNI);
		    
	printf("Nombre del Usuario: ");
	fflush(stdin);
	fgets(mis_usuarios[iMaxRegistros].nombre, 15, stdin);
	eliminar_espacios(mis_usuarios[iMaxRegistros].nombre);
        
    printf("Apellido del Usuario: ");
    fflush(stdin);
	fgets(mis_usuarios[iMaxRegistros].apellido, 25, stdin);
	eliminar_espacios(mis_usuarios[iMaxRegistros].apellido);
              
	// Bucle DO-WHILE que se repita mientras no se cumpla con un formato válido del EMAIL introducido (contiene @ y un . posterior).
    do
	{
        printf ("e-mail del alumno: ");
        fflush(stdin);
        fgets(mis_usuarios[iMaxRegistros].email, 40, stdin);
		eliminar_espacios(mis_usuarios[iMaxRegistros].email);      
        iResultado = comprobar_email(mis_usuarios[iMaxRegistros].email);
 	  
		if (iResultado==2)
			printf("\nDireccion de email valida\n\n")  ;
		else
			printf("\nDireccion de email no valida\n\n");
	} while ( iResultado!=2 );
	
	printf("\nEl Usuario ha sido dado de alta correctamente.\n\n");
	system("pause");
	
}



//***********************************************************
//**                                                       **
//**                  COMPROBAR EMAIL                      **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde 'alta_usuario' y 'modificacion_usuario' al pedir un EMAIL
// Se comprueba que la dirección de correo electrónico sea válida, para lo que la cadena debe contener un '@' y un '.' posterior.
// La función devuelve el valor de la comprobación, que deberá ser un 2 para que sea considerada válida.
//
int comprobar_email(char email[])
{   
    int iLongitud;
    int iResultado=0;
    int iContador;
    
    // Almacena la longitud de la cadena pasada como parámetro
	iLongitud=strlen(email);

	// Hace recorrido de la cadena de caracteres EMAIL mientras no se llega al final o no se encuentra un '#'
	for(iContador = 0; (iContador<iLongitud && iResultado!=1); iContador++)
	{ 
		if (email[iContador] == '@')
			iResultado=1;
	}		

	// Tan solo busca un '.' en caso de que previamente haya encontrado un '@'
	if (iResultado==1)
	{
		while(iContador<iLongitud && iResultado!=2)
		{
			iContador++;
			if (email[iContador]=='.') iResultado=2;
		}		
	}	  
	
	// Devuelve el resultado de la comprobación
	return (iResultado);

}


//***********************************************************
//**                                                       **
//**        FUNCION LISTADO_USUARIOS_APELLIDO              **
//**                                                       **
//***********************************************************
//
// Esta función es invocada por MENU_USUARIOS
//
// Invoca a la función ordenar_usuario, que se encarga de ordenar el vector de estructura de usuarios por el campo 'apellido'.
// Posteriormente hace un recorrido por el vector de la estructura de usuarios y por cada uno muestra en pantalla todos los campos.
//
void listado_usuarios_por_apellido(Usuario mis_usuarios[])
{   
    int iContador;
    
    // Se pasa como parámetro el vector a la estructura 'mis_usuarios' y lo devuelve ordenado por el campo 'apellido'
	ordenar_usuarios (mis_usuarios);    
    	    
	system("cls");
	printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	printf("\n______________LISTADO DE USUARIOS POR APELLIDO_____________________\n\n");
 
	printf("\n   # %-11s %-15s %-25s %-15s","DNI", "NOMBRE","APELLIDO", "EMAIL");
	printf("\n   _ ___         ______          ________                  _____\n");
 
 	// Recorrido al vector de la estructura de usuarios... mientras que no se encuentre el DNI nulo
	for(iContador = 0 ; (strcmp(mis_usuarios[iContador].DNI,"") !=0) ; iContador++)
	{
		// se imprime una línea por cada usuario, con todos los datos del usuario: num_usuario, DNI, nombre, apellido, email.
		printf("\n%4d %-11s %-15s %-25s %-15s", mis_usuarios[iContador].num_usuario, mis_usuarios[iContador].DNI, mis_usuarios[iContador].nombre, mis_usuarios[iContador].apellido, mis_usuarios[iContador].email);
	}
	printf("\n\n");
    system("pause");
	
}


//***********************************************************
//**                                                       **
//**        FUNCION GRABAR_USUARIOS_FICHERO                **
//**                                                       **
//***********************************************************
//
// Esta función es invocada cada vez que hay un alta, una modificación o una baja de usuarios, o bien se ha reordenado la estructura por algún criterio.
// Lo anterior permite que en las siguientes sesiones, no se hayan perdido los cambios realizados con el programa.
//
void grabar_usuarios_fichero (Usuario mis_usuarios[])
{   
	// iContador se usa para hacer el recorrido al vector de la estractura de usuarios
    int iContador;
    // pFichero es el puntero a un fichero
	FILE *pFichero;
    	    
	// Se abre el fichero en modo escritura
	pFichero = fopen("Usuarios.txt","w");
	
	// Se controla si hay error al abrir el fichero...
	if (pFichero == NULL)
	{	
		printf("\nError al abrir el fichero de Usuarios.\n");
		system("pause");		
	}
	// tan solo en el caso de que la apertura haya sido correcta, escribe una fila en el fichero por cada usuario.
	// Los campos se escriben separados por comas para poder leerlos correctamente con la función de leer_usuarios_fichero
	else
	{	
		printf("\nFichero de Usuarios abierto correctamente.\n");
		for(iContador = 0 ; (strcmp(mis_usuarios[iContador].DNI,"") !=0) ; iContador++)
		{	
			fprintf(pFichero, "%4d; %-11s; %-15s; %-25s; %-15s;\n", mis_usuarios[iContador].num_usuario, mis_usuarios[iContador].DNI, mis_usuarios[iContador].nombre, mis_usuarios[iContador].apellido, mis_usuarios[iContador].email);
		}		
	}
	
	// Se cierra el fichero
	fclose(pFichero);      					

}


//***********************************************************
//**                                                       **
//**        FUNCION LEER_USUARIOS_FICHERO                  **
//**                                                       **
//***********************************************************
//
// Esta función tan solo es invocada desde el MAIN para cargar inicialmente la estructura de USUARIOS con los datos grabados en fichero en sesiones anteriores.
//
// Se carga en un vector de estructura de USUARIOS el contenido del fichero.
// Cada fila del fichero es un usuario.
// Los campos están separados por el carácter ';' y por eso en el fscanf se busca con %[^;];
// Cada registro leído es almacenado en el vector a estructura.
// Se llama a la función 'eliminar_espacios', al que se le pasa por parámetro una cadena de caracteres y que elimina los espacios al final de la cadena (se crean al leer cada campo hasta el carácter ';'.
//
void leer_usuarios_fichero (Usuario mis_usuarios[])
{   
	// iContador se usa para el recorrido por el vector de estructura
    int iContador;
    // pFichero es el puntero a fichero
	FILE *pFichero;

	int num_usuario;
    	    
	// El fichero se abre para lectura    	    
	pFichero = fopen("Usuarios.txt","r");
	
	// Si la apertura del fichero es incorrecta, muestra un mensaje
	if (pFichero == NULL)
	{	
		printf("\nError al abrir el fichero de Usuarios.\n");
		system("pause");		
	}	
	// Si el fichero se abre correctamente
	else
	{	
		printf("\nFichero de Usuarios abierto correctamente.\n");
		iContador = 0;
		// Recorrido del fichero mientras que no se llegue al final
		while ( !feof(pFichero) )
		{
			fscanf(pFichero, "%d; %[^;]; %[^;]; %[^;]; %[^;];\n", &num_usuario, mis_usuarios[iContador].DNI, mis_usuarios[iContador].nombre, mis_usuarios[iContador].apellido, mis_usuarios[iContador].email);		
			mis_usuarios[iContador].num_usuario = num_usuario;
			// Se llama a la función 'eliminar_espacios' por cada cadena de caracteres leída, para eliminar los espacios al final de la cadena.						
			eliminar_espacios (mis_usuarios[iContador].DNI);
			eliminar_espacios (mis_usuarios[iContador].nombre);
			eliminar_espacios (mis_usuarios[iContador].apellido);
			eliminar_espacios (mis_usuarios[iContador].email);														
		
			iContador++;
		}		
	}
	       
	// Se cierra el fichero	       
	fclose(pFichero);      					

}

//***********************************************************
//**                                                       **
//**                  ELIMINAR ESPACIOS                    **
//**                                                       **
//***********************************************************
// 
// Esta función es invocada desde todas las funciones de lectura de ficheros: leer_usuarios_fichero, leer_libros_fichero y leer_prestamos_fichero.
// También es invocada después de hacer FGETS porque se ha comprobado que a veces se inserta un \n al final de la cadena de caracteres
//
// Se utiliza para eliminar los caracteres o espacios en blanco al final de una cadena de caracteres que se pasa por parámetro.
// Es necesaria porque al leer las cadenas de caracteres, en lugar de hacerlo por '%s', se hace buscando el carácter ';' como fin de cadena, por lo que se añaden espacios a la cadena leída.
// También eliminar todos los '\n' de la cadena de caracteres.
//
void eliminar_espacios (char sLiteral[])
{   
    int iLongitud;
    int iContador;
    
    // Se comienza el recorrido desde el final de la cadena
	iLongitud=strlen(sLiteral);
	
	// recorrido de la cadena de caracteres para eliminar los cambios de línea (se pueden introducir con fgets)
	for(iContador = 0; (iContador<iLongitud); iContador++)
		if (sLiteral[iContador]=='\n')
			sLiteral[iContador]='\0';	

	// mientras no se llegue al principio de la cadena y haya espacios en blanco, pone el carácter '\0' en dicha posición (indicando final de cadena y "borrando" el espacio sobrante).
	for(iContador = iLongitud-1; (iContador>0 && sLiteral[iContador]==' '); iContador--)
		sLiteral[iContador]='\0';
	
	
}


//***********************************************************
//**                                                       **
//**        FUNCION ORDENAR_USUARIOS                       **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde LISTADO_USUARIOS_APELLIDO con el objetivo de ordenar el vector de estructura de USUARIOS por el campo 'apellido'
//
// Se utiliza el método de la burbuja (sacado de INTERNET), que aunque es un poco más lento que otros, es el más sencillo de implementar.
//
void ordenar_usuarios (Usuario mis_usuarios[])
{
	
	int iNumRegistros;
	// Se necesita una variable temporal en la que almacenar el valor de una cadena de caracteres, mientras que intercambian los valores de 2 registros
	char tmp[100];
	int num_tmp;
    
    // Recorrido de la estructura de USUARIOS para determinar el número de registros
	for(iNumRegistros = 0 ; (strcmp(mis_usuarios[iNumRegistros].DNI,"") !=0) ; iNumRegistros++);
	
	int i, j;
	
	// El algoritmo de la burbuja hace un recorrido anidado de FOR para intercambiar 2 registros si alfabéticamente un valor es mayor que otro
	for(i=0; i<iNumRegistros-1; i++)
	{
		for(j=i+1; j<iNumRegistros; j++)
		{
			// Solo se intercambian los 2 registros si el 'i' es mayor alfabéticamente que el 'j'
			if(strcmp(mis_usuarios[i].apellido, mis_usuarios[j].apellido) > 0)
			{
				// En caso de intercambio de registros, se deben intercambiar TODOS los campos de estrctura: num_usuario, DNI, nombre, apellido, email
				num_tmp = mis_usuarios[i].num_usuario;
				mis_usuarios[i].num_usuario = mis_usuarios[j].num_usuario;
				mis_usuarios[j].num_usuario = num_tmp;
				strcpy (tmp, mis_usuarios[i].DNI);
				strcpy (mis_usuarios[i].DNI, mis_usuarios[j].DNI);
				strcpy (mis_usuarios[j].DNI, tmp);
				strcpy (tmp, mis_usuarios[i].nombre);
				strcpy (mis_usuarios[i].nombre, mis_usuarios[j].nombre);
				strcpy (mis_usuarios[j].nombre, tmp);
				strcpy (tmp, mis_usuarios[i].apellido);
				strcpy (mis_usuarios[i].apellido, mis_usuarios[j].apellido);
				strcpy (mis_usuarios[j].apellido, tmp);
				strcpy (tmp, mis_usuarios[i].email);
				strcpy (mis_usuarios[i].email, mis_usuarios[j].email);
				strcpy (mis_usuarios[j].email, tmp);
			}
		}
	}		

}


//***********************************************************
//**                                                       **
//**        FUNCION BUSQUEDA_USUARIOS                      **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_USUARIOS, MODIFICACION_USUARIOS, BAJA_USUARIOS, PRESTAMO_LIBRO, DEVOLUCION_LIBRO, CONSULTA_PRESTAMOS_USUARIO
// Su objetivo es mostrar todos los registros que cumplan una determinada condición, para poderlo seleccionar (para una modificación o borrado) o simplemente por verlos en pantalla
//
// Se solicita un texto que será buscado como parte del nombre o apellido del USUARIO.
// Se hace un recorrido del vector de la estructura de USUARIOS
// En caso de que exista coincidencia, imprime el registro --> se usa la función 'strstr' de la librería <string.h>, que buscar un literal dentro de una cadena de caracteres (trozo o palabra completa)

int busqueda_usuarios(Usuario mis_usuarios[])
{   
	// iEncontrado se usua par indicar si hay al menos un registro que cumpla con la condición de búsqueda.  Si se ha encontrado, iEncontrado = 1, en caso contrario iEncontrado = 0
    int iContador, iEncontrado;
    // sLiteral es el nombre de la cadena a buscar dentro de nombre o apellido
	char sLiteral[100];
    	
	system("cls");
	printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	printf("\n___________________BUSQUEDA DE USUARIOS____________________________\n\n");
    printf("\nIntroduzca el literal del Usuario a buscar (por nombre o por apellido): ");
    fflush(stdin);        	
    scanf("%s",sLiteral);
    printf("\n");
 
 	// Inicialmente no se ha encontrado ningún reigstro
 	iEncontrado = 0;
 
 	// Recorrido del vector de la estructura USUARIOS...
	for(iContador = 0 ; (strcmp(mis_usuarios[iContador].DNI,"") !=0) ; iContador++)
	{
		// Si se encuentra el literal en el campo 'nombre' o en el campo 'apellido'
		if ( (strstr(mis_usuarios[iContador].nombre,sLiteral) != NULL) || (strstr(mis_usuarios[iContador].apellido,sLiteral) != NULL) )
		{
			// Se indica que se ha encontrado al menos un registro
			iEncontrado ++;
			// la cabecera solo se imprime la primera vez
			if (iEncontrado == 1)
			{
				printf("\n   # %-11s %-15s %-25s %-15s","DNI", "NOMBRE","APELLIDO", "EMAIL");
				printf("\n   _ ___         ______          ________                  _____\n");
			}
			// se imprimen todos los datos del usuario
			printf("\n%4d %-11s %-15s %-25s %-15s", mis_usuarios[iContador].num_usuario, mis_usuarios[iContador].DNI, mis_usuarios[iContador].nombre, mis_usuarios[iContador].apellido, mis_usuarios[iContador].email);
		}
	}					
	printf("\n");
	// se devuelve valor 1 a la función que lo llama (modificación o borrado de usuario) en caso de no haber encontrado ningún registro que cumpla con la condición
	if (iEncontrado == 0)
	{
		printf("\nNo hay Usuarios que cumplan la condicion.\n\n");
		return 1;
	}
	// en caso contrario (se ha encontrado al menos un registro), se devuelve valor 0
	else
	{
		printf("\n");
		return 0;
	}
}


//***********************************************************
//**                                                       **
//**        FUNCION MODIFICACION_USUARIOS                  **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_USUARIOS
//
// Permite la modificación de los datos de un usuario (cualquiera de los datos) con las siguientes restricciones:
//   1) No se puede modificar el campo DNI de un usuario si ya tiene préstamos realizados (vigentes o caducados)
//   2) El campo EMAIL debe tener un formato que se verifica con la función 'comprobar_email'.
//
// Pasos a seguir:
//   1) Invocar a la función 'busqueda_usuarios', que muestra por pantalla todos los usuarios que cumplan con una condición (nombre o apellido contiene el literal pedido por pantalla)
//   2) Solo se permite modificar los datos de un registro si la función 'busqueda_usuarios' devuelve un 0 (cuando se ha encontrado al menos un registro que cumple la condición
//      2.a) Recorrido de la estructura de USUARIOS para determinar el número de registros
//      2.b) Bucle DO-WHILE para solicitar un número de registro (num_usuario) que exista  --> Si  no se encuentra, muestra mensaje y se vuelve a pedir el número de usuario
//      2.c) Recorre la estructura de préstamos.  Si encuentra el usuario, no se podrá modificar su DNI (el resto de campos sí).
//
// A tener en cuenta:
//      1) Al modificar el DNI, se comprueba que no coincida con el de otro usuario (DNI es campo único) --> DO-WHILE para solicitarlo hasta que no coincida con ninguno
//      2) Al modificar el EMAIL, se invoca a 'comprobar_email' para verificar el formato (contiene un '@' y un '.' posterior).
//      3) Al modificar cualquier campo, si no se introduce nada (se pulta RETURN), no se modifica el valor del campo que tenía previamente
//
void modificacion_usuarios(Usuario mis_usuarios[], Prestamo mis_prestamos[])
{   
    int iContador, iContador2, iMaxRegistros, iContadorPrestamo;
	char sTemporal[100];
	int num_usuario;
	int iResultado;

	// Invoca a la función 'busqueda_usuarios', que muestra por pantalla todos los usuarios que cumplan con una condición (nombre o apellido contiene el literal pedido por pantalla)	
	iResultado = busqueda_usuarios(mis_usuarios);
	
	// tan solo se modifica un registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
		// Recorrido de la estructura de USUARIOS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_usuarios[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Usuario a modificar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_usuario);
    		printf("\n");
 	 		// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContador = 0 ; (mis_usuarios[iContador].num_usuario != num_usuario) && (iContador <= iMaxRegistros ); iContador++);
			// Si se ha llegado al final del vector sin encontrar el registro...
			if (iContador > iMaxRegistros)
				printf("\nNo existe el registro %d.\n\n", num_usuario);			
		} while (iContador > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro

		// Recorre la estructura de préstamos.  Si encuentra el usuario, no se podrá modificar su DNI (el resto de campos sí).
		for(iContadorPrestamo = 0 ; (strcmp(mis_prestamos[iContadorPrestamo].DNI, "") != 0) && (strcmp(mis_prestamos[iContadorPrestamo].DNI, mis_usuarios[iContador].DNI) !=0) ; iContadorPrestamo++);
	
		// Mensaje si diciendo que no se puede modificar el DNI en caso que se haya prestado un libro a dicho usuario previamente
		if (strcmp(mis_prestamos[iContadorPrestamo].DNI, mis_usuarios[iContador].DNI) ==0)
		{
			printf("\nNo se puede modificar el campo DNI porque el Usuario ya tiene Prestamos.\n\n");
		}
		else
		{
			// bucle DO-WHILE para verificar que no se duplica el DNI (no se puede repetir)
    		do
			{	
    			printf("Numero de DNI (actual %s): ", mis_usuarios[iContador].DNI);
    			fflush(stdin); 
				fgets(sTemporal, 10, stdin);
				eliminar_espacios (sTemporal);   			
 	 			// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
				for(iContador2 = 0 ; ( (strcmp(mis_usuarios[iContador2].DNI, sTemporal)!=0) && (iContador2 <= iMaxRegistros ) ); iContador2++);
				if (iContador2 <= iMaxRegistros && strcmp(sTemporal,"") !=0 )
					printf("\nEl DNI %s corresponde a otro Usuario existente (no puede haber duplicados).\n\n", mis_usuarios[iContador2].DNI);
			} while ( iContador2 <= iMaxRegistros && strcmp(sTemporal,"") !=0 );
    		if (strcmp(sTemporal,"") !=0)		
				strcpy (mis_usuarios[iContador].DNI, sTemporal);
		}

    		    
		printf("Nombre del Usuario (actual %s): ", mis_usuarios[iContador].nombre);
		// Se almacena en 'sTemporal' el valor que tenía previamente este campo
    	strcpy(sTemporal, mis_usuarios[iContador].nombre);
		fflush(stdin);  
		fgets(mis_usuarios[iContador].nombre, 15, stdin);
		eliminar_espacios (mis_usuarios[iContador].nombre);
     	// si no se ha introducido nada por teclado, restaura el valor que tenía antes (lo que está en 'sTemporal')
    	if (strcmp(mis_usuarios[iContador].nombre,"") ==0)
    		strcpy(mis_usuarios[iContador].nombre, sTemporal);
	        
    	printf("Apellido del Usuario (actual %s): ", mis_usuarios[iContador].apellido);
    	strcpy(sTemporal, mis_usuarios[iContador].apellido);
		fflush(stdin);
		fgets(mis_usuarios[iContador].apellido, 25, stdin); 
		eliminar_espacios (mis_usuarios[iContador].apellido);
    	if (strcmp(mis_usuarios[iContador].apellido,"") ==0)
        	strcpy(mis_usuarios[iContador].apellido, sTemporal);       
     
		// el campo e-mail tiene un tratamiento especial porque se valida su formato  
		iResultado = 2;       
    	do
		{	
        	printf ("e-mail del Usuario (actual %s): ", mis_usuarios[iContador].email);
  			strcpy(sTemporal, mis_usuarios[iContador].email); 
        	fflush(stdin);
        	fgets(mis_usuarios[iContador].email, 40, stdin);
			eliminar_espacios (mis_usuarios[iContador].email);		        	
          	// si no se ha modificado el campo, se restaura su valor
    		if (strcmp(mis_usuarios[iContador].email,"") ==0)
    		{	
    			strcpy(mis_usuarios[iContador].email, sTemporal);
			}
			// en caso de haber modificado el campo, se comprueba su validez
        	else
        	{
        		// Se invoca a 'comprobar_email', que busca que tenga un '@' y un '.' posterior.  Si no se cumple la condición, el formato se considera inválido
        		iResultado = comprobar_email(mis_usuarios[iContador].email);
 	  
				if (iResultado==2)
					printf("\nDireccion de email valida\n\n")  ;
				else
					printf("\nDireccion de email no valida\n\n");
			}

		} while ( iResultado!=2 );  // saldrá del bucle cuando la función 'comprobar_email' devuelve valor 2 (significa formato correcto)
		
		printf("\nEl Usuario ha sido modificado correctamente.\n\n");
	
	} 
 
	system("pause");  

}


//***********************************************************
//**                                                       **
//**        FUNCION BAJA_USUARIOS                          **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_USUARIOS
//
// Da de baja un usuario del vector de estructura de USUARIOS
//
// Realiza los siguientes pasos:
//   1) Invoca la función 'busqueda_usuarios' para mostrar todos los usuarios que cumplan una condiciones (nombre o apellido contiene un literal introducido por teclado)
//   2) Solo se puede eliminar un registro si la función 'busqueda_usuarios' ha devuelto valor 0, que significa que hay al menos un registro que cumple la condición de búsqueda
//       2.a) Recorrido de la estructura de USUARIOS para determinar el número de registros.
//       2.b) Bucle DO-WHILE para pedir el número de registro a eliminar --> no finaliza el bucle hasta que no se introduce un usuario existente en USUARIOS
//       2.c) Recorrido de la estructura de préstamos.  Si encuentra el usuario, no se podrá eliminar el registro
//       2.d) Si no se encuentra el usuario en prestamos, se puede borrar.
//       2.e.) Pide confirmación por teclado.  El registro solo se borra si se contesta 's'.
//
void baja_usuarios(Usuario mis_usuarios[], Prestamo mis_prestamos[])
{
	// iRegistroBuscado se usa para indicar el índice del vector del usuario a eliminar
	// iMaxRegistros se usa para contabilizar el número máximo de usuarios en el vector de la estructura
	// iContadorPrestamo se usa para el recorrido por el vector de prestamos --> ver si el usuario ya tiene prestamos y evitar que se pueda eliminar
	// iContador se usa para el recorrido de eliminación del registro, desde iRegistroBuscado hasta iMaxRegistros
    int iRegistroBuscado, iMaxRegistros, iContador, iContadorPrestamo;
	int num_usuario;
	// cSeguro se usa para confirmar si se borra el usuario una vez seleccionado
	char cSeguro;
	// iResultado se usa para recoger el valor devuelto por 'busqueda_usuarios'.  Valor = 0 significa que hay al menos un registro que cumple con condición, valor = 1 en caso contrario
	int iResultado;
	
	// Invoca la función 'busqueda_usuarios' para mostrar todos los usuarios que cumplan una condiciones (nombre o apellido contiene un literal introducido por teclado)	
	iResultado = busqueda_usuarios(mis_usuarios);
	
	// tan solo se elimina un registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
	
	    // Recorrido de la estructura de USUARIOS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_usuarios[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a borrar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Usuario a eliminar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_usuario);
    		printf("\n");
 	
 			// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iRegistroBuscado = 0 ; (mis_usuarios[iRegistroBuscado].num_usuario != num_usuario) && (iRegistroBuscado <= iMaxRegistros ); iRegistroBuscado++);
			// No existe el registro si hemos llegado al final del recorrido...
			if (iRegistroBuscado > iMaxRegistros)
				printf("\nNo existe el registro %d.\n\n", num_usuario);				
		
		} while (iRegistroBuscado > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro

		// recorre la estructura de préstamos.  Si encuentra el usuario, no se podrá eliminar el registro
		for(iContadorPrestamo = 0 ; (strcmp(mis_prestamos[iContadorPrestamo].DNI, "") != 0) && (strcmp(mis_prestamos[iContadorPrestamo].DNI, mis_usuarios[iRegistroBuscado].DNI) !=0) ; iContadorPrestamo++);
	
		// Mensaje indicando que no se puede eliminar el usuario en caso de que se haya encontrado el DNI en la estructura de prestamos	
		if (strcmp(mis_prestamos[iContadorPrestamo].DNI, mis_usuarios[iRegistroBuscado].DNI) ==0)
		{
			printf("\nNo se puede eliminar el Usuario porque tiene Prestamos.\n\n");
		}
		// si no se ha encontrado el registro, puede borrarse...
		else
		{
			// Pide confirmación antes de borrar el registro
			// Bucle DO-WHILE mientras se conteste algo diferentes de 's' o 'n'
			do {
				printf("\n%4d %-11s %-15s %-25s %-15s", mis_usuarios[iRegistroBuscado].num_usuario, mis_usuarios[iRegistroBuscado].DNI, mis_usuarios[iRegistroBuscado].nombre, mis_usuarios[iRegistroBuscado].apellido, mis_usuarios[iRegistroBuscado].email);
				printf("\n\nSe va a proceder a borrar el registro anterior.  Esta seguro? (s/n) ");
    			fflush(stdin);        	
    			scanf("%c", &cSeguro);
    			printf("\n");
				} while (cSeguro != 's' && cSeguro != 'n');
	
			// Solo se borra el registro si se ha confirmado con 's'
			if (cSeguro == 's')
			{	
				// El borrador del registro consiste en hacer un recorrido en MIS_USUARIOS desde el registro a buscar, y poniendo los valores del siguiente usuario
				for(iContador = iRegistroBuscado ; (strcmp(mis_usuarios[iContador].DNI,"") !=0) ; iContador++)
				{	
					// cada uno de los 5 campos del estructura de USUARIOS se machaca con el valor del siguiente registro
					mis_usuarios[iContador].num_usuario = mis_usuarios[iContador+1].num_usuario;
					strcpy (mis_usuarios[iContador].DNI, mis_usuarios[iContador+1].DNI);
					strcpy (mis_usuarios[iContador].nombre, mis_usuarios[iContador+1].nombre);
					strcpy (mis_usuarios[iContador].apellido, mis_usuarios[iContador+1].apellido);
					strcpy (mis_usuarios[iContador].email, mis_usuarios[iContador+1].email);
				}				
		
				// Al borrar un Usuario hay que renumerar los números de registro para evitar que queden números no consecutivos
				// num_usuario es un número único dentro del vector de USUARIOS.  Se usa en las búsquedas de usuarios, para seleccionar el registro que se va a modificar o eliminar
				for(iContador = 0 ; (strcmp(mis_usuarios[iContador].DNI,"") !=0) ; iContador++)
					mis_usuarios[iContador].num_usuario = iContador;
				printf("\nEl Usuario ha sido eliminado correctamente.\n\n");
			}
			else
				printf("\nEl Usuario no ha sido eliminado.\n\n");		

		}

		
	} 
 
	system("pause");   
			
	
}


//***********************************************************
//**                                                       **
//**                  FUNCION ALTA_LIBRO                   **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_LIBROS par dar de alta un nuevo libro.
//
// El nuevo libro se añade al final del vector de estructura de libros. --> para ello se hace un recorrido hasta el último registro.
// Se controla que el ISBN del nuevo libro no exista ya, en caso contrario pide de nuevo del ISBN hasta introducir uno válido.
// Da un mensaje indicando que se ha dado correctamente el libro.
//
void alta_libro(Libro mis_libros[])
{   
	int iOpcion;
    int iContador;
    char sISBN[100];
    int iMaxRegistros;
    
    // Recorrido de la estructura de LIBROS para determinar el número de registros
    for(iMaxRegistros = 0 ; (strcmp(mis_libros[iMaxRegistros].ISBN,"") !=0) ; iMaxRegistros++);
       
    // num_libro es un campo de valor único (no se repite) y se usa en modificación y borrado de Libros       
    // Se asigna a num_libro el siguiente número secuencial según el número de registro
    mis_libros[iMaxRegistros].num_libro = iMaxRegistros;
	
    system("cls");
    printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
    printf("\n_______________________ALTA DE LIBROS______________________________\n\n");

	// bucle DO-WHILE para verificar que no se duplica el ISBN (no se puede repetir)
    do
	{
    	printf("Numero de ISBN: ");
    	fflush(stdin);
		fgets(sISBN, 11, stdin);
		eliminar_espacios (sISBN);    	
 	 	// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
		for(iContador = 0 ; ( (strcmp(mis_libros[iContador].ISBN, sISBN)!=0) && (iContador <= iMaxRegistros ) ); iContador++);
		if (iContador <= iMaxRegistros)
			printf("\nEl ISBN %s corresponde a otro Libro existente (no puede haber duplicados).\n\n", mis_libros[iContador].ISBN);
	} while ( iContador <= iMaxRegistros );   
	strcpy (mis_libros[iMaxRegistros].ISBN, sISBN);
		    
    printf("Titulo del Libro: ");
    fflush(stdin);
	fgets(mis_libros[iMaxRegistros].titulo, 35, stdin);
	eliminar_espacios (mis_libros[iMaxRegistros].titulo);
        
    printf("Genero del Libro: ");
    fflush(stdin);
    fgets(mis_libros[iMaxRegistros].genero, 20, stdin);
	eliminar_espacios (mis_libros[iMaxRegistros].genero);
    
    printf("Autor del Libro: ");
    fflush(stdin);
    fgets(mis_libros[iMaxRegistros].autor, 35, stdin);
	eliminar_espacios (mis_libros[iMaxRegistros].autor);    

	printf("\nEl Libro ha sido dado de alta correctamente.\n\n");
	system("pause");
		
}

//***********************************************************
//**                                                       **
//**        FUNCION LISTADO_LIBROS_ORDENADO                **
//**                                                       **
//***********************************************************
//
// Esta función es invocada por MENU_LIBROS, con 2 valores posibles como parámetro:
//    valor 1 = se ordena el listado de libros por titulo
//    valor 2 = se ordena el listado de libros por autor
//    valor 3 = se ordena el listado de libros por genero+titulo
//
// Invoca a la función ordenar_libros_titulo, ordenar_libros_autor u ordenar_libros_genero, según haya que ordenar el vector de estructura de libros por el campo 'titulo' o 'autor'.
// Posteriormente hace un recorrido por el vector de la estructura de libros y por cada uno muestra en pantalla todos los campos.
//
void listado_libros_ordenado (Libro mis_libros[], int iOpcion)
{   
    int iContador;
    

    if (iOpcion == 1)
    {
    	// Se pasa como parámetro el vector a la estructura 'mis_libros' y lo devuelve ordenado por el campo 'titulo'
    	ordenar_libros_titulo (mis_libros);
    	system("cls");
		printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");    	
		printf("\n________________LISTADO DE LIBROS POR TITULO_______________________\n\n");    	
	}
	else if (iOpcion == 2)
	{
		// Se pasa como parámetro el vector a la estructura 'mis_libros' y lo devuelve ordenado por el campo 'autor'
		ordenar_libros_autor (mis_libros);
    	system("cls");
		printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");    	
		printf("\n________________LISTADO DE LIBROS POR AUTOR________________________\n\n");   		
	}
	else
	{
		// Se pasa como parámetro el vector a la estructura 'mis_libros' y lo devuelve ordenado por el campo 'genero' y por 'titulo'
    	ordenar_libros_genero (mis_libros);
    	system("cls");
		printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");    	
		printf("\n_______________LISTADO DE LIBROS POR GENERO________________________\n\n");   		
	}
    	 
    	    

	printf("\n   # %-11s %-35s %-20s %-35s","ISBN", "TITULO","GENERO", "AUTOR");
	printf("\n   _ ____        ______                              ______               _____\n");
 
  	// Recorrido al vector de la estructura de libros... mientras que no se encuentre el ISBN nulo
	for(iContador = 0 ; (strcmp(mis_libros[iContador].ISBN,"") !=0) ; iContador++)
	{
		// se imprime una línea por cada libro, con todos los datos del libro: num_libro, ISBN, titulo, genero, autor.
		printf("\n%4d %-11s %-35s %-20s %-35s", mis_libros[iContador].num_libro, mis_libros[iContador].ISBN, mis_libros[iContador].titulo, mis_libros[iContador].genero, mis_libros[iContador].autor);
	}
	printf("\n\n");
    system("pause");
	
}


//***********************************************************
//**                                                       **
//**        FUNCION GRABAR_LIBROS_FICHERO                  **
//**                                                       **
//***********************************************************
//
// Esta función es invocada cada vez que hay un alta, una modificación o una baja de libros, o bien se ha reordenado la estructura por algún criterio.
// Lo anterior permite que en las siguientes sesiones, no se hayan perdido los cambios realizados con el programa.
//
void grabar_libros_fichero (Libro mis_libros[])
{   
	// iContador se usa para hacer el recorrido al vector de la estractura de usuarios
    int iContador;
    // pFichero es el puntero a un fichero    
	FILE *pFichero;
    	    
	// Se abre el fichero en modo escritura
	pFichero = fopen("Libros.txt","w");

	// Se controla si hay error al abrir el fichero...	
	if (pFichero == NULL)
	{	
		printf("\nError al abrir el fichero de Libros.\n");
		system("pause");		
	}
	// tan solo en el caso de que la apertura haya sido correcta, escribe una fila en el fichero por cada usuario.
	// Los campos se escriben separados por comas para poder leerlos correctamente con la función de leer_usuarios_fichero	
	else
	{	
		printf("\nFichero de Libros abierto correctamente.\n");
		for(iContador = 0 ; (strcmp(mis_libros[iContador].ISBN,"") !=0) ; iContador++)
		{	
			fprintf(pFichero, "%4d; %-11s; %-35s; %-20s; %-35s;\n", mis_libros[iContador].num_libro, mis_libros[iContador].ISBN, mis_libros[iContador].titulo, mis_libros[iContador].genero, mis_libros[iContador].autor);			
		}		
	}

	// Se cierra el fichero	
	fclose(pFichero);      					

}


//***********************************************************
//**                                                       **
//**        FUNCION LEER_LIBROS_FICHERO                    **
//**                                                       **
//***********************************************************
//
// Esta función tan solo es invocada desde el MAIN para cargar inicialmente la estructura de LIBROS con los datos grabados en fichero en sesiones anteriores.
//
// Se carga en un vector de estructura de LIBROS el contenido del fichero.
// Cada fila del fichero es un usuario.
// Los campos están separados por el carácter ';' y por eso en el fscanf se busca con %[^;];
// Cada registro leído es almacenado en el vector a estructura.
// Se llama a la función 'eliminar_espacios', al que se le pasa por parámetro una cadena de caracteres y que elimina los espacios al final de la cadena (se crean al leer cada campo hasta el carácter ';'.
//
void leer_libros_fichero (Libro mis_libros[])
{   
	// iContador se usa para el recorrido por el vector de estructura
    int iContador;
    // pFichero es el puntero a fichero
	FILE *pFichero;

	int num_libro;
    	    
	// El fichero se abre para lectura    	    
	pFichero = fopen("Libros.txt","r");

	// Si la apertura del fichero es incorrecta, muestra un mensaje	
	if (pFichero == NULL)
	{	
		printf("\nError al abrir el fichero de Libros.\n");
		system("pause");		
	}
	// Si el fichero se abre correctamente		
	else
	{	
		printf("\nFichero de Libros abierto correctamente.\n");
		iContador = 0;
		// Recorrido del fichero mientras que no se llegue al final		
		while ( !feof(pFichero) )
		{
			fscanf(pFichero, "%d; %[^;]; %[^;]; %[^;]; %[^;];\n", &num_libro, mis_libros[iContador].ISBN, mis_libros[iContador].titulo, mis_libros[iContador].genero, mis_libros[iContador].autor);
			mis_libros[iContador].num_libro = num_libro;
			// Se llama a la función 'eliminar_espacios' por cada cadena de caracteres leída, para eliminar los espacios al final de la cadena.				
			eliminar_espacios (mis_libros[iContador].ISBN);
			eliminar_espacios (mis_libros[iContador].titulo);
			eliminar_espacios (mis_libros[iContador].genero);
			eliminar_espacios (mis_libros[iContador].autor);										
		
			iContador++;
		}		
	}
	
	// Se cierra el fichero        
	fclose(pFichero);      					

}



//***********************************************************
//**                                                       **
//**        FUNCION ORDENAR_LIBROS_TITULO                  **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde LISTADO_LIBROS_ORDENADO con el objetivo de ordenar el vector de estructura de LIBROS por el campo 'titulo'
//
// Se utiliza el método de la burbuja (sacado de INTERNET), que aunque es un poco más lento que otros, es el más sencillo de implementar.
//
void ordenar_libros_titulo (Libro mis_libros[])
{
	
	int iNumRegistros;
	// Se necesita una variable temporal en la que almacenar el valor de una cadena de caracteres, mientras que intercambian los valores de 2 registros	
	char tmp[100];
	int num_tmp;
    
    // Recorrido de la estructura de LIBROS para determinar el número de registros
	for(iNumRegistros = 0 ; (strcmp(mis_libros[iNumRegistros].ISBN,"") !=0) ; iNumRegistros++);
	
	int i, j;
	
	// El algoritmo de la burbuja hace un recorrido anidado de FOR para intercambiar 2 registros si alfabéticamente un valor es mayor que otro	
	for(i=0; i<iNumRegistros-1; i++)
	{
		for(j=i+1; j<iNumRegistros; j++)
		{
			// Solo se intercambian los 2 registros si el 'i' es mayor alfabéticamente que el 'j'
			if(strcmp(mis_libros[i].titulo, mis_libros[j].titulo) > 0)
			{
				// En caso de intercambio de registros, se deben intercambiar TODOS los campos de estrctura: num_libro, ISBN, titulo, genero, autor
				num_tmp = mis_libros[i].num_libro;
				mis_libros[i].num_libro = mis_libros[j].num_libro;
				mis_libros[j].num_libro = num_tmp;
				strcpy (tmp, mis_libros[i].ISBN);
				strcpy (mis_libros[i].ISBN, mis_libros[j].ISBN);
				strcpy (mis_libros[j].ISBN, tmp);
				strcpy (tmp, mis_libros[i].titulo);
				strcpy (mis_libros[i].titulo, mis_libros[j].titulo);
				strcpy (mis_libros[j].titulo, tmp);
				strcpy (tmp, mis_libros[i].genero);
				strcpy (mis_libros[i].genero, mis_libros[j].genero);
				strcpy (mis_libros[j].genero, tmp);
				strcpy (tmp, mis_libros[i].autor);
				strcpy (mis_libros[i].autor, mis_libros[j].autor);
				strcpy (mis_libros[j].autor, tmp);
			}
		}
	}		

}


//***********************************************************
//**                                                       **
//**        FUNCION ORDENAR_LIBROS_AUTOR                   **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde LISTADO_LIBROS_ORDENADO con el objetivo de ordenar el vector de estructura de LIBROS por el campo 'titulo'
//
// Se utiliza el método de la burbuja (sacado de INTERNET), que aunque es un poco más lento que otros, es el más sencillo de implementar.
//
void ordenar_libros_autor (Libro mis_libros[])
{
	
	int iNumRegistros;
	// Se necesita una variable temporal en la que almacenar el valor de una cadena de caracteres, mientras que intercambian los valores de 2 registros		
	char tmp[100];
	int num_tmp;
    
    // Recorrido de la estructura de LIBROS para determinar el número de registros
	for(iNumRegistros = 0 ; (strcmp(mis_libros[iNumRegistros].ISBN,"") !=0) ; iNumRegistros++);
	
	int i, j;
	
	// El algoritmo de la burbuja hace un recorrido anidado de FOR para intercambiar 2 registros si alfabéticamente un valor es mayor que otro		
	for(i=0; i<iNumRegistros-1; i++)
	{
		for(j=i+1; j<iNumRegistros; j++)
		{
			// Solo se intercambian los 2 registros si el 'i' es mayor alfabéticamente que el 'j'
			if(strcmp(mis_libros[i].autor, mis_libros[j].autor) > 0)
			{
				// En caso de intercambio de registros, se deben intercambiar TODOS los campos de estrctura: num_libro, ISBN, titulo, genero, autor				
				num_tmp = mis_libros[i].num_libro;
				mis_libros[i].num_libro = mis_libros[j].num_libro;
				mis_libros[j].num_libro = num_tmp;
				strcpy (tmp, mis_libros[i].ISBN);
				strcpy (mis_libros[i].ISBN, mis_libros[j].ISBN);
				strcpy (mis_libros[j].ISBN, tmp);
				strcpy (tmp, mis_libros[i].titulo);
				strcpy (mis_libros[i].titulo, mis_libros[j].titulo);
				strcpy (mis_libros[j].titulo, tmp);
				strcpy (tmp, mis_libros[i].genero);
				strcpy (mis_libros[i].genero, mis_libros[j].genero);
				strcpy (mis_libros[j].genero, tmp);
				strcpy (tmp, mis_libros[i].autor);
				strcpy (mis_libros[i].autor, mis_libros[j].autor);
				strcpy (mis_libros[j].autor, tmp);
			}
		}
	}		

}

//***********************************************************
//**                                                       **
//**        FUNCION ORDENAR_LIBROS_GENERO                  **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde LISTADO_LIBROS_ORDENADO con el objetivo de ordenar el vector de estructura de LIBROS por el campo 'titulo'
//
// Se utiliza el método de la burbuja (sacado de INTERNET), que aunque es un poco más lento que otros, es el más sencillo de implementar.
//
void ordenar_libros_genero (Libro mis_libros[])
{
	
	int iNumRegistros;
	// Se necesita una variable temporal en la que almacenar el valor de una cadena de caracteres, mientras que intercambian los valores de 2 registros		
	char tmp[100];
	int num_tmp;
    
    // Recorrido de la estructura de LIBROS para determinar el número de registros
	for(iNumRegistros = 0 ; (strcmp(mis_libros[iNumRegistros].ISBN,"") !=0) ; iNumRegistros++);
	
	int i, j;
	
	// El algoritmo de la burbuja hace un recorrido anidado de FOR para intercambiar 2 registros si alfabéticamente un valor es mayor que otro		
	for(i=0; i<iNumRegistros-1; i++)
	{
		for(j=i+1; j<iNumRegistros; j++)
		{
			// Solo se intercambian los 2 registros si el 'i' es mayor alfabéticamente que el 'j'
			if(strcmp(mis_libros[i].genero, mis_libros[j].genero) > 0)
			{
				// En caso de intercambio de registros, se deben intercambiar TODOS los campos de estrctura: num_libro, ISBN, titulo, genero, autor				
				num_tmp = mis_libros[i].num_libro;
				mis_libros[i].num_libro = mis_libros[j].num_libro;
				mis_libros[j].num_libro = num_tmp;
				strcpy (tmp, mis_libros[i].ISBN);
				strcpy (mis_libros[i].ISBN, mis_libros[j].ISBN);
				strcpy (mis_libros[j].ISBN, tmp);
				strcpy (tmp, mis_libros[i].titulo);
				strcpy (mis_libros[i].titulo, mis_libros[j].titulo);
				strcpy (mis_libros[j].titulo, tmp);
				strcpy (tmp, mis_libros[i].genero);
				strcpy (mis_libros[i].genero, mis_libros[j].genero);
				strcpy (mis_libros[j].genero, tmp);
				strcpy (tmp, mis_libros[i].autor);
				strcpy (mis_libros[i].autor, mis_libros[j].autor);
				strcpy (mis_libros[j].autor, tmp);
			}
		}
	}		

}



//***********************************************************
//**                                                       **
//**        FUNCION BUSQUEDA_LIBROS                        **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_LIBROS, MODIFICACION_LIBROS, BORRADO_LIBROS, PRESTAMO_LIBRO, DEVOLUCION_LIBRO, CONSULTA_PRESTAMOS_USUARIO
// Su objetivo es mostrar todos los registros que cumplan una determinada condición, para poderlo seleccionar (para una modificación o borrado) o simplemente por verlos en pantalla
//
// Se solicita un texto que será buscado como parte del titulo, genero o autor del LIBRO.
// Se hace un recorrido del vector de la estructura de LIBROS
// En caso de que exista coincidencia, imprime el registro --> se usa la función 'strstr' de la librería <string.h>, que buscar un literal dentro de una cadena de caracteres (trozo o palabra completa)
//
int busqueda_libros(Libro mis_libros[])
{   
	// iEncontrado se usua par indicar si hay al menos un registro que cumpla con la condición de búsqueda.  Si se ha encontrado, iEncontrado = 1, en caso contrario iEncontrado = 0
    int iContador, iEncontrado;
    // sLiteral es el nombre de la cadena a buscar dentro de titulo, genero o autor
	char sLiteral[100];
    	
	system("cls");
	printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	printf("\n____________________BUSQUEDA DE LIBROS_____________________________\n\n");
    printf("\nIntroduzca el literal del Libro a buscar (por titulo, por genero o por autor): ");
    fflush(stdin);        	
    scanf("%s",sLiteral);
    printf("\n");
 
  	// Inicialmente no se ha encontrado ningún reigstro
 	iEncontrado = 0;

 	// Recorrido del vector de la estructura LIBROS... 
	for(iContador = 0 ; (strcmp(mis_libros[iContador].ISBN,"") !=0) ; iContador++)
	{
		// Si se encuentra el literal en el campo 'titulo', 'genero' o 'autor'		
		if ( (strstr(mis_libros[iContador].titulo,sLiteral) != NULL) || (strstr(mis_libros[iContador].genero,sLiteral) != NULL) || (strstr(mis_libros[iContador].autor,sLiteral) != NULL) )
		{
			// Se indica que se ha encontrado al menos un registro			
			iEncontrado ++;
			// la cabecera solo se imprime la primera vez			
			if (iEncontrado == 1)
			{
				printf("\n   # %-11s %-35s %-20s %-35s","ISBN", "TITULO","GENERO", "AUTOR");
				printf("\n   _ ____        ______                              ______               _____\n");				
			}
			// se imprimen todos los datos del libro			
			printf("\n%4d %-11s %-35s %-20s %-35s", mis_libros[iContador].num_libro, mis_libros[iContador].ISBN, mis_libros[iContador].titulo, mis_libros[iContador].genero, mis_libros[iContador].autor);
		}
	}					
	printf("\n");
	
	// se devuelve valor 1 a la función que lo llama (modificación o borrado de libro) en caso de no haber encontrado ningún registro que cumpla con la condición	
	if (iEncontrado == 0)
	{
		printf("\nNo hay Libros que cumplan la condicion.\n\n");
		return 1;
	}
	// en caso contrario (se ha encontrado al menos un registro), se devuelve valor 0
	else
	{
		printf("\n");
		return 0;
	}
		
}



//***********************************************************
//**                                                       **
//**        FUNCION MODIFICACION_LIBROS                    **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_LIBROS
//
// Permite la modificación de los datos de un usuario (cualquiera de los datos) con las siguientes restricciones:
//   1) No se puede modificar el campo ISBN de un libro si ya ha sido prestado (vigente o caducado)
//
// Pasos a seguir:
//   1) Invocar a la función 'busqueda_libros', que muestra por pantalla todos los libros que cumplan con una condición (titulo, genero o autor contiene el literal pedido por pantalla)
//   2) Solo se permite modificar los datos de un registro si la función 'busqueda_libros' devuelve un 0 (cuando se ha encontrado al menos un registro que cumple la condición
//      2.a) Recorrido de la estructura de LIBROS para determinar el número de registros
//      2.b) Bucle DO-WHILE para solicitar un número de registro (num_libro) que exista  --> Si  no se encuentra, muestra mensaje y se vuelve a pedir el número de libro
//      2.c) Recorre la estructura de préstamos.  Si encuentra el libro, no se podrá modificar su ISBN (el resto de campos sí).
//
// A tener en cuenta:
//      1) Al modificar el ISBN, se comprueba que no coincida con el de otro libro (ISBN es campo único) --> DO-WHILE para solicitarlo hasta que no coincida con ninguno
//      2) Al modificar cualquier campo, si no se introduce nada (se pulta RETURN), no se modifica el valor del campo que tenía previamente
//
void modificacion_libros(Libro mis_libros[], Prestamo mis_prestamos[])
{   
    int iContador, iContador2, iMaxRegistros, iContadorPrestamo;
	char sTemporal[100];
	int num_libro;
	int iResultado;

	// Invoca a la función 'busqueda_libros', que muestra por pantalla todos los libros que cumplan con una condición (titulo, genero o autor contiene el literal pedido por pantalla)		
	iResultado = busqueda_libros(mis_libros);
	
	// tan solo se modifica un registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
	    // Recorrido de la estructura de LIBROS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_libros[iMaxRegistros].ISBN,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Libro a modificar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_libro);
    		printf("\n");
 	
 			// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContador = 0 ; (mis_libros[iContador].num_libro != num_libro) && (iContador <= iMaxRegistros ); iContador++);
			if (iContador > iMaxRegistros)
				printf("\nNo existe el registro %d.\n\n", num_libro);				
		
		} while (iContador > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro
		
		// recorre la estructura de préstamos.  Si encuentra el libro, no se podrá modificar su ISBN (el resto de campos sí).
		for(iContadorPrestamo = 0 ; (strcmp(mis_prestamos[iContadorPrestamo].ISBN, "") != 0) && (strcmp(mis_prestamos[iContadorPrestamo].ISBN, mis_libros[iContador].ISBN) !=0) ; iContadorPrestamo++);

		// Mensaje diciendo que no se puede modificar el ISBN en caso que se haya prestado el libro previamente		
		if (strcmp(mis_prestamos[iContadorPrestamo].ISBN, mis_libros[iContador].ISBN) ==0)
		{
			printf("\nNo se puede modificar el campo ISBN porque el Libro ya tiene Prestamos.\n\n");
		}
		else
		{
			// bucle DO-WHILE para verificar que no se duplica el ISBN (no se puede repetir)
	    	do
			{	
	    		printf("Numero de ISBN (actual %s): ", mis_libros[iContador].ISBN);
	    		fflush(stdin);
    			fgets(sTemporal, 11, stdin);
    			eliminar_espacios (sTemporal);	
	 	 		// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
				for(iContador2 = 0 ; ( (strcmp(mis_libros[iContador2].ISBN, sTemporal)!=0) && (iContador2 <= iMaxRegistros ) ); iContador2++);
				if (iContador2 <= iMaxRegistros && strcmp(sTemporal,"") !=0 )
					printf("\nEl ISBN %s corresponde a otro Libro existente (no puede haber duplicados).\n\n", mis_libros[iContador2].ISBN);
			} while ( iContador2 <= iMaxRegistros && strcmp(sTemporal,"") !=0 );
	    	if (strcmp(sTemporal,"") !=0)		
				strcpy (mis_libros[iContador].ISBN, sTemporal);
		}
 
     
		printf("Titulo del Libro (actual %s): ", mis_libros[iContador].titulo);
		// Se almacena en 'sTemporal' el valor que tenía previamente este campo		
    	strcpy(sTemporal, mis_libros[iContador].titulo);
    	fflush(stdin);
    	fgets(mis_libros[iContador].titulo, 35, stdin);
    	eliminar_espacios (mis_libros[iContador].titulo);	
      	// si no se ha introducido nada por teclado, restaura el valor que tenía antes (lo que está en 'sTemporal')    	
    	if (strcmp(mis_libros[iContador].titulo,"") ==0)
    		strcpy(mis_libros[iContador].titulo, sTemporal);
	        
	    printf("Genero del Libro (actual %s): ", mis_libros[iContador].genero);
    	strcpy(sTemporal, mis_libros[iContador].genero);
    	fflush(stdin);
    	fgets(mis_libros[iContador].genero, 20, stdin);
    	eliminar_espacios (mis_libros[iContador].genero);
    	if (strcmp(mis_libros[iContador].genero,"") ==0)
        	strcpy(mis_libros[iContador].genero, sTemporal);       
              
    	printf ("Autor del Libro (actual %s): ", mis_libros[iContador].autor);
    	strcpy(sTemporal, mis_libros[iContador].autor);
    	fflush(stdin);
    	fgets(mis_libros[iContador].autor, 35, stdin); 
		eliminar_espacios (mis_libros[iContador].autor);   	
     	if (strcmp(mis_libros[iContador].autor,"") ==0)
        	strcpy(mis_libros[iContador].autor, sTemporal);        

		printf("\nEl Libro ha sido modificado correctamente.\n\n");
	
	} 
 
	system("pause");   
	
}  		   



//***********************************************************
//**                                                       **
//**        FUNCION BAJA_LIBROS                            **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_LIBROS
//
// Da de baja un libro del vector de estructura de LIBROS
//
// Realiza los siguientes pasos:
//   1) Invoca la función 'busqueda_libros' para mostrar todos los libros que cumplan una condiciones (titulo, genero o autor contiene un literal introducido por teclado)
//   2) Solo se puede eliminar un registro si la función 'busqueda_libros' ha devuelto valor 0, que significa que hay al menos un registro que cumple la condición de búsqueda
//       2.a) Recorrido de la estructura de LIBROS para determinar el número de registros.
//       2.b) Bucle DO-WHILE para pedir el número de registro a eliminar --> no finaliza el bucle hasta que no se introduce un libro existente en LIBROS
//       2.c) Recorrido de la estructura de préstamos.  Si encuentra el libro, no se podrá eliminar el registro
//       2.d) Si no se encuentra el libro en prestamos, se puede borrar.
//       2.e.) Pide confirmación por teclado.  El registro solo se borra si se contesta 's'.
//
void baja_libros(Libro mis_libros[], Prestamo mis_prestamos[])
{   
	// iRegistroBuscado se usa para indicar el índice del vector del usuario a eliminar
	// iMaxRegistros se usa para contabilizar el número máximo de usuarios en el vector de la estructura
	// iContadorPrestamo se usa para el recorrido por el vector de prestamos --> ver si el usuario ya tiene prestamos y evitar que se pueda eliminar
	// iContador se usa para el recorrido de eliminación del registro, desde iRegistroBuscado hasta iMaxRegistros
    int iRegistroBuscado, iMaxRegistros, iContador, iContadorPrestamo;
	int num_libro;
	// cSeguro se usa para confirmar si se borra el usuario una vez seleccionado	
	char cSeguro;
	// iResultado se usa para recoger el valor devuelto por 'busqueda_usuarios'.  Valor = 0 significa que hay al menos un registro que cumple con condición, valor = 1 en caso contrario	
	int iResultado;

	// Invoca la función 'busqueda_libros' para mostrar todos los libros que cumplan una condicion (titulo, genero o autor contiene un literal introducido por teclado)		
	iResultado = busqueda_libros(mis_libros);	
	
	// tan solo se borra un registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
	
	    // Recorrido de la estructura de LIBROS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_libros[iMaxRegistros].ISBN,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a borrar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Libro a eliminar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_libro);
    		printf("\n");
 	
 			// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iRegistroBuscado = 0 ; (mis_libros[iRegistroBuscado].num_libro != num_libro) && (iRegistroBuscado <= iMaxRegistros ); iRegistroBuscado++);
			// No existe el registro si hemos llegado al final del recorrido...			
			if (iRegistroBuscado > iMaxRegistros)
				printf("\nNo existe el registro %d.\n\n", num_libro);				
		
		} while (iRegistroBuscado > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro

		// recorre la estructura de préstamos.  Si encuentra el libro, no se podrá modificar su ISBN (el resto de campos sí).
		for(iContadorPrestamo = 0 ; (strcmp(mis_prestamos[iContadorPrestamo].ISBN, "") != 0) && (strcmp(mis_prestamos[iContadorPrestamo].ISBN, mis_libros[iRegistroBuscado].ISBN) !=0) ; iContadorPrestamo++);

		// Mensaje indicando que no se puede eliminar el libro en caso de que se haya encontrado el ISBN en la estructura de prestamos			
		if (strcmp(mis_prestamos[iContadorPrestamo].ISBN, mis_libros[iRegistroBuscado].ISBN) ==0)
		{
			printf("\nNo se puede eliminar el Libro porque tiene Prestamos.\n\n");
		}
		// si no se ha encontrado el registro, puede borrarse...		
		else
		{
			// Pide confirmación antes de borrar el registro
			// Bucle DO-WHILE mientras se conteste algo diferentes de 's' o 'n'			
			do {
				printf("\n%4d %-11s %-35s %-20s %-35s", mis_libros[iRegistroBuscado].num_libro, mis_libros[iRegistroBuscado].ISBN, mis_libros[iRegistroBuscado].titulo, mis_libros[iRegistroBuscado].genero, mis_libros[iRegistroBuscado].autor);
				printf("\n\nSe va a proceder a borrar el registro anterior.  Esta seguro? (s/n) ");
	    		fflush(stdin);        	
	    		scanf("%c", &cSeguro);
	    		printf("\n");
		
			} while (cSeguro != 's' && cSeguro != 'n');
		
			// Solo se borra el registro si se ha confirmado con 's'
			if (cSeguro == 's')
			{
				// El borrado del registro consiste en hacer un recorrido en MIS_LIBROS desde el registro a buscar, y poniendo los valores del siguiente libro				
				for(iContador = iRegistroBuscado ; (strcmp(mis_libros[iContador].ISBN,"") !=0) ; iContador++)
				{	
					// cada uno de los 5 campos del estructura de LIBROS se machaca con el valor del siguiente registro
					mis_libros[iContador].num_libro = mis_libros[iContador+1].num_libro;
					strcpy (mis_libros[iContador].ISBN, mis_libros[iContador+1].ISBN);
					strcpy (mis_libros[iContador].titulo, mis_libros[iContador+1].titulo);
					strcpy (mis_libros[iContador].genero, mis_libros[iContador+1].genero);
					strcpy (mis_libros[iContador].autor, mis_libros[iContador+1].autor);
				}	
			
				// Al borrar un Libro hay que renumerar los números de registro para evitar que queden números no consecutivos
				// num_libro es un número único dentro del vector de LIBROS.  Se usa en las búsquedas de libros, para seleccionar el registro que se va a modificar o eliminar				
				for(iContador = 0 ; (strcmp(mis_libros[iContador].ISBN,"") !=0) ; iContador++)
					mis_libros[iContador].num_libro = iContador;
				printf("\nEl Libro ha sido eliminado correctamente.\n\n");				
			}
			else
				printf("\nEl Libro no ha sido eliminado.\n\n");
	
		}	
	} 
 
	system("pause");    
		
}
 


//***********************************************************
//**                                                       **
//**        FUNCION LEER_PRESTAMOS_FICHERO                 **
//**                                                       **
//***********************************************************
//
// Esta función tan solo es invocada desde el MAIN para cargar inicialmente la estructura de PRESTAMOS con los datos grabados en fichero en sesiones anteriores.
//
// Se carga en un vector de estructura de PRESTAMOS el contenido del fichero.
// Cada fila del fichero es un préstamo.
// Los campos están separados por el carácter ';' y por eso en el fscanf se busca con %[^;];
// Cada registro leído es almacenado en el vector a estructura.
// Se llama a la función 'eliminar_espacios', al que se le pasa por parámetro una cadena de caracteres y que elimina los espacios al final de la cadena (se crean al leer cada campo hasta el carácter ';'.
//
void leer_prestamos_fichero (Prestamo mis_prestamos[])
{   
	// iContador se usa para el recorrido por el vector de estructura
    int iContador;
    // pFichero es el puntero a fichero    
	FILE *pFichero;

	int num_prestamo;
    	    
	// El fichero se abre para lectura      	    
	pFichero = fopen("Prestamos.txt","r");

	// Si la apertura del fichero es incorrecta, muestra un mensaje		
	if (pFichero == NULL)
	{	
		printf("\nError al abrir el fichero de Prestamos.\n");
		system("pause");		
	}	
	// Si el fichero se abre correctamente
	else
	{	
		printf("\nFichero de Prestamos abierto correctamente.\n");
		iContador = 0;
		// Recorrido del fichero mientras que no se llegue al final	
		while ( !feof(pFichero) )
		{
			fscanf(pFichero, "%d; %[^;]; %[^;]; %[^;]; %[^;];\n", &num_prestamo, mis_prestamos[iContador].DNI, mis_prestamos[iContador].ISBN, mis_prestamos[iContador].fecha_prestamo, mis_prestamos[iContador].fecha_devolucion);		
			mis_prestamos[iContador].num_prestamo = num_prestamo;
			// Se llama a la función 'eliminar_espacios' por cada cadena de caracteres leída, para eliminar los espacios al final de la cadena.						
			eliminar_espacios (mis_prestamos[iContador].DNI);
			eliminar_espacios (mis_prestamos[iContador].ISBN);
			eliminar_espacios (mis_prestamos[iContador].fecha_prestamo);
			eliminar_espacios (mis_prestamos[iContador].fecha_devolucion);														
		
			iContador++;
		}		
	}
	 
	// Se cierra el fichero      
	fclose(pFichero);      					

}



//***********************************************************
//**                                                       **
//**        FUNCION GRABAR_PRESTAMOS_FICHERO               **
//**                                                       **
//***********************************************************
//
// Esta función es invocada cada vez que hay préstamos o una devolución de un libro, o bien se ha reordenado la estructura por algún criterio.
// Lo anterior permite que en las siguientes sesiones, no se hayan perdido los cambios realizados con el programa.
//
void grabar_prestamos_fichero (Prestamo mis_prestamos[])
{   
	// iContador se usa para hacer el recorrido al vector de la estractura de usuarios
    int iContador;
    // pFichero es el puntero a un fichero        
	FILE *pFichero;
    	    
	// Se abre el fichero en modo escritura
	pFichero = fopen("Prestamos.txt","w");
	
	// Se controla si hay error al abrir el fichero...		
	if (pFichero == NULL)
	{	
		printf("\nError al abrir el fichero de Prestamos.\n");
		system("pause");		
	}
	// tan solo en el caso de que la apertura haya sido correcta, escribe una fila en el fichero por cada usuario.
	// Los campos se escriben separados por comas para poder leerlos correctamente con la función de leer_usuarios_fichero	
	else
	{	
		printf("\nFichero de Prestamos abierto correctamente.\n");
		for(iContador = 0 ; (strcmp(mis_prestamos[iContador].DNI,"") !=0) ; iContador++)
		{	
			fprintf(pFichero, "%4d; %-11s; %-15s; %-25s; %-15s;\n", mis_prestamos[iContador].num_prestamo, mis_prestamos[iContador].DNI, mis_prestamos[iContador].ISBN, mis_prestamos[iContador].fecha_prestamo, mis_prestamos[iContador].fecha_devolucion);
		}		
	}

	// Se cierra el fichero		
	fclose(pFichero);      					

}

//***********************************************************
//**                                                       **
//**        FUNCION PRESTAMO_LIBRO                         **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_PRESTAMOS para dar de alta un nuevo préstamo.
//
// Se invoca a la función 'busqueda_usuarios' para localizar el usuario al que se prestará el libro --> se introduce el criterio de búsqueda y saca listado de usuarios.
// Si hay algún usuario que cumpla con los requisitos de búsqueda... se hace un bucle DO-WHILE hasta que se introduzca un 'num_usuario' que exista en la estructura de usuarios
// Una vez localizado el usuario al que prestar el libro, se muestra mensaje con los datos del usuario.
//
// Se invoca a la función 'busqueda_libros' para localizar el libro que se prestará el libro --> se introduce el criterio de búsqueda y saca listado de libros.
// Si hay algún libro que cumpla con los requisitos de búsqueda... se hace un bucle DO-WHILE hasta que se introduzca un 'num_libro' que exista en la estructura de libros
// Una vez localizado el libro que se prestará, se muestra mensaje con los datos del libro.
//
// Se hace un recorrido de la estructura de PRESTAMOS para determinar el número de registros y para averiguar:
//   1) si el libro está actualmente en préstamo  --> si es así, muestra mensaje y no deja prestar el libro.
//   2) si el usuario tiene más de 3 libros ya prestados  --> si es así, muestra mensaje y no deja prestar el libro.
// En caso de no cumplirse con uno de los casos anteriores, añade el préstamo (DNI + ISBN) al final de la estructura de prestamos.
//   1) En el campo 'fecha_prestamo' se indica la fecha actual, obtenida del sistema con las funciones 'time' y 'localtime' y copiando resultado a variable 'fechayhora'.
//   2) En el campo 'fecha_devolucion' se indica el literal 'NO DEVUELTO'.
// Al final se muestra un mensaje indicando el libro que se ha prestado y el usuario.
// Además se indica la fecha máxima de devolución, obtenida del sistema con las funciones 'time' y 'localtime' y a la que se han añadido 14 días, y copiando resultado a variable 'fechayhoradevolucion'.
// 
void prestamo_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[])
{   
	// iContadorUsuarios indica la posición dentro del vector de estructura de usuarios al que se le prestará el libro.
	// iContadorLibros indica la posición dentro del vector de estructura de libros ue se prestará.
	// iMaxRegistros se usa en vario recorridos para verificar si se ha llegado al final del recorrido de una estructura o no.
	// iLibroPrestado tendrá valor igual a 1 cuando el libro esté prestado y 0 en caso contrario.
	// iUsuarioPrestamos tendrá el número de libros que tiene actualmente el usuario en préstamo
    int iContadorUsuarios, iContadorLibros, iMaxRegistros, iLibroPrestado=0, iUsuarioPrestamos=0;

	// num_usuario y num_libro son pedidos por teclado tras mostrar los usuarios y los libros, para indicar el número de registro seleccionado.
	int num_usuario, num_libro;

	// iResultado recoge lo que devuelven las funciones 'busqueda_usuarios' y 'busqueda_libros'.
	int iResultado;

	// variables para obtener la fecha actual del sistema y la fecha máxima de devolución (14 días más tarde)
  	time_t t;
   	struct tm *tm;
   	char fechayhora[100], fechayhoradevolucion[100];

   	t=time(NULL);
   	tm=localtime(&t);
   	strftime(fechayhora, 100, "%d/%m/%Y", tm); 
	 
	// suma 1.209.600 segundos, es decir, 14 días a la fecha actual del sistema  
	t = t + 1209600;
	tm=localtime(&t);
   	strftime(fechayhoradevolucion, 100, "%d/%m/%Y", tm); 

	// proporciona un listado de usuarios a partir de un criterio de búsqueda.  Devuelve valor 1 si no se ha encontrado ningún registro que cumpla requisito, 0 en caso contrario.		
	iResultado = busqueda_usuarios(mis_usuarios);
	
	// tan solo se accede al registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
		// Recorrido de la estructura de USUARIOS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_usuarios[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a buscar
			printf("\nIntroduzca el numero de registro del Usuario a buscar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_usuario);
    		printf("\n");
 	 		// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContadorUsuarios = 0 ; (mis_usuarios[iContadorUsuarios].num_usuario != num_usuario) && (iContadorUsuarios <= iMaxRegistros ); iContadorUsuarios++);
			if (iContadorUsuarios > iMaxRegistros)
				printf("\nNo existe el Usuario %d.\n\n", num_usuario);			
		} while (iContadorUsuarios > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro

			
		printf("\nSe va a prestar un Libro al Usuario %s %s %s.\n\n", mis_usuarios[iContadorUsuarios].DNI, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido);
	
	}
	
	system("pause");

	// proporciona un listado de libros a partir de un criterio de búsqueda.  Devuelve valor 1 si no se ha encontrado ningún registro que cumpla requisito, 0 en caso contrario.	
	iResultado = busqueda_libros(mis_libros);
	
	// tan solo se accede al registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
	    // Recorrido de la estructura de LIBROS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_libros[iMaxRegistros].ISBN,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a buscar
			printf("\nIntroduzca el numero de registro del Libro a buscar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_libro);
    		printf("\n");
 	
 			// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContadorLibros = 0 ; (mis_libros[iContadorLibros].num_libro != num_libro) && (iContadorLibros <= iMaxRegistros ); iContadorLibros++);
			if (iContadorLibros > iMaxRegistros)
				printf("\nNo existe el Libro %d.\n\n", num_libro);				
		
		} while (iContadorLibros > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro     

		printf("\nEl Libro a prestar es %s %s.\n\n", mis_libros[iContadorLibros].ISBN, mis_libros[iContadorLibros].titulo);
	
	} 

	system("pause");

    system("cls");
    printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
    printf("\n____________________PRESTAMO DE LIBROS_____________________________\n\n");
    
    // Recorrido de la estructura de PRESTAMOS para determinar el número de registros y para averiguar si el libro está actualmente en préstamo o el usuario tiene más de 3 libros ya prestados
	for(iMaxRegistros = 0 ; (strcmp(mis_prestamos[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++)
	{
		// iLibroPrestado tendrá valor igual a 1 cuando el libro esté prestado y 0 en caso contrario.
		if ( (strcmp(mis_prestamos[iMaxRegistros].ISBN,mis_libros[iContadorLibros].ISBN) ==0) && (strcmp(mis_prestamos[iMaxRegistros].fecha_devolucion,"NO DEVUELTO") ==0) )
			iLibroPrestado = 1;
		// iUsuarioPrestamos tendrá el número de libros que tiene actualmente el usuario en préstamo
		if ( (strcmp(mis_prestamos[iMaxRegistros].DNI,mis_usuarios[iContadorUsuarios].DNI) ==0) && (strcmp(mis_prestamos[iMaxRegistros].fecha_devolucion,"NO DEVUELTO") ==0) )
			iUsuarioPrestamos++;
	}
	
	// Si el libro se encuentra actualmente en préstamo... no se puede prestar
	if (iLibroPrestado == 1)
	{
		printf("\nNo se puede prestar el Libro porque actualmente esta en prestamo.\n\n");
	}
	// Si um usuario tiene tres préstamos en vigor... no se puede prestar	
	if (iUsuarioPrestamos >= 3)
	{
		printf("\nNo se puede prestar el Libro porque el Usuario ya tiene 3 prestamos.\n\n");
	}

	// en caso contrario se da de alta en la estructura...	
	if (iLibroPrestado == 0 && iUsuarioPrestamos < 3)
	{	
	    // num_prestamo es un campo de valor único (no se repite)       
	    // Se asigna a num_prestamo el siguiente número secuencial según el número de registro
	    mis_prestamos[iMaxRegistros].num_prestamo = iMaxRegistros;
		strcpy(mis_prestamos[iMaxRegistros].DNI, mis_usuarios[iContadorUsuarios].DNI);
		strcpy(mis_prestamos[iMaxRegistros].ISBN, mis_libros[iContadorLibros].ISBN);
		strcpy(mis_prestamos[iMaxRegistros].fecha_prestamo, fechayhora);		 
		strcpy(mis_prestamos[iMaxRegistros].fecha_devolucion, "NO DEVUELTO");

		printf("\nEl Prestamo del Libro '%s' a '%s %s' ha sido realizado correctamente.\n", mis_libros[iContadorLibros].titulo, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido);
		printf("\nEl Libro se debera devolver antes del %s.\n\n", fechayhoradevolucion);
	}
       
	system("pause");	

}

//***********************************************************
//**                                                       **
//**        FUNCION LISTADO_PRESTAMOS_POR_LIBRO            **
//**                                                       **
//***********************************************************
//
// Esta función es invocada por MENU_PRESTAMOS.
// A diferencia de los listados de usuarios y de libros, esta función recibe como parámetros los vectores a las estructuras de prestamos, usuarios y libros (los 2 últimos para datos adicionales)
//
// Invoca a la función ordenar_prestamos, que se encarga de ordenar el vector de estructura de prestamos por el campo 'ISBN' del libro.
// Posteriormente hace un recorrido por el vector de la estructura de prestamos y por cada uno de los registros hace lo siguiente:
//      1) Recorrido de la estructura de USUARIOS para encontrar el usuario al que se le ha prestado el libro
//      2) Recorrido de la estructura de LIBROS para encontrar el libro prestado
//      3) Imprimir una fila con todos los datos: DNI y nombre+apellido del usuario, ISBN y titulo del libro, fecha de prestamo y fecha de devolución
//
void listado_prestamos_por_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[])
{   
	// 3 contadores, iContador para el registro de prestamos, y los otros 2 para el contador al recorrer los vectores de usuarios y libros.
    int iContador, iContadorUsuarios, iContadorLibros;
    
    // Se pasa como parámetro el vector a la estructura 'mis_prestamos' y lo devuelve ordenado por el campo 'ISBN' del libro
	ordenar_prestamos (mis_prestamos);
    	    
	system("cls");
	printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
	printf("\n_________LISTADO DE PRESTAMOS POR ISBN DE LIBRO____________________\n\n");
 
	printf("\n   # %-11s %-15s %-25s %-15s %-35s %-25s %-15s","DNI", "NOMBRE","APELLIDO", "ISBN", "TITULO", "FECHA PRESTAMO", "FECHA DEVOLUCION");
	printf("\n   _ ___         ______          ________                  ____            ______                              _____________             ________________\n");	
 
  	// Recorrido al vector de la estructura de usuarios... mientras que no se encuentre el DNI nulo
	for(iContador = 0 ; (strcmp(mis_prestamos[iContador].DNI,"") !=0) ; iContador++)
	{
		// Recorrido de la estructura de USUARIOS para encontrar el usuario al que se le ha prestado el libro  --> de aquí se sacan los datos de nombre + apellido que no están en prestamos
		for(iContadorUsuarios = 0 ; (strcmp(mis_usuarios[iContadorUsuarios].DNI, mis_prestamos[iContador].DNI) !=0) ; iContadorUsuarios++);
		// Recorrido de la estructura de LIBROS para encontrar el libro prestado  --> de aquí se sacan el dato de titulo que no está en prestamos
		for(iContadorLibros = 0 ; (strcmp(mis_libros[iContadorLibros].ISBN, mis_prestamos[iContador].ISBN) !=0) ; iContadorLibros++);
		// se imprime una línea por cada usuario, con todos los datos del prestamo: num_prestamo, DNI y nombre+apellido del usuario, ISBN y titulo del libro, fecha de prestamo y fecha de devolución		
		printf("\n%4d %-11s %-15s %-25s %-15s %-35s %-25s %-15s", mis_prestamos[iContador].num_prestamo, mis_prestamos[iContador].DNI, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido, 
																mis_prestamos[iContador].ISBN, mis_libros[iContadorLibros].titulo, mis_prestamos[iContador].fecha_prestamo, mis_prestamos[iContador].fecha_devolucion);
	}
	printf("\n\n");
    system("pause");
	
}


//***********************************************************
//**                                                       **
//**        FUNCION ORDENAR_PRESTAMOS                      **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde LISTADO_PRESTAMOS_POR_LIBRO con el objetivo de ordenar el vector de estructura de PRESTAMOS por el campo 'ISBN' del libro
//
// Se utiliza el método de la burbuja (sacado de INTERNET), que aunque es un poco más lento que otros, es el más sencillo de implementar.
//
void ordenar_prestamos (Prestamo mis_prestamos[])
{
	
	int iNumRegistros;
	// Se necesita una variable temporal en la que almacenar el valor de una cadena de caracteres, mientras que intercambian los valores de 2 registros		
	char tmp[100];
	int num_tmp;
    
    // Recorrido de la estructura de PRESTAMOS para determinar el número de registros
	for(iNumRegistros = 0 ; (strcmp(mis_prestamos[iNumRegistros].DNI,"") !=0) ; iNumRegistros++);
	
	int i, j;
	
	// El algoritmo de la burbuja hace un recorrido anidado de FOR para intercambiar 2 registros si alfabéticamente un valor es mayor que otro		
	for(i=0; i<iNumRegistros-1; i++)
	{
		for(j=i+1; j<iNumRegistros; j++)
		{
			// Solo se intercambian los 2 registros si el 'i' es mayor alfabéticamente que el 'j'			
			if(strcmp(mis_prestamos[i].ISBN, mis_prestamos[j].ISBN) > 0)
			{
				// En caso de intercambio de registros, se deben intercambiar TODOS los campos de estrctura: num_prestamo, DNI, ISBN, fecha_prestamo, fecha_devolucion
				num_tmp = mis_prestamos[i].num_prestamo;
				mis_prestamos[i].num_prestamo = mis_prestamos[j].num_prestamo;
				mis_prestamos[j].num_prestamo = num_tmp;
				strcpy (tmp, mis_prestamos[i].DNI);
				strcpy (mis_prestamos[i].DNI, mis_prestamos[j].DNI);
				strcpy (mis_prestamos[j].DNI, tmp);
				strcpy (tmp, mis_prestamos[i].ISBN);
				strcpy (mis_prestamos[i].ISBN, mis_prestamos[j].ISBN);
				strcpy (mis_prestamos[j].ISBN, tmp);
				strcpy (tmp, mis_prestamos[i].fecha_prestamo);
				strcpy (mis_prestamos[i].fecha_prestamo, mis_prestamos[j].fecha_prestamo);
				strcpy (mis_prestamos[j].fecha_prestamo, tmp);
				strcpy (tmp, mis_prestamos[i].fecha_devolucion);
				strcpy (mis_prestamos[i].fecha_devolucion, mis_prestamos[j].fecha_devolucion);
				strcpy (mis_prestamos[j].fecha_devolucion, tmp);			
			}
		}
	}		

}



//***********************************************************
//**                                                       **
//**        FUNCION DEVOLUCION_LIBRO                       **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_PRESTAMOS
//
//
// 0) Captura de la fecha actual del sistema para almacenarla en el campo 'fecha_devolución'
//
// 1) Búsqueda de Usuario:
//     Se invoca a la función 'busqueda_usuarios' para localizar el usuario al que se prestará el libro --> se introduce el criterio de búsqueda y saca listado de usuarios.
//     Si hay algún usuario que cumpla con los requisitos de búsqueda... se hace un bucle DO-WHILE hasta que se introduzca un 'num_usuario' que exista en la estructura de usuarios
//     Una vez localizado el usuario al que prestar el libro, se muestra mensaje con los datos del usuario.
//
// 2) Búsqueda de Libro:
//     Se invoca a la función 'busqueda_libros' para localizar el libro que se prestará el libro --> se introduce el criterio de búsqueda y saca listado de libros.
//     Si hay algún libro que cumpla con los requisitos de búsqueda... se hace un bucle DO-WHILE hasta que se introduzca un 'num_libro' que exista en la estructura de libros
//     Una vez localizado el libro que se prestará, se muestra mensaje con los datos del libro.
//
// 3) Recorrido de la estructura de PRESTAMOS para buscar el prestamo:
//     La condición para encontrar el préstamo buscado es que coincida el DNI del usuario, el ISBN del libro y el libro todavía esté prestado (fecha_devolucion = 'NO DEVUELTO')
//     Si encuentra el préstamo, pone la fecha actual en la fecha_devolucion y muestra mensaje
//     En caso contrario (no se ha encontrado el préstamo tras recorres la estructura de PRESTAMOS), se indica con un mensaje
//
void devolucion_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[])
{   

	// iContadorUsuarios se usa para hacer el recorrido por el vector de USUARIOS hasta encontrar al seleccionado
	// iContadorLibros se usa para hacer el recorrido por el vector de LIBROS hasta encontrar al seleccionado	
    int iContadorUsuarios, iContadorLibros, iMaxRegistros;
	char sTemporal[100];
	int num_usuario, num_libro;
	// iResultado se usa para almacenar lo que devuelven las funciones 'busqueda_usuarios' y 'busqueda_libros'
	// valor = 0 significa que se ha encontrado al menos un registro que cumple con la condición; valor = 1 significa lo contrario
	int iResultado;

	// Variables de <time.h> para obtener la hora del sistema
  	time_t t;
   	struct tm *tm;
   	// fechayhora = fecha actual del sistema, que se copia en fecha_devolucion
   	// fechayhoradevolucion = fecha actual menos 14 días, para ver si se ha devuelto a tiempo o retrasado
   	// fechayhoraprestamo = fecha del prestamo
   	char fechayhora[100], fechayhoradevolucion[100], fechayhoraprestamo[100];

	// se obtiene la hora del sistema
   	t=time(NULL);
   	tm=localtime(&t);
   	// se copia en 'fechayhora' la fecha actual del sistema, como cadena de caracteres
   	strftime(fechayhora, 100, "%d/%m/%Y", tm);
   	
   	// resta 1.209.600 segundos, es decir, 14 días a la fecha actual del sistema  
	t = t - 1209600;
	tm=localtime(&t);
   	strftime(fechayhoradevolucion, 100, "%Y/%m/%d", tm); 
	
	// Invoca a la función 'busqueda_usuarios' para mostrar un listado de todos los usuarios que cumplen una condición (nombre o apellido contiene un literal introducido por teclado)
	iResultado = busqueda_usuarios(mis_usuarios);
	
	// tan solo se accede al registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
		// Recorrido de la estructura de USUARIOS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_usuarios[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Usuario a buscar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_usuario);
    		printf("\n");
 	 		// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContadorUsuarios = 0 ; (mis_usuarios[iContadorUsuarios].num_usuario != num_usuario) && (iContadorUsuarios <= iMaxRegistros ); iContadorUsuarios++);
			if (iContadorUsuarios > iMaxRegistros)
				printf("\nNo existe el Usuario %d.\n\n", num_usuario);			
		} while (iContadorUsuarios > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro

			
		printf("\nSe va a devolver un Prestamo realizado al Usuario %s %s %s.\n\n", mis_usuarios[iContadorUsuarios].DNI, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido);
	
	}
	
	system("pause");

	// Invoca a la función 'busqueda_libros' para mostrar un listado de todos los libros que cumplen una condición (titulo, genero o autor contiene un literal introducido por teclado)	
	iResultado = busqueda_libros(mis_libros);
	
	// tan solo se modifica un registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
	    // Recorrido de la estructura de LIBROS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_libros[iMaxRegistros].ISBN,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Libro a buscar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_libro);
    		printf("\n");
 	
 			// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContadorLibros = 0 ; (mis_libros[iContadorLibros].num_libro != num_libro) && (iContadorLibros <= iMaxRegistros ); iContadorLibros++);
			if (iContadorLibros > iMaxRegistros)
				printf("\nNo existe el Libro %d.\n\n", num_libro);				
		
		} while (iContadorLibros > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro     

		printf("\nEl Libro a devolver es %s %s.\n\n", mis_libros[iContadorLibros].ISBN, mis_libros[iContadorLibros].titulo);
	
	} 
	
	// en este punto ya se tiene seleccionado en 'iContadorUsuarios' y 'iContadorLibros' los registros de usuario y libro que se va a devolver

	system("pause");

    system("cls");
    printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
    printf("\n___________________ DEVOLUCION DE LIBROS___________________________\n\n");
    
    // Recorrido de la estructura de PRESTAMOS para buscar el prestamo
	for(iMaxRegistros = 0 ; (strcmp(mis_prestamos[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++)
	{
		// paramos la búsqueda si se encuentra el usuario, el libro y el libro no está devuelto (en fecha_devolucion tiene el valor 'NO DEVUELTO') ...
		if ( (strcmp(mis_prestamos[iMaxRegistros].DNI,mis_usuarios[iContadorUsuarios].DNI) ==0) && (strcmp(mis_prestamos[iMaxRegistros].ISBN,mis_libros[iContadorLibros].ISBN) ==0) && (strcmp(mis_prestamos[iMaxRegistros].fecha_devolucion,"NO DEVUELTO") ==0))
		{
			strcpy(mis_prestamos[iMaxRegistros].fecha_devolucion, fechayhora);
			fechayhoraprestamo[0]=mis_prestamos[iMaxRegistros].fecha_prestamo[6];
			fechayhoraprestamo[1]=mis_prestamos[iMaxRegistros].fecha_prestamo[7];
			fechayhoraprestamo[2]=mis_prestamos[iMaxRegistros].fecha_prestamo[8];
			fechayhoraprestamo[3]=mis_prestamos[iMaxRegistros].fecha_prestamo[9];						
			fechayhoraprestamo[4]='/';
			fechayhoraprestamo[5]=mis_prestamos[iMaxRegistros].fecha_prestamo[3];
			fechayhoraprestamo[6]=mis_prestamos[iMaxRegistros].fecha_prestamo[4];
			fechayhoraprestamo[7]='/';
			fechayhoraprestamo[8]=mis_prestamos[iMaxRegistros].fecha_prestamo[0];
			fechayhoraprestamo[9]=mis_prestamos[iMaxRegistros].fecha_prestamo[1];
			fechayhoraprestamo[10]='\0';
			if (strcmp(fechayhoradevolucion,fechayhoraprestamo)>0)
				printf("\nEl Libro se presto el dia %s y se ha devuelto el dia %s, superando los 14 dias de prestamo por lo que tendra penalizacion de 1 euro.\n\n", mis_prestamos[iMaxRegistros].fecha_prestamo, mis_prestamos[iMaxRegistros].fecha_devolucion);				
			printf("\nLa Devolucion del Libro '%s' prestado a '%s %s' ha sido realizada correctamente.\n\n", mis_libros[iContadorLibros].titulo, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido);
			break;
		}
	}

	// Si el DNI está vacío es porque hemos llegado al final del recorrido SIN encontrar el préstamo buscado (ese usuario, ese libro y NO DEVUELTO)
	if (strcmp(mis_prestamos[iMaxRegistros].DNI,"") ==0)
	{
		printf("\nNO existe el Prestamo del Libro '%s' a '%s %s'.\n\n", mis_libros[iContadorLibros].titulo, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido);
	}
	
	system("pause");	

}



//***********************************************************
//**                                                       **
//**        FUNCION CONSULTA_PRESTAMOS_LIBRO               **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_PRESTAMOS
// Muestra todos los préstamos realizados a un libro (actuales o pasados)
//
// Pasos a seguir:
//    1) Invoca a la función 'busqueda_libros' para mostrar un listado de todos los libros que cumplen una condición (titulo, genero o autor contiene un literal introducido por teclado)
//    2) Solo pide el número de un libro si se ha encontrado algún registro que cumplan la condición (iResultado = 0)
//    3) Recorrido de la estructura de LIBROS para determinar el número de registros
//    4) Bucle DO-WHILE mientras que no se encuentra el libro
//    5) Recorrido de la estructura de PRESTAMOS para buscar el prestamo
//       5.1) Recorrido de la estructura de USUARIOS para encontrar el usuario al que se le ha prestado el libro  --> es para tener los datos de nombre + apellido de usuario (además del DNI)
//       5.2) Recorrido de la estructura de LIBROS para encontrar el libro prestado --> es para tener el dato del título del libro (además del ISBN)
//       5.3) Imprime una fila por cada vez que el libro ha sido prestado con todos sus datos, algunos sacados de USUARIOS y LIBROS  --> num_prestamo, DNI, nombre, apellido, ISBN, titulo, fecha prestamo, fecha devolucion
//
void consulta_prestamos_libro(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[])
{   
	// iContadorUsuarios se usa para hacer el recorrido por el vector de USUARIOS hasta encontrar al seleccionado
	// iContadorLibros se usa para hacer el recorrido por el vector de LIBROS hasta encontrar al seleccionado	
    int iContadorUsuarios, iContadorLibros, iMaxRegistros;
	int num_usuario, num_libro;
	// iResultado se usa para almacenar lo que devuelven las funciones 'busqueda_usuarios' y 'busqueda_libros'
	// valor = 0 significa que se ha encontrado al menos un registro que cumple con la condición; valor = 1 significa lo contrario	
	int iResultado;   	

	// Invoca a la función 'busqueda_libros' para mostrar un listado de todos los libros que cumplen una condición (titulo, genero o autor contiene un literal introducido por teclado)	
	iResultado = busqueda_libros(mis_libros);
	
	// tan solo se accede al registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
	    // Recorrido de la estructura de LIBROS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_libros[iMaxRegistros].ISBN,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Libro a buscar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_libro);
    		printf("\n");
 	
 			// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContadorLibros = 0 ; (mis_libros[iContadorLibros].num_libro != num_libro) && (iContadorLibros <= iMaxRegistros ); iContadorLibros++);
			if (iContadorLibros > iMaxRegistros)
			{
				printf("\nNo existe el Libro %d.\n\n", num_libro);
				system("pause");
			}
				
		} while (iContadorLibros > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro     

	} 

    system("cls");
    printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
    printf("\n_______________CONSULTA PRESTAMOS DE UN LIBRO______________________\n\n");
    
	printf("\n   # %-11s %-15s %-25s %-15s %-35s %-25s %-15s","DNI", "NOMBRE","APELLIDO", "ISBN", "TITULO", "FECHA PRESTAMO", "FECHA DEVOLUCION");
	printf("\n   _ ___         ______          ________                  ____            ______                              _____________             ________________\n");	    
    
    // Recorrido de la estructura de PRESTAMOS para buscar el prestamo
	for(iMaxRegistros = 0 ; (strcmp(mis_prestamos[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++)
	{
		// Si en el recorrido se encuentra el registro buscado...
		if ( (strcmp(mis_prestamos[iMaxRegistros].ISBN,mis_libros[iContadorLibros].ISBN) ==0) )
		{
			// Recorrido de la estructura de USUARIOS para encontrar el usuario al que se le ha prestado el libro
			for(iContadorUsuarios = 0 ; (strcmp(mis_usuarios[iContadorUsuarios].DNI, mis_prestamos[iMaxRegistros].DNI) !=0) ; iContadorUsuarios++);
			// Recorrido de la estructura de LIBROS para encontrar el libro prestado
			for(iContadorLibros = 0 ; (strcmp(mis_libros[iContadorLibros].ISBN, mis_prestamos[iMaxRegistros].ISBN) !=0) ; iContadorLibros++);
			// Imprime una fila por cada vez que el libro ha sido prestado con todos sus datos, algunos sacados de USUARIOS y LIBROS
			printf("\n%4d %-11s %-15s %-25s %-15s %-35s %-25s %-15s", mis_prestamos[iMaxRegistros].num_prestamo, mis_prestamos[iMaxRegistros].DNI, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido, 
				 													mis_prestamos[iMaxRegistros].ISBN, mis_libros[iContadorLibros].titulo, mis_prestamos[iMaxRegistros].fecha_prestamo, mis_prestamos[iMaxRegistros].fecha_devolucion);
		}
	}

	printf("\n\n");
	
	system("pause");

}

//***********************************************************
//**                                                       **
//**        FUNCION CONSULTA_PRESTAMOS_USUARIO             **
//**                                                       **
//***********************************************************
//
// Esta función es invocada desde MENU_PRESTAMOS
// Muestra todos los préstamos realizados a un usuario (actuales o pasados)
//
// Pasos a seguir:
//    1) Invoca a la función 'busqueda_usuarios' para mostrar un listado de todos los usuarios que cumplen una condición (nombre o apellido contiene un literal introducido por teclado)
//    2) Solo pide el número de un usuario si se ha encontrado algún registro que cumplan la condición (iResultado = 0)
//    3) Recorrido de la estructura de USUARIOS para determinar el número de registros
//    4) Bucle DO-WHILE mientras que no se encuentra el usuario
//    5) Recorrido de la estructura de PRESTAMOS para buscar el prestamo
//       5.1) Recorrido de la estructura de USUARIOS para encontrar el usuario al que se le ha prestado el libro  --> es para tener los datos de nombre + apellido de usuario (además del DNI)
//       5.2) Recorrido de la estructura de LIBROS para encontrar el libro prestado --> es para tener el dato del título del libro (además del ISBN)
//       5.3) Imprime una fila por cada vez que el libro ha sido prestado con todos sus datos, algunos sacados de USUARIOS y LIBROS  --> num_prestamo, DNI, nombre, apellido, ISBN, titulo, fecha prestamo, fecha devolucion
//
void consulta_prestamos_usuario(Usuario mis_usuarios[], Libro mis_libros[], Prestamo mis_prestamos[])
{   
    int iContadorUsuarios, iContadorLibros, iMaxRegistros;
	char sTemporal[100];
	int num_usuario, num_libro;
	int iResultado;   	
	
	iResultado = busqueda_usuarios(mis_usuarios);
	
	// tan solo se accede al registro si se ha encontrado alguno que cumpla con el criterio de búsqueda
	if (iResultado == 0)
	{
		// Recorrido de la estructura de USUARIOS para determinar el número de registros
		for(iMaxRegistros = 0 ; (strcmp(mis_usuarios[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++);	 	

		// El numero de registro a modificar debe existir por lo que se hace bucle DO...WHILE hasta que se proporciona un número de registro válido
		do {
			// Se pide el numero de registro a modificar
			printf("\nIntroduzca el numero de registro del Usuario a buscar: ");
    		fflush(stdin);        	
    		scanf("%d", &num_usuario);
    		printf("\n");
 	 		// Se hace un recorrido por la estructura para localizarlo... hasta que se encuentra o finalizamos el recorrido sin encontrarlo
			for(iContadorUsuarios = 0 ; (mis_usuarios[iContadorUsuarios].num_usuario != num_usuario) && (iContadorUsuarios <= iMaxRegistros ); iContadorUsuarios++);
			if (iContadorUsuarios > iMaxRegistros)
				printf("\nNo existe el Usuario %d.\n\n", num_usuario);			
		} while (iContadorUsuarios > iMaxRegistros);  // sólo se termina el bucle si el contador no indica que se ha recorrido la estructura sin encontrar el registro

			
		printf("\nSe va a devolver un Prestamo realizado al Usuario %s %s %s.\n\n", mis_usuarios[iContadorUsuarios].DNI, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido);
	
	}

    system("cls");
    printf("\n__________________BIBLIOTECA DE LA ETSIDI__________________________\n\n");		
    printf("\n_______________CONSULTA PRESTAMOS DE UN USUARIO____________________\n\n");
    
	printf("\n   # %-11s %-15s %-25s %-15s %-35s %-25s %-15s","DNI", "NOMBRE","APELLIDO", "ISBN", "TITULO", "FECHA PRESTAMO", "FECHA DEVOLUCION");
	printf("\n   _ ___         ______          ________                  ____            ______                              _____________             ________________\n");	    
    
    // Recorrido de la estructura de PRESTAMOS para buscar el prestamo
	for(iMaxRegistros = 0 ; (strcmp(mis_prestamos[iMaxRegistros].DNI,"") !=0) ; iMaxRegistros++)
	{
		// paramos la búsqueda si se encuentra el usuario, el libro y el libro no está prestado...
		if ( (strcmp(mis_prestamos[iMaxRegistros].DNI,mis_usuarios[iContadorUsuarios].DNI) ==0) )
		{
			// Recorrido de la estructura de USUARIOS para encontrar el usuario al que se le ha prestado el libro
			for(iContadorUsuarios = 0 ; (strcmp(mis_usuarios[iContadorUsuarios].DNI, mis_prestamos[iMaxRegistros].DNI) !=0) ; iContadorUsuarios++);
			// Recorrido de la estructura de LIBROS para encontrar el libro prestado
			for(iContadorLibros = 0 ; (strcmp(mis_libros[iContadorLibros].ISBN, mis_prestamos[iMaxRegistros].ISBN) !=0) ; iContadorLibros++);
			printf("\n%4d %-11s %-15s %-25s %-15s %-35s %-25s %-15s", mis_prestamos[iMaxRegistros].num_prestamo, mis_prestamos[iMaxRegistros].DNI, mis_usuarios[iContadorUsuarios].nombre, mis_usuarios[iContadorUsuarios].apellido, 
				 													mis_prestamos[iMaxRegistros].ISBN, mis_libros[iContadorLibros].titulo, mis_prestamos[iMaxRegistros].fecha_prestamo, mis_prestamos[iMaxRegistros].fecha_devolucion);
		}
	}

	printf("\n\n");
	
	system("pause");

}
