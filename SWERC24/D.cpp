#include <bits/stdc++.h>

using namespace std;

pair<long long,int> A[200001];

int main(){
	int N;
	while(cin >> N){
		long long h;
		for(int i=0; i<N; ++i){
			scanf("%lld", &h); // required to avoid TLE
			A[i] = make_pair(h, i);
		}
		sort(A, A+N);
		
		set<int> locations;
		locations.insert(A[N-1].second);
		int res = 0; // long long?
		for(int i=N-2, d; i>=0; --i){
			auto it = locations.insert(A[i].second);
			d= 200001; //inf value
			++it.first;
			if(it.first != locations.end()){ // right dir
				d = min(d, (*it.first) - A[i].second);
			}
			--it.first;
			if(it.first != locations.begin()){ // left dir
				--it.first;
				d = min(d, A[i].second - (*it.first));
			}
			res += d;
		}
		cout << res << '\n';
	}
}
