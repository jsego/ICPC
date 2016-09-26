#include<iostream>
#include<algorithm>

using namespace std;

int T[50][50];
int R[50][50][50];
int N;

int recur( int x, int y, int l ){
	if( l == 0 ){
		return 0;
	}
	if( R[x][y][l] != -1)
		return R[x][y][l];

	for(int no = 1; no < N; no++){
		if( no + x < N && no + y < N)
			R[x][y][l] = max( R[x][y][l], recur( x + no, y + no, l-1) + T[x + no][y + no] );
		if( x >= no && no + y < N)
			R[x][y][l] = max( R[x][y][l], recur( x - no, y + no, l-1) + T[x - no][y + no] );
		if( no + x < N && y >= no )
			R[x][y][l] = max( R[x][y][l], recur( x + no, y - no, l-1) + T[x + no][y - no] );
		if( x >= no && y >= no )
			R[x][y][l] = max( R[x][y][l], recur( x - no, y - no, l-1) + T[x - no][y - no] );
	}

	return R[x][y][l];
}

int main(){
	int kases; cin >> kases;
	while( kases-- ){
		int L, cx, cy;
		cin >> N >> L; //L+=-3;
		cin >> cy >> cx;
		for(int x = 0; x < N; x++)
			for(int y = 0; y < N; y++){
				cin >> T[x][y];
				for(int l = 0; l <= L; l++) 
					R[x][y][l] = -1;
			}

		cout << recur( cx, cy, L ) << endl;
	}
}
