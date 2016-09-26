#include<iostream>
#include<vector>
using namespace std;

int main(){
	int P; cin >> P;
	while( P-- ){
		int K, p, q; 
		char c;
		cin >> K >> p >> c >> q;
		//cout <<  K << " " << p << " " << c << " " << q << endl;
		vector< bool > v;
		while( p != 1 || q != 1 ){
			//cout << p << " " << q << endl;
			if( q > p ){ // is left child
				q -= p;
				v.push_back( true );
			}
			else{ // is right child;
				p -= q;
				v.push_back( false );
			}
		}
		if( int(v.size()) == 0 ){
			cout << K << " 1" << endl; continue;
		}
		long long count = (1LL << int(v.size()));
		long long half = (1LL << int(v.size()-1));

		for( int i = int(v.size()) - 1; i >= 0; i-- ){
			if( !v[ i ] ){
				count += half;
			}
			half/=2;
		}
		cout << K << " " << count << endl;
	}
}
