//
//  double.c
//  gogl
//
//  Created by eastany on 15/4/9.
//  Copyright (c) 2015年 eastany. All rights reserved.
//

#include "double.h"
static GLfloat c1_3_spin=0.0;
void c1_3_init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void c1_3_display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(c1_3_spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPopMatrix();
    glutSwapBuffers();
}

void c1_3_spinDisplay(void)
{
    c1_3_spin+=5.0;
    if(c1_3_spin>360.0){
        c1_3_spin-=360.0;
    }
    glutPostRedisplay();
}

void c1_3_reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void c1_3_mouse(int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN){
                glutIdleFunc(c1_3_spinDisplay);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN){
                glutIdleFunc(NULL);
            }
            break;
        default:
            break;
    }
}

void main_test(){
    //glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(250,250);
    glutInitWindowPosition(100, 100);
    //glutCreateWindow(argv[0]);
    c1_3_init();
    glutDisplayFunc(c1_3_display);
    glutReshapeFunc(c1_3_reshape);
    glutMouseFunc(c1_3_mouse);
    glutMainLoop();
}