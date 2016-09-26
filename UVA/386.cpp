/*
*  Javier Segovia
*  Accepted in 0.044
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
int M[201];
int find(int i,int f,int v){
	int res=-1;
	while (i<f) {
		res = (f+i)/2;
		if(M[res] == v) return res;
		else if(M[res] < v) i=res+1;
		else f = res;
	}
	return -1;
}
int main(){
	int d;
	for(int i=1;i<201;i++) M[i] = i*i*i;
	for (int i=6; i<201; i++) {
		for (int j=2; j<i; j++) {
			for (int k=j; k<i; k++) {				
				d = find(k,i,M[i]-(M[j]+M[k]) );
				if(d!=-1) printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,d);
			}
		}
	}
}