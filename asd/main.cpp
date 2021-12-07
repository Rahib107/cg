#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>

#include<math.h>


static float	pm=  300.0;
static float	bm=  350.0;
static float	tm=  300.0;
static float	cm=  -300.0;
float spin = 0.0;

GLfloat	tx	=  5;
GLfloat	ty	=  5;



void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0;i<=360; i++){
    rad = i*(3.1416/180);
    glVertex2f(x+rx*cos(rad),y+ry*sin(rad));

    }
    glEnd();


}

void sun()
{
    glPushMatrix();
    glTranslated(270,260,0);
    glColor3f(1.0, 0.76, 0.3);
    circle(20,30,0,0);
    glPopMatrix();
}



void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
        glVertex2d(x,y);
        glVertex2d(x,y1);
        glVertex2d(x1,y1);
        glVertex2d(x1,y);


    glEnd();
}

void triangle(int x, int y, int x1, int x2,int y1)
{
    glBegin(GL_POLYGON);
        glVertex2d(x,y);
        glVertex2d(x1,y);

        glVertex2d(x1,y);
        glVertex2d(x2,y1);

        glVertex2d(x2,y1);
        glVertex2d(x,y);
        glEnd();
}
void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
        glVertex2d(x1,y1);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
        glVertex2d(x2,y2);
        glEnd();
}

void ground()
{
     glColor3f(1.3, 1.0, 0.53);
     rectangle(-300,-300,300,-10);

}
void road()
{

        glColor3f(0.3, 0.3, 0.3);
        rectangle(-300,-200,300,-30);

        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-30,300,-33);

        glColor3f(0.0, 0.0, 0.0);
        rectangle(-300,-205,300,-200);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-120,-230,-110);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(-270,-120,-200,-110);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(-150,-120,0,-110);

        glColor3f(1.0, 1.0, 1.0);
        rectangle(50,-120,150,-110);
        glColor3f(1.0, 1.0, 1.0);
        rectangle(200,-120,290,-110);

}

void makeprivatecar(){
    glColor3f(1.0, 1.1, 0.0);
    circle(5,15,0,0);
    rectangle(0,-15,60,15);

    glColor3f(0.2, 0.47, 1.0);
    triangle(5,15,20,20,45);
    triangle(40,15,60,40,45);

    glColor3f(0, 0, 0);
    rectangle(20,15,40,45);

    glColor3f(1.0, 1.1, 0.0);
    circle(5,10,80,-5);

    glColor3f(1.0, 1.1, 0.0);
    rectangle1(60,-15,80,-15,60,15,80,5);



    glColor3f(1.0, 1.0, 1.0);
    circle(6,12,10,-15);
    circle(6,12,60,-15);

}
void privatecarMove(){
cm=cm+.04;
    if(cm>330)
        cm =+350;
        glutPostRedisplay();
}

void privatecar()
{
    privatecarMove();
    for(int i=0;i<1;i++)
     {

     glPushMatrix();
     glTranslatef(cm,-50,0);
     makeprivatecar();
     glPopMatrix();

    }
}

void railline()
{
    glColor3f(0,0,0);
    rectangle(-300,-230,300,-225);
    rectangle(-300,-260,300,-265);
    int i = 0;

    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    for(i=-305;i<=300;i=i+30){

        glVertex2d(i,-260);
        glVertex2d(i+5,-260);
        glVertex2d(i+20,-225);
        glVertex2d(i+25,-225);

    }
    glEnd();

}

void building()
{
    glColor3f(85.0, 87.0, 115.3);
    rectangle(-100,-9,60,220);
    glColor3f(0.0, 0.0, 0.7);

    glColor3f(0.4, 1.0, 1.0);
    rectangle1(60,-9,70,0,60,220,70,220);

        glColor3f(0, 0, 0);
        rectangle(-35,-9,-5,30);

rectangle(-90,100,-70,80);
rectangle(-90,140,-70,120);
rectangle(-90,180,-70,160);
rectangle(-90,210,-70,190);

        rectangle(-60,100,-40,80);
        rectangle(-60,140,-40,115);
        rectangle(-60,155,-40,175);
        rectangle(-60,210,-40,190);






         rectangle(-30,100,-10,80);
         rectangle(-30,140,-10,120);
         rectangle(-30,175,-10,155);
         rectangle(-30,210,-10,190);




rectangle(0,100,20,80);\
rectangle(0,140,20,120);\
rectangle(0,174,20,155);\
rectangle(0,210,20,190);\




        rectangle(30,100,50,80);

    rectangle(30,140,50,120);
    rectangle(30,175,50,157);
    rectangle(30,210,50,190);


        rectangle(-90,70,-70,50);
        rectangle(-60,70,-40,50);
        rectangle(-30,70,-10,50);
        rectangle(0,70,20,50);
        rectangle(30,70,50,50);


}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
    ground();
    road();

    privatecar();
    railline();
    building();
    glFlush();
}


void init()
{
    glClearColor(0.3, .65, 1, 1.0);
	glOrtho(-300,300,-300,300,-150,500);
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Computer Grapics Project");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
