#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
#include<sstream>
#include<string>
using namespace std;

int main(){
	int N; cin >> N;
	map< string , int > P;
	vector< string > W[10001];
	string s, line;
	getline( cin , line );
	int totalID = 0;
	for(int n = 0; n < N; n++){
		getline( cin , line );
		istringstream iss( line );
		iss >> s;
		int id;
		map< string , int >::iterator it = P.find( s );
		if( it == P.end() ){
			id = totalID;
			P[ s ] = totalID++;
		}
		else
			id = (it->second);
		while( iss >> s ){
			W[ id ].push_back( s );
		}
	}
	map< string , int > res;
	for( int i = 0; i < int( W[0].size() ); i++){
		res[ W[0][i] ] = res[ W[0][i] ] + 1;
	}
	for(int id = 1; id < totalID; id++){
		map< string , int > acres;
		map< string , int >::iterator it;
		for( int i = 0; i < int( W[ id ].size() ); i++){
			it = res.find( W[ id ][ i ] );
			if( it != res.end() ){
				int cant = (it->second);
				it = acres.find( W[ id ][ i ] );
				if( it == acres.end() ){
					acres[ W[ id ][ i ] ] = cant + 1;
				}
				else{
					//acres[ W[ id ][ i ] ] = acres[ W[ id ][ i ] ] + 1;
					(it->second)++;
				}
			}
		}
		swap( res , acres );
	}

	vector< pair< int , string > > vp;
	for( map< string , int >::iterator it = res.begin(); it != res.end(); it++){
		vp.push_back( make_pair( -(it->second) , it->first ) );
	}
	sort( vp.begin() , vp.end() );
	for(int i = 0; i < int(vp.size()); i++)
		//cout << vp[i].first << " " << vp[i].second << endl;
		cout << vp[i].second << endl;
	if( vp.size() == size_t( 0 ) )
		cout << "ALL CLEAR" << endl;
}




