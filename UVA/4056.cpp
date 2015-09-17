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
#define MIN(a,b) ((a)<(b)?(a):(b))
void printi(string &s,int xi,int yi,int xf,int yf){
	xi--; yi--; int mid =(int)s.LE,tot,ch,x,y; tot=(mid<<1)-2;
	for (int i=xi; i<xf; i++) {
		for (int j=yi; j<yf; j++) {
			if(i<mid) x=i;
			else x=tot-i;
			if(j<mid) y=j;
			else y=tot-j;
			ch = MIN(x,y);
			printf("%c",s[ch]);
		}
		printf("\n");
	}
}

int main(){
	int kases,Q; scanf("%d",&kases);kases++;
	string s;
	for(int k=1;k<kases;k++) {
	//	if(k>1)printf("\n");
		cin>>s>>Q;
		int xi,yi,xf,yf;
		printf("Square %d:\n",k); Q++;
		for (int i=1; i<Q; i++) {
			printf("Query %d:\n",i);
			scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
			printi(s,xi,yi,xf,yf);
		}
		printf("\n");
	}
}