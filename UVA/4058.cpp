#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define F false
#define T true

long long S[22][2005];
long long res[2005];
bool FI[22] ={
	T,F,T,T,F,F,
	T,F,F,F,F,F,
	T,F,T,F,F,F,
	T,F,F,F
};
int LI[22][8]={
	{7,0,1,5,11,13,17,21},//0
	{1,2,0,0,0,0,0,0},//1
	{7,0,1,5,11,13,17,21},//2
	{7,0,1,5,11,13,17,21},//3
	{1,2,0,0,0,0,0,0},//4
	{2,4,6,0,0,0,0,0},//5
	{7,0,1,5,11,13,17,21},//6
	{2,18,20,0,0,0,0,0},//7
	{2,14,19,0,0,0,0,0},//8
	{2,18,20,0,0,0,0,0},//9
	{2,14,19,0,0,0,0,0},//10
	{2,18,20,0,0,0,0,0},//11
	{7,0,1,5,11,13,17,21},//12
	{3,3,9,15,0,0,0,0},//13
	{7,0,1,5,11,13,17,21},//14
	{1,7,0,0,0,0,0,0},//15
	{1,8,0,0,0,0,0,0},//16
	{3,10,12,16,0,0,0,0},//17
	{7,0,1,5,11,13,17,21},//18
	{3,3,9,15,0,0,0,0},//19
	{3,10,12,16,0,0,0,0},//20
	{2,14,19,0,0,0,0,0}	//21
};
int W[22]={
	1,2,1,1,2,2,
	1,1,1,1,1,2,
	1,2,1,2,2,2,
	1,2,2,2
};
int N;

int main(){
	for(int i=0;i<2005;i++) for(int j=0;j<22;j++) S[j][i] = 0;
	for(int i=0;i<2005;i++) res[i] = 0;
	long long LIM = 1000000000; LIM*=1000;
	res[0] = 0; res[1] = 1;
	S[0][1] = 1; //S[0][2] = 1;
	S[1][2] = 1; S[5][2] = 1;
	S[11][2] = 1; S[13][2] = 1;
	S[17][2] = 1; S[21][2] = 1;
	int ac;
	for (int j=1; j<2001; j++) {//cuantas pueden ir a su der
		for (int i=0; i<22; i++) {
			for (int k=1; k<=LI[i][0]; k++) {
				ac = LI[i][k];
				S[ac][j+W[ac]] += S[i][j];
				if(S[ac][j+W[ac]] >= LIM){
					S[ac][j+W[ac]]-=LIM;
				}
				if (FI[ac]) {
					res[j+W[ac]]+=S[i][j];
					if(res[j+W[ac]] >= LIM){
						res[j+W[ac]]-=LIM;
					}
				}
			}
		}
	}
	//res[2] = 1;
	int kases=1;
	while (scanf("%d",&N), N ) {
	//	for(int i=0;i<22;i++) cout<<"FIN: "<<i<<" -> "<<S[i][N]<<endl;
		printf("Case %d: %lld\n",kases++,res[N]);
	}
}