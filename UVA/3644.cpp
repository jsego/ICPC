#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int mf[100002];
int sete(int n){
	if(mf[n] == n) return n;
	else mf[n] = sete(mf[n]);
	return mf[n];
}
int main(){
	int A,B;
	for (int i=0; i<100002; i++) {
		mf[i] = i;
	}
	while(cin>>A){
		int max=0,result=0;
		while (A!=-1 && cin>>B) {
			max = MAX(max,MAX(A,B));
			A = sete(A); B = sete(B);
			if(A == B)result++;
			else mf[A] = B;
			cin>>A;
		}
		cout<<result<<endl;
		for (int i=0; i<=max; i++) {
			mf[i] = i;
		}
	}
}