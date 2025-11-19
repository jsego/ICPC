#include <bits/stdc++.h>

using namespace std;

int main(){
	long long R, d;
	int N;
	while(cin >> R){
		long long from_left = 0;
		long long from_right = R;
		cin >> N;
		for(int i=0; i<N; ++i){
			cin >> d;
			from_left += d;
			from_right += d;
			if(from_left < 0) from_left = 0;
			else if(from_left > R) from_left = R;
			if(from_right < 0) from_right = 0;
			else if(from_right > R) from_right = R;
		}
		if(from_left != from_right) cout << "uncertain\n";
		else cout << from_left << '\n';
	}
}
