#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define PII pair< long long , int >
#define MP make_pair
#define PB push_back

long long res[2005];

bool comp_funct( PII a , PII b ){ return a.first < b.first ;}

long long simulate( vector< PII > &v , size_t p, int s, int t, int n) {
	long long total_time = t; // starts picking first knapsack time
	long long current_time = v[p].first ;
	vector< PII >::iterator it = ( v.begin() + p );

	while(--n){
		(it->second)--;

		if( (it->second) == 0 ) v.erase( it );

		current_time = ( current_time + t ) % s;
		it = lower_bound( v.begin() , v.end() , make_pair( current_time , 0 ) , comp_funct);
		if( it == v.end() ){
			it = v.begin();
			total_time += ( it->first ) + (s - current_time) + t;
		}
		else{
			total_time += ( (it->first) - current_time + t);
		}
		current_time = it->first;		
	}
	return total_time;
}

long long gcd( long long a, long long b ){
	if( b == 0) return a;
	return gcd( b, a%b);
}

int main(){
	int N, S, T;
	while( cin >> N >> S >> T ){
		vector< int > knapsacks(N);
		for(int n = 0; n < N ; n++) cin >> knapsacks[n];
		sort( knapsacks.begin(), knapsacks.end() );

		PII ac = MP( 0 , 1 );
		PII past = MP( 0 , 0 );
		vector< PII > v;
		vector< long long > gaps;

		// Saving knapsacks in a compact way
		for(int n = 0; n < N ; n++){
			ac.first = knapsacks[n];
			if( ac.first != past.first ){
				if( past.second != 0 ){
					v.PB( past );
				}
				past = ac;
			}
			else{
				past.second++;
			}
		}
		if( past.second != 0 ){
			v.PB( past );
		}

		// Calculating gaps between knapsacks
		gaps.push_back( (S - v[int(v.size())-1].first) + v[0].first ) ;
		for(int n = 1; n < int(v.size()) ; n++){	
			gaps.push_back( v[n].first - v[n-1].first );
		}

		// Searching best, worst and avg case
		long long mini = 1000000000000000000LL, maxi = -1, avgtop = 0, avgden = S, avggcd ;
		for(size_t n = 0; n < v.size(); n++){
			vector< PII > aux = v;
			res[n] = simulate( aux , n , S, T, N);
			mini = min( res[n] , mini );
			maxi = max( res[n] + gaps[n] - 1 , maxi );
			avgtop += (gaps[n] * res[n]) + ( ( gaps[n] - 1 ) * gaps[n] / 2) ;
		} 
		avggcd = gcd( avgtop, avgden );
		
		cout << mini << endl << maxi << endl << avgtop / avggcd << "/" << avgden / avggcd << endl;
		
		
	}
}
