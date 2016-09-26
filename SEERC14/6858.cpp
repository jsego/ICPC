#include<iostream>

using namespace std;

int main(){
	int X, Y, N, A;
	while( cin >> X >> Y ){
		cin >> N;
		while( N-- ){
			cin >> A;
			bool yes = ( ( X%A == 0 ) && ( (Y-2)%A == 0 )  );
			yes |= ( ( (X-1)%A == 0 ) && ( (Y-1)%A == 0 ) );
			yes |= ( ( (X-2)%A == 0 ) && ((Y%A) == 0 ) );
			yes |= ( (X%A == 0) && ((X-2)%A == 0) && ((Y-1)%A == 0) );
			yes |= ( (Y%A == 0) && ((Y-2)%A == 0) && ((X-1)%A == 0) );
			cout << (yes?"YES":"NO") << endl;
		}
	}
}
