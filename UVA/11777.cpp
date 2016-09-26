/*
*  Javier Segovia
*  Accepted in 0.012
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
int max3(int a,int b,int c){
	int max=0;
	if(a>=b){
		max=a;
		if(b>=c) max+=b;
		else max+=c;
	}
	else {
		max=b;
		if(a>=c) max+=a;
		else max+=c;
	}

	return max;
}
int main(){
	int t1,t2,final,att,c1,c2,c3;
	char c;
	int kases; cin>>kases; kases++;
	for (int i=1; i<kases; i++) {
		cin>>t1>>t2>>final>>att>>c1>>c2>>c3;
		//int tot = 2*(t1+t2+final+att)+max3(c1,c2,c3);
		double tot = t1+t2+final+att+(max3(c1,c2,c3)/2.0);
		if(tot>=90.0) c='A';
		else if(tot>=80.0) c='B';
		else if(tot>=70.0) c='C';
		else if(tot>=60.0) c='D';
		else c='F';
			
		/*if(tot>=180) c='A';
		else if(tot>=160) c='B';
		else if(tot>=140) c='C';
		else if(tot>=120) c='D';
		else c='F';*/
		printf("Case %d: %c\n",i,c);
	}
}