#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int A[100005],x[100005],y[100005],c[100005],d[100005];

int main(){
	int kases; 
	cin>>kases; 
	bool first=true;
	while( kases-- ){
		if(first) first=false;
		else cout<<endl;
		int C, N, B, k, sum;
		cin >> C >> N; 
		A[0]=0; d[0]=0;
		for( int l = 1; l <= N; l++){
			cin >> x[ l ] >> y[ l ] >> c[ l ];
			B = c[ l ]; 
			k = l - 1;
			A[ l ] = A[ l - 1 ] + 2*( x[ l ] + y[ l ] );
			d[ l ] = abs( x[ l ] - x[ l - 1 ]) + abs( y[ l ] - y[ l - 1 ]);
			while( k > 0 ){
				B += c[ k ]; 
				if(B > C) break;
				sum = A[ k - 1 ] + x[ k ] + y[ k ];
				for(int i = k + 1; i <= l; i++) 
					sum += d[ i ];
				sum += x[ l ] + y[ l ];
				k--;
				A[l] = min( A[ l ] , sum );
			}
		}
		cout<< A[ N ] <<endl;
	}
}
