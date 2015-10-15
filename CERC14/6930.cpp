#include<iostream>
#include<vector>
#include<list>
using namespace std;

int T[1001][3];
long long R[1001][3]; // rate (num/den) - dir
int N;
long long B[5001];

bool ADJ( int a , int b ){
	int dx = T[a][0] - T[b][0];
	int dy = T[a][1] - T[b][1];
	int r  = T[a][2] + T[b][2];
	//cout << r*r << " = " << dx*dx << " + " << dy*dy << endl;
	return ( (dx*dx + dy*dy) == r*r );
}

long long GCD( long long a, long long b ){
	if( b == 0 ) return a;
	return GCD( b, a%b );
}

void BFS(){
	list< int > l;
	for( int i = 1; i < N; i++){
		l.push_back( i );
	}
	int p = 0, t = 0;
	long long r = 0, rn = 1, rd = 1, dir = 0, nr, nd, ngcd;
	B[t++] = r;  B[t++] = rn;
	B[t++] = rd; B[t++] = dir ;
	while( p < t ){
		r  = B[p++]; rn  = B[p++]; 
		rd = B[p++]; dir = B[p++];
		R[r][0] = rn; R[r][1] = rd; R[r][2] = dir;
		//for( int i = 0; i < N; i++){
		for( list< int >::iterator it = l.begin() ; it != l.end() ; ){
			//cout << r << " " << i << " " << ADJ( r , i ) << endl;
			if( ADJ( r , *it ) ){
				nr = T[ r ][2] * R[r][0];
				nd = T[*it][2] * R[r][1];
				ngcd = GCD( nr, nd );
				nr /= ngcd; nd /= ngcd;
				B[t++] = *it; B[t++] = nr;
				B[t++] = nd; B[t++] = dir^1 ;
				it = l.erase( it );
			}
			else it++;
		}
	}
}

int main(){
	int kases;
	cin >> kases;
	while( kases-- ){
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> T[i][0] >> T[i][1] >> T[i][2];
			R[i][0] = R[i][1] = R[i][2] = 0;
		}
		BFS( );
		for(int i = 0; i < N; i++){ //cout << i ; for(int j = 0; j < 3; j++) cout << " " << R[i][j]; cout << endl;
			if( R[i][0] ){
				cout << R[i][0];
				if( R[i][1] > 1 ){
					cout << "/" << R[i][1];
				}
				cout << " " << (R[i][2]?"counterclockwise":"clockwise") << endl;
			}
			else{
				cout << "not moving" << endl;
			}
		}
	}
}
