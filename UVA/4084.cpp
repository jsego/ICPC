#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX_DBL 2000000000
#define MIN_DBL -2000000000
int main(){
	double A[6],sum=0,min=MAX_DBL,max=MIN_DBL;
	bool ok=false;
	for (int i=0; i<6; i++) {
		cin>>A[i]; ok|=(A[i]!=0.0);
		sum+=A[i];
		min = MIN(min,A[i]);
		max= MAX(max,A[i]);
	}
	while (ok) {
		cout<<(sum-min-max)/4.0<<endl;
		ok=false; sum = 0; min=MAX_DBL; max = MIN_DBL;
		for (int i=0; i<6; i++) {
			cin>>A[i]; ok|=(A[i]!=0.0);
			sum+=A[i];
			min = MIN(min,A[i]);
			max= MAX(max,A[i]);
		}
	}
	
}