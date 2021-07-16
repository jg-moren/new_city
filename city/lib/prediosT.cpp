#import"prediosT.h"
openOBJ planoT("obj/predioT.obj");
LoadBMP chaoT_load("texture/grama.bmp");

prediosT::draw(){
/*	glBegin(GL_POLYGON);
	glNormal3f(-1, 1,-1);glVertex3f(0,0,0);
	glNormal3f( 1, 1,-1);glVertex3f(1,0,0);
	glNormal3f( 1, 1, 1);glVertex3f(1,0,1);
	glNormal3f(-1, 1, 1);glVertex3f(0,0,1);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1, 1,-1);glVertex3f(0  ,0.01,0.2);
	glNormal3f( 1, 1,-1);glVertex3f(1  ,0.01,0.2);
	glNormal3f( 1, 1, 1);glVertex3f(1  ,0.01,0.8);
	glNormal3f(-1, 1, 1);glVertex3f(0  ,0.01,0.8);
	glEnd();
	
	glBegin(GL_POLYGON);
	glNormal3f(-1, 1,-1);glVertex3f(0.2,0.01,1  );
	glNormal3f( 1, 1,-1);glVertex3f(0.8,0.01,1  );
	glNormal3f( 1, 1, 1);glVertex3f(0.8,0.01,0.2);
	glNormal3f(-1, 1, 1);glVertex3f(0.2,0.01,0.2);
	glEnd();
*/	
	glPushMatrix();
	glRotatef(0,0,1,0);
	glTranslatef(0.5,0,0.5);
	glScalef(0.5,0.5,0.5);
	chaoT_load.draw();
	planoT.draw();
	glPopMatrix();

}

float*prediosT::hitbox(float coo[2],float speed,int rotate){
	float a[3] = {coo[0],coo[1],speed};
	switch(rotate){
		case 0:
		case 4:
			if(coo[1]<((int)coo[1])+0.2)a[1]=(int)coo[1]+0.2,a[2]=a[2]/1000;
			if(coo[0]<((int)coo[0])+0.2 && coo[1]>((int)coo[1])+0.85)a[0]=(int)coo[0]+0.2,a[2]=a[2]/1000;
			if(coo[0]<((int)coo[0])+0.15&& coo[1]>((int)coo[1])+0.8 )a[1]=(int)coo[1]+0.8,a[2]=a[2]/1000;

			if(coo[0]>((int)coo[0])+0.8 && coo[1]>((int)coo[1])+0.85)a[0]=(int)coo[0]+0.8,a[2]=a[2]/1000;
			if(coo[0]>((int)coo[0])+0.85&& coo[1]>((int)coo[1])+0.8 )a[1]=(int)coo[1]+0.8,a[2]=a[2]/1000;

		break;
		case 1:
			if(coo[0]<((int)coo[0])+0.2)a[0]=(int)coo[0]+0.2,a[2]=a[2]/1000;
			if(coo[0]>((int)coo[0])+0.8 && coo[1]<((int)coo[1])+0.15)a[0]=(int)coo[0]+0.8,a[2]=a[2]/1000;
			if(coo[0]>((int)coo[0])+0.85&& coo[1]<((int)coo[1])+0.2 )a[1]=(int)coo[1]+0.2,a[2]=a[2]/1000;
			
			if(coo[0]>((int)coo[0])+0.8 && coo[1]>((int)coo[1])+0.85)a[0]=(int)coo[0]+0.8,a[2]=a[2]/1000;
			if(coo[0]>((int)coo[0])+0.85&& coo[1]>((int)coo[1])+0.8 )a[1]=(int)coo[1]+0.8,a[2]=a[2]/1000;
			
		break;
		case 2:
			if(coo[1]>((int)coo[1])+0.8)a[1]=(int)coo[1]+0.8,a[2]=a[2]/1000;
			if(coo[0]<((int)coo[0])+0.2 && coo[1]<((int)coo[1])+0.15)a[0]=(int)coo[0]+0.2,a[2]=a[2]/1000;
			if(coo[0]<((int)coo[0])+0.15&& coo[1]<((int)coo[1])+0.2 )a[1]=(int)coo[1]+0.2,a[2]=a[2]/1000;
			
			
			if(coo[0]>((int)coo[0])+0.8 && coo[1]<((int)coo[1])+0.15)a[0]=(int)coo[0]+0.8,a[2]=a[2]/1000;
			if(coo[0]>((int)coo[0])+0.85&& coo[1]<((int)coo[1])+0.2 )a[1]=(int)coo[1]+0.2,a[2]=a[2]/1000;
			
		break;
		case 3:
			if(coo[0]>((int)coo[0])+0.8)a[0]=(int)coo[0]+0.8,a[2]=a[2]/1000;
			if(coo[0]<((int)coo[0])+0.2 && coo[1]<((int)coo[1])+0.15)a[0]=(int)coo[0]+0.2,a[2]=a[2]/1000;
			if(coo[0]<((int)coo[0])+0.15&& coo[1]<((int)coo[1])+0.2 )a[1]=(int)coo[1]+0.2,a[2]=a[2]/1000;
			
			if(coo[0]<((int)coo[0])+0.2 && coo[1]>((int)coo[1])+0.85)a[0]=(int)coo[0]+0.2,a[2]=a[2]/1000;
			if(coo[0]<((int)coo[0])+0.15&& coo[1]>((int)coo[1])+0.8 )a[1]=(int)coo[1]+0.8,a[2]=a[2]/1000;			
						
		break;
	}

	return a;
}

