/*
*  Javier Segovia
*  Accepted in 0.052
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
int A[155];

void calc(int n){
	for(int m=2;;m++){
		vector<int> v(n,0);
		for (int i=0; i<n ; i++) {
			v[i] = i;
		}
		int ac=0;
		while (v[ac]!= 1 && int(v.SL) > 1) {
			v.erase(v.begin()+ac);
			ac = (ac+m-1)%int(v.SL);
		}
		if(int(v.SL) == 1 && v[0] == 1){ 
			A[n] = m; 
			return;
		}
	}
}

int main(){
	int N;
	for (int i=3; i<151; i++) {
		calc(i);
		//if(i<10) cout<<A[i]<<endl;
	}
	while (scanf("%d",&N),N ) {
		printf("%d\n",A[N]);
	}
}