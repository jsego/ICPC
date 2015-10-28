#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main(){
	int T; cin >> T;
	string s; getline( cin , s );
	while( T-- ){
		bool first = true;
		vector< string > sounds;
		set< string > animals;
		while( getline( cin , s ), s != "what does the fox say?" ){
			istringstream iss( s );
			string sound;
			if( first ) {
				while( iss >> sound ){
					sounds.push_back( sound );
				}
				first = false;
			}
			else{
				iss >> sound;
				while( iss >> sound ){
					animals.insert( sound );
				}
			}
		}
		first = true;
		for(int i = 0; i < int( sounds.size() ); i++){
			if( animals.find( sounds[i] ) == animals.end() ){
				if( first ){
					first = false;
					cout << sounds[i] ;
				}
				else cout << " " << sounds[i];
			}
		}
		cout << endl;
	}
}
