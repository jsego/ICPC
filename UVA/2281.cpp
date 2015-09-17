/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int A[16][3];

int main(){
	for (int i=0; i<16; i++) {
		for (int j=0; j<3; j++) {
			cin>>A[i][j];
		}
	}
	int a,b,c,ac;
	while (cin>>a>>b>>c, a!=-1 && b!=-1 && c!=-1) {
		int pos=-1,dist=2000000000;
		for (int i=0; i<16; i++) {
			ac = (A[i][0]-a)*(A[i][0]-a) + (A[i][1]-b)*(A[i][1]-b) + (A[i][2]-c)*(A[i][2]-c);
			if(ac<dist){dist=ac; pos = i;}
		}
		cout<<"("<<a<<","<<b<<","<<c<<") maps to ("<<A[pos][0]<<","<<A[pos][1]<<","<<A[pos][2]<<")"<<endl;
	}
}