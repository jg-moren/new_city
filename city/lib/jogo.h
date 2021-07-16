#ifndef  JOGO_H
#define  JOGO_H

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <math.h>
#define PI 3.1415

#include"obj_luz.h"
#include"mapa.h"
#include"carro.h"

class jogo
{
  public:
    void keyOperationsJogo(bool keyStates [256]);
    displayJogo();
};

#endif  /*JOGO_H*/

