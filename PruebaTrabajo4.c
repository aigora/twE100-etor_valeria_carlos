
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


