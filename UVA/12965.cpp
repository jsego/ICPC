#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
	int N; cin >> N;
	while( N-- ){
		int P, C;
		cin >> P >> C;
		vector< pair< int , bool > > vp(P+C,make_pair(0 , true) );
		for(int i = 0; i < P; i++){
			cin >> vp[i].first;
		}
		for(int i = 0; i < C; i++){
			cin >> vp[i+P].first;
			vp[i+P].second = false;
		}
		sort( vp.begin() , vp.end() );
		int res = P, bval = 0;
		int ap = P, ac = 0, lc = 0;
		for(int r = 0; r < P+C; ){
			int selected_val = vp[r].first;
			do{
				if( vp[r].second ) ap--;
				else ac++;
				r++;
			}while( r < P+C && vp[r].first == selected_val );
			if( ap + lc < res ){
				res = ap + lc; 
				bval = selected_val;
			}
			lc = ac;
		}
		cout << bval << " " << res << endl;
	}
}
