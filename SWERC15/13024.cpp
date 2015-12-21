#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define SQ(a) ((a)*(a))
#define X first
#define Y second
#define SZ size()
#define PB push_back

typedef long long T;
typedef pair<T,T> P;

T xp(P p, P q, P r){
	return ( q.X - p.X ) * ( r.Y - p.Y ) - ( r.X - p.X ) * ( q.Y - p.Y );
}

struct Vect{
	P p, q;
	T dist;

	Vect( P &a, P &b ){
		p = a; q = b;
		dist = SQ( a.X - b.X ) + SQ( a.Y - b.Y );
	}

	bool operator<(const Vect &v) const{
		T t = xp( p, q, v.p );
		return t < 0 || ( t == 0 && dist < v.dist ) ;
	}
};

vector< P > convexhull( vector< P > v ){ // v.SZ >= 2
	sort( v.begin(), v.end() );
	vector< Vect > u;
	for(int i = 1; i < (int)v.SZ; i++){
		u.PB( Vect( v[ i ], v[ 0 ] ) );
	}
	sort( u.begin() , u.end() );
	vector< P > w( v.SZ , v[ 0 ] );
	int j = 1;
	w[ 1 ] = u[ 0 ].p;
	for(int i = 1; i < (int) u.SZ; i++){
		T t = xp( w[ j - 1 ], w[ j ], u[ i ].p );
		for( j--; t < 0 && j > 0; j-- )
			t = xp( w[ j - 1 ] , w[ j ], u[ i ].p );
		j += ( (t > 0) ? 2 : 1 );
		w[ j ] = u[ i ].p;
	}
	w.resize( j + 1 );
	return w;
}

bool check( P &a, vector< P > &w ){
	if( xp( w[ 0 ] , a , w[ int(w.SZ) - 1 ] ) < 0 )
		return false;
	for(int i = 1; i < int(w.SZ); i++){
		if( xp( w[ i ] , a , w[ i - 1 ] ) < 0 )
			return false;
	}
	return true;
}

int main(){
	int L, S;
	while( cin >> L ){
		vector< P > v( L );
		for(int l = 0; l < L; l++)
			cin >> v[ l ].X >> v[ l ].Y;

		vector< P > w = convexhull( v );

		cin >> S;
		P ac;
		int res = 0;
		for(int s = 0; s < S; s++){
			cin >> ac.X >> ac.Y;
			res += check( ac , w );
		}
		cout << res << endl;
	}
}
