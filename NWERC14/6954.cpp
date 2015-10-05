#include<iostream>
#include<cmath>
using namespace std;

#define THRESH 0.0000000000000001
#define INF 45.0

int main(){
	cout.setf( ios::fixed );
	cout.precision( 10 ) ;
	int n;
	long double p, s, v;
	while( cin >> n >> p >> s >> v ){
		long double minc = THRESH, maxc = INF, midc;
		long double left, right = (s*p*pow10(9))/ (v * n * sqrt(2.0) * log(log2(n)));
		long double base = log2(n), s2 = sqrt(2.0);
		while( minc + THRESH < maxc ){
			midc = (maxc + minc)/2.0;
			left = midc*midc*(pow(base, midc*s2));
			if( left  < right ) minc = midc;
			else maxc = midc;
		}
		cout << n*pow(log2(n),minc*s2)/(p*pow10(9)) + (s*minc + s)/(v*minc) << " " << minc << endl;
	}
}
