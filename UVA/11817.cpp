/*
*  Javier Segovia
*  Accepted in 0.020
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))

int main(){
	int kases; cin>>kases;
	double pi = 3.14159265358979323846;
	double r = 6371009;
	while (kases--) {
		double lat1,lat2,long1,long2;
		cin>>lat1>>long1>>lat2>>long2;
		lat1 = pi*lat1/180.0;
		lat2 = pi*lat2/180.0;
		long1 = pi*long1/180.0;
		long2 = pi*long2/180.0;
		double logdist = fabs(long1-long2);
		double alpha = acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(logdist));
		alpha = MIN(alpha,acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(2*pi-logdist)));
		//cout<<alpha<<endl;
		unsigned long long arco = (unsigned long long)(r*alpha - 2*r*sin(alpha/2.0) + 0.5);
		cout<<arco<<endl;
	}
}