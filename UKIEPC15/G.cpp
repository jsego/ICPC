#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define X first
#define Y second

int T[1001][1201]; // m - u
pair<int,int> F[1001][1201];
vector< pair< pair< int , int > , string > > vp;
int R[10];

int main(){
	double m, u, price;
	int d, st;
	string name, sz;
	cin >> m >> u >> d;
	for(int i = 0; i < d; i++){
		R[ i ] = 0;
		cin >> name >> st >> sz >> price;
		st = ( st * 60 ) / (sz[2] - '0');
		vp.push_back( make_pair( make_pair( int(price*100.0000000001) , st ) , name ) );
//cout << vp[i].Y << " (" << vp[i].X.X << "," << vp[i].X.Y << ")" << endl;
	}

	int M = int(m*100.0000000001), U = int(u*60.0000000001);
//cout << M << " " << U << endl;
	for(int i = 0; i < d; i++)
		R[ i ]  = 0;
	for(int i = 0; i <= M; i++)
		for(int j = 0; j <= U; j++){
			T[ i ][ j ] = -1;
			F[ i ][ j ] = make_pair( -1 , -1 );
		}
	T[ 0 ][ 0 ] = 9;

	int ni, nj;
	for( int i = 0; i <= M; i++ ){
		for( int j = 0; j <= U; j++ ){
			for( int k = 0; k < d; k++ ){
				ni = i - vp[ k ].X.X;
				nj = j - vp[ k ].X.Y;
				if( ni >= 0 && nj >= 0 && T[ ni ][ nj ] != -1 ){
					T[ i ][ j ] = k;
					F[ i ][ j ] = make_pair( ni , nj );
					break;
				}
			}
		}
	}

	if( T[ M ][ U ] == -1 )
		cout << "IMPOSSIBLE" << endl;
	else{
		while( M != 0 && U != 0 ){
			R[ T[ M ][ U ] ]++;
			int aM = F[ M ][ U ].X;
			int aU = F[ M ][ U ].Y;
			M = aM; U = aU;
		}
		for(int i = 0; i < d; i++){
			if( R[ i ] )
				cout << vp[ i ].Y << " " << R[ i ] << endl;
		}
	}
}


