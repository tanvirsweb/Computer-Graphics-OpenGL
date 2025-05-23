#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x = 0, y, x2, y2, m, i, j, p;
int dx = 0, dy = 0, r;
void display(void)
{
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    p = 1 - r;
    while ((x <= y))
    {
        if (p < 0)
        {
            x = x + 1;
            y = y;
            printf("%0.2f %0.2f\n", x, y);
            p = p + (2 * x) + 1;
        }

        else
        {
            x = x + 1;
            y = y - 1;
            printf("%0.2f %0.2f\n", x, y);
            p = p + (2 * x) + 1 - (2 * y);
        }
        glVertex3f(((x / 100)), ((y / 100)), 0.0);
        glVertex3f(((y / 100)), ((x / 100)), 0.0);
        glVertex3f((-(x / 100)), (-(y / 100)), 0.0);
        glVertex3f((-(x / 100)), ((y / 100)), 0.0);
        glVertex3f(((x / 100)), (-(y / 100)), 0.0);
        glVertex3f(((y / 100)), (-(x / 100)), 0.0);
        glVertex3f((-(y / 100)), (-(x / 100)), 0.0);
        glVertex3f((-(y / 100)), ((x / 100)), 0.0);
    }
    glEnd();

    /* don't wait!
     * start processing buffered OpenGL routines
     */
    glFlush();
}
void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    /**
    gluOrtho2D(-300, 300, 0, 600);

    */
}
/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA). Open window with "hello"
 * in its title bar. Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char **argv)
{

    printf("Enter radius: ");
    scanf("%d", &r);
    y = r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
