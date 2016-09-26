#include<iostream>

using namespace std;

struct matrix{
	long long a11, a12, a21, a22;
	matrix(long long _a11,long long _a12,long long _a21,long long _a22):a11(_a11),a12(_a12),a21(_a21),a22(_a22){}
	long long expo( long long k ){
		long long a = a11, b = a12, c = a21, d = a22;
		long long ra = 1, rb = 0, rc = 0, rd = 1;
		while( k ){
			long long na, nb, nc, nd;
			if( k&1 ){
				//ra += a; rb += b; rc += c; rd += d;
				na = ( ra * a + rb * c )% 1000000000;
				nb = ( ra * b + rb * d )% 1000000000;
				nc = ( rc * a + rd * c )% 1000000000;
				nd = ( rc * b + rd * d )% 1000000000;
				ra = na; rb = nb; rc = nc; rd = nd;
			}
			na = ( a * a + b * c ) % 1000000000;
			nb = ( a * b + b * d ) % 1000000000;
			nc = ( c * a + d * c ) % 1000000000;
			nd = ( c * b + d * d ) % 1000000000;
			a = na; b = nb; c = nc; d = nd;
			k >>= 1;
		}
		return (rb) % 1000000000;
	}
};

int main(){
	int P; cin >> P;
	while( P-- ){
		long long K, Y;
		cin >> K >> Y;
		matrix m( 1, 1, 1, 0 );
		cout << K << " " << m.expo( Y ) << endl;
	}
}
