#import"openOBJ.h"
#include "loadBMP.h"

template <typename T>
string ToString(T val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}
	

vector<string> openOBJ::split (const string &s, char delim) {//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

openOBJ::openOBJ(char *filename){
	vector<vector<int> > insertf;
	vector<int> insertf2;
	vector<float> insert;
	vector<string> insertmtl;
	vector<vector<float> >insert2;

	string line;
    ifstream myfile(filename, ios::in);
    while ( getline(myfile,line) )
    {
    	
      	if(line.substr(0,line.find(' '))=="v"){           		
      		insert.insert(insert.end(),atof(split(line,' ')[1].c_str()));
      		insert.insert(insert.end(),atof(split(line,' ')[2].c_str()));
      		insert.insert(insert.end(),atof(split(line,' ')[3].c_str()));
       		v.push_back(insert);
			insert.clear(); 
     		
      		
	  	}
	  	if(line.substr(0,line.find(' '))=="vt"){
      		insert.insert(insert.end(),atof(split(line,' ')[1].c_str()));
      		insert.insert(insert.end(),atof(split(line,' ')[2].c_str()));
       		vt.push_back(insert);
			insert.clear(); 
	  	}
	  	if(line.substr(0,line.find(' '))=="vn"){
      		insert.insert(insert.end(),atof(split(line,' ')[1].c_str()));
      		insert.insert(insert.end(),atof(split(line,' ')[2].c_str()));
      		insert.insert(insert.end(),atof(split(line,' ')[3].c_str()));
       		vn.push_back(insert);
			insert.clear(); 
	  	}
	  	if(line.substr(0,line.find(' '))=="f"){
	  		for(int i=1;i<=split(line,' ').size()-1;i++){
	  
				insertf2.insert(insertf2.end(),atoi(split(split(line,' ')[i],'/')[0].c_str()));
      			if(split(split(line,' ')[1],'/').size()>=2){
					insertf2.insert(insertf2.end(),atoi(split(split(line,' ')[i],'/')[1].c_str()));
      			}if(split(split(line,' ')[1],'/').size() >=3){
					insertf2.insert(insertf2.end(),atoi(split(split(line,' ')[i],'/')[2].c_str()));
      			}
				insertf.push_back(insertf2);
				insertf2.clear(); 
	  		}
       		f.push_back(insertf);
			insertf.clear(); 
	  	}
	  	if(line.substr(0,line.find(' '))=="usemtl"){
	  		insertmtl.insert(insertmtl.end(),split(line,' ')[1]);
	  		insertmtl.insert(insertmtl.end(), ToString(f.size()) );
	  		usemtl.push_back(insertmtl);
	  		insertmtl.clear();

	  	}
	  	if(line.substr(0,line.find(' '))=="mtllib"){
	  			string linemtl;
	  			const char* file_name = split(line,' ')[1].c_str();
    			ifstream myfilemtl(file_name, ios::in);
    			while ( getline(myfilemtl,linemtl) ){
    				
    				
    				//cout<<split(linemtl,' ')[0];
    				if(linemtl.substr(0,linemtl.find(' '))=="newmtl"){
    				mtl.insert(mtl.end(),split(linemtl,' ')[1]);
					}
    				if(linemtl.substr(0,linemtl.find(' '))=="Ns"){
    					insert.insert(insert.end(),atof(split(linemtl,' ')[1].c_str()));
    					insert2.push_back(insert);
    					insert.clear();
					}
					if(linemtl.substr(0,linemtl.find(' '))=="Ka" || linemtl.substr(0,linemtl.find(' '))=="Kd" || linemtl.substr(0,linemtl.find(' '))=="Ks" || linemtl.substr(0,linemtl.find(' '))=="Ke"){
    					insert.insert(insert.end(),atof(split(linemtl,' ')[1].c_str()));
	   					insert.insert(insert.end(),atof(split(linemtl,' ')[2].c_str()));
    					insert.insert(insert.end(),atof(split(linemtl,' ')[3].c_str()));
    					insert2.push_back(insert);
    					insert.clear();
					}
					if(linemtl.substr(0,linemtl.find(' '))=="illum"){
    					mtl_values.push_back(insert2);
    					insert2.clear();
					}

				}
				myfilemtl.close();
	  	}
	  	

	}
	myfile.close();
	
	
}

openOBJ::draw(){
		GLfloat diffuse [4]={0.8,0.8,0.8,1.0};
		glMaterialfv(GL_FRONT,GL_DIFFUSE, diffuse );
		
		GLfloat ambient [4]={1.0,1.0,1.0,1.0};
		glMaterialfv(GL_FRONT,GL_AMBIENT, ambient );
		
		GLfloat emission [4]={0.0,0.0,0.0,1.0};
		glMaterialfv(GL_FRONT,GL_EMISSION, emission );
		
		GLfloat especular[4]={0.5,0.5,0.5,1.0};
		glMaterialfv(GL_FRONT,GL_SPECULAR, especular);
		glMateriali(GL_FRONT,GL_SHININESS,10);
	
glColor3f(1,1,1);
	
			for(int i1=0;i1<f.size();i1++){
				
			for(int ii1=0; ii1<usemtl.size();ii1++){
				if(i1==atoi(usemtl[ii1][1].c_str())){
					for(int ii2=0;ii2<mtl.size();ii2++){
						if(mtl[ii2]==usemtl[ii1][0]){
							
							glMateriali(GL_FRONT,GL_SHININESS,mtl_values[ii2][0][0]);
							
							GLfloat ambient [4]={mtl_values[ii2][1][0] ,mtl_values[ii2][1][1],mtl_values[ii2][1][2],1.0};
							glMaterialfv(GL_FRONT,GL_AMBIENT, ambient );
							
							GLfloat diffuse [4]={mtl_values[ii2][2][0] ,mtl_values[ii2][2][1],mtl_values[ii2][2][2],1.0};
							glMaterialfv(GL_FRONT,GL_DIFFUSE, diffuse );							
							
							GLfloat especular[4]={mtl_values[ii2][3][0] ,mtl_values[ii2][3][1],mtl_values[ii2][3][2],1.0};
							glMaterialfv(GL_FRONT,GL_SPECULAR, especular);
							
							if(mtl_values[ii2].size()>=5){
								GLfloat emission [4]={mtl_values[ii2][4][0] ,mtl_values[ii2][4][1],mtl_values[ii2][4][2],1.0};
								glMaterialfv(GL_FRONT,GL_EMISSION, emission);
							}
							
		  					
						}
					}
				}
			}				
				
				
			glBegin(GL_POLYGON);
	  		for(int i2=0;i2<f[i1].size();i2++){
	  			if(f[i1][i2].size()>=2)glTexCoord2f(vt[f[i1][i2][1]-1][0],vt[f[i1][i2][1]-1][1]);
	  			if(f[i1][i2].size()>=3)glNormal3f(vn[f[i1][i2][2]-1][0],vn[f[i1][i2][2]-1][1],vn[f[i1][i2][2]-1][2]);
	  			glVertex3f(v[f[i1][i2][0]-1][0],v[f[i1][i2][0]-1][1],v[f[i1][i2][0]-1][2]);
		  	}
		  	glEnd();
		}

}
