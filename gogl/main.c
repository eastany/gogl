//
//  main.c
//  gogl
//
//  Created by eastany on 15/4/1.
//  Copyright (c) 2015年 eastany. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <math.h>
#include <stdio.h>
float pi = 3.141592653;
static float delt = 0.01;
static int day = 0;

void my_display(void)
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotated(day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day/30.0*360.0-day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);
    
    glutSwapBuffers();
    //glFlush();
}

void spin_display(){
    day += 1;
    if(day > 365){
        day = 0;
    }
    glutPostRedisplay();
}



void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0);
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    //glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    myInit();
    glutDisplayFunc(my_display);
    glutIdleFunc(spin_display);
    //glutReshapeFunc(my_reshape);
    //glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;
}
