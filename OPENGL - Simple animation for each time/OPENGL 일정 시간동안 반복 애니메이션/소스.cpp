#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>

GLdouble Delta = 0.0;

void MyDisplay() { // 화면 출력 코드
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);

	glVertex3f(-0.5, 1.0 - Delta, 0.0);
	glVertex3f(0.5, 1.0 - Delta, 0.0);
	glVertex3f(0.5, 0.0 - Delta, 0.0);
	glVertex3f(-0.5, 0.0 - Delta, 0.0);

	glEnd();
	glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight) { // 윈도우를 크게 해도 네모의 사이즈 유지
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)800;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)800;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

void MyIdle() {
	Delta += 0.001;
	glutPostRedisplay();
}

void MyTimer(int Value) {
	Delta -= Delta;
	glutPostRedisplay();
	glutTimerFunc(2000, MyTimer, 1);
}

void main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL 1st Report");
	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);

	glutDisplayFunc(MyDisplay);

	glutReshapeFunc(MyReshape);

	glutIdleFunc(MyIdle);

	glutTimerFunc(2000, MyTimer, 1);

	glutMainLoop();
}