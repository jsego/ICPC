
#include <iostream>

using namespace std;

int main() {
	int C;
	cin >> C;
	for ( int i = 1; i <= C; ++i ) {
		string s, t;
		cin >> s >> t;
		
		int fp = 0, fn = 0, qp = 0, qn = 0;
		for ( unsigned j = 0; j < s.size(); ++j ) {
			if ( s[j] == '0' && t[j] == '1' ) fp++;
			if ( s[j] == '1' && t[j] == '0' ) fn++;
			if ( s[j] == '?' && t[j] == '1' ) qp++;
			if ( s[j] == '?' && t[j] == '0' ) qn++;
		}

		int m = fp < fn ? fn : fp;
		int res = fp + qp < fn ? -1 : qp + qn + m;
		cout << "Case " << i << ": " << res << "\n";
	}
}
