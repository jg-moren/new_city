#ifndef  CARRO_H
#define  CARRO_H

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#import"openOBJ.h"
#import"LoadBMP.h"
#define PI 3.1415


class carro
{


  public:
    draw();
    roda();
    float*hitbox(float coo[2], float speed,float angle);
};

#endif  /*CARRO_H*/
