#import"carro.h"
#import"mapa.h"

	openOBJ car("obj/cedan.obj");
 	openOBJ car_wheel("obj/rodas.obj");

	LoadBMP car_load("texture/cedan.bmp");
carro::draw(){
	glPushMatrix();
	glScalef(0.05,0.05,-0.05);
	glTranslatef(0,0.15,0.2);
	car_load.draw();
	car.draw();
	glPopMatrix();
}
carro::roda(){
	glPushMatrix();
	glScalef(0.05,0.05,0.05);
	car_load.draw();
	car_wheel.draw();
	glPopMatrix();
}

float*carro::hitbox(float coo[2], float speed,float angle){
	float colisao[2] = {-0.1,0.075};
	float box[2]={0.5,0.5};
	float* result;
	mapa mapa_colisao;

	//	glVertex3f(coo[0]+colisao*sin((angle)*PI/180)  ,0.015,  coo[1]+colisao*cos((angle)*PI/180) );
		
		box[0]=coo[0]+colisao[0]*sin((angle)*PI/180);
		box[1]=coo[1]+colisao[0]*cos((angle)*PI/180);
		result = mapa_colisao.colisao(box,speed);
		result[0]=result[0]-colisao[0]*sin((angle)*PI/180);
		result[1]=result[1]-colisao[0]*cos((angle)*PI/180);
		if(speed != result[2])return result;

		
		box[0]=result[0]+colisao[1]*sin((angle)*PI/180);
		box[1]=result[1]+colisao[1]*cos((angle)*PI/180);
		result = mapa_colisao.colisao(box,speed);
		result[0]=result[0]-colisao[1]*sin((angle)*PI/180);
		result[1]=result[1]-colisao[1]*cos((angle)*PI/180);
		return result;
	
}
