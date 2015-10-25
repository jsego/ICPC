#include<iostream>

using namespace std;

long long GCD(long long a, long long b ){
	if( b == 0) return a;
	return GCD( b, a%b );
}

int main(){
	long long v1, d1, v2, d2, kases = 1;
	while( cin >> v1 >> d1 >> v2 >> d2, v1 || d1 || v2 || d2 ){
		long long gcd1 = GCD( d1 , v1 );
		long long gcd2 = GCD( d2 , v2 );
		d1 /= gcd1; v1 /= gcd1;
		d2 /= gcd2; v2 /= gcd2;
		if( d1*v2 <= d2*v1 )
			cout << "Case #"<< kases << ": You owe me a beer!" << endl;
		else
			cout << "Case #"<< kases << ": No beer for the captain." << endl;
		long long num = d1 * v2 + d2 * v1;
		long long den = 2 * v1 * v2;
		long long gcd3 = GCD( num , den );
		num /= gcd3;
		den /= gcd3;
		cout << "Avg. arrival time: " << num ;
		if( den > 1 ) cout << "/" << den << endl;
		else cout << endl;
		kases++;
	}
}
