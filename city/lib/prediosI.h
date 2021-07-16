#ifndef  PREDIOSI_H
#define  PREDIOSI_H

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <vector>
#import"openOBJ.h"
#import"LoadBMP.h"

class prediosI
{
  public:
    draw();
    float* hitbox(float coo[2],float speed,int rotate);
};

#endif  /*PREDIOSI_H*/

