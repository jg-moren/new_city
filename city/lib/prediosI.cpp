#import"prediosI.h"

openOBJ planoI("obj/predioI.obj");
LoadBMP chaoI_load("texture/grama.bmp");

prediosI::draw(){

/*	glBegin(GL_POLYGON);
	glNormal3f(-1, 1,-1);glVertex3f(0,0,0);
	glNormal3f( 1, 1,-1);glVertex3f(1,0,0);
	glNormal3f( 1, 1, 1);glVertex3f(1,0,1);
	glNormal3f(-1, 1, 1);glVertex3f(0,0,1);
	glEnd();
*/	
/*
	glBegin(GL_POLYGON);
	glNormal3f(-1, 1,-1);glVertex3f(0  ,0.01,0.2);
	glNormal3f( 1, 1,-1);glVertex3f(1,0.01,0.2);
	glNormal3f( 1, 1, 1);glVertex3f(1,0.01,0.8);
	glNormal3f(-1, 1, 1);glVertex3f(0  ,0.01,0.8);
	glEnd();
*/
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-0.5,0,0.5);
	glScalef(0.5,0.5,0.5);
	chaoI_load.draw();
	planoI.draw();
	glPopMatrix();


}

float*prediosI::hitbox(float coo[2],float speed,int rotate){
	float a[3] = {coo[0],coo[1],speed};
	switch(rotate){
		case 0:
		case 2:
		case 4:
			if(coo[1]<((int)coo[1])+0.2)a[1]=(int)coo[1]+0.2,a[2]=a[2]/1000;
			if(coo[1]>((int)coo[1])+0.8)a[1]=(int)coo[1]+0.8,a[2]=a[2]/1000;
		break;

		
		case 1:
		case 3:
			if(coo[0]<((int)coo[0])+0.2)a[0]=(int)coo[0]+0.2,a[2]=a[2]/1000;
			if(coo[0]>((int)coo[0])+0.8)a[0]=(int)coo[0]+0.8,a[2]=a[2]/1000;
			
		break;

	}


	return a;
}

