#ifndef  PREDIOST_H
#define  PREDIOST_H

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <vector>
#import"openOBJ.h"
#import"LoadBMP.h"
class prediosT
{
  public:
    draw();
    float* hitbox(float coo[2],float speed,int rotate);
};

#endif  /*PREDIOST_H*/

