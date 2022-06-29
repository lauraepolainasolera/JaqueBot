#include "freeglut.h"
#include "ETSIDI.h"
#include "../Coordinador.h"
#include "../Tablero.h"



using ETSIDI::SpriteSequence;
//
//class Peon {
//public:
//	SpriteSequence peon;
//
//	informarme de si se pueden poner ifs en constructores, si no, clases peon negro y peon blanco
//
//	Peon(): peon("bin/peonblanco.png", 1, 1, 20) { peon.setCenter(5, 5); peon.setSize(10, 10); }
//
//	void dibuja(SpriteSequence peon) {
//		glPushMatrix();
//		glTranslatef(0, 0, 0);
//		peon.flip(false, false);
//		peon.draw();
//		glTranslatef(0, 0, 0);
//		glPopMatrix();
//	}
//};

//void Peon::peon()

Coordinador master;

void OnKeyboardDown(unsigned char key, int x, int y);
//void onSpecialKeyboardDown(int key, int x, int y);
void OnDraw(void);
void OnTimer(int value);
//void inicio();

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}



void OnDraw(void)
{
	gluLookAt(0, 0, 15,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 10.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
//dibujo del suelo
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0, -5.0f);
	glVertex3f(-5.0f, 0, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0, 5.0f);
	glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);

	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	

	master.dibuja();
	glutPostRedisplay();
	//p.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	
	//poner aqui el código de teclado

	master.tecla(key);

	master.tablero.SeleccionarCasilla(key);

	glutPostRedisplay();

}

void OnTimer(int value)
{
//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

