#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int C[30000];
int RES[30000];
bool P[30000][5];
int V[5];
int main(){
	for (int i=0; i<10001; i++) {
		C[i] = RES[i] = 0;
		for (int j=0; j<5; j++) {
			P[i][j] = true;
		}
	}
	C[0] = 6;
	RES[0] = 1;
	for (int i=0; i<5; i++) {
		V[i] = 0;
	}
	V[0]++;
	for (int i=1; i<7; i++) {
		C[i] = 1; P[i][0] = false;
	}
	int last=6,max,num;
	for (int i=1; i<10001; i++) {
		max=1000000; num=-1;
		for (int j=0; j<5; j++) {
			if(P[i][j]){
				if (V[j] < max) {
					max=V[j];
					num = j;
				}
			}			   
		}
		RES[i] = num+1;
		V[num]++;
		P[i+1][num] = false;
		C[i+1]++;
		for (int j=C[i]+1; j<6; j++) {
			P[last][num]=false;
			C[last]++;
			last++;
		}last--;		
	}
	int kases; scanf("%d",&kases);//cin>>kases;
	while (kases--) {
		//cin>>num;
		//cout<<RES[num-1]<<endl;
		scanf("%d",&num);
		printf("%d\n",RES[num-1]);
	}
}