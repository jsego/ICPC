#include<iostream>
#include<vector>

using namespace std;

char T[10][10];
int mx[4] = {-1,1,-1,1};
int my[4] = {-1,-1,1,1};

int recur(int x, int y, int jumps){
	int nx, ny, res = jumps;
	for(int i = 0; i < 4; i++){
		nx = x + mx[i]; ny = y + my[i];
		if( nx > 0 && nx < 9 && ny > 0 && ny < 9 && T[nx][ny] == 'B'){
			T[nx][ny] = '#';
			nx += mx[i]; ny += my[i];
			if( nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && T[nx][ny] == '#'){
				T[nx][ny] = 'W'; T[x][y] = '#';
				res = max( res , recur( nx , ny , jumps + 1 ) );
				T[nx][ny] = '#'; T[x][y] = 'W';
			}
			nx -= mx[i]; ny -= my[i];
			T[nx][ny] = 'B';
		}
	}
	return res;
}

int main(){
	int kases; cin >> kases;
	while( kases-- ){
		vector<pair<int,int> > vp;
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)	{
				cin >> T[i][j];
				if( T[i][j] == 'W' )
					vp.push_back( make_pair( i , j ) );
			}
		int res = 0;
		for(int i = 0; i < int(vp.size()); i++){
			res = max( res , recur( vp[i].first , vp[i].second , 0 ) );
		}
		cout << res << endl;
	}
}
