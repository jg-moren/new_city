#import"mapa.h"

#include <vector>

mapa::draw(){
	for(int i1=0;i1 < sizeof(var_mapa[0])/sizeof(var_mapa[0][0]);i1++){
		for(int i2=0; i2 < sizeof(var_mapa)/sizeof(var_mapa[0]);i2++){
			glPushMatrix();
			glTranslatef(i2+0.5,0,i1+0.5);
			switch(var_mapa[i1][i2][0]){
				case 1:
					glRotatef(var_mapa[i1][i2][1]*90,0,1,0);
					glTranslatef(-0.5,0,-0.5);
					prediosI I;
					I.draw();
				break;	
				case 2:
					glRotatef(var_mapa[i1][i2][1]*90,0,1,0);
					glTranslatef(-0.5,0,-0.5);
					prediosL L;
					L.draw();
				break;	
				case 3:
					glRotatef(var_mapa[i1][i2][1]*90,0,1,0);
					glTranslatef(-0.5,0,-0.5);
					prediosT T;
					T.draw();
				break;	
			}
			glPopMatrix();
		}
	}
}

float* mapa::colisao(float coo[2],float speed){
	float* result;
	switch(var_mapa[(int)coo[1]][(int)coo[0]][0]){
		case 1:
			prediosI I;
			result=I.hitbox(coo,speed,var_mapa[(int)coo[1]][(int)coo[0]][1]);
		break;
		case 2:
			prediosL L;
			result=L.hitbox(coo,speed,var_mapa[(int)coo[1]][(int)coo[0]][1]);
		break;
		case 3:
			prediosT T;
			result=T.hitbox(coo,speed,var_mapa[(int)coo[1]][(int)coo[0]][1]);
		break;
	}
	return result;
	
}
