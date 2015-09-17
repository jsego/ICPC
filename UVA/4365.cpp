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

int bin(int a,int b){
	int dif = a-b;
	int res=1;
	for (int i=a; i>MAX(dif,b); i--) {
		res*=i;
	}
	for (int i=MIN(dif,b); i>1; i--) {
		res/=i;
	}
	return res;
}

int main(){
	int A,B;
	while (cin>>A>>B && (A!=-1 || B!=-1)) {
		if (A>10 || B>10) {
			cout<<A<<"+"<<B<<"!="<<A+B<<endl;
			continue;
		}
		int b = bin(A+B,B), c=A+B;
		cout<<A<<"+"<<B;
		if (c==b) {
			cout<<"="<<c;
		}
		else {
			cout<<"!="<<c;
		}
		cout<<endl;
	}
}