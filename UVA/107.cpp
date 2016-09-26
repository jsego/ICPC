/*
*  Javier Segovia
*  Accepted in 0.076
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ULL unsigned long long
#define UI unsigned int

UI a,b,n,x;

UI expo(UI b,UI e){
	if(b == 0) return 0;
	UI res = 1,base = b;
	while (e) {
		if(e&1){
			res*=base;
		}
		base*=base;
		e>>=1;
	}
	return res;
}

bool check(){
	ULL i=0,cont=0;
	for(i=1; i<b; i*=n) {cont++;}
	if(i>b) return false;
	ULL j=0;
	j = expo(n+1,cont);
	if(j == a){x = cont; return true;}
	return false;
}

int main(){
	while (scanf("%d %d",&a,&b),a||b) {
		UI sum ,lv ,last,count ;
		if(b == 1){
			sum = a + (a-1);
			count= -1;
			while(a){ count++; a>>=1;}
		}
		else{
			for(n = 2;n<65536;n++){
				if(check())
					break;
			}
		
			sum = a; lv = 1; last = a; count = 1;
			
			while (1) {
				lv*=n;
				if(lv >= b) break;
				last/=(n+1);
				sum += lv*last;
				count += lv;
			}
			if(b!=1) sum+=b;
		}
		printf("%d %d\n",count,sum);
	}
}