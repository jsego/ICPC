#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(n == 1) cout << "50 60 70\n";
		else if(n == 2) cout << "3 7 91\n";
		else if(n < 10) cout << "98 99 100\n";
		else cout << "1 2 3\n";
	}
}
