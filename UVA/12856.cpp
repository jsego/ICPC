#include<iostream>
#include<string>

using namespace std;

unsigned long long R[1000001][3];

unsigned long long comb( string &s, size_t f, size_t t){
	for( int i = 0; i < 3; i++ ) R[0][i] = 0;
	unsigned long long res = 0;
	for( size_t i = f, o = 1; i < t; i++, o++){
		unsigned offset = (s[i]-'0') % 3;
		if( offset == 0 ){
			R[o][0] = R[o-1][0]+1;
			R[o][1] = R[o-1][1];
			R[o][2] = R[o-1][2];
		}
		else if( offset == 1 ){
			R[o][0] = R[o-1][2];
			R[o][1] = R[o-1][0]+1;
			R[o][2] = R[o-1][1];
		}
		else{
			R[o][0] = R[o-1][1];
			R[o][1] = R[o-1][2];
			R[o][2] = R[o-1][0]+1;
		}
		res += R[o][0];
		//cout << R[o][0] << " " << R[o][1] << " " << R[o][2] << endl;
	}
	return res;
}

int main(){
	string s;
	while( cin >> s ){
		size_t from = 0, to = 0;
		unsigned long long res = 0;
		while( from < s.length() ){
			from = s.find_first_of("0123456789", to);
			if( from == string::npos )
				break;
			to  = s.find_first_not_of("0123456789", from);
			if( to == string::npos )
				to = s.length();
			//cout << from << " " << to << endl;
			res += comb(s, from, to);
			from = to+1;
		}
		cout << res << endl;
	}
}
