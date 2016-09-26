#include<iostream>
#include<cmath>
using namespace std;
int main(){
	unsigned long long lim = 44721359;
	for(unsigned long long x = 2; x < lim; x++){
		unsigned long long n, y;
		if(x & 1 ){
			n = x*x;
			y = sqrt((n+1)/2 );
			if(y*y != (n+1)/2 ){
				y = 0;
			}
		}
		else{
			n = x*x/2;
			y = sqrt(n + 1);
			if(y*y != n + 1){
				y = 0;
			}
		}
		unsigned long long z = n / x;
		if ( y && z * x == n ) {
			//cout << x << " " << y << " " << z << " " << n << "\n";
			cout << n << endl;
		}
	}
	
}
