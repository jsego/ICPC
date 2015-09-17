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
	unsigned int A,B;
	while (cin>>A>>B ) {
		unsigned int lim=1,res=0;
		bool b1,b2;
		for(int i=0;i<32;i++){
			b1=A&lim; b2=B&lim;
			if(b1!=b2)res|=lim;
			lim<<=1;
		}
		cout<<res<<endl;
	}
}