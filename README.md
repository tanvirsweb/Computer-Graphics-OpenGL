# Computer-Graphics-OpenGL

Computer-Graphics-OpenGL [Tanvir Anjom Siddique](https://tanvirsweb.github.io/)

## Put this files in those folders [get files here](/glut-3.7.6-bin/)

1. `C:\TDM-GCC-32\include\GL\glut.h`
2. `C:\TDM-GCC-32\lib\glut32.lib`
3. `C:\Windows\System32\glut32.dll`
4. `C:\Windows\SysWOW64\glut32.dll`

<br>
now open CodeBlocks > File > new > Project > GLUT > next > input ProjectName > select glut route(base): C:\TDM-GCC-32\ > build project.

## Traiangle_Pentagon_Trapezoid

```cpp
#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
     * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
     */
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS); // Begin quadrilateral coordinates

    // Trapezoid
    glVertex3f(0.05f, 0.05f, 0.0f);
    glVertex3f(0.35f, 0.05f, 0.0f);
    glVertex3f(0.40f, 0.35f, 0.0f);
    glVertex3f(0.00f, 0.35f, 0.0f);

    glEnd(); // End quadrilateral coordinates

    glBegin(GL_TRIANGLES); // Begin triangle coordinates

    // Pentagon
    glVertex3f(0.5f, 0.05f, 0.0f);
    glVertex3f(0.75f, 0.05f, 0.0f);
    glVertex3f(0.5f, 0.35f, 0.0f);

    glVertex3f(0.5f, 0.35f, 0.0f);
    glVertex3f(0.75f, 0.05f, 0.0f);
    glVertex3f(0.75f, 0.35f, 0.0f);

    glVertex3f(0.5f, 0.35f, 0.0f);
    glVertex3f(0.75f, 0.35f, 0.0f);
    glVertex3f(0.63f, 0.50f, 0.0f);

    // Triangle
    glVertex3f(0.30f, 0.65f, 0.0f);
    glVertex3f(0.60f, 0.65f, 0.0f);
    glVertex3f(0.45, 0.85f, 0.0f);

    glEnd(); // End triangle coordinates
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
    glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
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
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}

```

## Rotation Shapes

```cpp
#include <windows.h>
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

// Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape key
		exit(0);
	}
}

// Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);		  // Enable color
	glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Change the background to sky blue
}

// Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 30.0f;
float _cameraAngle = 0.0f;

// Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);

	glPushMatrix();
	glTranslatef(0.0f, -1.0f, 0.0f);
	glRotatef(_angle, 0.0f, 0.0f, -1.0f);

	glBegin(GL_QUADS);

	// Trapezoid
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, 0.5f, 0.0f);
	glVertex3f(-0.7f, 0.5f, 0.0f);

	glEnd();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glScalef(0.7f, 0.7f, 0.7f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);

	// Pentagon
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);

	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLES);

	// Triangle
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glEnd();

	glPopMatrix();

	glutSwapBuffers();
}

void update(int value)
{
	_angle += 2.0f;
	if (_angle > 360)
	{
		_angle -= 360;
	}

	glutPostRedisplay(); ////Tell GLUT that the scene has changed
	glutTimerFunc(25, update, 0);
}

int main(int argc, char **argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	// Create the window
	glutCreateWindow("Color");
	initRendering();

	// Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); // Add a timer

	glutMainLoop();
	return 0;
}

```

## House Drawing using Lines

```cpp
#include <windows.h>
#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display window colour to white

	glMatrixMode(GL_PROJECTION); // Set projection parameters
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window

	// Set colour to black
	glColor3f(0.0, 0.0, 0.0);
	// Adjust the point size
	glPointSize(5.0);

	// Set colour to red
	glColor3f(1.0, 0.0, 0.0);

	// Draw an outlined triangle
	glBegin(GL_LINES);

	glVertex2i(0, 200);
	glVertex2i(400, 200);

	glVertex2i(200, 400);
	glVertex2i(200, 0);

	glEnd();

	glFlush(); // Process all OpenGL routines
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);						 // Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode

	glutInitWindowPosition(50, 100);			   // Set window position
	glutInitWindowSize(400, 300);				   // Set window size
	glutCreateWindow("An Example OpenGL Program"); // Create display window

	init();						 // Execute initialisation procedure
	glutDisplayFunc(drawShapes); // Send graphics to display window
	glutMainLoop();				 // Display everything and wait

	return 0;
}

```

## Line Drawing: DDA

```cpp
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1, y1, x2, y2, m, i, j;
float dx, dy;
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
    // write your code here

    if (m > 0 && m <= 1)
    {
        while (x1 <= x2 && y1 <= y2)
        {
            x1 = x1 + 1;
            y1 = y1 + m;
            glVertex3f(x1 / 100, y1 / 100, 0.0);
            printf("%f %f", x1, y1);
        }
    }
    else if (m > 1)
    {
        while (x1 <= x2 && y1 <= y2)
        {
            x1 = x1 + (1 / m);
            y1 = y1 + 1;
            glVertex3f(x1 / 100, y1 / 100, 0.0);
            printf("%f %f", x1, y1);
        }
    }

    else if (m > -1 && m <= 0)
    {
        while (x1 >= x2 && y1 >= y2)
        {
            x1 = x1 - 1;
            y1 = y1 - m;
            glVertex3f(x1 / 100, y1 / 100, 0.0);
            printf("%f %f", x1, y1);
        }
    }
    else if (m < -1)

    {

        while (x1 >= x2 && y1 >= y2)
        {
            x1 = x1 - (1 / m);
            y1 = y1 - 1;
            glVertex3f(x1 / 100, y1 / 100, 0.0);
            printf("%f %f", x1, y1);
        }
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
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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

    // glVertex3f(x1/100,y1/100,0.0);write your code here
    printf("Enter value of X1 :");
    scanf("%f", &x1);
    printf("Enter value of y1 :");
    scanf("%f", &y1);
    printf("Enter value of X2 :");
    scanf("%f", &x2);
    printf("Enter value of Y2 :");
    scanf("%f", &y2);
    dx = x2 - x1;
    dy = y2 - y1;
    m = dy / dx;

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

```

## Mid Point Circle Drawing

```cpp
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

```

## Line Drawing: Bresenham

```cpp
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1, y1, x2, y2, m, i, j, p;
int dx = 0, dy = 0;
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
    p = (2 * dy) - dx;
    for (i = x1, j = y1; i <= x2, j <= y2;)
    {
        if (p >= 0)
        {
            i = i + 1;
            j = j + 1;
            if ((i > x2) || (j > y2))
            {
                break;
            }
            printf("%0.2f %0.2f\n", i, j);
            glVertex3f((i / 100), (j / 100), 0.0);
            p = p + (2 * dy) - (2 * dx);
        }
        else if (p < 0)
        {
            i = i + 1;
            if ((i > x2) || (j > y2))
            {
                break;
            }
            printf("%0.2f %0.2f\n", i, j);
            glVertex3f((i / 100), (j / 100), 0.0);
            p = p + (2 * dy);
        }
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
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
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

    printf("Enter first point: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter second point: ");
    scanf("%f %f", &x2, &y2);
    dx = x2 - x1;
    dy = y2 - y1;
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

```

## Different Shapes: Mouse & Keyboard

```cpp
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;
static float tx = 10.0;
static float ty = 0.0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	// glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glTranslatef(tx, ty, 0);

	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();

	glFlush();
}

void spinDisplay_left(void)
{
	spin = 5;
	glutPostRedisplay();
	glRotatef(spin, 0.0, 0.0, 1.0);
}

void spinDisplay_right(void)
{
	spin = -5;
	glutPostRedisplay();
	glRotatef(spin, 0.0, 0.0, 1.0);
}

void init(void)
{
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{

	case 'l':
		spinDisplay_left();
		break;

	case 'r':
		spinDisplay_right();
		break;

	case 's':
		glutIdleFunc(NULL);
		break;

	default:
		break;
	}
}

void spe_key(int key, int x, int y)
{

	switch (key)
	{

	case GLUT_KEY_LEFT:
		tx -= 5;
		glutPostRedisplay();
		break;

		// spinDisplay_left();
		// break;

	case GLUT_KEY_RIGHT:
		tx += 5;
		glutPostRedisplay();
		break;

		// spinDisplay_right();
		// break;

	default:
		break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_left);
		break;
	case GLUT_MIDDLE_BUTTON:
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);
		// glutIdleFunc(NULL); // make idle function inactive
		break;
	default:
		break;
	}
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("mist");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);

	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0; /* ANSI C requires main to return int. */
}

```

## Advanced Mouse Keyboard

```cpp
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;
static float tx = 10.0;
static float ty = 0.0;
static float r = 1;
static float g = 1;
static float b = 1;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	// glRotatef(spin, 0.0, 0.0, 1.0);

	glColor3f(r, g, b);

	glTranslatef(tx, ty, 0);
	// glColor3f(0.0, 0.1, 0.0);
	//			glRotatef(_angle, x, y, z);
	glutSolidTorus(1.0, 20.2, 10, 100); // inner radius, outer radius, sides, segments

	glRectf(-13.5, -13.5, 13.5, 13.5);
	glPopMatrix();

	glFlush();
}

void spinDisplay_left(void)
{
	spin = 5;
	glutPostRedisplay();
	glRotatef(spin, 0.0, 0.0, 1.0);
}

void spinDisplay_right(void)
{
	spin = -5;
	glutPostRedisplay();
	glRotatef(spin, 0.0, 0.0, 1.0);
}

void init(void)
{
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{

	case 'l':
		spinDisplay_left();
		break;

	case 'r':
		spinDisplay_right();
		break;

	case 's':
		glutIdleFunc(NULL);
		break;

	default:
		break;
	}
}

void spe_key(int key, int x, int y)
{

	switch (key)
	{

	case GLUT_KEY_LEFT:
		tx -= 5;
		r = 1;
		g = 0;
		b = 1;
		glutPostRedisplay();
		break;

		// spinDisplay_left();
		// break;

	case GLUT_KEY_RIGHT:
		tx += 5;
		r = 0;
		g = 1;
		b = 0;
		// glColor3f (0.0, 0.0, 1.0);
		glutPostRedisplay();
		break;

		// spinDisplay_right();
		// break;

	case GLUT_KEY_UP:
		ty += 5;
		r = 0;
		g = 0;
		b = 1;
		// glColor3f (0.0, 0.0, 1.0);
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
		ty -= 5;
		r = 1;
		g = 1;
		b = 0;
		// glColor3f (0.0, 0.0, 1.0);
		glutPostRedisplay();
		break;

	default:
		break;
	}
}

void my_mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_left);
		break;
	case GLUT_MIDDLE_BUTTON:
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);
		// glutIdleFunc(NULL); // make idle function inactive
		break;
	default:
		break;
	}
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("mist");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);
	//	glutReshapeFunc(my_reshape);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0; /* ANSI C requires main to return int. */
}

```

## Lighting in OpenGL

```cpp
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

// Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape key
		exit(0);
	}
}

// Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); // Enable lighting
	// you can have upto 8 lighting
	glEnable(GL_LIGHT0);	// Enable light #0
	glEnable(GL_LIGHT1);	// Enable light #1
	glEnable(GL_NORMALIZE); // Automatically normalize normals
							// glShadeModel(GL_SMOOTH); //Enable smooth shading
}

// Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = -70.0f;

// Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -8.0f);

	// Add ambient light
	// sh that shines everywhere in our scene by the same amount
	// every face gets the same amount
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	// Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; // Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};	  // Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	// Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; // Color (0.5, 0.2, 0.2)
	// Coming from the direction (-1, 0.5, 0.5)
	//  0 because direced light source
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glRotatef(_angle, 1.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	// Front
	// normal is a vector perpendicular the face we are drawing
	// we need this because if the light source is directly opp to the face then it will be light a lot
	// or if behind it won't be lit at all
	// they have to point outwards, so the back of the face don't get light
	glNormal3f(0.0f, 0.0f, 1.0f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);

	// Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);

	// Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);

	// Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);

	glEnd();

	glutSwapBuffers();
}

void update(int value)
{
	_angle += 1.5f;
	if (_angle > 360)
	{
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char **argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	// Create the window
	glutCreateWindow("Lighting ");
	initRendering();

	// Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); // Add a timer

	glutMainLoop();
	return 0;
}

```

## Draw 3D shapes

```cpp
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

// Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape key
		exit(0);
	}
}

// Initializes 3D rendering
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); // Enable lighting
	// you can have upto 8 lighting
	glEnable(GL_LIGHT0);	// Enable light #0
	glEnable(GL_LIGHT1);	// Enable light #1
	glEnable(GL_NORMALIZE); // Automatically normalize normals
							// glShadeModel(GL_SMOOTH); //Enable smooth shading
}

// Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = -70.0f;

// Draws the 3D scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -8.0f);

	// Add ambient light
	// sh that shines everywhere in our scene by the same amount
	// every face gets the same amount
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	// Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; // Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f};	  // Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	// Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; // Color (0.5, 0.2, 0.2)
	// Coming from the direction (-1, 0.5, 0.5)
	//  0 because direced light source
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glRotatef(_angle, 1.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);

	// Front
	// normal is a vector perpendicular the face we are drawing
	// we need this because if the light source is directly opp to the face then it will be light a lot
	// or if behind it won't be lit at all
	// they have to point outwards, so the back of the face don't get light
	glNormal3f(0.0f, 0.0f, 1.0f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);

	// Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	// glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);

	// Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	// glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);

	// Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	// glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	// glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);

	glEnd();

	glutSwapBuffers();
}

void update(int value)
{
	_angle += 1.5f;
	if (_angle > 360)
	{
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char **argv)
{
	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	// Create the window
	glutCreateWindow("Lighting ");
	initRendering();

	// Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); // Add a timer

	glutMainLoop();
	return 0;
}

```

## Rotating Fan

```cpp
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glColor3f(1.0, 1.0, 1.0);

	glRectf(-25.0, -4.0, 25.0, 4.0);
	glRectf(-4.0, -25.0, 4.0, 25.0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTorus(1.00, 6.4, 10, 100);
	glPopMatrix();

	glFlush();
}

void spinDisplay_right1(void)
{
	spin = -.60;
	glutPostRedisplay();
	glRotatef(spin, 0.0, 0.0, 1.0);
}

void init(void)
{
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

int a = 0;
void my_keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{

	case 's':
	{
		if (a == 0)
		{
			glutIdleFunc(spinDisplay_right1);
			a = 1;
		}

		else
		{
			glutIdleFunc(NULL);
			a = 0;
		}
	}
	case 'k':
	{

		glRotatef(-10, 0.0, 0.0, 1.0);
		break;
	}
	case 'i':
		glRotatef(3, 0.0, 0.0, 1.0);
		break;

	default:
		break;
	}
}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("mist");
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);

	glutMainLoop();
	return 0; /* ANSI C requires main to return int. */
}

```
