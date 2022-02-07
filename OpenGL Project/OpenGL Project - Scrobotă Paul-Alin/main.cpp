#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
//declarare variabile pentru rotire picioare, rotire corp.
GLfloat rps = 0.0;
GLfloat rpd = 0.0;
GLfloat rotire =0.0;
int refreshMills = 15;
//functia de rotire a caracterului
void rotirecaracter(void)
{
rotire = rotire + 0.1;
if (rotire > 360.0)
rotire = rotire - 360.0;
glutPostRedisplay();
}
//functia de atribuire a unor comenzi butoanelor mousse-ului
void mouse(int button, int state, int x, int y)
{
switch (button)
{
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN) //in cazul in care este apasat butonul stang al mouse-ului se activeaza functia de rotatie
glutIdleFunc(rotirecaracter);
break;
case GLUT_RIGHT_BUTTON:
if (state == GLUT_DOWN) //in cazul in care este apasat butonul stang al mouse-ului se dezactiveaza functia de rotatie
glutIdleFunc(NULL);
break;
default:
break;
}
}
// functia de atribuire a unor comenzi butoanelor tastaturii ( A , S , D )
void tastatura (unsigned  char Key, int x, int y)
{
    switch (Key)
    {

        case 'a' : // in cazul in care se apasa tasta A, caracterul va efectua un pas
        {
            rps = 45;
            rpd = - 90;
        }
        break;

          case 's' : // in cazul in care se apasa tasta S, caracterul va reveni la pozitia initiala
        {
            rps = 0;
            rpd = 0;
        }
        break;

        case 'd' : // in cazul in care se apasa tasta D, caracterul va efectua un pas diferit de cel de pe tasta A
        {
            rps = - 45;
            rpd =  90;
        }
        break;
    }
}

void timer(int value) {
 glutPostRedisplay();
 glutTimerFunc(refreshMills, timer, 0);
}

//atribuirea unui nume window-lui animatiei
char title[] = "Caracter Steve - Paul-Alin Scrobota";

//stabilirea fundalului si a mediului proiectului
void initGL() {
        /// Culoare cer
        glClearColor(0.094, 0.478f, 0.858f, 1.0f);
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glShadeModel(GL_SMOOTH);
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
//crearea terenului pe care sta caracterul ( iarba ) si a caracterului principal ( fiecare parte din el este generata separat )
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
/// Iarba
    glLoadIdentity();
    glTranslatef(0.0f,-10.0f,0.0f);
    glColor3f(0.0549,0.5607,0.1921);
    glBegin(GL_QUADS);
        glVertex3f(100,0,100);
        glVertex3f(100,0,-100);
        glVertex3f(-100,0,-100);
        glVertex3f(-100,0,100);
    glEnd();
///Trup Steve Inceput-----------------------------------------------------------------------
    glLoadIdentity();
    glTranslatef(-2.5f,-2.5f,-35.0f);
    glRotatef(rotire,0,1,0);
    glBegin(GL_QUADS); //pentru a genera caracterul de vom folosi de comanda quads care genereaza suprafete poligonale
///Abdomen
     glColor3f(0.086,0.78,0.72); //stabilirea culorii tricoului caracterului, culoare stabilita cu ajutorul unui Color Picker Online
     glVertex3f(-2.5,0,0); //stabilirea punctelor care stau la baza crearii suprafetei abdomenului
    glVertex3f(2.5,0,0);
    glVertex3f(2.5,7,0);
    glVertex3f(-2.5,7,0);
///Spate
    glColor3f(0.086,0.78,0.72); //stabilirea culorii tricoului caracterului, culoare stabilita cu ajutorul unui Color Picker Online
     glVertex3f(-2.5,0,-3);//stabilirea punctelor care stau la baza crearii suprafetei spatelui
    glVertex3f(2.5,0,-3);
    glVertex3f(2.5,7,-3);
    glVertex3f(-2.5,7,-3);
///LateralDreapta
    glColor3f(0.0627,0.619,0.564);//stabilirea culorii tricoului caracterului, culoare stabilita cu ajutorul unui Color Picker Online
     glVertex3f(2.5,0,0); //stabilirea punctelor care stau la baza crearii suprafetei laterale
    glVertex3f(2.5,0,-3);
    glVertex3f(2.5,7,-3);
    glVertex3f(2.5,7,0);
///LateralStanga
    glColor3f(0.0627,0.619,0.564);//stabilirea culorii tricoului caracterului, culoare stabilita cu ajutorul unui Color Picker Online
    glVertex3f(-2.5,0,0);//stabilirea punctelor care stau la baza crearii suprafetei laterale
    glVertex3f(-2.5,0,-3);
    glVertex3f(-2.5,7,-3);
    glVertex3f(-2.5,7,0);
///Sub
     glVertex3f(0,0,0);//stabilirea culorii tricoului caracterului, culoare stabilita cu ajutorul unui Color Picker Online
    glVertex3f(2.5,0,0);//stabilirea punctelor care stau la baza crearii suprafetei de sub caracter
    glVertex3f(2.5,0,-3);
    glVertex3f(-2.5,0,-3);
///Sus
    glVertex3f(-2.5,7,0);//stabilirea culorii tricoului caracterului, culoare stabilita cu ajutorul unui Color Picker Online
    glVertex3f(2.5,7,0); //stabilirea punctelor care stau la baza crearii suprafetei de deasupra caracterului
    glVertex3f(2.5,7,-3);
    glVertex3f(-2.5,7,-3);
///Trup Steve Gata-----------------------------------------------------------------------

///Cap Caracter Inceput---------------------------------------------------------------
///Fata Cap
    glColor3f(0.878,0.674,0.411);
     glVertex3f(-1.5,7,0);
    glVertex3f(1.5,7,0);
    glVertex3f(1.5,10,0);
    glVertex3f(-1.5,10,0);
///Spate Cap
    glColor3f(0.27,0.20,0.07);
     glVertex3f(-1.5,7,-3);
    glVertex3f(1.5,7,-3);
    glVertex3f(1.5,10,-3);
    glVertex3f(-1.5,10,-3);
///LateralDreapta Cap
    glColor3f(0.27,0.20,0.07);
     glVertex3f(1.5,10,0);
    glVertex3f(1.5,7,0);
    glVertex3f(1.5,7,-3);
    glVertex3f(1.5,10,-3);
///LateralStanga Cap
    glColor3f(0.27,0.20,0.07);
     glVertex3f(-1.5,10,0);
    glVertex3f(-1.5,7,0);
    glVertex3f(-1.5,7,-3);
    glVertex3f(-1.5,10,-3);
///Sus Cap
   glColor3f(0.27,0.20,0.07);
    glVertex3f(-1.5,10,0);
    glVertex3f(1.5,10,0);
    glVertex3f(1.5,10,-3);
    glVertex3f(-1.5,10,-3);
///Gura
glColor3f(0,0,0);
    glVertex3f(-0.5,8,0.1);
    glVertex3f(0.5,8,0.1);
    glVertex3f(0.5,8.1,0.1);
    glVertex3f(-0.5,8.1,0.1);
///Ochi Stang
    glColor3f(0,0,0);
    glVertex3f(-1,8.5,0.001);
    glVertex3f(-0.5,8.5,0.001);
    glVertex3f(-0.5,9.5,0.001);
    glVertex3f(-1,9.5,0.001);
///Ochi Drept
   glColor3f(0,0,0);
    glVertex3f(0.5,8.5,0.001);
    glVertex3f(1,8.5,0.001);
    glVertex3f(1,9.5,0.001);
    glVertex3f(0.5,9.5,0.001);
///Breton
   glColor3f(0.27,0.20,0.07);
    glVertex3f(-1.5,10,0.001);
    glVertex3f(1.5,10,0.001);
    glVertex3f(1.5,9.75,0.001);
    glVertex3f(-1.5,9.75,0.001);
    glEnd();
///Cap Caracter Gata-------------------------------------------------------------

///Mana Stanga--------------------------------------------------------------------
glRotatef(0,1,0,0);
glBegin(GL_QUADS);
///Umar Stang
///Fata Umar
    glColor3f(0.086,0.78,0.72);
    glVertex3f(4.5,7,0);
    glVertex3f(2.5,7,0);
    glVertex3f(2.5,5,0);
    glVertex3f(4.5,5,0);
///SpateUmar
    glColor3f(0.086,0.78,0.72);
    glVertex3f(4.5,7,-3);
    glVertex3f(2.5,7,-3);
    glVertex3f(2.5,5,-3);
    glVertex3f(4.5,5,-3);
///LateralUmarSt
    glColor3f(0.0627,0.619,0.564);
   glVertex3f(4.5,7,0);
    glVertex3f(4.5,7,-3);
    glVertex3f(4.5,5,-3);
    glVertex3f(4.5,5,0);
///VarfUmar
      glColor3f(0.086,0.78,0.72);
    glVertex3f(4.5,7,0);
    glVertex3f(2.5,7,0);
    glVertex3f(2.5,7,-3);
    glVertex3f(4.5,7,-3);
///Fata Mana
     glColor3f(0.878,0.674,0.411);
     glVertex3f(4.5,5,0);
    glVertex3f(2.5,5,0);
    glVertex3f(2.5,2,0);
    glVertex3f(4.5,2,0);
///Spate Mana
    glColor3f(0.878,0.674,0.411);
     glVertex3f(4.5,5,-3);
    glVertex3f(2.5,5,-3);
    glVertex3f(2.5,2,-3);
    glVertex3f(4.5,2,-3);
///Lateral Dreapta Mana
    glColor3f(0.77,0.525,0.258);
     glVertex3f(2.5,5,0);
    glVertex3f(2.5,5,-3);
    glVertex3f(2.5,2,-3);
    glVertex3f(2.5,2,0);
///Lateral Stanga Mana
     glColor3f(0.77,0.525,0.258);
     glVertex3f(4.5,5,0);
    glVertex3f(4.5,5,-3);
    glVertex3f(4.5,2,-3);
    glVertex3f(4.5,2,0);
///Sub Mana Stanga
    glColor3f(0.77,0.525,0.258);
     glVertex3f(2.5,2,0);
    glVertex3f(2.5,2,-3);
    glVertex3f(4.5,2,-3);
    glVertex3f(4.5,2,0);
    glEnd();
///Mana Stanga Gata--------------------------------------------------------

///Mana Dreapta---------------------------------------------------------------
glRotatef(0,1,0,0);
glBegin(GL_QUADS);
///Umar Drept
///Fata Umar
    glColor3f(0.086,0.78,0.72);
    glVertex3f(-2.5,7,0);
    glVertex3f(-4.5,7,0);
    glVertex3f(-4.5,5,0);
    glVertex3f(-2.5,5,0);
///SpateUmar
    glColor3f(0.086,0.78,0.72);
    glVertex3f(-2.5,7,-3);
    glVertex3f(-4.5,7,-3);
    glVertex3f(-4.5,5,-3);
    glVertex3f(-2.5,5,-3);
///LateralUmarDr
    glColor3f(0.0627,0.619,0.564);
   glVertex3f(-4.5,7,0);
    glVertex3f(-4.5,7,-3);
    glVertex3f(-4.5,5,-3);
    glVertex3f(-4.5,5,0);
///VarfUmar
      glColor3f(0.086,0.78,0.72);
    glVertex3f(-2.5,7,0);
    glVertex3f(-4.5,7,0);
    glVertex3f(-4.5,7,-3);
    glVertex3f(-2.5,7,-3);
///Fata Mana
     glColor3f(0.878,0.674,0.411);
     glVertex3f(-2.5,5,0);
    glVertex3f(-4.5,5,0);
    glVertex3f(-4.5,2,0);
    glVertex3f(-2.5,2,0);
///Spate Mana
    glColor3f(0.878,0.674,0.411);
     glVertex3f(-2.5,5,-3);
    glVertex3f(-4.5,5,-3);
    glVertex3f(-4.5,2,-3);
    glVertex3f(-2.5,2,-3);
///Lateral Dreapta Mana
    glColor3f(0.77,0.525,0.258);
     glVertex3f(-4.5,5,0);
    glVertex3f(-4.5,5,-3);
    glVertex3f(-4.5,2,-3);
    glVertex3f(-4.5,2,0);
///Lateral Stanga Mana
     glColor3f(0.77,0.525,0.258);
     glVertex3f(-2.5,5,0);
    glVertex3f(-2.5,5,-3);
    glVertex3f(-2.5,2,-3);
    glVertex3f(-2.5,2,0);
///Sub Mana Dreapta
    glColor3f(0.77,0.525,0.258);
     glVertex3f(-4.5,2,0);
    glVertex3f(-4.5,2,-3);
    glVertex3f(-2.5,2,-3);
    glVertex3f(-2.5,2,0);
    glEnd();
///Maini Caracter Gata-------------------------------------------------------------------

///Picior Stang------------------------------------------------------------------
glRotatef(rps,1,0,0);
glBegin(GL_QUADS);
///Fata Picior
     glColor3f(0,0,1);
     glVertex3f(0.5,0,0);
    glVertex3f(0.5,-5,0);
    glVertex3f(2.5,-5,0);
    glVertex3f(2.5,0,0);
///Spate Picior
    glColor3f(0,0,1);
     glVertex3f(0.5,0,-3);
    glVertex3f(0.5,-5,-3);
    glVertex3f(2.5,-5,-3);
    glVertex3f(2.5,0,-3);
///Lateral Dreapta Picior
    glColor3f(0,0,0.78);
     glVertex3f(0.5,0,0);
    glVertex3f(0.5,-5,0);
    glVertex3f(0.5,-5,-3);
    glVertex3f(0.5,0,-3);
///Lateral Stanga Picior
     glColor3f(0,0,0.78);
     glVertex3f(2.5,0,0);
    glVertex3f(2.5,-5,0);
    glVertex3f(2.5,-5,-3);
    glVertex3f(2.5,0,-3);
///Sub Picior Stang
   glColor3f(0.3,0.3,0.3);
     glVertex3f(0.5,-5,0);
    glVertex3f(2.5,-5,0);
    glVertex3f(2.5,-5,-3);
    glVertex3f(0.5,-5,-3);
///Sus Picior Stang
      glColor3f(0,0,1);
     glVertex3f(0.5,0,0);
    glVertex3f(2.5,0,0);
    glVertex3f(2.5,0,-3);
    glVertex3f(0.5,0,-3);
glEnd();
///Picior Stang Gata------------------------------------------------------------------

///Picior Drept Inceput-------------------------------------------------------------
glRotatef(rpd,1,0,0);
glBegin(GL_QUADS);
///Fata Picior
     glColor3f(0,0,1);
     glVertex3f(-2.5,0,0);
    glVertex3f(-2.5,-5,0);
    glVertex3f(-0.5,-5,0);
    glVertex3f(-0.5,0,0);
///Spate Picior
    glColor3f(0,0,1);
     glVertex3f(-2.5,0,-3);
    glVertex3f(-2.5,-5,-3);
    glVertex3f(-0.5,-5,-3);
    glVertex3f(-0.5,0,-3);
///Lateral Dreapta Picior
    glColor3f(0,0,0.78);
     glVertex3f(-2.5,0,0);
    glVertex3f(-2.5,-5,0);
    glVertex3f(-2.5,-5,-3);
    glVertex3f(-2.5,0,-3);
///Lateral Stanga Picior
     glColor3f(0,0,0.78);
     glVertex3f(-0.5,0,0);
    glVertex3f(-0.5,-5,0);
    glVertex3f(-0.5,-5,-3);
    glVertex3f(-0.5,0,-3);
///Sub Picior Drept
      glColor3f(0.3,0.3,0.3);
     glVertex3f(-2.5,-5,0);
    glVertex3f(-0.5,-5,0);
    glVertex3f(-0.5,-5,-3);
    glVertex3f(-2.5,-5,-3);
///Sus Picior Drept
      glColor3f(0,0,1);
     glVertex3f(-2.5,0,0);
    glVertex3f(-0.5,0,0);
    glVertex3f(-0.5,0,-3);
    glVertex3f(-2.5,0,-3);
    glEnd();
///Picioare Drept Gata-------------------------------------------------------------
glutSwapBuffers();
}
void reshape(GLsizei width, GLsizei height) { //functie pentru redimensionarea caracterului
if (height == 0) height = 1;
GLfloat aspect = (GLfloat)width / (GLfloat)height;
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(55.0f, aspect, 0.1f, 100.0f);
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE);
glutInitWindowSize(1599, 899);
glutInitWindowPosition(0, 0);
glutCreateWindow(title); //validarea titlului
glutDisplayFunc(display); //validarea afisarii
glutReshapeFunc(reshape); //validarea comenzii de redimensionare
initGL();
glutTimerFunc(0, timer, 0);
glutKeyboardFunc(tastatura); //validarea comenzilor de pe tastatura
glutMouseFunc(mouse); //validarea comenzilor de pe mouse
glutMainLoop();
return 0;
}
