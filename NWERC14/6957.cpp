#include<iostream>
#include<vector>

using namespace std;

int main(){
	int N;
	while( cin >> N ){
		vector< vector< int > > v(N+1, vector<int>());
		vector< pair<int,int> > visited(N+1, make_pair(-1,-1) );
		int current_freq = 1, a, b;
		for(int n = 1; n < N; n++){
			cin >> a >> b ;
			v[a].push_back( b );
			v[b].push_back( a );
		}
		int p = 0, tot = 1, ac, child, f1, f2;
		vector<int> bfs;
		bfs.push_back( 1 );
		while( p < tot ){
			ac = bfs[p++];
			f1 = visited[ac].first;
			f2 = visited[ac].second;
			if( f1 == -1 ){
				f1 = current_freq++;
				visited[ac].first = f1;
			}
			if( f2 == -1 ){
				f2 = current_freq++;
				visited[ac].second = f2;
			}	
			if( int(v[ac].size()) == 1 ){ // leaf alone
				child = v[ac][0];
				if( visited[child].first != -1 ) continue;
				visited[child].first = f2;
				visited[child].second = f1;
				bfs.push_back( child );
				tot++;
			}
			else if( int(v[ac].size()) > 1 ){ // multiple childs
				for(int i=0, count = 0; i < int(v[ac].size()); i++){
					child = v[ac][i];
					if( visited[child].first != -1 ) continue;
					visited[child].first = (count&1?f1:f2);
					bfs.push_back( child );
					tot++; count++;
				}
			}
		}	
		for(int i = 1; i <= N; i++){
			f1 = visited[i].first;
			f2 = visited[i].second;
			cout << f1 << " " << f2 << endl;
		}
	}
}
