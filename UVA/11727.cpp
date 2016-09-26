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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int kases; cin>>kases;
	for (int i=1; i<=kases; i++) {
		int a,b,c,min,max,sum;
		cin>>a>>b>>c; sum = a+b+c;
		min = MIN(a,MIN(b,c));
		max = MAX(a,MAX(b,c))+min;
		cout<<"Case "<<i<<": "<<sum-max<<endl;
	}
}