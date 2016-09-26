#include<iostream>

using namespace std;

int GCD(int a, int b ){
	if( b == 0 ) return a;
	return GCD( b , a%b );
}

int main(){
	int AB, AC, BD;
	while( cin >> AB >> AC >> BD ){
		int f1 = AB * AC;
		int f2 = BD - AC;
		int gcd = GCD( f1 , f2 ) ; 
		cout << (f1/gcd) << "/" << (f2/gcd) << endl;
	}
}
