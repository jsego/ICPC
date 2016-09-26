#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int T[100001][2];
int N, P;

bool check_line( int p1, int p2 ){
	int count = 2;
	long long x1 = T[p1][0], y1 = T[p1][1], x2 = T[p2][0], y2 = T[p2][1], xp, yp;
	bool H = (y1 == y2);
	bool V = (x1 == x2);
	for(int i = 0; i < N; i++){
		if( i == p1 || i == p2 ) continue;
		xp = T[i][0]; yp = T[i][1];
		if(H){
			if( yp == y1 )
				count++;
		}
		else if(V){
			if( xp == x1 )
				count++;
		}
		else{
			if( (yp-y1)*(x2-x1) == (xp-x1)*(y2-y1) )
				count++;
		}
	} 
	return (count >= P);
}

int main(){
	while( cin >> N >> P ){
		for(int n = 0; n < N; n++) cin >> T[n][0] >> T[n][1];
		if( N == 1 ){
			cout << "possible" << endl;
			continue;
		}
		// Number of total points
		P = (N * P + 99)/100; 
		bool possible = false;
		int iters = 250;
		while( !possible && iters-- ){
			// Pick two random numbers
			int p1 = rand()%N;
			int p2 = rand()%N;
			// Avoid to use same point
			while(p1 == p2) 
				p2 = rand()%N;
			possible = check_line( p1, p2);
		}
		cout << ( possible ? "possible" : "impossible" ) << endl;
	}
}
