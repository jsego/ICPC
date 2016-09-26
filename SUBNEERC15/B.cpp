#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int N, aux; cin >> N;
	vector<pair<int,int> > vp(N);
	for(int i = 0;i<N;i++){
		cin >> vp[i].first >> vp[i].second;
		aux = max( vp[i].first , vp[i].second );
		vp[i].first = min( vp[i].first , vp[i].second );
		vp[i].second = aux;
	}

	sort( vp.begin() , vp.end() );

	long long best_w = 0, best_h = 0, best_area = 0;
	long long cw, current_area;
	for(int i = 0; i < N; i++){
		cw = vp[i].first; 
		int total = N-i;
		vector< int > vi;
		for(int j = i; j < N; j++){
			vi.push_back( vp[j].second );
		}
		sort( vi.begin() , vi.end() );
		for(int j = 0; j < int( vi.size() ); j++){
			current_area = cw * vi[j] * ( total - j );
			if( current_area > best_area ){
				best_area = current_area;
				best_w = cw; best_h = vi[j];
			}
		}
	}
	
	cout << best_area << endl << best_w << " " << best_h << endl;
}
