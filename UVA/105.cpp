/*
*  Javier Segovia
*  Accepted in 0.036
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
#define MAX(a,b) ((a)>(b)?(a):(b))
int A[10001];
int main(){
	for (int i=0; i<10001; i++) {
		A[i] = 0;
	}
	int x,y,alt;
	while (cin>>x>>alt>>y) {
		for (int i=x; i<y; i++) {
			A[i] = MAX(A[i],alt);
		}
	}
	int last=0; x=0;
	while(A[x]==0) x++;
	cout<<x<<" "<<A[x]; last=A[x++];
	for (; x<10001; x++) {
		if (A[x]!=last) {
			cout<<" "<<x<<" "<<A[x];
			last = A[x];
		}
	}cout<<endl;
}