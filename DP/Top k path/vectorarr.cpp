
//#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int NX=2;
int NY=3;
int NZ=5;
int i,j,k; 
 
 
int main()
{
	vector<vector<vector<float> > > grdarray(NZ,vector<vector<float> >(NY,vector<float>(NX,0)));
	for(int z=0;z<NZ;z++)
	{
		for (int y=0;y<NY;y++)
		{
			for (int x=0;x<NX;x++)
			{
				grdarray[x][y][z]=2;
				cout<<grdarray[x][y][z]<<"  ";
			}
			cout<<"\n";
		}
	}
	
}
 
