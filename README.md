## Biblioteca ETSIDI-CEV ##
La idea del proyecto es crear un programa para la gestión de una biblioteca,con  Usuarios, Libros y Préstamos.
## Integrantes del equipo
Nombres, apellidos, y usuario GitHub de los integrantes del equipo:
- Etor Gonzalez Perea - EtorGonzalezPerea,
- Valeria Muñoz Salazar - Sarael444
- Carlos Rodriguez Funes - CarlosRdgzFunes
## Objetivos del trabajo
- Se realizará un programa en C para la gestión de una biblioteca, que permita:
 	- Gestionar Usuarios: Alta / Baja / Modificación de Usuarios, listado de Usuarios, búsqueda de Usuarios (que contengan una cadena en nombre o apellido).
	- Gestionar Libros: Alta / Baja / Modificación de Libros, listado de Libros ordenados por varios campos, búsqueda de Libros.
	- Gestionar Préstamos:  Realizar un préstamo,  realizar una devolución, consultar histórico de préstamos realidos a un Usuario, consultar historial de préstamos realizados de un Libro.
- Todas las opciones anteriores se implementarán a través de funciones, en las que se pasarán los datos de las estructuras por referencia.
- La funcion MAIN principal llamará a diferentes menus, implementados por medio de funciones.
- La selección de las opciones en los menús se realizará por bucles DO-WHILE y con un SWITCH-CASE dentro, hasta que se seleccione salir o volver al menú principal
- Todos los datos se almacenarán en memoria en diferentes estructuras (usuario, libros, préstamos).  Cada estructura tendrá varios campos según se trate de un usuario, libro o préstamo.
- Para poder mantener los datos entre sesiones, se volcarán a fichero cada vez que se de de alta un registro o se modifique.
- Los ficheros se leerán al principio del programa para mantener los datos grabados en sesiones anteriores.
- Se incluirán validaciones en algunos campos (formato de email válido, DNI de usuarios no duplicados).
- Las fecha de préstamo y devolución se tomarán del sistema.
- Para las cadenas se usará la función GETS, que permitirá espacios dentro de la cadena.
- Se utilizarán bucles repetitivos DO-WHILE, WHILE, FOR, para implementar los recorridos de las estructuras y las preguntas a hacer.
- Se usarán sentencias de control como IF, IF-ELSE, para tomar decisiones según los valores introducidos.
