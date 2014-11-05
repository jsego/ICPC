
#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string s;
	int D, P, S[10001];
	for ( getline( cin, s ); cin; getline( cin, s ) ) {
		istringstream is( s );
		is >> D >> P;

		int i = -1, k = -1;
		while ( is >> S[++i] )
			if ( k < 0 && P < S[i] ) k = D - i + 1;
		if ( i < D ) {
			int A, B;
			if ( S[i-2]*S[i-4] == S[i-3]*S[i-3] ) A = 0;
			else A = ( S[i-1]*S[i-4] - S[i-2]*S[i-3] ) / ( S[i-2]*S[i-4] - S[i-3]*S[i-3] );
			if ( S[i-3] == 0 ) B = 0;
			else B = ( S[i-1] - A*S[i-2] ) / S[i-3];
			for ( ; i < D; ++i ) {
				S[i] = A*S[i-1] + B*S[i-2];
				if ( k < 0 && P < S[i] ) k = D - i + 1;
			}
		}
		if ( k < 0 ) cout << "The spider may fall!\n";
		else if ( k > D ) cout << "The spider is going to fall!\n";
		else cout << k << "\n";
	} 
}
