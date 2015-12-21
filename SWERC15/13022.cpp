#include<iostream>
#include<set>

using namespace std;

#define LIM 64

int main(){
	set< long long > S;
	long long base = 0, base2;
	for(int a = 1; a < LIM; a++){
		base = (base << 1)|1;
		for(int b = 0; b+a < LIM; b++){
			base2 = (base << b);
			int c = a+b;
			while( c < LIM ){
				S.insert( base2 );
				if( c + a < LIM ){
					base2 = (base2 << a ) | base;
					S.insert( base2 );
					c += a;
				}
				else break;
				if( c + b < LIM ){
					base2 = (base2 << b );
					S.insert( base2 );
					c += b;
				}
				else break;
			}
		}
	}
	long long X, Y;
	while( cin >> X >> Y ){
		int res = 0;
		for( set< long long >::iterator it = S.begin(); it != S.end(); it++)
			if( X <= *it && *it <= Y)
				res++;
		cout << res << endl;
	}
}
