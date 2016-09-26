#include<iostream>
#include<vector>
#include<sstream>

using namespace std;
int A[ 10 ];

long long fillfrom( vector< int > &v, int p ){
	for( int i = 9; p < int(v.size()) && i >= 0; i-- ){
		for( int j = 0; p < int(v.size()) && j < 2; j++ ){
			if( A[ i ] < 2 ){
				v[ p ] = i; A[ i ]++; p++;
			}
		}
	}
	if( p < int(v.size() ) )
		return -1;
	long long res = 0;
	for( int i = 0; i < int( v.size() ); i++ ){
		res = (res * 10 + v[ i ] );
	}
	return res;
}

long long sol( vector<int> &v, int p ){
	long long res = 0;
	if( int( v.size() ) == p ){
		for( int i = 0; i < p; i++ ){
			res = (res * 10 ) + v[ i ];
		}
		return res;
	}
	res = -1; 
	int orig = v[ p ];
	for( int i = v[ p ]; i>=0; i-- ){
		if( A[ i ] == 2 ) continue;
		else if( i < orig ){
			v[ p ] = i;
			A[ i ]++;
			res = fillfrom( v, p+1 );
			A[ i ]--; break;
		}
		else{
			A[ i ]++;
			res = sol(v,p+1); 
			if( res != -1)
				break;
			A[ i ]--;
		}
	}
	return res;
}

int main(){
	long long ac;
	while( cin >> ac ){
		for( int i = 0; i < 10; i++ ) A[ i ] = 0;
		stringstream ss;
		ss <<  ac ;
		string s = ss.str();
		vector< int > v;
		for( int i = 0; i < int(s.length()); i++ )
			v.push_back( int(s[ i ]-'0') );
		long long res = sol( v, 0 );
		if( res == -1 ){
			res = 0;
			for( int i = 9; i >= 0; i-- ){
				for( int j = 0; j < 2; j++ ){
					if( res*10 + i > ac ) break;
					res = (res*10) + i;
				}
				if( res*10 + i > ac ) break;
			}
		}
		cout << res << endl;
	}
	
}
