/*
*  Javier Segovia
*  Accepted in 0.016
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
short A[101];
int main(){
	int kases; cin>>kases;
	cout.setf(ios::fixed);
	cout.precision(3);
	while (kases--) {
		int C; cin>>C; int tot=0;
		for(int i=0;i<C;i++){
			cin>>A[i];
			tot+=A[i];
		}
		int cant=0;
		for (int i=0; i<C ; i++) {
			if (C*A[i]>tot) {
				cant++;
			}
		}
		double res = (double)(cant+0.000000001)/(double)(C+0.000000001);
		res*=100.0;
		cout<<res<<"%"<<endl;
	}
}