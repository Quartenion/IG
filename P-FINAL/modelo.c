/*	
======================================================
          Práctica Final Informática Gráfica
	
	        Estudiante: Fernando Lanzarot Facio
=======================================================
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>		
#include "practicasIG.h"
#include <vector>
#include "file_ply_stl.h"

using namespace std;

// DECLARACIÓN DE VARIABLES GLOBALES
int modo = GL_FILL;
int ilu = 1;
const float DADO = 0.25f;

float angBrazo = 0;
float angOjo = 0;
float angParpado = 0;
float angCabeza = 0;
float angCofre = 0;
float altBoca  = 0;


int animacionAdivino = 0;
int animacionDespertar = 0;
int animacionDormir = 0;
int animacionMoneda = 0;
int animacionFortuna = 0;
int animacionCofre = 0;
int fortunaPendiente = 0;
int duracion = 0;
int monedas = 0;
int fortunas = 0;

// IDENTIFICADORES DE OBJETOS
int idRanura = 10;
int idMoneda1 = 20;
int idMoneda2 = 30;
int idMoneda3 = 40;
int idMoneda4 = 50;
int idMoneda5 = 60;
int idMoneda6 = 70;
int idTienda = 80;
int idMaquina = 90;
int idFortuna = 100;
int idCofre = 110;
int idTiovivo = 120;

// PARAMETROS DE TRANSFORMACIÓN
int dirBrazo = 1;
int dirOjo = 1;
int dirParpado = 1;
int dirCabeza = -1;
int dirBoca = 1;
int dirCofre = 1;
int dirCaballo1 = 1;
int dirCaballo2 = -1;
int dirCaballo3 = 1;
int dirCaballo4 = -1;

float movMonedaTemp = 3.5;
float movFortunaTemp = 1;
float movCaballo1 = 0;
float movCaballo2 = 0;
float movCaballo3 = 0;
float movCaballo4 = 0;
float rotCaballos = 0;
int tamMonedaTemp = 0;
int tamMoneda1 = 1;
int tamMoneda2 = 1;
int tamMoneda3 = 1;
int tamMoneda4 = 1;
int tamMoneda5 = 1;
int tamMoneda6 = 1;

// DECLARACIÓN DE COLORES
GLfloat rojoCircus[4] = {0.5f, 0.0f, 0.0f, 1.0f};
GLfloat tela_specular[] = {0.2f, 0.2f, 0.2f, 1.0f};  
GLfloat tela_shininess[] = {5.0f};

GLfloat blancoCircus[4] = {0.95f, 0.9f, 0.8f, 1.0f};
GLfloat cuerda_specular[] = {0.3f, 0.3f, 0.3f, 1.0f}; 
GLfloat cuerda_shininess[] = {10.0f};                

GLfloat rojoMetalico[4] = {0.5f, 0.0f, 0.0f, 1.0f};
GLfloat moradoOscuro[4] = {0.3f, 0.0f, 0.5f, 1.0f};

GLfloat verdeOscuro[] = {0.13f, 0.55f, 0.13f, 1.0f};   
GLfloat hierba_specular[] = {0.1f, 0.2f, 0.1f, 1.0f};  
GLfloat hierba_shininess[] = {10.0f};  

GLfloat oroBrillante[] = {1.0f, 0.843f, 0.0f, 1.0f}; 
GLfloat oro_specular[] = {0.628281f, 0.555802f, 0.366065f, 1.0f}; 
GLfloat oro_shininess[] = {51.2f};   

GLfloat oroClarito[4] = {0.94f, 0.82f, 0.42f, 1.0f};

GLfloat metalBase[4] = {0.75f, 0.75f, 0.75f, 1.0f};
GLfloat metal_specular[] = {0.9f, 0.9f, 0.9f, 1.0f};
GLfloat metal_shininess[] = {50.0f};

GLfloat gemaRojaAmbient[] = {0.2f, 0.0f, 0.0f, 1.0f};    
GLfloat gemaRojaDiffuse[] = {0.8f, 0.1f, 0.1f, 1.0f};    
GLfloat gemaRojaSpecular[] = {1.0f, 0.8f, 0.8f, 1.0f};   
GLfloat gemaRojaShininess[] = {90.0f}; 

GLfloat marronOscuro[4] = {0.16f, 0.03f, 0.06f, 1.0f};
GLfloat marronTurron[4] = {0.82f, 0.70f, 0.49f, 1.0f};
GLfloat piel[4] = {0.82f, 0.65f, 0.47f, 1.0f};
GLfloat amarilloMostaza[4] = {0.85f, 0.65f, 0.13f, 1.0f};
GLfloat azulIntensoOscuro[4] = {0.0f, 0.1f, 0.4f, 1.0f};
GLfloat bolaDeCristal[4] = {0.6f, 0.2f, 0.8f, 0.4f};
GLfloat cristal[4] = {0.5f, 0.8f, 0.9f, 0.3f}; 
GLfloat hitbox[4] = {0.5f, 0.8f, 0.9f, 0.0f}; 
GLfloat plateado[4] = {0.50754f, 0.50754f, 0.50754f, 1.0f}; 

// DECLARACIÓN DE FUNCIONES
void initModel ()
{
  
}

void toggleAnimacion()
{
  if(animacionAdivino == 0){
    animacionAdivino = 1;
  }
  else{
    animacionAdivino = 0;
  }
}

void setModo(int M)
{
  modo = M;
}

void setAngBrazo(int ang)
{
  angBrazo = ang;
}

void setAngX(int ang)
{
  angOjo = ang;
}

void setAngZ(int ang)
{
  angCabeza = ang;
}

void setAltura(float height)
{
  altBoca = height;
}

int getAngBrazo()
{
  return angBrazo;
}

int getAngX()
{
  return angOjo;
}

int getAngZ()
{
  return angCabeza;
}

float getAltura()
{
  return altBoca;
}

void setIluminacion()
{
  if(ilu == 1){
    ilu = 0;
  }
  else{
    ilu = 1;
  }
}

void transformar(int objetoID)
{
  if(objetoID == idRanura && monedas > 0 && !animacionAdivino && !animacionDespertar && !animacionDormir && !animacionFortuna && !fortunaPendiente)
  {
    monedas--;
    cout << "Has consumido una moneda" << endl;
    tamMonedaTemp = 1;
    duracion = 0;
    animacionMoneda = 1;
  }

  if(objetoID == idMoneda1)
  {
    monedas++;
    cout << "Has coleccionado " << monedas << " moneda(s)" << endl;
    tamMoneda1 = 0;
  }

  if(objetoID == idMoneda2)
  {
    monedas++;
    cout << "Has coleccionado " << monedas << " moneda(s)" << endl;
    tamMoneda2 = 0;
  }

  if(objetoID == idMoneda3)
  {
    monedas++;
    cout << "Has coleccionado " << monedas << " moneda(s)" << endl;
    tamMoneda3 = 0;
  }

  if(objetoID == idMoneda4)
  {
    monedas++;
    cout << "Has coleccionado " << monedas << " moneda(s)" << endl;
    tamMoneda4 = 0;
  }

  if(objetoID == idMoneda5)
  {
    monedas++;
    cout << "Has coleccionado " << monedas << " moneda(s)" << endl;
    tamMoneda5 = 0;
  }

  if(objetoID == idMoneda6)
  {
    monedas++;
    cout << "Has coleccionado " << monedas << " moneda(s)" << endl;
    tamMoneda6 = 0;
  }

  if(objetoID == idFortuna && !animacionFortuna)
  {
    fortunaPendiente = 1;
    fortunas++;
    cout << "Has coleccionado " << fortunas << " fortuna(s)" << endl;
    movFortunaTemp = 1;
    fortunaPendiente = 0;
  }

  if(objetoID == idCofre && !animacionCofre)
  {
    animacionCofre = 1;
  }
}

void ColorSeleccion( int i, int componente)
{
  unsigned char r = (i & 0xFF);
  unsigned char g = (componente & 0xFF);
  glColor3ub(r,g,0);
}

// OBJETOS 3D BÁSICOS
void calcularNormal(float v0[3], float v1[3], float v2[3]) 
{
  float normal[3];

  // Vectores entre los vértices
  float u[3] = {v1[0] - v0[0], v1[1] - v0[1], v1[2] - v0[2]};
  float v[3] = {v2[0] - v0[0], v2[1] - v0[1], v2[2] - v0[2]};

  // Producto cruzado
  normal[0] = u[1] * v[2] - u[2] * v[1];
  normal[1] = u[2] * v[0] - u[0] * v[2];
  normal[2] = u[0] * v[1] - u[1] * v[0];

  // Normalización del vector normal
  float length = sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
  normal[0] /= length;
  normal[1] /= length;
  normal[2] /= length;

  // Asignar la normal
  glNormal3f(normal[0], normal[1], normal[2]);
}

void prismaTrapecio(float height, float baseTop, float baseBottom, float depth) 
{
  // Calcula los desplazamientos desde el centro para la base menor y mayor
  float topOffset = baseTop / 2.0f;
  float bottomOffset = baseBottom / 2.0f;

  // Vértices de la cara frontal
  float frontBottomLeft[3] = {-bottomOffset, 0.0f, depth / 2.0f};
  float frontBottomRight[3] = {bottomOffset, 0.0f, depth / 2.0f};
  float frontTopRight[3] = {topOffset, height, depth / 2.0f};
  float frontTopLeft[3] = {-topOffset, height, depth / 2.0f};

  // Vértices de la cara trasera
  float backBottomLeft[3] = {-bottomOffset, 0.0f, -depth / 2.0f};
  float backBottomRight[3] = {bottomOffset, 0.0f, -depth / 2.0f};
  float backTopRight[3] = {topOffset, height, -depth / 2.0f};
  float backTopLeft[3] = {-topOffset, height, -depth / 2.0f};

  // Cara frontal (trapecio, vértices en sentido antihorario)
  glBegin(GL_POLYGON);
  calcularNormal(frontBottomLeft, frontBottomRight, frontTopRight);
  glVertex3fv(frontBottomLeft);    // Vértice inferior izquierdo
  glVertex3fv(frontBottomRight);   // Vértice inferior derecho
  glVertex3fv(frontTopRight);      // Vértice superior derecho
  glVertex3fv(frontTopLeft);       // Vértice superior izquierdo
  glEnd();

  // Cara trasera (trapecio, vértices en sentido antihorario)
  glBegin(GL_POLYGON);
  calcularNormal(backTopLeft, backTopRight, backBottomRight);
  glVertex3fv(backTopLeft);        // Vértice superior izquierdo
  glVertex3fv(backTopRight);       // Vértice superior derecho
  glVertex3fv(backBottomRight);    // Vértice inferior derecho
  glVertex3fv(backBottomLeft);     // Vértice inferior izquierdo
  glEnd();

  // Cara lateral derecha (rectángulo, vértices en sentido antihorario)
  glBegin(GL_QUADS);
  calcularNormal(frontBottomRight, backBottomRight, backTopRight);
  glVertex3fv(frontBottomRight);   // Vértice inferior derecho frontal
  glVertex3fv(backBottomRight);    // Vértice inferior derecho trasero
  glVertex3fv(backTopRight);       // Vértice superior derecho trasero
  glVertex3fv(frontTopRight);      // Vértice superior derecho frontal
  glEnd();

  // Cara lateral izquierda (rectángulo, vértices en sentido antihorario)
  glBegin(GL_QUADS);
  calcularNormal(frontTopLeft, backTopLeft, backBottomLeft);
  glVertex3fv(frontTopLeft);       // Vértice superior izquierdo frontal
  glVertex3fv(backTopLeft);        // Vértice superior izquierdo trasero
  glVertex3fv(backBottomLeft);     // Vértice inferior izquierdo trasero
  glVertex3fv(frontBottomLeft);    // Vértice inferior izquierdo frontal
  glEnd();

  // Cara inferior (rectángulo, vértices en sentido antihorario)
  glBegin(GL_QUADS);
  calcularNormal(backBottomLeft, backBottomRight, frontBottomRight);
  glVertex3fv(backBottomLeft);     // Vértice inferior izquierdo trasero
  glVertex3fv(backBottomRight);    // Vértice inferior derecho trasero
  glVertex3fv(frontBottomRight);   // Vértice inferior derecho frontal
  glVertex3fv(frontBottomLeft);    // Vértice inferior izquierdo frontal
  glEnd();

  // Cara superior (rectángulo, vértices en sentido antihorario)
  glBegin(GL_QUADS);
  calcularNormal(frontTopLeft, frontTopRight, backTopRight);
  glVertex3fv(frontTopLeft);       // Vértice superior izquierdo frontal
  glVertex3fv(frontTopRight);      // Vértice superior derecho frontal
  glVertex3fv(backTopRight);       // Vértice superior derecho trasero
  glVertex3fv(backTopLeft);        // Vértice superior izquierdo trasero
  glEnd();
}

void prismaTriangulo(float base, float height, float depth) 
{
  float halfBase = base / 2.0f;
  float halfDepth = depth / 2.0f;

  // Coordenadas de los vértices del prisma
  float frontTop[3] = {0.0f, height, halfDepth};
  float frontLeft[3] = {-halfBase, 0.0f, halfDepth};
  float frontRight[3] = {halfBase, 0.0f, halfDepth};

  float backTop[3] = {0.0f, height, -halfDepth};
  float backLeft[3] = {-halfBase, 0.0f, -halfDepth};
  float backRight[3] = {halfBase, 0.0f, -halfDepth};

  // Caras frontales y traseras (triángulos)
  glBegin(GL_TRIANGLES);

  // Frente
  calcularNormal(frontLeft, frontRight, frontTop);
  glVertex3fv(frontLeft);
  glVertex3fv(frontRight);
  glVertex3fv(frontTop);

  // Atrás
  calcularNormal(backRight, backLeft, backTop);
  glVertex3fv(backRight);
  glVertex3fv(backLeft);
  glVertex3fv(backTop);

  glEnd();

  // Caras laterales y base (cuadrados)
  glBegin(GL_QUADS);

  // Lado izquierdo
  calcularNormal(frontLeft, backLeft, backTop);
  glVertex3fv(frontTop);
  glVertex3fv(backTop);
  glVertex3fv(backLeft);
  glVertex3fv(frontLeft);

  // Lado derecho
  calcularNormal(backRight, frontRight, frontTop);
  glVertex3fv(backTop);
  glVertex3fv(frontTop);
  glVertex3fv(frontRight);
  glVertex3fv(backRight);

  // Base
  calcularNormal(frontLeft, frontRight, backRight);
  glVertex3fv(backLeft);
  glVertex3fv(backRight);
  glVertex3fv(frontRight);
  glVertex3fv(frontLeft);

  glEnd();
}

void prismaSemiCirculo(float radius, int segments, float height) 
{
  float angleStep = M_PI / segments;  // Paso de ángulo para el semicírculo
    
  // Dibujar la base (semicírculo en z = 0) con normales hacia abajo
  glBegin(GL_TRIANGLE_FAN);  
  glNormal3f(0.0f, 0.0f, -1.0f);  // Normal hacia abajo
  glVertex3f(0.0f, 0.0f, 0.0f);   // Centro de la base
  for (int i = segments; i >= 0; --i) 
  {
    float angle = angleStep * i;
    float x = radius * cos(angle);
    float y = radius * sin(angle);
    glVertex3f(x, y, 0.0f);
  }
  glEnd();

  // Dibujar la tapa (semicírculo en z = height) con normales hacia arriba
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f(0.0f, 0.0f, 1.0f);  // Normal hacia arriba
  glVertex3f(0.0f, 0.0f, height);  // Centro de la tapa
  for (int i = 0; i <= segments; ++i) 
  {
    float angle = angleStep * i;
    float x = radius * cos(angle);
    float y = radius * sin(angle);
    glVertex3f(x, y, height);
  }
  glEnd();

  // Dibujar las caras laterales
  for (int i = 0; i < segments; ++i) 
  {
    float angle1 = angleStep * i;
    float angle2 = angleStep * (i + 1);
        
    float x1 = radius * cos(angle1);
    float y1 = radius * sin(angle1);
    float x2 = radius * cos(angle2);
    float y2 = radius * sin(angle2);
        
    // Definir vértices de la cara
    float v0[] = {x2, y2, 0.0f};
    float v1[] = {x2, y2, height};
    float v2[] = {x1, y1, height};

    // Calcular normal para la cara lateral
    calcularNormal(v0, v1, v2);

    // Dibujar la cara lateral
    glBegin(GL_QUADS);
    glVertex3f(x2, y2, 0.0f);      // Vértice base 2
    glVertex3f(x2, y2, height);    // Vértice tapa 2
    glVertex3f(x1, y1, height);    // Vértice tapa 1
    glVertex3f(x1, y1, 0.0f);      // Vértice base 1
    glEnd();
  }

  // Dibujar el rectángulo en el plano z-x que cierra el semicírculo
  glBegin(GL_QUADS);
  glNormal3f(0.0f, -1.0f, 0.0f);  // Normal hacia el plano z-x
  glVertex3f(-radius, 0.0f, height);
  glVertex3f(-radius, 0.0f, 0.0f);
  glVertex3f(radius, 0.0f, 0.0f);
  glVertex3f(radius, 0.0f, height);
  glEnd();
}

void esfera(float radius) 
{
  GLUquadric* quadric = gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);
  gluSphere(quadric, radius, 32, 32);
  gluDeleteQuadric(quadric);
}

void semiEsfera(float x, float y, float z, float radio) 
{
  int numLados = 50; // Número de segmentos para la esfera
  int numVerticales = 25; // Número de segmentos verticales (solo la mitad de la esfera)

  glPushMatrix();
  glTranslatef(x, y, z); // Mover la semi-esfera a las coordenadas deseadas
  glRotatef(90.0f,1,0,0);

  // Dibuja la mitad superior de la esfera
  glBegin(GL_TRIANGLES);
  for (int i = 0; i < numVerticales; ++i) 
  {
    // Ángulos latitudinales (solo de 0 a pi/2 para la mitad superior)
    float lat1 = (M_PI / numVerticales) * i; // Ángulo latitudinal de la primera fila
    float lat2 = (M_PI / numVerticales) * (i + 1); // Ángulo latitudinal de la segunda fila

    for (int j = 0; j < numLados; ++j) 
    {
      // Ángulos longitudinales
      float lon1 = (2.0f * M_PI / numLados) * j; // Ángulo longitudinal de la primera columna
      float lon2 = (2.0f * M_PI / numLados) * (j + 1); // Ángulo longitudinal de la segunda columna

      // Coordenadas esféricas para los 4 vértices del triángulo
      float x1 = radio * sin(lat1) * cos(lon1);
      float y1 = radio * sin(lat1) * sin(lon1);
      float z1 = radio * cos(lat1);

      float x2 = radio * sin(lat2) * cos(lon1);
      float y2 = radio * sin(lat2) * sin(lon1);
      float z2 = radio * cos(lat2);

      float x3 = radio * sin(lat2) * cos(lon2);
      float y3 = radio * sin(lat2) * sin(lon2);
      float z3 = radio * cos(lat2);

      float x4 = radio * sin(lat1) * cos(lon2);
      float y4 = radio * sin(lat1) * sin(lon2);
      float z4 = radio * cos(lat1);

      // Solo dibujamos la mitad superior (latitud > 0)
      if (lat1 < M_PI / 2) 
      {
        // Calcular las normales para los dos triángulos
        float v0[3] = {x1, y1, z1};
        float v1[3] = {x2, y2, z2};
        float v2[3] = {x3, y3, z3};
        calcularNormal(v0, v1, v2);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x3, y3, z3);

        v0[0] = x1; v0[1] = y1; v0[2] = z1;
        v1[0] = x3; v1[1] = y3; v1[2] = z3;
        v2[0] = x4; v2[1] = y4; v2[2] = z4;
        calcularNormal(v0, v1, v2);
        glVertex3f(x1, y1, z1);
        glVertex3f(x3, y3, z3);
        glVertex3f(x4, y4, z4);
      }
    }
  }
  glEnd();

  // Dibuja la base plana de la semi-esfera (el círculo en el plano z = 0)
  glBegin(GL_TRIANGLES);
  for (int j = 0; j < numLados; ++j) 
  {
    // Ángulo longitudinal de la base
    float lon1 = (2.0f * M_PI / numLados) * j;
    float lon2 = (2.0f * M_PI / numLados) * (j + 1);

    // Coordenadas para los vértices de la base
    float x1 = radio * cos(lon1);
    float y1 = radio * sin(lon1);
    float z1 = 0.0f;

    float x2 = radio * cos(lon2);
    float y2 = radio * sin(lon2);
    float z2 = 0.0f;

    // Vértice central (origen de la base)
    float x0 = 0.0f;
    float y0 = 0.0f;
    float z0 = 0.0f;

    // Calcular la normal para la base
    float v0[3] = {x2, y2, z2};
    float v1[3] = {x1, y1, z1};
    float v2[3] = {x0, y0, z0};
    calcularNormal(v0, v1, v2);

    // Dibuja el triángulo que forma la base de la semi-esfera
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y1, z1);
    glVertex3f(x0, y0, z0);
  }
  glEnd();

  glPopMatrix();
}

void cuartoEsfera(float x, float y, float z, float radio) 
{
    int numLados = 50; // Número de segmentos para la esfera
    int numVerticales = 25; // Número de segmentos verticales

    glPushMatrix();
    glTranslatef(x, y, z); // Mover el cuarto de esfera a las coordenadas deseadas
    glRotatef(90.0f, 1, 0, 0);

    // Dibuja un cuarto de la esfera
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < numVerticales; ++i) 
    {
        // Ángulos latitudinales (de 0 a pi/2 para la mitad superior)
        float lat1 = (M_PI / 2.0f / numVerticales) * i;     // Ángulo latitudinal de la primera fila
        float lat2 = (M_PI / 2.0f / numVerticales) * (i + 1); // Ángulo latitudinal de la segunda fila

        for (int j = 0; j < numLados / 4; ++j) // Solo un cuarto del ángulo longitudinal
        {
            // Ángulos longitudinales (de 0 a pi/2)
            float lon1 = (M_PI / 2.0f / (numLados / 4)) * j;     // Ángulo longitudinal de la primera columna
            float lon2 = (M_PI / 2.0f / (numLados / 4)) * (j + 1); // Ángulo longitudinal de la segunda columna

            // Coordenadas esféricas para los 4 vértices del triángulo
            float x1 = radio * sin(lat1) * cos(lon1);
            float y1 = radio * sin(lat1) * sin(lon1);
            float z1 = radio * cos(lat1);

            float x2 = radio * sin(lat2) * cos(lon1);
            float y2 = radio * sin(lat2) * sin(lon1);
            float z2 = radio * cos(lat2);

            float x3 = radio * sin(lat2) * cos(lon2);
            float y3 = radio * sin(lat2) * sin(lon2);
            float z3 = radio * cos(lat2);

            float x4 = radio * sin(lat1) * cos(lon2);
            float y4 = radio * sin(lat1) * sin(lon2);
            float z4 = radio * cos(lat1);

            // Calcular las normales para los dos triángulos
            float v0[3] = {x1, y1, z1};
            float v1[3] = {x2, y2, z2};
            float v2[3] = {x3, y3, z3};
            calcularNormal(v0, v1, v2);
            glVertex3f(x1, y1, z1);
            glVertex3f(x2, y2, z2);
            glVertex3f(x3, y3, z3);

            v0[0] = x1; v0[1] = y1; v0[2] = z1;
            v1[0] = x3; v1[1] = y3; v1[2] = z3;
            v2[0] = x4; v2[1] = y4; v2[2] = z4;
            calcularNormal(v0, v1, v2);
            glVertex3f(x1, y1, z1);
            glVertex3f(x3, y3, z3);
            glVertex3f(x4, y4, z4);
        }
    }
    glEnd();

    glPopMatrix();
}

void prismaCirculo(float radius, float height) 
{
  GLUquadric* quadric = gluNewQuadric();
  gluQuadricNormals(quadric, GLU_SMOOTH);

  // Cuerpo del cilindro
  glRotatef(-90, 1, 0, 0);
  gluCylinder(quadric, radius, radius, height, 32, 32);

  // Base inferior
  glPushMatrix();
  glTranslatef(0.0f, 0.0f, 0.0f); // Mover a la posición de la base inferior
  glRotatef(180, 0, 1, 0);
  gluDisk(quadric, 0.0f, radius, 32, 1); // Crear la base inferior
  glPopMatrix();

  // Base superior
  glPushMatrix();
  glTranslatef(0.0f, 0.0f, height); // Mover a la posición de la base superior
  gluDisk(quadric, 0.0f, radius, 32, 1); // Crear la base superior
  glPopMatrix();

  gluDeleteQuadric(quadric);
}

void prismaCuadrado(float width, float height, float depth) 
{
  glScalef(width, height, depth);
  glutSolidCube(1.0f);
}

void cono(float radius, float height, int slices) 
{
  float angleIncrement = 2.0f * M_PI / slices;

  // Dibujar la base del cono
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0f, 0.0f, 0.0f); // Color rojo para la base
  float baseCenter[3] = {0.0f, 0.0f, 0.0f};
  glVertex3f(baseCenter[0], baseCenter[1], baseCenter[2]);

  for (int i = 0; i <= slices; ++i) {
    float angle = i * angleIncrement;
    float x = radius * cos(angle);
    float z = radius * sin(angle);
    float vertex[3] = {x, 0.0f, z};

    // Calcular la normal para la base
    if (i > 0) {
        float prevVertex[3] = {radius * cos((i - 1) * angleIncrement), 0.0f, radius * sin((i - 1) * angleIncrement)};
        calcularNormal(baseCenter, prevVertex, vertex);
    }
    glVertex3f(vertex[0], vertex[1], vertex[2]);
  }
  glEnd();

  // Dibujar la superficie lateral
  glBegin(GL_TRIANGLE_STRIP);

  for (int i = 0; i <= slices; ++i) {
    float angle = i * angleIncrement;
    float x = radius * cos(angle);
    float z = radius * sin(angle);
    float baseVertex[3] = {x, 0.0f, z};
    float tipVertex[3] = {0.0f, height, 0.0f};

    // Calcular la normal para la cara lateral
    float prevAngle = (i > 0) ? (i - 1) * angleIncrement : (slices - 1) * angleIncrement;
    float prevBaseVertex[3] = {radius * cos(prevAngle), 0.0f, radius * sin(prevAngle)};
    calcularNormal(tipVertex, baseVertex, prevBaseVertex);

    // Añadir vértices
    glVertex3f(baseVertex[0], baseVertex[1], baseVertex[2]);
    glVertex3f(tipVertex[0], tipVertex[1], tipVertex[2]);
  }
  glEnd();
}

void prismaTrianguloRectangulo(float base, float height, float depth) 
{
  // Vértices del triángulo base (triángulo rectángulo en el plano XZ)
  float v0[] = {0.0f, 0.0f, 0.0f};          // Vértice en el origen
  float v1[] = {base, 0.0f, 0.0f};          // Vértice en el eje X
  float v2[] = {0.0f, 0.0f, height};        // Vértice en el eje Z

  // Vértices superiores (mismo triángulo, desplazado en el eje Y)
  float v3[] = {0.0f, depth, 0.0f};
  float v4[] = {base, depth, 0.0f};
  float v5[] = {0.0f, depth, height};

  // Dibujar la base inferior
  glBegin(GL_TRIANGLES);
  calcularNormal(v0, v1, v2); // Calcular normal para la base inferior
  glVertex3fv(v0);
  glVertex3fv(v1);
  glVertex3fv(v2);
  glEnd();

  // Dibujar la base superior
  glBegin(GL_TRIANGLES);
  calcularNormal(v5, v4, v3); // Calcular normal para la base superior
  glVertex3fv(v5);
  glVertex3fv(v4);
  glVertex3fv(v3);
  glEnd();

  // Dibujar las caras laterales
  glBegin(GL_QUADS);

  // Cara 1: v0-v1-v4-v3
  calcularNormal(v3, v4, v1); // Calcular normal para la cara lateral 1
  glVertex3fv(v3);
  glVertex3fv(v4);
  glVertex3fv(v1);
  glVertex3fv(v0);

  // Cara 2: v1-v2-v5-v4
  calcularNormal(v4, v5, v2); // Calcular normal para la cara lateral 2
  glVertex3fv(v4);
  glVertex3fv(v5);
  glVertex3fv(v2);
  glVertex3fv(v1);

  // Cara 3: v2-v0-v3-v5
  calcularNormal(v5, v3, v0); // Calcular normal para la cara lateral 3
  glVertex3fv(v5);
  glVertex3fv(v3);
  glVertex3fv(v0);
  glVertex3fv(v2);

  glEnd();
}

void piramideTruncada(float baseWidth, float baseDepth, float topWidth, float topDepth, float height) 
{
  // Vértices de la base inferior (en el plano XZ)
  float b0[] = {-baseWidth / 2.0f, 0.0f, -baseDepth / 2.0f};
  float b1[] = { baseWidth / 2.0f, 0.0f, -baseDepth / 2.0f};
  float b2[] = { baseWidth / 2.0f, 0.0f,  baseDepth / 2.0f};
  float b3[] = {-baseWidth / 2.0f, 0.0f,  baseDepth / 2.0f};

  // Vértices de la base superior (en el plano XZ, desplazada en el eje Y)
  float t0[] = {-topWidth / 2.0f, height, -topDepth / 2.0f};
  float t1[] = { topWidth / 2.0f, height, -topDepth / 2.0f};
  float t2[] = { topWidth / 2.0f, height,  topDepth / 2.0f};
  float t3[] = {-topWidth / 2.0f, height,  topDepth / 2.0f};

  // Dibujar la base inferior
  glBegin(GL_QUADS);
  calcularNormal(b2, b1, b0); // Normal para la base inferior
  glVertex3fv(b0);
  glVertex3fv(b1);
  glVertex3fv(b2);
  glVertex3fv(b3);
  glEnd();

  // Dibujar la base superior
  glBegin(GL_QUADS);
  calcularNormal(t2, t1, t0); // Normal para la base superior
  glVertex3fv(t3);
  glVertex3fv(t2);
  glVertex3fv(t1);
  glVertex3fv(t0);
  glEnd();

  // Dibujar las caras laterales
  glBegin(GL_QUADS);

  // Cara 1: b0-b1-t1-t0
  calcularNormal(t0, t1, b1);
  glVertex3fv(t0);
  glVertex3fv(t1);
  glVertex3fv(b1);
  glVertex3fv(b0);

  // Cara 2: b1-b2-t2-t1
  calcularNormal(t1, t2, b2);
  glVertex3fv(t1);
  glVertex3fv(t2);
  glVertex3fv(b2);
  glVertex3fv(b1);

  // Cara 3: b2-b3-t3-t2
  calcularNormal(t2, t3, b3);
  glVertex3fv(t2);
  glVertex3fv(t3);
  glVertex3fv(b3);
  glVertex3fv(b2);

  // Cara 4: b3-b0-t0-t3
  calcularNormal(t3, t0, b0);
  glVertex3fv(t3);
  glVertex3fv(t0);
  glVertex3fv(b0);
  glVertex3fv(b3);

  glEnd();
}

// ESTRUCTURAS PARA EL MODELO 3D
struct Vertice 
{
  float x, y, z;        
  float nx = 0, ny = 0, nz = 0; 
  float u = 0, v = 0;
};

struct Triangulo 
{
  int idx1, idx2, idx3; 
  float nx, ny, nz;   
};

// CLASES PARA LOS OBJETOS 3D
class Ejes:Objeto3D 
{ 
  public: 
    float longitud = 30;
    // Dibuja el objeto
    void draw( )
    {
      glDisable (GL_LIGHTING);
      glBegin (GL_LINES);
      {
        glColor3f (0, 1, 0);
        glVertex3f (0, 0, 0);
        glVertex3f (0, longitud, 0);

        glColor3f (1, 0, 0);
        glVertex3f (0, 0, 0);
        glVertex3f (longitud, 0, 0);

        glColor3f (0, 0, 1);
        glVertex3f (0, 0, 0);
        glVertex3f (0, 0, longitud);
      }
      glEnd ();
      glEnable (GL_LIGHTING);

    }
}; 

class MallaVirtual : public Objeto3D
{
  public:
    vector<Vertice> vertices;      // Lista de vértices
    vector<Triangulo> triangulos;  // Lista de triángulos

    const char *imagen;
    int textura = 0;

    float color_difuso[4] = {0.8f, 0.8f, 0.8f, 1.0f};     
    float color_especular[4] = {0.2f, 0.2f, 0.2f, 1.0f};  
    float color_ambiente[4];                              
    float brillo = 10.0f;
    int difuso = 0;

    float altura;
    float desplazamiento;

    float minX, maxX, minY, maxY, minZ, maxZ;
    vector<float> centroGeometrico;
};

class ImportaMalla : public MallaVirtual
{
  public:
    ImportaMalla(const char *nombreArchivo, const char * nombre_arch)
    {
        imagen = nombre_arch;

        vector<float> vertices_ply;
        vector<int> caras_ply;
        vector<float> texturas_ply;
        ply::read(nombreArchivo, vertices_ply, caras_ply, texturas_ply);

        // Convertir los datos del PLY a la estructura Vertice
        int num_vertices = vertices_ply.size() / 3;
        for (int i = 0; i < num_vertices; ++i) {
            Vertice vertice;
            vertice.x = vertices_ply[3 * i];
            vertice.y = vertices_ply[3 * i + 1];
            vertice.z = vertices_ply[3 * i + 2];
            vertice.nx = vertice.ny = vertice.nz = 0.0f;
            vertice.u = texturas_ply[2 * i];
            vertice.v = texturas_ply[2 * i + 1];
            vertices.push_back(vertice);
        }

        // Crear los triángulos y calcular las normales de las caras
        int num_caras = caras_ply.size() / 3;
        for (int i = 0; i < num_caras; ++i) {
            Triangulo tri;
            tri.idx1 = caras_ply[3 * i];
            tri.idx2 = caras_ply[3 * i + 1];
            tri.idx3 = caras_ply[3 * i + 2];

            // Calcular la normal del triángulo
            calcularNormalTriangulo(tri);
            triangulos.push_back(tri);
        }

        // Calcular las normales de los vértices (para sombreado suave)
        calcularNormalesVertices();
    }

    ImportaMalla(const char *nombreArchivo)
    {
        vector<float> vertices_ply;
        vector<int> caras_ply;
        ply::read(nombreArchivo, vertices_ply, caras_ply);

        // Convertir los datos del PLY a la estructura Vertice
        int num_vertices = vertices_ply.size() / 3;
        for (int i = 0; i < num_vertices; ++i) {
            Vertice vertice;
            vertice.x = vertices_ply[3 * i];
            vertice.y = vertices_ply[3 * i + 1];
            vertice.z = vertices_ply[3 * i + 2];
            vertice.nx = vertice.ny = vertice.nz = 0.0f;
            vertices.push_back(vertice);
        }

        // Crear los triángulos y calcular las normales de las caras
        int num_caras = caras_ply.size() / 3;
        for (int i = 0; i < num_caras; ++i) {
            Triangulo tri;
            tri.idx1 = caras_ply[3 * i];
            tri.idx2 = caras_ply[3 * i + 1];
            tri.idx3 = caras_ply[3 * i + 2];

            // Calcular la normal del triángulo
            calcularNormalTriangulo(tri);
            triangulos.push_back(tri);
        }

        // Calcular las normales de los vértices (para sombreado suave)
        calcularNormalesVertices();
    }

    // Calcula la normal de un triángulo 
    void calcularNormalTriangulo(Triangulo& tri)
    {
        Vertice &v1 = vertices[tri.idx1];
        Vertice &v2 = vertices[tri.idx2];
        Vertice &v3 = vertices[tri.idx3];

        float ux = v2.x - v1.x;
        float uy = v2.y - v1.y;
        float uz = v2.z - v1.z;

        float vx = v3.x - v1.x;
        float vy = v3.y - v1.y;
        float vz = v3.z - v1.z;

        // Producto cruzado
        tri.nx = uy * vz - uz * vy;
        tri.ny = uz * vx - ux * vz;
        tri.nz = ux * vy - uy * vx;

        // Normalizar la normal de la cara
        float length = sqrt(tri.nx * tri.nx + tri.ny * tri.ny + tri.nz * tri.nz);
        tri.nx /= length;
        tri.ny /= length;
        tri.nz /= length;
    }

    // Calcula las normales de los vértices (para sombreado suave)
    void calcularNormalesVertices()
    {
        for (auto& vertice : vertices) {
            vertice.nx = 0.0f;
            vertice.ny = 0.0f;
            vertice.nz = 0.0f;
        }

        for (const auto& tri : triangulos) {

            vertices[tri.idx1].nx += tri.nx;
            vertices[tri.idx1].ny += tri.ny;
            vertices[tri.idx1].nz += tri.nz;

            vertices[tri.idx2].nx += tri.nx;
            vertices[tri.idx2].ny += tri.ny;
            vertices[tri.idx2].nz += tri.nz;

            vertices[tri.idx3].nx += tri.nx;
            vertices[tri.idx3].ny += tri.ny;
            vertices[tri.idx3].nz += tri.nz;
        }

        // Normalizar las normales de los vértices
        for (auto& vertice : vertices) {
            float length = sqrt(vertice.nx * vertice.nx + vertice.ny * vertice.ny + vertice.nz * vertice.nz);
            if (length != 0.0f) {
                vertice.nx /= length;
                vertice.ny /= length;
                vertice.nz /= length;
            }
        }
    }

    void setColorDifuso(float r, float g, float b, float alpha = 1.0f)
    {
        color_difuso[0] = r; color_difuso[1] = g; color_difuso[2] = b; color_difuso[3] = alpha;
        if(difuso == 0){
          color_ambiente[0] = r; color_ambiente[1] = g; color_ambiente[2] = b; color_ambiente[3] = alpha;
        }   
    }

    void setColorEspecular(float r, float g, float b, float alpha = 1.0f)
    {
        color_especular[0] = r; color_especular[1] = g; color_especular[2] = b; color_especular[3] = alpha;
    }

    void setColorAmbiente(float r, float g, float b, float alpha = 1.0f)
    {
        color_ambiente[0] = r; color_ambiente[1] = g; color_ambiente[2] = b; color_ambiente[3] = alpha;
        difuso = 1;
    }

    void setBrillo(float shininess)
    {
        brillo = shininess;
    }

    void aplicarMaterial()
    {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color_difuso);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color_especular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color_ambiente);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo);
    }

    void aplicarTextura()
    {
      AsignarTextura(imagen);
      textura = 1;
    }

    // Dibuja el modelo con sombreado plano
    void draw()
    {
        glBegin(GL_TRIANGLES);
        for (const auto& tri : triangulos)
        {
            glNormal3f(tri.nx, tri.ny, tri.nz);

            const Vertice& v1 = vertices[tri.idx1];
            const Vertice& v2 = vertices[tri.idx2];
            const Vertice& v3 = vertices[tri.idx3];

            glVertex3f(v1.x, v1.y, v1.z);
            glVertex3f(v2.x, v2.y, v2.z);
            glVertex3f(v3.x, v3.y, v3.z);
        }
        glEnd();
    }

    // Dibuja el modelo con sombreado suave
    void drawSuave()
    {
        glBegin(GL_TRIANGLES);
        for (const auto& tri : triangulos)
        {
            const Vertice& v1 = vertices[tri.idx1];
            const Vertice& v2 = vertices[tri.idx2];
            const Vertice& v3 = vertices[tri.idx3];

            glNormal3f(v1.nx, v1.ny, v1.nz);
            glVertex3f(v1.x, v1.y, v1.z);

            glNormal3f(v2.nx, v2.ny, v2.nz);
            glVertex3f(v2.x, v2.y, v2.z);

            glNormal3f(v3.nx, v3.ny, v3.nz);
            glVertex3f(v3.x, v3.y, v3.z);
        }
        glEnd();
    }

    void drawTextura()
    {
      if (texId == 0) return; // Asegurarse de que hay una textura asignada

      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, texId);
      glBegin(GL_TRIANGLES);
    
      for (const auto& tri : triangulos)
      {
          glNormal3f(tri.nx, tri.ny, tri.nz);

          const Vertice& v1 = vertices[tri.idx1];
          const Vertice& v2 = vertices[tri.idx2];
          const Vertice& v3 = vertices[tri.idx3];

          glTexCoord2f(v1.u, v1.v);
          glVertex3f(v1.x, v1.y, v1.z);

          glTexCoord2f(v2.u, v2.v);
          glVertex3f(v2.x, v2.y, v2.z);

          glTexCoord2f(v3.u, v3.v);
          glVertex3f(v3.x, v3.y, v3.z);
      }

      glEnd();
      glDisable(GL_TEXTURE_2D);
    }

    int getAsignada()
    {
      return textura;
    }
};

ImportaMalla bale("paja.ply", "hay.jpg");
ImportaMalla plastic("plastico.ply", "plastic.jpg");

class TiendaCirco : public Objeto3D 
{
  private:                    
    // COMPONENTES BÁSICAS
    void cima()
    {
      // ASIGNACIÓN DE MATERIALES
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroBrillante);
      glMaterialfv(GL_FRONT, GL_SPECULAR, oro_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, oro_shininess);
      
      glPushMatrix();
      glTranslatef(0,1,0);
      glScalef(0.5,0.5,0.5);
      semiEsfera(0,1,0,1);

      glPushMatrix();
      glTranslatef(0,1,0);
      cono(1,5,20);
      glPopMatrix();
      glPopMatrix();
      
      glPushMatrix();
      prismaCirculo(0.2,1.5);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(0,0.7,0);
      prismaCirculo(0.3,0.2);
      glPopMatrix();

      glPushMatrix();
      prismaCirculo(0.6,0.2);
      glPopMatrix();

      glPushMatrix();
      glRotatef(180,1,0,0);
      semiEsfera(0,0,0,0.5);
      glPopMatrix();
    }

    void enganche()
    {
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroBrillante);
      glMaterialfv(GL_FRONT, GL_SPECULAR, oro_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, oro_shininess);

      glPushMatrix();
      glTranslatef(0, 2, 0);
      esfera(0.3);
      glPopMatrix();

      glPushMatrix();
      prismaCirculo(0.1, 2);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(0, 1.5, 0);
      prismaCirculo(0.2, 0.1);
      glPopMatrix();
    }

    void pared()
    {
      glPushMatrix();
        glTranslatef(0, 0, 19);
        glRotatef(-8.531,1,0,0);
        prismaTrapecio(20, 10.58, 12.52, 0.5);  
      glPopMatrix();
    }

    void decoracion()
    {
      glPushMatrix();
        glTranslatef(0.0f,1.25f,0.0f);
        glPushMatrix();
          prismaCuadrado(11.13, 2.5, 0.5);
        glPopMatrix();

        float tam_semi = 1.9f;
        float tam_sep = 3.65f;
        glPushMatrix();
          glTranslatef(-3.65f, 1.25f, -0.25f);
          prismaSemiCirculo(tam_semi, 100, 0.5);
          glTranslatef(tam_sep, 0.0f, 0.0f);
          prismaSemiCirculo(tam_semi, 100, 0.5);
          glTranslatef(tam_sep, 0.0f, 0.0f);
          prismaSemiCirculo(tam_semi, 100, 0.5);
        glPopMatrix();
      glPopMatrix();
    }

    void teja()
    {
      glPushMatrix();
        glTranslatef(0, 20, 17);
        glRotatef(-59,1,0,0);
        prismaTriangulo(11.13, 20, 0.5);
      glPopMatrix();
    }

    void cuerda()
    {
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoCircus);
      glMaterialfv(GL_FRONT, GL_SPECULAR, cuerda_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, cuerda_shininess);   

      glTranslatef(-40,-0.5,0);
      glPushMatrix();
        glRotatef(-46.8,0,0,1);
        prismaCirculo(0.05, 30.4);
      glPopMatrix();
    }

    void clavo()
    {
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, metalBase);
      glMaterialfv(GL_FRONT, GL_SPECULAR, metal_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, metal_shininess); 

      glRotatef(15,0,0,1);
      glTranslatef(0,-0.5,0);

      glPushMatrix();
        prismaCirculo(0.1, 1);
      glPopMatrix();

      glPushMatrix();
        glTranslatef(0, 1, 0);
        prismaCirculo(0.3, 0.1);
      glPopMatrix();

      glPushMatrix();
        glRotatef(180,1,0,0);
        cono(0.1, 0.5, 20);
      glPopMatrix();
    }
    // COMPONENTES CIRCO

    void paja()
    {
      glPushMatrix();
        bale.aplicarMaterial();
        if(bale.getAsignada() == 0)
        {
          bale.aplicarTextura();
        }
        bale.drawTextura();
      glPopMatrix();

      glPushMatrix();
        plastic.aplicarMaterial();
        if(plastic.getAsignada() == 0)
        {
          plastic.aplicarTextura();
        }
        plastic.drawTextura();
      glPopMatrix();
    }

    void base( int n, float radius, float height)
    {
      // PAJARES
      glPushMatrix();
        glTranslatef(17,1.8,20);
        glRotatef(-90,1,0,0);
        glRotatef(65,0,0,1);
        glScalef(6,6,6);
        paja();
      glPopMatrix();

      glPushMatrix();
        glTranslatef(23.5,1.8,28);
        glRotatef(-90,1,0,0);
        glRotatef(15,0,0,1);
        glScalef(6,6,6);
        paja();
      glPopMatrix();

      glPushMatrix();
        glTranslatef(21,5.5,24);
        glRotatef(-90,1,0,0);
        glRotatef(40,0,0,1);
        glScalef(6,6,6);
        paja();
      glPopMatrix();

      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, verdeOscuro);
      glMaterialfv(GL_FRONT, GL_SPECULAR, hierba_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, hierba_shininess);

      glPushMatrix();
        glTranslatef(0.0f, -height, 0.0);
        if (n < 3) {
          std::cerr << "El número de lados debe ser al menos 3." << std::endl;
          return;
        }

        float angleIncrement = 2 * M_PI / n; // Incremento angular
        std::vector<std::pair<float, float>> vertices;

        // Generar los vértices del polígono base
        for (int i = 0; i < n; i++) {
            float angle = i * angleIncrement;
            float x = radius * cos(angle);
            float z = radius * sin(angle);
            vertices.emplace_back(x, z);
        }

        // Dibujar caras laterales
        glBegin(GL_QUADS);
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;

            // Vértices de la cara lateral
            float x1 = vertices[i].first;
            float z1 = vertices[i].second;
            float x2 = vertices[next].first;
            float z2 = vertices[next].second;

            // Normal para la cara lateral
            float normalX = z2 - z1;
            float normalZ = x1 - x2;
            float length = sqrt(normalX * normalX + normalZ * normalZ);
            normalX /= length;
            normalZ /= length;

            glNormal3f(normalX, 0.0f, normalZ); // Normal para la cara lateral
            glVertex3f(x1, 0.0f, z1);           // Vértice inferior izquierdo
            glVertex3f(x1, height, z1);         // Vértice superior izquierdo
            glVertex3f(x2, height, z2);         // Vértice superior derecho
            glVertex3f(x2, 0.0f, z2);           // Vértice inferior derecho
        }
        glEnd();

        // Dibujar tapa inferior 
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, -1.0f, 0.0f); 
        for (int i = 0; i < n; i++) { 
            glVertex3f(vertices[i].first, 0.0f, vertices[i].second);
        }
        glEnd();

        // Dibujar tapa superior 
        glBegin(GL_POLYGON);
        glNormal3f(0.0f, 1.0f, 0.0f); 
        for (int i = n - 1; i >= 0; i--) { 
            glVertex3f(vertices[i].first, height, vertices[i].second);
        }
        glEnd();
      glPopMatrix();
    }

    void telon()
    {
      int alternar = 1;
      glPushMatrix();
        for(int i = 0; i < 9; i++)
        {
          if( alternar == 1 )
          {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoCircus);
            glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
            glRotatef(36,0,1,0);
            pared();
          }
          else if( alternar == -1)
          {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, rojoCircus);
            glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
            glRotatef(36,0,1,0);
            pared();
          }
          alternar *= -1;
        }
      glPopMatrix();
    }

    void techo()
    {
      glPushMatrix();

      glPushMatrix();
      glTranslatef(0,30.2,0);
      cima();
      glPopMatrix();

      int alternar = 1;
      for(int i = 0; i < 10; i++)
      {
        glRotatef(36,0,1,0);
        if(alternar == 1)
        {
          glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoCircus);
            glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
            teja();
          glPopMatrix();

          glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, rojoCircus);
            glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
            glTranslatef(0.0f,20.1f,16.9f);
            glRotatef(145,1,0,0);
            decoracion();
          glPopMatrix();
        }
        else if(alternar == -1)
        {
          glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, rojoCircus);
            glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
            teja();
          glPopMatrix();

          glPushMatrix();
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoCircus);
            glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
            glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
            glTranslatef(0.0f,20.1f,16.9f);
            glRotatef(145,1,0,0);
            decoracion();
          glPopMatrix();
        }

        glPushMatrix();
          glTranslatef(-5.5f,19.2f,17.0f);
          enganche();
        glPopMatrix();

        if( i != 1 && i != 2)
        {
          glPushMatrix();
            cuerda();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-39.5,0,0);
            clavo();
          glPopMatrix();
        }
        alternar *= -1;
      }
      glPopMatrix();
    }

    void circo()
    {
      base(10,100,1);
      telon();
      techo();
    }

  public:

    void draw()
    {
      circo();
    }
    
};

class Ranura : public Objeto3D
{
  private:
  void ranura()
  {
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroClarito);
    glPushMatrix();
    prismaCuadrado(1,2,0.5);
    glPopMatrix();

    // RANURA
    glPushMatrix();
    glTranslatef(-0.05,0.4,0.25);
    glRotatef(90,0,0,1);
    prismaSemiCirculo(0.3,20,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05,0.4,0.25);
    glRotatef(270,0,0,1);
    prismaSemiCirculo(0.3,20,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.65,0.3);
    prismaCuadrado(0.1,0.1,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0.15,0.3);
    prismaCuadrado(0.1,0.1,0.1);
    glPopMatrix();

    // DEVOLUCIÓN
    glPushMatrix();
    glTranslatef(-0.05,-0.7,0.25);
    glRotatef(90,0,0,1);
    prismaTrianguloRectangulo(0.5,0.2,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15,-0.7,0.25);
    glRotatef(90,0,0,1);
    prismaTrianguloRectangulo(0.5,0.2,0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-0.65,0.3);
    prismaCuadrado(0.1,0.1,0.22);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05,-0.7,0.41);
    glRotatef(90,0,0,1);
    prismaTrianguloRectangulo(0.1,0.04,0.1);
    glPopMatrix();

    // TORNILLOS
    glPushMatrix();
    glTranslatef(-0.4,0.9,0.25);
    glRotatef(90,1,0,0);
    prismaCirculo(0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,0.9,0.25);
    glRotatef(90,1,0,0);
    prismaCirculo(0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,-0.9,0.25);
    glRotatef(90,1,0,0);
    prismaCirculo(0.05,0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4,-0.9,0.25);
    glRotatef(90,1,0,0);
    prismaCirculo(0.05,0.05);
    glPopMatrix();
  }

  public:
    void draw()
    {
      ranura();
    }
};

ImportaMalla head("cabeza.ply");
ImportaMalla mandible("mandibula.ply");
ImportaMalla beard("barba.ply");
ImportaMalla turban("turbante.ply");
ImportaMalla moustache("bigote.ply");
ImportaMalla thorax("torso.ply");
ImportaMalla jacket("chaqueta.ply");
ImportaMalla left_hand("mano.ply");
ImportaMalla right_hand("manodcha.ply");
ImportaMalla arm("brazo.ply");
ImportaMalla shoulder("hombro.ply");

class Adivino : public Objeto3D
{
  private:
  void turbante()
  {
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, amarilloMostaza);
    glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
    
    turban.draw();
    glPushMatrix();
      glMaterialfv(GL_FRONT, GL_AMBIENT, gemaRojaAmbient);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, gemaRojaDiffuse);
      glMaterialfv(GL_FRONT, GL_SPECULAR, gemaRojaSpecular);
      glMaterialfv(GL_FRONT, GL_SHININESS, gemaRojaShininess);
      glScalef(1,1,1.5);
      glTranslatef(0,-0.45,0.5);
      esfera(0.5);
    glPopMatrix();
  }

  void boca()
  {
    glPushMatrix();
      glTranslatef(0,0,altBoca);

      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
      mandible.draw();

      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
        glTranslatef(0,-0.75,-0.8);
        glRotatef(90,0,0,1);
        glScalef(0.2,0.1,0.2);
        beard.draw();
      glPopMatrix();

    glPopMatrix();
  }

  void parpado()
  {
    glRotatef(angParpado,1,0,0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
    glPushMatrix();
    glRotatef(180,1,0,0);
    semiEsfera(0,0,0,0.22);
    glPopMatrix();
  }

  void ojo()
  {
    glPushMatrix();
      parpado();
    glPopMatrix();

    glRotatef(angOjo,0,1,0);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoCircus);
    esfera(0.2);
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, moradoOscuro);
    glTranslatef(0,0,0.06);
    esfera(0.15);
    glPopMatrix();
  }

  void ceja()
  {
    glPushMatrix();
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
      glTranslatef(0.15,0,0);
      glRotatef(90,0,0,1);
      prismaTrapecio(0.3,0.05,0.1,0.05);
    glPopMatrix();
  }

  void cabeza()
  {
    glPushMatrix();
      glRotatef(angCabeza,1,0,0);
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
      glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
      // CABEZA
      glPushMatrix();
        glTranslatef(0,0.2,0.2);
        glRotatef(-90,1,0,0);
        head.draw(); 
        boca();
      glPopMatrix();

      // TURBANTE
      glPushMatrix();
        glTranslatef(0,0.4,0);
        glRotatef(-110,1,0,0);
        glScalef(0.8,1,0.6);
        turbante();
      glPopMatrix();

      // OJOS
      glPushMatrix();
        glTranslatef(0.25,0.25,0.62);
        glScalef(0.5,0.5,0.5);
        ojo();
      glPopMatrix();

      glPushMatrix();
        glTranslatef(-0.25,0.25,0.62);
        glScalef(0.5,0.5,0.5);
        ojo();
      glPopMatrix();

      // CEJAS
      glPushMatrix();
        glTranslatef(0.25,0.4,0.8);
        glRotatef(20,0,1,0);
        ceja();
      glPopMatrix();

      glPushMatrix();
        glTranslatef(-0.25,0.4,0.8);
        glRotatef(160,0,1,0);
        ceja();
      glPopMatrix();

      // BIGOTE
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
        glTranslatef(0,-0.2,1);
        glScalef(0.2,0.2,0.1);
        glRotatef(-90,1,0,0);
        moustache.draw();
      glPopMatrix();

      // OREJAS
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
        glTranslatef(0.5,0.3,0.2);
        glRotatef(90,0,1,0);
        glRotatef(-135,0,0,1);
        glRotatef(20,0,1,0);
        prismaSemiCirculo(0.2,20,0.1);
      glPopMatrix();

      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
        glTranslatef(-0.5,0.3,0.2);
        glRotatef(-90,0,1,0);
        glRotatef(135,0,0,1);
        glRotatef(-20,0,1,0);
        prismaSemiCirculo(0.2,20,0.1);
      glPopMatrix();

      // DIENTES
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoCircus);
        glTranslatef(0,-0.25,0.7);
        prismaCuadrado(0.5,0.1,0.1);
      glPopMatrix();

    glPopMatrix();
  }

  void brazo()
  {
    glRotatef(angBrazo,0,1,0);

    glPushMatrix();
      glTranslatef(0,10,3.5);
      glRotatef(90,1,0,0);
      glRotatef(180,0,1,0);
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
      right_hand.draw();
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, amarilloMostaza);

      glPushMatrix();
        glScalef(1,0.6,1);
        arm.draw();
      glPopMatrix();

    glPopMatrix();
  }

  void torso()
  {
    // TORSO
    glPushMatrix();
      glTranslatef(0,1,0);
      glRotatef(-90,1,0,0);
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, amarilloMostaza);
      glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
      thorax.draw();
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, moradoOscuro);
      glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
      jacket.draw();
    glPopMatrix();

    // CUELLO
    glPushMatrix();
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
      glTranslatef(0,1.6,0.25);
      prismaCirculo(0.3,1);
    glPopMatrix();

    // BRAZO DERECHO
    glPushMatrix();
      glScalef(0.4,0.4,0.4);
      glTranslatef(-3.5,1.8,1);
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, amarilloMostaza);
        glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
        glTranslatef(0,0,4);
        glRotatef(90,1,0,0);
        glRotatef(180,0,1,0);

        glPushMatrix();
          glScalef(0.7,0.7,0.7);
          glRotatef(-25,0,1,0);
          shoulder.draw();
        glPopMatrix();


      glPopMatrix();

      glPushMatrix();
        glTranslatef(0,-10,0);
        brazo();
      glPopMatrix();

    glPopMatrix();

    // BRAZO IZQUIERDO
    glPushMatrix();
      glScalef(0.4,0.4,0.4);
      glTranslatef(3.5,1.8,1);
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, amarilloMostaza);
        glMaterialfv(GL_FRONT, GL_SPECULAR, tela_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, tela_shininess);
        glTranslatef(0,0,4);
        glRotatef(90,1,0,0);
        glRotatef(180,0,1,0);

        glPushMatrix();
          glScalef(0.7,0.7,0.7);
          glRotatef(25,0,1,0);
          shoulder.draw();
        glPopMatrix();

        glTranslatef(0,-0.5,0);

        glPushMatrix();
          glScalef(1,0.6,1);
          arm.draw();
        glPopMatrix();

        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, piel);
        left_hand.draw();
      glPopMatrix();
    glPopMatrix();
  }

  void adivino()
  {
    glPushMatrix();
      glTranslatef(0,3.3,0.4);
      glRotatef(30,1,0,0);
      cabeza();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.3,1.3,1.3);
      torso();
    glPopMatrix();
  }
  public:
  void draw()
  {
    adivino();
  }
};

// DECLARO AQUÍ EL ADIVINO PARA PODER USARLO EN LA MÁQUINA ADIVINO
Adivino adivino;
ImportaMalla curtain("cortina.ply", "cortina.jpeg");
ImportaMalla deck("baraja.ply", "tarot_back.jpg");
ImportaMalla hand("manocartas.ply", "tarot.jpg");
ImportaMalla rug("alfombra.ply", "rug.jpg");
ImportaMalla fondo("fondo.ply", "tarot_back.jpg");

class MaquinaAdivino : public Objeto3D
{
  private:
  // COMPONENTES MAQUINA ADIVINO
  void rayo()
  {
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroBrillante);
    glPushMatrix();
    glTranslatef(0,0.5,0);
    prismaTriangulo(0.1,0.3,0.1);
    glPopMatrix();
  }

  void dispensador()
  {
    // CAJA
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroClarito);

    glPushMatrix();
    glTranslatef(0,1,0);
    prismaCuadrado(4,0.5,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.7,0);
    prismaCuadrado(4,0.5,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75,1.35,0);
    prismaCuadrado(0.5,1.2,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.75,1.35,0);
    prismaCuadrado(0.5,1.2,0.5);
    glPopMatrix();

    // DECORACIÓN
    glPushMatrix();
    glTranslatef(0,1.9,-0.1);
    prismaSemiCirculo(1,20,0.35);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.1,-0.31);
    esfera(0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2.1,0.24);
    glRotatef(156,0,0,1);
    for(int i = 0; i < 14 ;i++)
    {
      if(i != 0 && i != 1 && i != 2)
      {
        glRotatef(-26.0714285714,0,0,1);
        rayo();
      }
    }
    glPopMatrix();
  }
  
  void baraja()
  {
    glPushMatrix();
      deck.aplicarMaterial();
      if(deck.getAsignada() == 0)
      {
        deck.aplicarTextura();
      }
      deck.drawTextura();
    glPopMatrix();
  }

  void mano()
  {
    glPushMatrix();
      hand.aplicarMaterial();
      if(hand.getAsignada() == 0)
      {
        hand.aplicarTextura();
      }
      hand.drawTextura();
    glPopMatrix();
  }

  void alfombra()
  {
    glPushMatrix();
      rug.aplicarMaterial();
      if(rug.getAsignada() == 0)
      {
        rug.aplicarTextura();
      }
      rug.drawTextura();
    glPopMatrix();
  }

  void panel()
  {
    glPushMatrix();
      fondo.aplicarMaterial();
      if(fondo.getAsignada() == 0)
      {
        fondo.aplicarTextura();
      }
      fondo.drawTextura();
    glPopMatrix();
  }

  void decoracion()
  {
    // BARAJA
    glPushMatrix();
      glTranslatef(3.5,9.2,3);
      glScalef(0.2,0.2,0.2);
      baraja();
    glPopMatrix();

    // CARTAS
    glPushMatrix();
      glTranslatef(0,9.2,3);
      glScalef(0.2,0.2,0.2);
      mano();
    glPopMatrix();

    // ALFOMBRA
    glPushMatrix();
      glTranslatef(0,8.925,0);
      glRotatef(90,1,0,0);
      glScalef(4,4,4);
      alfombra();
    glPopMatrix();

    // FONDO
    glPushMatrix();
      glTranslatef(0,14,-3.8);
      //glRotatef(90,1,0,0);
      glScalef(2,2,2);
      panel();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-2.1,5,3.8);
      dispensador();
    glPopMatrix();
    //////////////////// CARA FRONTAL ////////////////////
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
    // DECORACIÓN ARRIBA
    glPushMatrix();
      glTranslatef(-4.2, 8.5, 4.1);
      glRotatef(90,0,1,0);
      glPushMatrix();
        glRotatef(90,0,0,1);
        prismaSemiCirculo(0.3, 20, 8.4);
      glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.2, 20.5, 4.1);
    glRotatef(90,0,1,0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    prismaSemiCirculo(0.3, 20, 8.4);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN ABAJO
    glPushMatrix();
    glTranslatef(-4.2, 0.5, 4.1);
    glRotatef(90,0,1,0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    prismaSemiCirculo(0.3, 20, 8.4);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN IZDA
    glPushMatrix();
    glTranslatef(-4.7, 8.05, 4.1);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 7);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.7, 20, 4.1);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 11);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN DCHA
    glPushMatrix();
    glTranslatef(4.7, 8.05, 4.1);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 7);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.7, 20, 4.1);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 11);
    glPopMatrix();
    glPopMatrix();

    //////////////// CHINCHETAS ////////////////
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroClarito);
    // CHINCHETA ABAJO IZQUIERDA
    glPushMatrix();
    glTranslatef(-4.7,0.5,4.2);
    glRotatef(90,1,0,0);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA ABAJO DERECHA
    glPushMatrix();
    glTranslatef(4.7,0.5,4.2);
    glRotatef(90,1,0,0);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA MEDIO IZQUIERDA
    glPushMatrix();
    glTranslatef(-4.7,8.5,4.2);
    glRotatef(90,1,0,0);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA MEDIO DERECHA
    glPushMatrix();
    glTranslatef(4.7,8.5,4.2);
    glRotatef(90,1,0,0);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA ARRIBA IZQUIERDA
    glPushMatrix();
    glTranslatef(-4.7,20.5,4.2);
    glRotatef(90,1,0,0);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA ARRIBA DERECHA
    glPushMatrix();
    glTranslatef(4.7,20.5,4.2);
    glRotatef(90,1,0,0);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();

    //////////////////// CARA IZQUIERDA ////////////////////
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
    // DECORACIÓN ARRIBA
    glPushMatrix();
    glTranslatef(-5.1, 8.5, 3.2);
    glRotatef(180,0,1,0);
    glPushMatrix();
    glRotatef(-90,0,0,1);
    prismaSemiCirculo(0.3, 20, 6.26);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.1, 20.5, 3.2);
    glRotatef(180,0,1,0);
    glPushMatrix();
    glRotatef(-90,0,0,1);
    prismaSemiCirculo(0.3, 20, 6.26);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN ABAJO
    glPushMatrix();
    glTranslatef(-5.1, 0.5, 3.2);
    glRotatef(180,0,1,0);
    glPushMatrix();
    glRotatef(-90,0,0,1);
    prismaSemiCirculo(0.3, 20, 6.26);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN IZDA
    glPushMatrix();
    glTranslatef(-5.1, 8.05, -3.6);
    glRotatef(-90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 7);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.1, 20, -3.6);
    glRotatef(-90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 11);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN DCHA
    glPushMatrix();
    glTranslatef(-5.1, 8.05, 3.7);
    glRotatef(-90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 7);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5.1, 20, 3.7);
    glRotatef(-90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 11);
    glPopMatrix();
    glPopMatrix();

    //////////////// CHINCHETAS ////////////////
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroClarito);
    // CHINCHETA ABAJO IZQUIERDA
    glPushMatrix();
    glTranslatef(-5.2,0.5,3.7);
    glRotatef(90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA ABAJO DERECHA
    glPushMatrix();
    glTranslatef(-5.2,0.5,-3.6);
    glRotatef(90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();

    // CHINCHETA MEDIO IZQUIERDA
    glPushMatrix();
    glTranslatef(-5.2,8.5,3.7);
    glRotatef(90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA MEDIO DERECHA
    glPushMatrix();
    glTranslatef(-5.2,8.5,-3.6);
    glRotatef(90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();

    // CHINCHETA ARRIBA IZQUIERDA
    glPushMatrix();
    glTranslatef(-5.2,20.5,3.7);
    glRotatef(90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA ARRIBA DERECHA
    glPushMatrix();
    glTranslatef(-5.2,20.5,-3.6);
    glRotatef(90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();

    //////////////////// CARA DERECHA ////////////////////
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
    // DECORACIÓN ARRIBA
    glPushMatrix();
    glTranslatef(5.1, 8.5, 3.2);
    glRotatef(180,0,1,0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    prismaSemiCirculo(0.3, 20, 6.26);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.1, 20.5, 3.2);
    glRotatef(180,0,1,0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    prismaSemiCirculo(0.3, 20, 6.26);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN ABAJO
    glPushMatrix();
    glTranslatef(5.1, 0.5, 3.2);
    glRotatef(180,0,1,0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    prismaSemiCirculo(0.3, 20, 6.26);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN IZDA
    glPushMatrix();
    glTranslatef(5.1, 8.05, 3.7);
    glRotatef(90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 7);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.1, 20, 3.7);
    glRotatef(90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 11);
    glPopMatrix();
    glPopMatrix();

    // DECORACIÓN DCHA
    glPushMatrix();
    glTranslatef(5.1, 8.05, -3.6);
    glRotatef(90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 7);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.1, 20, -3.6);
    glRotatef(90,0,1,0);
    glPushMatrix();
    glRotatef(90,1,0,0);
    prismaSemiCirculo(0.3, 20, 11);
    glPopMatrix();
    glPopMatrix();

    //////////////// CHINCHETAS ////////////////
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, oroClarito);
    // CHINCHETA ABAJO IZQUIERDA
    glPushMatrix();
    glTranslatef(5.2,0.5,3.7);
    glRotatef(-90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA ABAJO DERECHA
    glPushMatrix();
    glTranslatef(5.2,0.5,-3.6);
    glRotatef(-90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();

    // CHINCHETA MEDIO IZQUIERDA
    glPushMatrix();
    glTranslatef(5.2,8.5,3.7);
    glRotatef(-90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA MEDIO DERECHA
    glPushMatrix();
    glTranslatef(5.2,8.5,-3.6);
    glRotatef(-90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();

    // CHINCHETA ARRIBA IZQUIERDA
    glPushMatrix();
    glTranslatef(5.2,20.5,3.7);
    glRotatef(-90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
    // CHINCHETA ARRIBA DERECHA
    glPushMatrix();
    glTranslatef(5.2,20.5,-3.6);
    glRotatef(-90,0,0,1);
    piramideTruncada(0.6,0.6,0.4,0.4,0.15);
    glPopMatrix();
  }

  void cortina()
  {  
    glPushMatrix();
      glRotatef(90,0,1,0);
      curtain.aplicarMaterial();
      if(curtain.getAsignada() == 0)
      {
        curtain.aplicarTextura();
      }
      curtain.drawTextura();
    glPopMatrix();
  }

  void marco()
  {
    // CORTINAS
    glPushMatrix();
    glTranslatef(-5.2,9,-3.8);
    glScalef(5,6,5);
      cortina();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.2,9,-3.8);
    glRotatef(180,0,1,0);
    glScalef(5,6,5);
      cortina();
    glPopMatrix();

    decoracion();
    // CARA FRONTAL
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronTurron);
    // ARRIBA
    glPushMatrix();
    glTranslatef(0, 8.5, 3.7);
    prismaCuadrado(10, 1, 1);
    glPopMatrix();

    // ABAJO
    glPushMatrix();
    glTranslatef(0, 0.5, 3.7);
    prismaCuadrado(10, 1, 1);
    glPopMatrix();

    // IZDA
    glPushMatrix();
    glTranslatef(-4.7, 10.5, 4.15);
    prismaCuadrado(1, 21, 0.1);
    glPopMatrix();

    // DCHA
    glPushMatrix();
    glTranslatef(4.7, 10.5, 4.15);
    prismaCuadrado(1, 21, 0.1);
    glPopMatrix();

    // CARA DERECHA
    // ARRIBA
    glPushMatrix();
    glTranslatef(4.7, 8.5, 0);
    prismaCuadrado(1, 1, 8);
    glPopMatrix();

    // ABAJO
    glPushMatrix();
    glTranslatef(4.7, 0.5, 0);
    prismaCuadrado(1, 1, 8);
    glPopMatrix();

    // IZDA
    glPushMatrix();
    glTranslatef(5.15, 10.5,3.7);
    prismaCuadrado(0.1, 21, 1);
    glPopMatrix();
    // DCHA
    glPushMatrix();
    glTranslatef(5.15, 10.5,-3.55);
    prismaCuadrado(0.1, 21, 1);
    glPopMatrix();

    // CARA IZQUIERDA
    // ABAJO
    glPushMatrix();
    glTranslatef(-4.7, 0.5, 0);
    prismaCuadrado(1, 1, 8);
    glPopMatrix();

    // ARRIBA
    glPushMatrix();
    glTranslatef(-4.7, 8.5, 0);
    prismaCuadrado(1, 1, 8);
    glPopMatrix();

    // IZDA
    glPushMatrix();
    glTranslatef(-5.15, 10.5,3.7);
    prismaCuadrado(0.1, 21, 1);
    glPopMatrix();

    // DCHA
    glPushMatrix();
    glTranslatef(-5.15, 10.5,-3.55);
    prismaCuadrado(0.1, 21, 1);
    glPopMatrix();

    // CARA TRASERA
    glPushMatrix();
    glTranslatef(0, 10.5, -4);
    prismaCuadrado(10.2, 21, 0.1);
    glPopMatrix();

    // TAPA
    glPushMatrix();
    glTranslatef(0,20.5,0.1);
    prismaCuadrado(10.4, 1, 8.2);
    glPopMatrix();

    // TECHO
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
    glTranslatef(0,21,0.08);
    piramideTruncada(10.4, 8.26, 12.4, 10.1, 1);
    glPopMatrix();
  }

  void caja()
  {
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronTurron);
    glPushMatrix();
    glTranslatef(0,4.5,0);
    prismaCuadrado(10, 9, 8);
    glPopMatrix();
  }

  void cristales()
  {
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cristal);
    //PANEL DCHA
    glPushMatrix();
      glRotatef(90,0,1,0);
      glTranslatef(0,15,5);
      prismaCuadrado(8,13,0.1);
    glPopMatrix();

    //PANEL FRONTAL
    glPushMatrix();
      glTranslatef(0,15,4);
      prismaCuadrado(10,13,0.1);
    glPopMatrix();

    //PANEL IZDA
    glPushMatrix();
      glRotatef(90,0,1,0);
      glTranslatef(0,15,-5);
      prismaCuadrado(8,13,0.1);
    glPopMatrix();

  }

  void bola()
  {
    glPushMatrix();
      glTranslatef(-3.3,9.1,2.8);
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
      prismaCirculo(1,0.1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-3.3,9,2.8);
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronOscuro);
      prismaCirculo(1.1,0.1);
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-3.3,10.1,2.8);
      glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, bolaDeCristal);
      esfera(1);
    glPopMatrix();
  }

  void maquina()
  {
    glPushMatrix();
      glTranslatef(0,9,-2.5);
      glScalef(2,2,2);
      adivino.draw();
    glPopMatrix();
    marco();
    caja();
    bola();
    cristales();
  }

  public:
    void draw()
    {
      maquina();
    }
};

// DECLARO AQUÍ LA MONEDA PARA PODER USARLA EN LA CLASE MONEDA
ImportaMalla monedachulisima("moneda.ply");

class Moneda : public Objeto3D
{
  private:
    void moneda()
    {
      GLfloat gris_clarito_ambient[] = {0.8f, 0.8f, 0.8f, 1.0f};  
      GLfloat gris_clarito_diffuse[] = {0.9f, 0.9f, 0.9f, 1.0f};  
      GLfloat gris_clarito_specular[] = {0.5f, 0.5f, 0.5f, 1.0f}; 
      GLfloat gris_clarito_shininess[] = {20.0f};                 

      // Asigna las propiedades al material
      glMaterialfv(GL_FRONT, GL_AMBIENT, gris_clarito_ambient);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, gris_clarito_diffuse);
      glMaterialfv(GL_FRONT, GL_SPECULAR, gris_clarito_specular);
      glMaterialfv(GL_FRONT, GL_SHININESS, gris_clarito_shininess);
      
      glTranslatef(0,0.1,0);
      glScalef(0.2,0.2,0.2);
      glRotatef(90,1,0,0);
      monedachulisima.draw();
    }
  public:
    void draw()
    {
      moneda();
    }
};

// DECLARO AQUÍ EL COFRE PARA PODER USARLO EN LA CLASE COFRE
ImportaMalla cofre_lados("cofre_lados.ply", "planks.jpg");
ImportaMalla cofre_marco("cofre_marco.ply", "iron.jpg");
ImportaMalla cofre_tapa_forro("cofre_tapa_forro.ply", "velvet.jpg");
ImportaMalla cofre_tapa_lados("cofre_tapa_lados.ply", "planks.jpg");
ImportaMalla cofre_tapa_marco("cofre_tapa_marco.ply", "iron.jpg");
ImportaMalla coins("monedas.ply");
ImportaMalla loose_coins("monedas_sueltas.ply");

class Cofre : public Objeto3D
{
  private:
    void tapa()
    {
      glPushMatrix();
        glTranslatef(0,-2.23,1.5);
        glPushMatrix();
          cofre_tapa_forro.aplicarMaterial();
          if(cofre_tapa_forro.getAsignada() == 0)
          {
            cofre_tapa_forro.aplicarTextura();
          }
          cofre_tapa_forro.drawTextura();
        glPopMatrix();
        
        glPushMatrix();
          cofre_tapa_lados.aplicarMaterial();
          if(cofre_tapa_lados.getAsignada() == 0)
          {
            cofre_tapa_lados.aplicarTextura();
          }
          cofre_tapa_lados.drawTextura();
        glPopMatrix();

        glPushMatrix();
          cofre_tapa_marco.aplicarMaterial();
          if(cofre_tapa_marco.getAsignada() == 0)
          {
            cofre_tapa_marco.aplicarTextura();
          }
          cofre_tapa_marco.drawTextura();
        glPopMatrix();
      glPopMatrix();
    }
    void cofre()
    {
      glPushMatrix();
        glTranslatef(0,2.23,-1.5);
        glRotatef(angCofre,1,0,0);
        tapa();
      glPopMatrix();

      glPushMatrix();

        glPushMatrix();
          cofre_lados.aplicarMaterial();
          if(cofre_lados.getAsignada() == 0)
          {
            cofre_lados.aplicarTextura();
          }
          cofre_lados.drawTextura();
        glPopMatrix();

        glPushMatrix();
          cofre_marco.aplicarMaterial();
          if(cofre_marco.getAsignada() == 0)
          {
            cofre_marco.aplicarTextura();
          }
          cofre_marco.drawTextura();
        glPopMatrix();

        glPushMatrix();
          coins.setColorDifuso(0.83f, 0.69f, 0.22f, 1.0f);  // Color dorado difuso
          coins.setColorEspecular(1.0f, 0.86f, 0.0f, 1.0f); // Color dorado brillante
          coins.setColorAmbiente(0.25f, 0.20f, 0.07f, 1.0f); // Color ambiente tenue para dorado
          coins.setBrillo(50.0f);                            // Valor de brillo alto para reflejar el brillo metálico
          coins.aplicarMaterial();
          coins.draw();
        glPopMatrix();

        glPushMatrix();
          loose_coins.setColorDifuso(0.83f, 0.69f, 0.22f, 1.0f);  // Color dorado difuso
          loose_coins.setColorEspecular(1.0f, 0.86f, 0.0f, 1.0f); // Color dorado brillante
          loose_coins.setColorAmbiente(0.25f, 0.20f, 0.07f, 1.0f); // Color ambiente tenue para dorado
          loose_coins.setBrillo(50.0f);                            // Valor de brillo alto para reflejar el brillo metálico
          loose_coins.aplicarMaterial();
          loose_coins.draw();
        glPopMatrix();
      glPopMatrix();
    }
  public:
    void draw()
    {
      cofre();
    }
};

ImportaMalla carousel("carousel.ply", "circo.jpg");
ImportaMalla horse("caballo.ply");

class Carousel : public Objeto3D
{
  private:
    void caballo()
    {
      glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronTurron);
        horse.draw();
      glPopMatrix();
    }

    void caballos()
    {
      glPushMatrix();
        
        // CABALLO #1
        glRotatef(90,0,0,1);
        glPushMatrix();
          glTranslatef(0,0,movCaballo1);
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronTurron);
          caballo();
        glPopMatrix();
        
        glPushMatrix();
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, plateado);
          glRotatef(90,1,0,0);
          glTranslatef(0.1,1,3.15);
          prismaCirculo(0.1,5);
        glPopMatrix();

        // CABALLO #2
        glRotatef(90,0,0,1);
        glPushMatrix();
          glTranslatef(0,0,movCaballo2);
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronTurron);
          caballo();
        glPopMatrix();

        glPushMatrix();
          glRotatef(90,1,0,0);
          glTranslatef(0.1,1,3.15);
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, plateado);
          prismaCirculo(0.1,5);
        glPopMatrix();

        // CABALLO #3
        glRotatef(90,0,0,1);
        glPushMatrix();
          glTranslatef(0,0,movCaballo3);
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronTurron);
          caballo();
        glPopMatrix();

        glPushMatrix();
          glRotatef(90,1,0,0);
          glTranslatef(0.1,1,3.15);
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, plateado);
          prismaCirculo(0.1,5);
        glPopMatrix();

        // CABALLO #4
        glRotatef(90,0,0,1);
        glPushMatrix();
          glTranslatef(0,0,movCaballo4);
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, marronTurron);
          caballo();
        glPopMatrix();

        glPushMatrix();
          glRotatef(90,1,0,0);
          glTranslatef(0.1,1,3.15);
          glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, plateado);
          prismaCirculo(0.1,5);
        glPopMatrix();
  
      glPopMatrix();
    }
    void tiovivo()
    {
      glPushMatrix();
        glRotatef(-90,1,0,0);
        carousel.aplicarMaterial();
        if(carousel.getAsignada() == 0)
        {
          carousel.aplicarTextura();
        }
        carousel.drawTextura();

        glRotatef(rotCaballos,0,0,1);
        caballos();
      glPopMatrix();
    }
  public:
    void draw()
    {
      tiovivo();
    }
};
// DECLARACIÓN DE OBJETOS 3D
Ejes ejesCoordenadas;
TiendaCirco tienda;
MaquinaAdivino maquina;
Ranura ranura;
Moneda moneda;
Cofre cofre;
Carousel tiovivo;



ImportaMalla fortune("fortuna.ply", "zoltar_full.jpg");

// FUNCIONES DE DIBUJO
void dibujoEscena(int seleccion)
{
  // POSICION DE LA FUENTE DE LUZ
  static GLfloat  pos[4] = { 5.0, 5.0, 10.0, 0.0 };	


  glPushMatrix ();		
  glClearColor (0.0, 0.0, 0.0, 1.0);	
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
  transformacionVisualizacion ();	
  glLightfv (GL_LIGHT0, GL_POSITION, pos);	

  // TOGGLE ILUMINACIÓN
  if(ilu == 1){
    glEnable(GL_LIGHTING);
  }
  else{
    glDisable(GL_LIGHTING); 
    glColor3f(1.0,1.0,1.0);
  }

  // NORMALIZACIÓN DE LAS NORMALES
  glEnable(GL_NORMALIZE);

  // HABILITACION DE TRANSARENCIA
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


  glPolygonMode(GL_FRONT_AND_BACK, modo);

  // DIBUJA LOS MODELOS DE LA ESCENA
  glTranslatef(0,-10,0);

  // CAROUSEL
  glPushMatrix();
    glTranslatef(-45,0,60);
    glScalef(3,3,3);
    tiovivo.draw();
  glPopMatrix();
  // COFRE
  // CONFIGURAMOS LA INTERACCIÓN DEL COFRE
  glPushMatrix();
    glTranslatef(-7,0.1,5);
    glRotatef(45,0,1,0);
    cofre.draw();
  glPopMatrix();

  // RANURA
  // CONFIGURAMOS LA INTERACCIÓN DE LA RANURA
  glPushMatrix();
    glTranslatef(2,4.5,2.6);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idRanura,1);
    }
    ranura.draw();
  glPopMatrix();

  // TIENDA
  // CONFIGURAMOS LA INTERACCIÓN DE LA TIENDA
  glPushMatrix();
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idTienda,1);
    }
    tienda.draw();
  glPopMatrix();

  // MAQUIA ADIVINO
  // CONFIGURAMOS LA INTERACCIÓN DE LA MÁQUINA ADIVINO
  glPushMatrix();
    glScalef(0.7,0.7,0.7);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idMaquina,1);
    }
    maquina.draw();
  glPopMatrix();

  // MONEDA ANIMACIÓN
  glPushMatrix();
    glTranslatef(2.1,4.9,movMonedaTemp);
    glRotatef(90,0,0,1);
    glScalef(tamMonedaTemp, tamMonedaTemp, tamMonedaTemp);
    moneda.draw();
  glPopMatrix();

  // FORTUNA ANIMACIÓN
  glPushMatrix();
    glTranslatef(-1.465,4.45,movFortunaTemp);
    glRotatef(180,0,0,1);
    glRotatef(180,0,1,0);
    glScalef(0.5,0.5,0.5);
    fortune.aplicarMaterial();
    if(fortune.getAsignada() == 0)
    {
      fortune.aplicarTextura();
    }
    fortune.drawTextura();
  glPopMatrix();

  // MONEDA #1
  glPushMatrix();
    glTranslatef(5,0,5);
    glScalef(tamMoneda1, tamMoneda1, tamMoneda1);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idMoneda1,1);
    }
    moneda.draw();
  glPopMatrix();

  // MONEDA #2
  glPushMatrix();
    glTranslatef(5.5,0,5);
    glScalef(tamMoneda2, tamMoneda2, tamMoneda2);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idMoneda2,1);
    }
    moneda.draw();
  glPopMatrix();

  // MONEDA #3
  glPushMatrix();
    glTranslatef(6,0,5);
    glScalef(tamMoneda3, tamMoneda3, tamMoneda3);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idMoneda3,1);
    }
    moneda.draw();
  glPopMatrix();

  // MONEDA #4
  glPushMatrix();
    glTranslatef(6.5,0,5);
    glScalef(tamMoneda4, tamMoneda4, tamMoneda4);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idMoneda4,1);
    }
    moneda.draw();
  glPopMatrix();

  // MONEDA #5
  glPushMatrix();
    glTranslatef(7,0,5);
    glScalef(tamMoneda5, tamMoneda5, tamMoneda5);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idMoneda5,1);
    }
    moneda.draw();
  glPopMatrix();

  // MONEDA #6
  glPushMatrix();
    glTranslatef(7.5,0,5);
    glScalef(tamMoneda6, tamMoneda6, tamMoneda6);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idMoneda6,1);
    }
    moneda.draw();
  glPopMatrix();

  // COFRE HITBOX
  glPushMatrix();
    glTranslatef(-7.5,2.1,4.5);
    glRotatef(45,0,1,0);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, hitbox);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idCofre,1);
    }
    prismaCuadrado(4.6,4,7.5);
  glPopMatrix();

  // FORTUNA HITBOX
  glPushMatrix();
    glTranslatef(-1.465,4.45,movFortunaTemp);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, hitbox);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idFortuna,1);
    }
    prismaCuadrado(1.5,0.2,3);
  glPopMatrix();

  // TIOVIVIO HITBOX
  glPushMatrix();
    glTranslatef(-45,15,60);
    glScalef(3,3,3);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, hitbox);
    if( seleccion == 1 )
    {
      glDisable(GL_LIGHTING);
      ColorSeleccion(idTiovivo,1);
    }
    prismaCuadrado(10,10,10);
  glPopMatrix();

  glPopMatrix ();		// Desapila la transformacion geometrica
}

void Dibuja (void)
{
  dibujoEscena (0);		// Dibuja
  glutSwapBuffers ();		// Intercambia el buffer de dibujo y visualizacion
}

// FUNCION DE ANIMACION
void idle (int v)
{
  if(animacionMoneda == 1)
  {
    movMonedaTemp -= 0.1;
    if(movMonedaTemp <= 2)
    {
      animacionDespertar = 1;
      animacionMoneda = 0;
      tamMonedaTemp = 0;
      movMonedaTemp = 3.5;
    }
  }

  if(animacionDespertar == 1)
  {
    angParpado -= 2;
    angCabeza -= 0.5;
    if(angParpado <= -90)
    {
      animacionDespertar = 0;
      animacionAdivino = 1;
    }
  }

  if(animacionDormir == 1)
  {
    if(angParpado <= 0)
    {
      angParpado += 2;
    }
    
    if(angCabeza <= 0)
    {
      angCabeza += 0.5;
    }

    if(altBoca <= 0)
    {
      altBoca += 0.01;
    }

    if(angBrazo >= 0)
    {
      angBrazo -= 0.5;
    }

    if(angCabeza >= 0 && angParpado >= 0 && altBoca >= 0 && angBrazo <= 0)
    {
      animacionDormir = 0;
      animacionFortuna = 1;
    }
  }

  if(animacionAdivino == 1)
  {
    // DURACIÓN DE LA ANIMACIÓN
    duracion +=1;
    if(duracion > 500)
    {
      animacionAdivino = 0;
      animacionDormir = 1;
    }
    // OSCILACIÓN BRAZO
    if(-8 >= angBrazo || angBrazo >= 12)
    {
      dirBrazo *= -1;
    }
    
    angBrazo += 0.5*dirBrazo;

    // OSCILACIÓN BOCA
    if(-0.25 >= altBoca || altBoca >= 0)
    {
      dirBoca *= -1;
    }

    altBoca += 0.01*dirBoca;

    // OSCILACIÓN OJOS
    if(-30 >= angOjo || angOjo >= 30)
    {
      dirOjo *= -1;
    }

    angOjo += 2*dirOjo;

    // OSCILACIÓN CABEZA
    if(-40 >= angCabeza || angCabeza >= 0)
    {
      dirCabeza *= -1;
    }

    angCabeza += 0.5*dirCabeza;

  }

  if(animacionFortuna == 1)
  {
    movFortunaTemp += 0.1;
    if(movFortunaTemp >= 3)
    {
      fortunaPendiente = 1;
      animacionFortuna = 0;
    }
  }

  if(animacionCofre == 1)
  {
    angCofre += 10 * dirCofre;
    if(angCofre >= 120 || angCofre <= -90)
    {
      dirCofre *= -1;
      animacionCofre = 0;
    }
  }

  // TIOVIVO
  rotCaballos += 2;
  movCaballo1 += dirCaballo1 * 0.01;
  movCaballo2 += dirCaballo2 * 0.03;
  movCaballo3 += dirCaballo3 * 0.06;
  movCaballo4 += dirCaballo4 * 0.02;

  if(movCaballo1 >= 0.7 || movCaballo1 <= -0.5)
  {
    dirCaballo1 *= -1;
  }

  if(movCaballo2 >= 0.7 || movCaballo2 <= -0.5)
  {
    dirCaballo2 *= -1;
  }

  if(movCaballo3 >= 0.7 || movCaballo3 <= -0.5)
  {
    dirCaballo3 *= -1;
  }

  if(movCaballo4 >= 0.7 || movCaballo4 <= -0.5)
  {
    dirCaballo4 *= -1;
  }

  glutPostRedisplay ();		// Redibuja
  glutTimerFunc (30, idle, 0);	// Vuelve a activarse dentro de 30 ms
}
