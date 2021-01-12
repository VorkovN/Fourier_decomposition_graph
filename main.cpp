#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

static auto func(double x, size_t nn)
{
	double res = 0;
	for(size_t n = 1; n <= nn; n++)
		res += (3.0*(cos(M_PI*double(n))-1.0)/(M_PI*M_PI*double(n)*double(n))*cos(M_PI*double(n)*x/1.5)-3.0*cos(M_PI * double(n))/(M_PI*double(n))*sin(M_PI*double(n)*x/1.5));
	return 15.0/4.0 + res;
}

void display()
{
	const size_t n = 30;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex2f(-20, 0);
		glVertex2f(720, 0);
		glColor3f(0, 1, 0);
		glVertex2f(0, -100);
		glVertex2f(0, 100);
	}
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, .2, 0);
	for (float x = -20.0; x < 20.0; x += 0.001) {
		glVertex2f(x, func(x, n));
	}
	glEnd();
	glFlush();
}

void init()
{
	glClearColor(0.25, 0.0, 0.2, 1.0);
	glColor3f(0.6, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3, 3, -1, 7, 0.0, 10.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 450);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("Furie");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
