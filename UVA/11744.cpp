/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<bitset>
#include<limits>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int N;
	scanf("%d",&N);
	string a,b;
	for(int n=0;n<N;n++){
		if(n)cout<<endl;
		cin>>a>>b; 
		cout<<a<<" "<<b<<endl;
		unsigned int A=0,B=0,C,D;
		for (int i=30,j=1; i>=0; i--,j<<=1) {
			if(a[i] == '1') A=(A|j);
			if(b[i] == '1') B=(B|j);
		}
		while (B) {
			D = A&B; 
			C = A^B;
			if(D&(1<<30)){ 
				cout<<bitset<31>(C);
				printf(" overflow\n");
				break;
			}
			else{ D<<=1;
				cout<<bitset<31>(C)<<" "<<bitset<31>(D)<<endl;
			}		
			A = C; B = D;
		}
	}
}