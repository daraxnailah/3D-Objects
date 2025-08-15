#include <windows.h>
#include <GL/glut.h>
#include <cmath>

char title[] = "UAS Grafika Komputer - Cube & Pyramid";
GLfloat angleCube = 0.0f;
GLfloat anglePyramid = 0.0f;

int refreshMills = 15;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Draw Cube (Left side)
    glLoadIdentity();
    glTranslatef(-3.0f, 0.0f, -10.0f);  // Position cube to the left
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    // Face Atas
    glColor3f(0.0f, 1.0f, 0.0f); // Hijau Terang
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Face Bawah
    glColor3f(1.0f, 0.5f, 0.0f); // Orange
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Face Muka
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Face Belakang
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Face Kiri
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Face Kanan
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();

    // Draw Pyramid (Right side)
    glLoadIdentity();
    glTranslatef(3.0f, 0.0f, -10.0f);  // Position pyramid to the right
    glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);

    // Face Depan
    glColor3f(1.0f, 0.0f, 0.0f);     // Merah
    glVertex3f(0.0f, 1.0f, 0.0f);    // Puncak
    glVertex3f(-1.0f, -1.0f, 1.0f);  // Kiri bawah
    glVertex3f(1.0f, -1.0f, 1.0f);   // Kanan bawah

    // Face Kanan
    glColor3f(0.0f, 1.0f, 0.0f);     // Hijau
    glVertex3f(0.0f, 1.0f, 0.0f);    // Puncak
    glVertex3f(1.0f, -1.0f, 1.0f);   // Kiri bawah
    glVertex3f(1.0f, -1.0f, -1.0f);  // Kanan bawah

    // Face Belakang
    glColor3f(0.0f, 0.0f, 1.0f);     // Biru
    glVertex3f(0.0f, 1.0f, 0.0f);    // Puncak
    glVertex3f(1.0f, -1.0f, -1.0f);  // Kiri bawah
    glVertex3f(-1.0f, -1.0f, -1.0f); // Kanan bawah

    // Face Kiri
    glColor3f(1.0f, 1.0f, 0.0f);     // Kuning
    glVertex3f(0.0f, 1.0f, 0.0f);    // Puncak
    glVertex3f(-1.0f, -1.0f, -1.0f); // Kiri bawah
    glVertex3f(-1.0f, -1.0f, 1.0f);  // Kanan bawah

    glEnd();

    // Base (Alas) - Persegi
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();

    glutSwapBuffers();

    angleCube += 0.4f;
    anglePyramid += 0.5f;
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, aspect, 0.5, 20.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(150, 100);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
