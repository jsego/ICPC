#include<iostream>
#include<string>

using namespace std;

bool isValid( string &s ){
	int ms = 0, es = 0;
	for(int i = 0; i < int( s.length() ); i++){
		if( s[i] != '?' && s[i] != 'M' && s[i] != 'E' )
			return false;
		else if( s[i] == 'M' )
			ms++;
		else if( s[i] == 'E' )
			es++;
	}
	if( ms != 1 || es != 1 )
		return false;
	return true;
}

bool axiomDef( string &s ){
	size_t mid = s.find( "M?E" ); //cout << mid << endl;
	if( mid == string::npos || mid == 0) return false;
	string f = s.substr( 0 , mid ) + "?"; 
	if( f == s.substr( mid + 3 ) )
		return true;
	return false;
}

bool productRule( string &s ){
	size_t mf = s.find( "?M?" );
	size_t ef = s.find( "?E?" );
	if( mf == string::npos ||
		ef == string::npos ||
		mf > ef )
		return false;
	unsigned x = mf + 1;
	unsigned y = ef - mf - 1;
	unsigned z = s.length() - (ef + 2);
	
	if( x > 0 && y > 0 && z > 0 && (z - x) == y )
		return true;
	return false;
}

int main(){
	int N; cin >> N;
	while( N-- ){
		string s;
		cin >> s;
		bool theorem = true;
		theorem &= isValid( s );
		if( theorem )
			theorem &= ( productRule(s) | axiomDef(s) );
		if( theorem ) cout << "theorem" << endl;
		else cout << "no-theorem" << endl;
	}
}
