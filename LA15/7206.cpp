#include<iostream>

using namespace std;

int N, M;
int C[ 5 ] = {10000,1000,100,10,1};
int main(){
	while( cin >> N >> M ){
		int res = 0;
		for( int m = 0; m < M; m++ ){
			int B, D, c, tot = 0;
			cin >> B >> D;
			for( int i = 1; i < N; i++ ){
				cin >> c;
				tot += c;
			}
			int current = 0;
			if( tot + D <= B ){
				current = D;
			}
			for( int v = 10000; v > 0; v/=10 ){
				if( tot + v <= B ){
					res += (v - current);
					break;
				}
			}
		}
		cout << res << endl;
	}
}
