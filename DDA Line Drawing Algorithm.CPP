#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include<stdio.h>

using namespace std;
int x1,y1,x2,y2;

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void dda_line(int x1, int y1, int x2, int y2){
    int dx = x2 - x1; int dy = y2 - y1;
    int steps = 1, length,x = x1,y = y1;
    length = max(abs(dx),abs(dy));
    int xinc = dx/length, yinc = dy/length;
    while(steps<=length){
        glBegin(GL_POINTS);
            glVertex2d(x, y);
        glEnd();
        x += xinc; y += yinc;
        steps++;
    }
    glFlush();
}

void world(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glPointSize(1.0);
    dda_line(x1,y1,x2,y2);
}

int main(int argc, char** argv){

    printf("please enter values between 0 and 500\n\n");
    printf("enter the value of x1: ");
    scanf("%d",&x1);
    printf("enter the value of y1: ");
    scanf("%d",&y1);
    printf("enter the value of x2: ");
    scanf("%d",&x2);
    printf("enter the value of y2: ");
    scanf("%d",&y2);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("DDA Line Drawing Algorithm");
    glutDisplayFunc(world);
    init();
    glutMainLoop();
    return 0;
}
