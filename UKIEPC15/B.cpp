#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
	cout.setf( ios::fixed );
	cout.precision( 6 );
	int N;
	double g;
	cin >> N >> g;
	int D, theta;
	vector< pair< int , double > > vp;
	for(int n = 0; n < N; n++){
		cin >> D >> theta;
		vp.push_back( make_pair( D , g * cos( double(theta) * 2.0 * M_PI / 360.0 )) );
	}
	vector< double > res;

	// D = vo * it + 0.5 * a * it^2
	// it = ((-vo) +- sqrt( vo*vo + 4 * 0.5 * a * D ) ) / (2 * 0.5 * a );
	// it = ((-vo) +- sqrt( vo^2 + 2 * a * D ) ) / a ;
	// vf = vo + it * a;

	for(int n = 0; n < N; n++){
		double vo = 0.0, vf = 0.0;
		for(int n2 = n; n2 < N; n2++){
			vo = vf = sqrt( vo * vo + 2.0 * vp[ n2 ].first * vp[ n2 ].second );
		}
		res.push_back( vf );
	}

	for(int n = 0; n < N; n++)
		cout << res[n] << endl;
}
