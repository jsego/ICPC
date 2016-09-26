#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;



int main(){
	int kases, N; 
	cin >> kases;
	while( kases-- ){
		cin >> N;

		long long canvas;
		priority_queue< long long , vector< long long > , greater< long long > > pq;

		for(int n = 0; n < N; n++){
			cin >> canvas;
			pq.push( canvas );
		}

		long long res = 0;
		while( pq.size() > size_t( 1 ) ){
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			pq.push( a + b );
			res += (a + b);
		}

		cout << res << endl;
	}
}
