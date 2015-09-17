/*
*  Javier Segovia
*  Accepted in 0.184
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<string.h>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define INF 1000000000
int A[70000];
bool S[70000];
int bfs[100000];
int I,F;

int main(){
	int N; cin>>N;
	while (N--) {
		int ac=0,tot=0,min = INF,num,st,ori;
		int a,b,c,d,na,nb,nc,nd;
		for(a=0;a<10;a++) for(b=0;b<10;b++) for(c=0;c<10;c++) for(d=0;d<10;d++){
			num = (a<<12) | (b<<8) | (c<<4) | d;
			S[num] = false;
			A[num] = INF;
		}
		cin>>a>>b>>c>>d;
		I = (a<<12) | (b<<8) | (c<<4) | d;
		cin>>a>>b>>c>>d;
		F = (a<<12) | (b<<8) | (c<<4) | d;
		int seens; cin>>seens;
		while (seens--) {
			cin>>a>>b>>c>>d;
			num = (a<<12) | (b<<8) | (c<<4) | d;
			//cout<<"INC: "<<num<<" I: "<<I<<" F: "<<F<<endl;
			S[num] = true;
			A[num] = -1;
		}
		bfs[tot++] = I; bfs[tot++] = 0;
		//cout<<"I: "<<I<<" F: "<<F<<endl;
		if(I == F){
			printf("0\n"); 
			continue;
		}
		S[I] = true;
		while (ac<tot) {
			ori = bfs[ac++]; st = bfs[ac++]; 
			a = (ori>>12); 
			b = (ori>>8)&15; 
			c = (ori>>4)&15; 
			d = (ori)&15;
		//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			na = a+1; if(na == 10) na=0;
			num = (ori&4095)|(na<<12);
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}
			na = a-1; if(na == -1)na = 9;
			num = (ori&4095)|(na<<12);
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}
			
			nb = b+1; if(nb == 10) nb=0;
			num = (ori&61695)|(nb<<8);
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}			
			nb = b-1; if(nb == -1) nb=9;
			num = (ori&61695)|(nb<<8);
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}
			
			nc = c+1; if(nc == 10) nc=0;
			num = (ori&65295)|(nc<<4);
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}
			nc = c-1; if(nc == -1) nc=9;
			num = (ori&65295)|(nc<<4);
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}
			
			nd = d+1; if(nd == 10) nd=0;
			num = (ori&65520)|nd;
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}
			nd = d-1; if(nd == -1) nd=9;
			num = (ori&65520)|nd;
			if(!S[num]){
				S[num] = true; 
				if(num!=F){
					bfs[tot++] = num; 
					bfs[tot++] = st+1;
				}
				else {
					min = st+1; break;
				}
			}
			
		}
		printf("%d\n",(min==INF?-1:min)); //cout<<endl;
	}
}