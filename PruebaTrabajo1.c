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

