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

int main(){
	int kases; scanf("%d",&kases);
	while (kases--) {
		double a,b,c,a1,b1,c1,s,r1,r2,r3;
		double A,B,C,res;
		
		scanf("%lf %lf %lf",&a,&b,&c);
		
		r1 = a+b;
		r2 = a+c;
		r3 = b+c;
		
		s = (r1+r2+r3)/2;
		res = sqrt(s*(s-r1)*(s-r2)*(s-r3));
		
		C = fabs(acos((r1*r1 - r2*r2 - r3*r3)/(-2*r2*r3)));
		B = fabs(acos((r2*r2 - r1*r1 - r3*r3)/(-2*r1*r3)));
		A = fabs(acos((r3*r3 - r2*r2 - r1*r1)/(-2*r2*r1)));
		
		a1 = a*a*A/2;
		b1 = b*b*B/2;
		c1 = c*c*C/2;
		
		res -=  (a1+b1+c1);
		printf("%.6f\n",fabs(res));
	}
}