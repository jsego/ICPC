#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T[4][4];
int nx[8] = {-1,-1,-1,0,0,1,1,1};
int ny[8] = {-1,0,1,-1,1,-1,0,1};
vector<int> L[10][10];

bool correctS( int n, int m, vector<int> &c ){
	int lim = n*m;
	vector<bool> visited( lim , false );
	visited[ c[0] ] = true;
	int f, t;
	for(int i = 1; i < int(c.size()); i++){
		f = c[i-1], t = c[i];
		for(int j = 0; j + 1< int(L[f][t].size()); j++){
			if( !visited[ L[f][t][j] ] )
				return false;
		}
		visited[ t ] = true;
	}
	return true;
}

int solve(int n , int m ){
	int lim = n*m;
	int res = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			for(int k = 0; k < lim; k++) L[i*m+j][k].clear();
			for(int k = 0; k < 8; k++){
				int ni = i + nx[k], nj = j + ny[k];
				vector<int> v;
				while( ni >= 0 && ni < n && nj >= 0 && nj < m ){					
					v.push_back( ni*m + nj );
					L[i*m+j][ni*m+nj] = v;
					ni += nx[k]; nj += ny[k];
				}
			}
		}

	for(int tam = 1; tam <= lim; tam++){
		vector<bool> v(lim, false);
		for(int i = lim-1, cont = tam; i >= 0 && cont > 0; i--, cont--)
			v[i] = true;
		do{
			vector<int> comb;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if( v[i*m + j] )
						comb.push_back( i*m + j );
			do{
				if( correctS( n , m , comb ) ){
					res++;
				}
			}while( next_permutation( comb.begin() , comb.end() ) );
		}while( next_permutation( v.begin() , v.end() ) );
	}
	return res;
}

int main(){
	for(int i = 0; i < 4; i++) T[i][0] = T[0][i] = 0;
	/*for(int i = 1; i < 4; i++)
		for(int j = i; j < 4; j++){
			T[i][j] = T[j][i] = solve( i , j );
		}*/
	T[1][1] = 1; T[1][2] = T[2][1] = 4; T[1][3] = T[3][1] = 11; 
	T[2][2] = 64; T[2][3] = T[3][2] = 1392; T[3][3] = 389497;
	int n, m, kases = 1;
	while( cin >> n >> m, n || m ){
		cout << "Case #" << kases++ << ": " << T[n][m] << endl;
	}
}
