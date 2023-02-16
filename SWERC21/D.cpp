
#include <bits/stdc++.h>

using namespace std;

string U, V, W;

void simplify(string & s) {
	while (s != W) {
		W = s;
		for (int i = s.find("AA"  ); i != string::npos; i = s.find("AA"  )) s.replace(i, 2, ""   );
		for (int i = s.find("BB"  ); i != string::npos; i = s.find("BB"  )) s.replace(i, 2, ""   );
		for (int i = s.find("CC"  ); i != string::npos; i = s.find("CC"  )) s.replace(i, 2, ""   );
		for (int i = s.find("ABAB"); i != string::npos; i = s.find("ABAB")) s.replace(i, 4, ""   );
		for (int i = s.find("BCBC"); i != string::npos; i = s.find("BCBC")) s.replace(i, 4, ""   );
		for (int i = s.find("BA"  ); i != string::npos; i = s.find("BA"  )) s.replace(i, 2, "AB" );
		for (int i = s.find("CB"  ); i != string::npos; i = s.find("CB"  )) s.replace(i, 2, "BC" );
		for (int i = s.find("CAB" ); i != string::npos; i = s.find("CAB" )) s.replace(i, 3, "BCA");
	}
}

int main() {
	int T; cin >> T;
	while (T--) cin >> U >> V, simplify(U), simplify(V), cout << (U == V ? "YES\n" : "NO\n");
}

