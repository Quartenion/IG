/*	Prácticas de Informática Gráfica

	Grupo C					Curso 2023-24

	Codigo base para la realización de las practicas de IG

	Estudiante:

=======================================================
	G. Arroyo, J.C. Torres
	Dpto. Lenguajes y Sistemas Informticos
	(Univ. de Granada)

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details
 http://www.gnu.org/copyleft/gpl.html

=======================================================

	 mouse.c
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "practicasIG.h"


#define __mouse__ 
#include "mouse.h"

using namespace std;

int MOUSE_LEFT_DOWN=0;
int MOUSE_MIDDLE_DOWN=0;
int MOUSE_RIGHT_DOWN=0;
int MOUSE_X, MOUSE_Y;



int ISINTERACTING;

/**

Procedimiento para gestionar los eventos de pulsacion de los botones del raton.

Argumentos:

boton: Codigo glut del boton que ha manipulado el usuario.

estado: Estado en el que esta el boton que se ha pulsado.

x,y: Posicion, en coordenadas de pantalla, en que se encuantra el cursor.

**/

int pick(int x, int y,int * i)
{
	GLint viewport[4];
	unsigned char data[4];

	glGetIntegerv (GL_VIEWPORT, viewport);
	glDisable(GL_DITHER);
	glDisable(GL_LIGHTING);
	dibujoEscena(1);
	glEnable(GL_LIGHTING);
	glEnable(GL_DITHER);
	glFlush();
	glFinish();

	glReadPixels(x,viewport[3]-y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,data);

	*i=data[0];

	glutPostRedisplay();
	return *i;
}

void clickRaton( int boton, int estado, int x, int y )
{
	int objetoID=-1;
	ISINTERACTING=1;
	if(boton==GLUT_LEFT_BUTTON && estado==GLUT_DOWN) {
		MOUSE_LEFT_DOWN=1;
		MOUSE_X=x;
		MOUSE_Y=y;
		pick(x,y,&objetoID);
		
		if(objetoID != 0)
		{
			cout << "Objeto seleccionado: " << objetoID << endl;
			transformar(objetoID);
		}
	}
	else if(boton==GLUT_MIDDLE_BUTTON && estado==GLUT_DOWN) {
		MOUSE_MIDDLE_DOWN=1;
		MOUSE_X=x;
		MOUSE_Y=y;
		}
	else if(boton==GLUT_RIGHT_BUTTON && estado==GLUT_DOWN) {
		MOUSE_RIGHT_DOWN=1;
		MOUSE_X=x;
		MOUSE_Y=y;
		}
	else {	
		MOUSE_LEFT_DOWN=0;
		MOUSE_MIDDLE_DOWN=0;
		MOUSE_RIGHT_DOWN=0;
		ISINTERACTING=0;
		}
	glutPostRedisplay();
}


/**

Procedimiento para gestionar los eventos de movimiento del raton.

Argumentos:

x,y: Posicion, en coordenadas de pantalla, en que se encuantra el cursor.

**/

void RatonMovido( int x, int y )
{
char texto[30];
float ax,ay,az,d;
getCamara (ax, ay, az, d);
	if(MOUSE_MIDDLE_DOWN) {
			if(x!=MOUSE_X) ay+=x-MOUSE_X;
			if(y!=MOUSE_Y) ax+=y-MOUSE_Y;
			setCamara (ax, ay, az,  d);
	}
	else if(MOUSE_RIGHT_DOWN) {
		if(y!=MOUSE_Y) {
			d+=100.0*(y-MOUSE_Y)/200; //escalar el zoom
			setCamara (ax,  ay,  az,  d);
		}
	}
	
	MOUSE_X=x;
	MOUSE_Y=y;
glutPostRedisplay();
}
