/*
*  Javier Segovia
*  Accepted in 0.064
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
int A[1001];
int main(){
	int n;
	while (cin>>n ) {
		for (int i=0; i<n; i++) {
			cin>>A[i];
		}
		int count=0;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n ; j++) {
				if (A[j]<A[i]) {
					count++;
				}
			}
		}
		cout<<"Minimum exchange operations : "<<count<<endl;
	}
}