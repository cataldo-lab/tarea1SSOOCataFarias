# ssootarea1

# tarea1SSOOCataFarias

Aclaración:

   $g++ -std=c++11 -pthread -o carrera carrera.cpp   
   
    $./carrera

aparecera en pantalla:

"Ingrese la cantidad de metros que debe recorrer cada auto (M)" : <Numero_Entero>

"Ingrese la cantidad de autos (N)" : <Numero_Entero> 

#------------------------------------------------------

#Sistema 2:

#Archivo Makefile
   
   $CXX = g++

    $CXXFLAGS = -std=c++11 -pthread -Wall

    $EXEC = carrera_autos

    $(EXEC): carrera.cpp

    $(CXX) $(CXXFLAGS) -o $(EXEC) carrera.cpp

#se presiona archivo nombre: carrera aparecera en pantalla:

"Ingrese la cantidad de metros que debe recorrer cada auto (M)" : <Numero_Entero>

"Ingrese la cantidad de autos (N)" : <Numero_Entero>

#Se abre una terminal bash

# tarea1SSOOCataFarias
