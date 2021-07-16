#ifndef  LOADBMP_H
#define  LOADBMP_H

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

#define SAIR {fclose(fp_arquivo); return ;}
#define CTOI(C) (*(int*)&C)

class LoadBMP
{
  private:
	GLubyte *image;

	GLsizei Width,Height;
  public:
    
	LoadBMP(char *filename);
    draw();
};

#endif  /*LOADBMP_H*/








