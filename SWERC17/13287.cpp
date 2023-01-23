#include <bits/stdc++.h>

using namespace std;

int main(){
	int W, N;
	
	while(cin >> W >> N){
		long long area = 0;
		long long w_i, l_i;
		for(int i = 0; i < N; i++){
			cin >> w_i >> l_i;
			area += w_i*l_i;
		}	
		cout << (area / W) << "\n";
	}
}
