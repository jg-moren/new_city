#include"obj_luz.h"


obj_luz::luz1(){
		
		GLfloat light1_ambient[] = { 0.01, 0.01, 0.01, 0.5 };
		GLfloat light1_diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
		GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 0.0 };
		GLfloat light1_position[] = { 3.0, 1.0, 5.0, 1.0 };
		GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
		
		glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
		glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.1);
		
		



		glEnable(GL_LIGHT1);

	
}
		
obj_luz::luz2(float coo[2],float angle){
		
		GLfloat light2_ambient[] = { 0.01, 0.01, 0.01, 0.5 };
		GLfloat light2_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat light2_specular[] = { 0.0, 0.0, 0.0, 0.0 };
		GLfloat light2_position[] = { coo[0], 0.1, coo[1], 1.0 };
		GLfloat spot2_direction[] = { -sin(angle*PI/180), 0.0, -cos(angle*PI/180) };
		
		glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
		glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.1);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.1);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01);
		
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot2_direction);
		glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 50.0);
/*		
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(light1_position[0],light1_position[1],light1_position[2]);
		glColor3f(1,1,1);
		glutSolidCube(1);
		glEnable(GL_LIGHTING);

		glPopMatrix();
*/
		glEnable(GL_LIGHT2);

	
}
	

		
	



