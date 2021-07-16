#ifndef  OPENOBJ_H
#define  OPENOBJ_H

#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class openOBJ
{	
  private:
  	vector<vector<float> > v;
	vector<vector<float> > vt;
	vector<vector<float> > vn;
	vector<vector<vector<int> > > f;
	
	vector<string>mtl;
	vector<vector<vector<float> > > mtl_values;
	vector<vector<string> >usemtl;

	vector<string> split (const string &s, char delim);
  public:
    openOBJ(char *filename);
    draw();
};

#endif  /*OPENOBJ_H*/
