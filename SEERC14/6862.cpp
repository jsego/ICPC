#include<iostream>

using namespace std;
int S[101];
int main(){

	for(int m = 1; m < 101; m++){
		for(int x = 1; x <= m; x++){
			for(int y = x; y <= m; y++){
				for(int z = y+1; z <= m; z++)
					if( x*x + y*y == z*z )
						S[m]++;
			}
		}
	}

	int M, N; 
	while( cin >> M >> N ){
		cout << S[M] + (M+1)*(N-1)<< endl;
	}
}
