/*
*  Javier Segovia
*  Accepted in 0.008
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
int A[101][5];

void translate(int i){
	int last = i%10;
	if(last>0 && last<4) A[i][0]+=last;
	else if(last==4 || last==9) A[i][0]++;
	else if(last>5 && last<9) A[i][0]+=(last-5);
	if(last>3&&last<9)A[i][1]++;
	else if(last==9)A[i][2]++;
	last=((i/10)%10);
	if(last>0 && last<4) A[i][2]+=last;
	else if(last==4 || last==9) A[i][2]++;
	else if(last>5 && last<9) A[i][2]+=(last-5);
	if(last>3&&last<9)A[i][3]++;
	else if(last==9)A[i][4]++;
}

int main(){
	int N;
	for(int j=0;j<5;j++) A[0][j] = 0;
	for (int i=1; i<101; i++) {
		for(int j=0;j<5;j++) A[i][j] = A[i-1][j];
		translate(i);
	}
	while (cin>>N && N ) {
		cout<<N<<": "<<A[N][0]<<" i, "<<A[N][1]<<" v, "<<A[N][2]<<" x, "<<A[N][3]<<" l, "<<A[N][4]<<" c"<<endl;
	}
}