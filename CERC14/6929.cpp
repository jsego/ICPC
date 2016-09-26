#include<iostream>

using namespace std;

int main(){
	// a*x + sum(x-1) == N
	// a*x + (x*(x-1)/2) == N
	// 2a*x + x*(x-1) == 2*N
	// x^2 + x*(2a-1) == 2*N
	// x^2 + x*(2a-1) - 2*N == 0
	// x = ( (1-2a) +- sqrt( (2a-1) - 4*1*(-2N) ) ) / 2*1
	// a == (2N - x*(x-1) ) / 2x

	int kases;
	cin >> kases;
	while( kases-- ){	
		int N; cin >> N;
		int x = 2, a = -1, sumx;
		while(true){
			sumx = x*(x-1)/2;
			if( sumx > N ) break;
			if( (N-sumx)%x == 0 ){
				a = (N-sumx)/x;
				break;
			}
			x++;
		}
		if( a < 1 ) cout << "IMPOSSIBLE" << endl;
		else{
			cout << N << " = "<<a;
			for(int i = a+1; i < a+x ; i++)
				cout << " + " << i;
			cout << endl;
		}
	}
}
