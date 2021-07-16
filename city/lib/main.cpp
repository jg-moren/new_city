#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <math.h>
#define PI 3.1415

#include"obj_luz.h"
#include"mapa.h"
#include"carro.h"
#include"jogo.h"

using namespace std;

bool keyStates [256] ; 

void display(){
	
jogo jogo;
jogo.keyOperationsJogo(keyStates);
jogo.displayJogo();
	glutSwapBuffers();
}

void Timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(60, Timer, 1);
	
}

void keyPressed (unsigned char key, int x, int y) {
keyStates[key] = true;
}

void keyUp (unsigned char key, int x, int y) {
keyStates[key] = false; 
}

void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
gluPerspective(100.0, (GLfloat) w/(GLfloat) h, 0.01, 100.0);

}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("jogo ");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
	glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events
	glutTimerFunc(0, Timer, 0);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
