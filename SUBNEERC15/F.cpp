#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

#define X first
#define Y second

//Dedicated time for each dish
int T[102];

bool achievable( vector<pair<int,pair<int,int> > > &v, int t ){
	for(int i = 0; i < 102; i++) T[i] = 0;
	//cout << t << endl;
	for(int i = 0; i < 10001; i++){
		int best_dish = -1;
		for(int j = 0; j < int(v.size()); j++){
			if( T[j] < t && v[j].Y.Y == i )
				return false;
			if( ( v[j].Y.X <= i ) && ( i < v[j].Y.Y ) && 
				( T[j] < t ) && ( best_dish == -1 || v[j].Y.Y <= v[best_dish].Y.Y ) )
				best_dish = j;
		}
		//cout << t << " " << i << " " << best_dish << endl;
		T[ best_dish ]++;
	}
	/*for(int i = 0; i < int(v.size()); i++){
		int cant = t;
		for(int j = v[i].Y.X ; j < v[i].Y.Y && cant > 0; j++){
			if( !R[j] ){
				R[j] = true; cant--;
			}
		}
		if( cant > 0 )
			return false;
	}*/
	return true;
}

int main(){
	int N; cin >> N;
	vector<pair< int , pair<int,int> > > vp(N);
	int mini = 1000000000;
	for(int n = 0; n < N; n++){
		cin >> vp[n].Y.X >> vp[n].Y.Y;
		vp[n].X = abs( vp[n].Y.Y - vp[n].Y.X );
		mini = min( mini , vp[n].X );
	}
	//sort( vp.begin() , vp.end() );
	int tmax = mini, tmin = 0, tmid;
	while( tmin < tmax ){//given time
		tmid = (tmax+tmin+1)/2;
		if( achievable( vp , tmid ) ){
			tmin = tmid;
		}
		else{
			tmax = tmid-1;
		}
	}
	cout << tmin * N << endl;
}
