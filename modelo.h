/*	Prácticas de Informática Gráfica

	Grupos C y D				Curso 2023-24
 	
	Codigo base para la realización de las practicas de IG
	
	Estudiante: Fernando Lanzarot Facio

=======================================================
*/

#include "lector-jpg.h"

void dibujoEscena(int seleccion);

void transformar(int objetoID);
/**
	Funcion de redibujado. Se ejecuta con los eventos postRedisplay
**/
void Dibuja (void);

/**
	Funcion de fondo
**/
void idle (int v);

/**
	Funcion de inicializacion del modelo y de las variables globales
**/
void initModel ();

/**
	Funcion de asignacion del modelo a la ventana
**/
void toggleAnimacion();

void setModo(int M);

void setAngBrazo(int ang);

void setAngX(int ang);

void setAngZ(int ang);

void setAltura(float height);

int getAngBrazo();

int getAngX();

int getAngZ();

float getAltura();

void setIluminacion();


#include "lector-jpg.h"
#include <GL/glut.h>
#include <iostream>

class Objeto3D {
protected:
	GLuint texId;

public:
	Objeto3D() : texId(0) {}  
	virtual void draw() = 0;

	void AsignarTextura(const char *nombre_arch) {
		unsigned ancho, alto;
		unsigned char *textura = LeerArchivoJPEG(nombre_arch, ancho, alto);

		if (textura == nullptr) {
			std::cerr << "Error al leer la textura: " << nombre_arch << std::endl;
			return;
		}

		if (texId == 0) {  // Verificar si el texId no se ha generado
			glGenTextures(1, &texId);
		}
		glBindTexture(GL_TEXTURE_2D, texId);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, ancho, alto, 0, GL_RGB, GL_UNSIGNED_BYTE, textura);

		delete[] textura;  // Liberar memoria correctamente
	}
};

