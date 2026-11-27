# IG · Informática Gráfica

Práctica final de **Informática Gráfica** (Grado en Ingeniería Informática, Universidad de Granada), escrita en **C con OpenGL y GLUT**.

La escena es una **carpa de feria** con fardos de paja alrededor. Dentro hay una **máquina del adivino tipo Zoltar**: una vitrina con cortinas, un adivino articulado con turbante, cartas del tarot, una bola de cristal, monedas y un cofre. Usa modelos PLY, texturas JPG, iluminación, cámara orbital y una animación del adivino.

## La escena

| Exterior: la carpa | Interior: el adivino animado |
|---|---|
| ![Vuelta alrededor de la carpa](docs/capturas/carpa-exterior.gif) | ![Animación del adivino](docs/capturas/adivino-animacion.gif) |

![Máquina del adivino](docs/capturas/adivino.jpg)

Imágenes renderizadas con el propio programa, compilado en Linux.

## Contenido

Todo está en `P-FINAL/`:

- **Código**: `practicasIG.c` (programa principal), `modelo.c` (la escena y la animación), `visual.c` (cámara y proyección), `entradaTeclado.c` y `mouse.c` (controles), `file_ply_stl.cc` y `lector-jpg.cpp` (carga de modelos y texturas).
- **Modelos** `.ply` y **texturas** `.jpg`.
- **Memoria**: `DOCUMENTACIÓN.pdf`.

## Cómo ejecutarlo

Necesita Linux (o WSL en Windows) con un compilador de C/C++ y las librerías de GLUT y JPEG.

1. Instala las dependencias (Ubuntu/Debian):
   ```bash
   sudo apt install build-essential freeglut3-dev libjpeg-dev
   ```
2. Compila y ejecuta:
   ```bash
   cd P-FINAL
   rm -f *.o practicasIG   # quita los ficheros compilados que hay en el repo
   make
   ./practicasIG
   ```

La cámara empieza dentro de la carpa, delante de la máquina. Para ver la carpa desde fuera, aléjate con `-` o AvPág.

### Controles

| Tecla | Acción |
|---|---|
| Flechas | Girar la cámara |
| `+` / `-`, RePág / AvPág | Acercar / alejar |
| `p` / `l` / `f` | Dibujar en puntos / líneas / relleno |
| `i` | Activar o desactivar la iluminación |
| `m` | Iniciar o parar la animación |
| `h` | Ayuda en la terminal |
| `Esc` | Salir |

## Autoría

**Fernando Lanzarot Facio**.
