## Biblioteca ETSIDI-CEV ##
La idea del proyecto es crear un programa para la gestión de usuarios, gestión de préstamo y gestión de libros.

## Integrantes del equipo
Nombres, apellidos, y usuario GitHub de los integrantes del equipo:
  Etor Gonzalez Perea - EtorGonzalezPerea,
  Valeria Muñoz Salazar - Sarael444
  Carlos Rodriguez Funes - CarlosRdgzFunes

## Objetivos del trabajo
 -cProgramaión en .c.
 -Realizar un programa para la gestión de una biblioteca, que permita:
 	- Gestionar Usuarios: Alta / Baja / Modificación de Usuarios, listado de Usuarios, búsqueda de Usuarios.
	- Gestionar Libros: Alta / Baja / Modificación de Libros, listado de Libros ordenados por varios campos, búsqueda de Libros.
	- Gestionar Préstamos:  Realizar un préstamo,  realizar una devolución, consultar histórico de préstamos realidos a un Usuario, consultar historial de préstamos realizados de un Libro.
	
- Uso de funciones: Los menus para seleccionar las opciones se realizarán a través de funciones y seleccionando la opción por bucles DO-WHILE y con un SWITCH-CASE dentro.
- Todos los datos se volcarán en memoria en diferentes estructuras (usuario, libros, préstamos) y se volcarán a fichero cada vez que se de  de  de alta un registro o se modifique.  Los ficheros se  leerán al princip del programa para mantener  los datos grabados en sesiones anteriores.
- Se incluirán validaciones en algunos camposy se utilifuf funciones de fechas.


// Biblioteca ETSIDI-CEV
// Etor, Valeria y Carlos

#include <stdio.h>

int main ()
{
	// Este es nuestro proyecto para la asignatura de Informática.
	// Vamos a crear un programa que se encargue de efectuar tareas
	// tales como préstamos, gestiones y todo lo descrito en la
	// cabecera de GitHub.
	
	// Variables
	int
	char repetir
	
	
	// Cuerpo (en desarrollo)
	

		puts ("\250Desea repetir la ejecución de este programa?   ");
		scanf ("%c", &repetir);
		fflush (stdin);        
	} while ((repetir == 's')||(repetir == 'S'));
	
	return 12345;
}
