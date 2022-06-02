#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "myShape.h"
#define KEY_ESC 27

float theta =0.0;
float move=0.0;
int sw =1;
GLfloat lightpos[] = { 200.0, 1000.0, -500.0, 1.0 };


DrawString(char *str, float x0,float y0, double w, double h)
{
	int i,len;
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.,w,0.,h);
 	len = strlen(str);
	for(i=0;i<len;i++){
	glRasterPos2f(x0+20*i,y0);
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *str);
	  str++;
	}
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	
	
	
	
	glPushMatrix();
	glTranslatef(0.0,-2.5,-25.0);
	glRotatef(30,1.0,0.0,0.0);
	glRotatef(25,0.0,1.0,0.0);
	//glRotatef(90,0.0,1.0,0.0);
	//glTranslatef(50.0,0.0,0.0);
	
	//線路1の描画
	glPushMatrix();
	glColor3d(0,0,0);
	glBegin(GL_LINES);
		glVertex3f(0.7, -1.4, 10.0);
		glVertex3f(0.7, -1.4, -33.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.7, -1.4, 10.0);
		glVertex3f(-0.7, -1.4, -33.0);
	glEnd();
	for(int i=0;i<=14;i++){
		glBegin(GL_LINES);
		glVertex3f(0.7, -1.4, -33.0+(i*3));
		glVertex3f(-0.7, -1.4, -33.0+(i*3));
		glEnd();
	}	
	glPopMatrix();
	//線路1の描画終了
	
	//線路2の描画
	glPushMatrix();
	glRotatef(-8,0.0,1.0,0.0);
	glBegin(GL_LINES);
		glVertex3f(0.7, -1.4, 0.0);
		glVertex3f(0.7, -1.4, -33.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(-0.7, -1.4, 0.0);
		glVertex3f(-0.7, -1.4, -33.0);
	glEnd();
	for(int i=0;i<=11;i++){
		glBegin(GL_LINES);
		glVertex3f(0.7, -1.4, -33.0+(i*3));
		glVertex3f(-0.7, -1.4, -33.0+(i*3));
		glEnd();
	}	
	glPopMatrix();
	//線路2の描画終了
	

	//glEnable(GL_LIGHTING);
	//一人目の描画
	glPushMatrix();
	if((move>=24.0&&sw==1)||(move>=24.0&&sw==0)){
		//GLfloat red[]={0.8,0,0,1};
		//glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,red);
		glColor3f(0.8,0.0,0.0);
		glRotatef(-90,0.0,0.0,1.0);
	}else{
		//GLfloat blue[]={0,0,1,1};
		//glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,blue);
		glColor3f(0.0,0.0,0.6);
	}	
	
	
	glPushMatrix();
		glTranslatef(0.0,0.0,-23.0);
		mySolidCylinder(0.1,1.5,24);
    glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0.45,0.0,-23.0);
		glRotatef(45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.45,0.0,-23.0);
		glRotatef(-45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.3,-1.0,-23.0);
		glRotatef(30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.3,-1.0,-23.0);
		glRotatef(-30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0,0.9,-23.0);
	glutSolidSphere(0.4,20,20);
	glPopMatrix();
	
	glPopMatrix();
	//一人目の描画終了
	
	
	
	
	
	//ニ人目の描画
	glPushMatrix();
	if((move>=21.0&&sw==1)||(move>=21.0&&sw==0)){
		glColor3f(0.8,0.0,0.0);
		glRotatef(-90,0.0,0.0,1.0);
	}else{
		glColor3f(0.0,0.0,0.8);
	}	
	
	glPushMatrix();
		glTranslatef(0.0,0.0,-20.0);
		mySolidCylinder(0.1,1.5,24);
    glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0.45,0.0,-20.0);
		glRotatef(45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.45,0.0,-20.0);
		glRotatef(-45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.3,-1.0,-20.0);
		glRotatef(30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.3,-1.0,-20.0);
		glRotatef(-30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0,0.9,-20.0);
	glutSolidSphere(0.4,20,20);
	glPopMatrix();
	
	glPopMatrix();
	//ニ人目の描画終了
	
	
	
	
	//三人目の描画
	glPushMatrix();
	if((move>=18.0&&sw==1)||(move>=18.0&&sw==0)){
		glColor3f(0.8,0.0,0.0);
		glRotatef(-90,0.0,0.0,1.0);
	}else{
		glColor3f(0.0,0.0,1.0);
	}	
	
	glPushMatrix();
		glTranslatef(0.0,0.0,-17.0);
		mySolidCylinder(0.1,1.5,24);
    glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0.45,0.0,-17.0);
		glRotatef(45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.45,0.0,-17.0);
		glRotatef(-45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.3,-1.0,-17.0);
		glRotatef(30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.3,-1.0,-17.0);
		glRotatef(-30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0,0.9,-17.0);
	glutSolidSphere(0.4,20,20);
	glPopMatrix();
	
	glPopMatrix();
	
	//三人目の描画終了
	
	
	
	
	//四人目の描画
	glPushMatrix();
	glRotatef(-8,0.0,1.0,0.0);
	if((move>=21.0&&sw==2)||(move>=21.0&&sw==0)){
		glColor3f(0.8,0.0,0.0);
		glRotatef(-90,0.0,0.0,1.0);
	}else{
		glColor3f(0.0,0.0,1.0);
	}	
	
	glPushMatrix();
		glTranslatef(0.0,0.0,-20.0);
		mySolidCylinder(0.1,1.5,24);
    glPopMatrix();

	
	glPushMatrix();
		glTranslatef(0.45,0.0,-20.0);
		glRotatef(45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.45,0.0,-20.0);
		glRotatef(-45,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.3,-1.0,-20.0);
		glRotatef(30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.3,-1.0,-20.0);
		glRotatef(-30,0.0,0.0,1.0);
		mySolidCylinder(0.1,1.2,24);
    glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0,0.9,-20.0);
	glutSolidSphere(0.4,20,20);
	glPopMatrix();
	
	glPopMatrix();
	//四人目の描画終了
	
	//glDisable(GL_LIGHTING);	
	
	//トロッコの描画
	glPushMatrix();
	if(sw==2){
		glRotatef(-8,0.0,1.0,0.0);
	}
	glTranslatef(0.0,0.0,0.0-move);
	if(sw==0){
		if(move>=10.5){
			glRotatef(82.5,0.0,1.0,0.0);
			
			glTranslatef(0.0,0.0,-1.5);
		}	
	}	
	
	glPushMatrix();//車輪の描画
	glPushMatrix();
		glColor3f( 0.0, 0.0, 0.0 );
		glTranslatef(0.6,-1.0,1.5);
		glRotatef(90,0.0,0.0,1.0);
		glRotatef(theta,0.0,1.0,0.0);
		mySolidCylinder(0.4,0.3,24);
    glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.0, 0.0, 0.0 );
		glTranslatef(-0.6,-1.0,1.5);
		glRotatef(90,0.0,0.0,1.0);
		glRotatef(theta,0.0,1.0,0.0);
		mySolidCylinder(0.4,0.3,24);
    glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.2, 0.2, 0.2 );
		glTranslatef(0.6,-1.0,4.5);
		glRotatef(90,0.0,0.0,1.0);
		glRotatef(theta,0.0,1.0,0.0);
		mySolidCylinder(0.4,0.3,24);
    glPopMatrix();
	
	glPushMatrix();
		glColor3f( 0.2, 0.2, 0.2 );
		glTranslatef(-0.6,-1.0,4.5);
		glRotatef(90,0.0,0.0,1.0);
		glRotatef(theta,0.0,1.0,0.0);
		mySolidCylinder(0.4,0.3,24);
    glPopMatrix();
	glPopMatrix();//車輪の描画終了
	
	//本体の描画
	glColor3f( 0.5, 0.5, 0.0);;
	glBegin(GL_QUADS);
		glVertex3f(-0.7,-0.7,1.0);
		glVertex3f(-0.7,-0.7,5.0);
		glVertex3f(0.7,-0.7,5.0);
		glVertex3f(0.7,-0.7,1.0);
	glEnd();
	
	glColor3f( 0.5, 0.2, 0.2);
	glBegin(GL_QUADS);
		glVertex3f(-0.7,-0.7,1.0);
		glVertex3f(-0.7,0.7,1.0);
		glVertex3f(0.7,0.7,1.0);
		glVertex3f(0.7,-0.7,1.0);
	glEnd();

	glColor3f( 0.5, 0.2, 0.2);
	glBegin(GL_QUADS);
		glVertex3f(0.7,-0.7,1.0);
		glVertex3f(0.7,0.7,1.0);
		glVertex3f(0.7,0.7,5.0);
		glVertex3f(0.7,-0.7,5.0);
	glEnd();

	glColor3f( 0.5, 0.2, 0.2);
	glBegin(GL_QUADS);
		glVertex3f(-0.7,-0.7,1.0);
		glVertex3f(-0.7,0.7,1.0);
		glVertex3f(-0.7,0.7,5.0);
		glVertex3f(-0.7,-0.7,5.0);
	glEnd();
	
	glColor3f( 0.6, 0.3, 0.3);
	glBegin(GL_QUADS);
		glVertex3f(-0.7,-0.7,5.0);
		glVertex3f(-0.7,0.7,5.0);
		glVertex3f(0.7,0.7,5.0);
		glVertex3f(0.7,-0.7,5.0);
	glEnd();
	
	glColor3f( 0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
		glVertex3f(-0.7,0.7,1.0);
		glVertex3f(-0.7,0.7,5.0);
		glVertex3f(0.7,0.7,5.0);
		glVertex3f(0.7,0.7,1.0);
	glEnd();
	glPopMatrix();//本体の描画終了
	
	
	glPopMatrix();
	//トロッコの描画終了
	
	
	
	
	//文字列
	glPushMatrix();
	glPushMatrix();
	glColor3d(0.8,0.,0.);
	if(move<18.0){
        DrawString("0 KILL",300,400,500,500);
	}else if(move>=18.0&&move<21){
		if(sw==1||sw==0){
			DrawString("1 KILL",300,400,500,500);
		}else if(sw==2){
			DrawString("0 KILL",300,400,500,500);
		}	
	}else if(move>=21.0&&move<24){
		if(sw==1){
			DrawString("2 KILL",300,400,500,500);
		}else if(sw==2){
			DrawString("1 KILL",300,400,500,500);
		}else if(sw==0){
			DrawString("3 KILL",300,400,500,500);
		}	
	}else if(move>=24){
		if(sw==1){
			DrawString("3 KILL",300,400,500,500);
		}else if(sw==2){
			DrawString("1 KILL",300,400,500,500);
		}else if(sw==0){
			DrawString("4 KILL",300,400,500,500);
		}	
	}
	glPopMatrix();
	
	glPushMatrix();
		glColor3d(0.,0.,1.);
		DrawString("S:START",330,250,500,500);
		DrawString("X:SWITCH",330,230,500,500);
		DrawString("Z:RESET",330,210,500,500);
		DrawString("W:???",330,190,500,500);
	glPopMatrix();
	
	glPopMatrix();
	//
	
	
	
	
	glPopMatrix();
	glutSwapBuffers();
	
	
}

void idle(void)/*イベントがなければidleがつねに実行される*/
{
	theta=fmod(theta+0.01,360.0);/*回転角を０°～３６０°まで0.5°づつ増加させる）*/
	move+=0.03;
	glutPostRedisplay();/*ディスプレイコールバックバック関数(display)を実行*/
}


void myKbd(unsigned char key, int x, int y)
{
	if(key==KEY_ESC){
		exit(0);
	}else if( key == 115){
		glutIdleFunc(idle);
	}else if(key == 120 && move == 0){
		if(sw==1){
			sw=2;
			printf("スイッチを切り替えました\n");
		}else if(sw==2){
			sw=1;
			printf("スイッチを切り替えました\n");
		}
	}else if(key == 119 && move == 0){
		sw=0;
		glutIdleFunc(idle);
	}else if(key == 122){
		glutIdleFunc(NULL);
		sw=1;
		move=0;
		printf("リセットしました\n");
	}	
	glutPostRedisplay();
}


void myInit(char *progname)
{
	int width=500,height=500;
	float aspect=(float)width/(float)height;
	
	glutInitWindowPosition(0,0);
	glutInitWindowSize(width,height);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(progname);
	glClearColor(1.0,1.0,1.0,1.0);	
	glutKeyboardFunc(myKbd);
	
	glMatrixMode(GL_PROJECTION);
	/*投影変換行列スタックを操作対象とする*/
	glLoadIdentity();/*行列スタックをクリア*/
	gluPerspective(30.0,aspect,1.0,50.0);
	glMatrixMode(GL_MODELVIEW);/*幾何変換行列スタックを操作対象する*/
	//glEnable(GL_LIGHT0);
}


int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	myInit(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(myKbd);
	glutMainLoop();
	return(0);
}