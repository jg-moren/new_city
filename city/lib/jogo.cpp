#include"jogo.h"

float angle,plusangle,carangle;
float roda;
float speed;
float coo[2]={0.5,0.5};

void jogo::keyOperationsJogo (bool keyStates [256]) {
 if(keyStates['a']){
 	plusangle+=0.02;
 }
 if(keyStates['d']){
 	plusangle-=0.02;
 }
 if(keyStates['w'])speed= speed*1.04-0.0005;
 if(keyStates['s']){
 	speed= speed/1.02;
 	if(speed < 0.002)speed+=0.001;
 }
 
roda += speed/250;

 if(speed <-0.002 ){
	angle+=plusangle*15;
	if(carangle != angle)carangle += (angle-carangle)/10;
}else{
//	carangle = angle;
	plusangle=0;
}
 plusangle = plusangle/1.07;
 speed=speed/1.01;
 
 coo[0] += speed*sin( angle*PI/180);
 coo[1] += speed*cos( angle*PI/180);
 
 carro colisao;
 coo[0] = (colisao.hitbox(coo,speed,angle))[0];
 coo[1] = (colisao.hitbox(coo,speed,angle))[1];
 speed = (colisao.hitbox(coo,speed,angle))[2];


}

jogo::displayJogo(){

glClearColor(0.0, 0.0, 0.0, 1.0);

glEnable(GL_DEPTH_TEST);
glShadeModel(GL_SMOOTH);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);




glEnable(GL_LIGHTING);
glEnable(GL_COLOR_MATERIAL);

/* Define a Texturizacao */
glEnable ( GL_TEXTURE_2D );
glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );


glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

//-----------------------------------------------------------------------------------------------------------------
GLfloat lmodelo_ambiente[] = { 0.0, 0.0, 0.0, 1.0 };
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodelo_ambiente);

gluLookAt(0.2*sin(carangle*PI/180)+coo[0],0.1,0.2*cos(carangle*PI/180)+coo[1],0+coo[0],0,0+coo[1],0,1,0);
//gluLookAt(coo[0],5,coo[1]+0.00000001,coo[0],0,coo[1],0,1,0);
//gluLookAt(coo[0]-0.3,0.1,coo[1],coo[0],0,coo[1],0,1,0);



glPushMatrix();
obj_luz luz;
luz.luz1();
luz.luz2(coo,angle);

		glDisable(GL_LIGHTING);
		glDisable( GL_TEXTURE_2D );
		
for(int i1=0;i1<100;i1++ ){
		glPushMatrix();
		glTranslatef(coo[0],0.5,coo[1]);
		glRotatef(i1*13,0,1,0);
		glTranslatef(1.5,0,0);
		glRotatef(i1*47,0,1,0);
		glTranslatef(0.5,0,0);
		glutSolidSphere(0.01,10,10);
		glPopMatrix();		

}
	
		
		
		glPushMatrix();

		glTranslatef(coo[0]+5,2.5,coo[1]+2);
		glColor3f(1,1,1);
		glutSolidSphere(1.5,20,20);

		glPopMatrix();
		
		glEnable(GL_LIGHTING);
		glEnable ( GL_TEXTURE_2D );



GLfloat semespecular[4]={0.0,0.0,0.0,1.0};
glMaterialfv(GL_FRONT,GL_SPECULAR, semespecular);
glMateriali(GL_FRONT,GL_SHININESS,20);




glPushMatrix();	
glTranslatef(coo[0],0,coo[1]);
glRotatef(angle,0,1,0);
glColor3f(1,1,1);
carro carro;
carro.draw();

glPushMatrix();
glTranslatef( 0.027,0.02,-0.06);
if(speed<0)glRotatef( plusangle*250,0,1,0);
if(speed>0)glRotatef(-plusangle*250,0,1,0);
glRotatef(roda*100000,1,0,0);
glScalef( 1,1,1);
carro.roda();
glPopMatrix();

glPushMatrix();
glTranslatef( 0.027,0.02, 0.03);
glRotatef(roda*100000,1,0,0);
glScalef( 1,1,1);
carro.roda();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.027,0.02,-0.06);
if(speed<0)glRotatef( plusangle*250,0,1,0);
if(speed>0)glRotatef(-plusangle*250,0,1,0);
glRotatef(roda*100000,1,0,0);
glScalef(-1,1,1);
carro.roda();
glPopMatrix();

glPushMatrix();
glTranslatef(-0.027,0.02, 0.03);
glRotatef(roda*100000,1,0,0);
glScalef(-1,1,1);
carro.roda();
glPopMatrix();

glPopMatrix();
//--------------------------------------------------------------------------------------------------------------------
glPushMatrix();
mapa pista;
pista.draw();
glPopMatrix();

glPopMatrix();



}
