#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>

double pre_x = -0.5, pre_y = -0.5;

void MyDisplay() { // 화면 출력 코드
	glClearColor(0.5, 0.5, 0.5, 0.5);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex3f(pre_x, pre_y, 0.0);
	glVertex3f(-pre_x, pre_y, 0.0);
	glVertex3f(-pre_x, -pre_y, 0.0);
	glVertex3f(pre_x, -pre_y, 0.0);
	glEnd();
	glFlush();
}

void MyReshape(int NewWidth, int NewHeight) { // 윈도우를 크게 해도 네모의 사이즈 유지
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)500;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
		-1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

void MyMouse(int x, int y) {
	pre_x = ((double)x - 500.0) / 500.0;
	pre_y = ((double)y - 500.0) / 500.0;
	glutPostRedisplay();
}

void main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL 1st Report");

	glutDisplayFunc(MyDisplay);

	glutReshapeFunc(MyReshape);

	glutPassiveMotionFunc(MyMouse);

	glutMainLoop();
}