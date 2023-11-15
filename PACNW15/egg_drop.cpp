#include<bits/stdc++.h>

using namespace std;

int main(){
	int N, K;
	while(cin >> N >> K){
		int lowest = 2, highest = K-1, current;		
		string res;
		for(int i = 0; i < N; i++){
			cin >> current >> res;
			if(res == "SAFE") lowest = max(lowest, current+1);
			else if(res == "BROKEN") highest = min(highest, current-1);
		}
		cout << lowest << " " << highest << "\n";
	}
}
