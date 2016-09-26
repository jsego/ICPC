#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int F[10][12];

long double getScore( vector<bool> &c ){
	vector<int> v(12, 0);
	long double res = 1.0;

	for(int i=0;i<10;i++){
		if( c[i] ){
			for(int j = 0; j < 12; j++)
				v[j] = max( v[j], F[i][j] );
		}
	}

	for(int i = 0; i < 12; i++)
		res *= pow((long double)v[i], 1.0/12.0 );

	return res;
}

int main(){
	int kases; cin >> kases;
	while( kases-- ){
		for(int i=0;i<10;i++)
			for(int j=0;j<12;j++)
				cin >> F[i][j];
		vector<bool> best(10, false);
		vector<bool> curr(10, false);
		long double best_score = -1.0, current_score;
		for(int i = 5; i < 10; i++) {
			curr[i] = best[i] = true;
		}

		do{
			current_score = getScore( curr );
			if( current_score >= best_score ){
				best_score = current_score;
				best = curr;
			}
		}while(next_permutation( curr.begin() , curr.end() ) );

		bool first = true;
		for(int i=0;i<10;i++){
			if( best[i] ){
				if( first ){ cout << i+4; first = false;}
				else cout << " " << i+4;
			}
		}cout<<endl;
	}
}
