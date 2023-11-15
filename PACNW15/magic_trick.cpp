#include<bits/stdc++.h>

using namespace std;

bool is_messy(vector<string> &ops, vector<long long> &v, long long i){
	for(size_t l = 0; l < ops.size(); ++l){
		if(ops[l] == "DIVIDE"){
			if((i % v[l]) != 0) return true;
			i /= v[l];
		}
		else if(ops[l] == "ADD") i += v[l];
		else if(ops[l] == "MULTIPLY") i *= v[l];
		else if(ops[l] == "SUBTRACT"){
			if(i < v[l]) return true;
			i -= v[l];
		}
	}
	return false;
}

int main(){
	int N;
	while(cin >> N){
		vector<string> ops(N);
		vector<long long> v(N);
		for(int i=0; i<N; i++) cin>>ops[i]>>v[i];
		int res=0;
		for(long long i=1;i<101;i++){
			if(is_messy(ops, v, i))
				++res;
		}
		cout << res << "\n";
	}
}
