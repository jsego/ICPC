#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

string convert( const string &s ){
	string res = s;
	for( unsigned i = 0; i < res.length() ; i++ ){
		if( res[i] >= 'A' && res[i] <= 'Z' )	
			res[i] = ( res[i] - 'A' + 'a' );	
	}
	size_t ar = res.find("@");
	string login = res.substr( 0 , ar);
	string domain = res.substr( ar+1 );
	if( domain == "bmail.com"  ){
		size_t plus = login.find( "+" );
		if( plus != string::npos )
			login = login.substr( 0 , plus );
		string aux = "";
		for( unsigned i = 0; i < login.length(); i++)
			if( login[i] != '.' )
				aux.push_back( login[i] );
		login = aux;
	}
	return login+"@"+domain;
}

int main(){
	int N;
	cin >> N;
	map< string , vector< string > > M;
	for( int i = 0; i < N ; i++ ){
		string s, converted;
		cin >> s;
		converted = convert( s );
		M[ converted ].push_back( s );
	}
	cout << M.size() << endl;
	for( map< string , vector< string > >::iterator it = M.begin(); it != M.end(); it++){
		cout << (it->second).size();
		for(unsigned j = 0; j < (it->second).size() ; j++){
			cout << " " << (it->second)[j];
		}
		cout << endl;
	}
}
