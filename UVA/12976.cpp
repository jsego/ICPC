#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define X first
#define Y second
#define T long double
int N, K;

int main(){
	cout.setf( ios::fixed );
	cout.precision( 6 );
	int kases = 1;
	while( cin >> N >> K , N || K){
		vector<pair< T ,T> > vs(N);
		vector<pair< T , pair< T , T> > > vp(N - K + 1);
		for(int i = 0; i < N ; i++)
			cin >> vs[i].X >> vs[i].Y;

		sort( vs.begin() , vs.end() );
		
		T sumK = 0.0;
		for(int k = 0; k + 1 < K; k++){
			sumK += vs[k].X;
		}

		for(int j = K-1, i = 0; j < N ; j++, i++){
			vp[i].X = vs[j].Y / vs[j].X ;
			vp[i].Y.X = vs[j].X;
			vp[i].Y.Y = vs[j].Y;
		}

		long double res = -1.0, acres;

		for(int i = 0; i < int(vp.size()); i++){			
			acres = (vp[i].Y.X + sumK) * vp[i].X;
			if( res < 0.0 )
				res = acres;
			else if( acres < res )
				res = acres;
		}

		cout << "Case #" << kases++ << ": " << res << endl;
	}
}
