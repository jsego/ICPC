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
int A[15]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987};//millas
int B[15]={2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};//km
float D[1001];
int T[1001];
int main(){
	for (int i=0; i<1001; i++) {
		D[i] = i*1.6f; T[i] = 0;
	}
	for (int i=1; i<1001; i++) {
		float expe = i*1.6f,min=10000.0f;
		int pos=-1;
		for (int j=0; j<15 && A[j]<=i; j++) {
			if ( float(T[i-A[j]]+B[j]) < min+expe ) {
				min = fabs(T[i-A[j]]+B[j]-expe);
				pos = j;
			}
		}
		D[i] = min;
		T[i] = T[i-A[pos]]+B[pos];
	}
	int n;
	scanf("%d",&n);
	while (n) {
		printf("%.2f\n",D[n]);
		scanf("%d",&n);
	}
}