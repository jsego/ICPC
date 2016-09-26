#include<iostream>
#include<set>

using namespace std;

#define ULL unsigned long long

ULL T[ 1001 ];
ULL X[ 1001 ];

ULL GCD( ULL a , ULL b ){
	if( b == 0 ) return a;
	return GCD( b , a%b );
}

int main(){
	int M , N;
	cin >> M >> N;
	for( int m = 0; m < M; m++)
		cin >> T[ m ];
	for( int n = 0; n < N; n++)
		cin >> X[ n ];
	set< pair< ULL , ULL > > S;
	set< ULL > D;
	for( int n = 0; n + M <= N; n++){
		bool ok = true;
		ULL lastX = X[ n + 1], diffX = X[ n + 1 ] - X[ n ], cx;
		ULL lastT = T[ 1 ], diffT = T[ 1 ] - T[ 0 ], ct;
		ULL gcd = GCD( diffX , diffT );
		cx = diffX / gcd;
		ct = diffT / gcd;
		for( int m = 2; m < M; m++){
			diffT = T[ m ] - lastT;
			diffX = X[ n + m ] - lastX;
			gcd = GCD( diffX , diffT );
			diffX /= gcd;
			diffT /= gcd;
			if( diffX != cx || diffT != ct ){
				ok = false; 
				break;
			}
			lastX = X[ n + m ];
			lastT = T[ m ];
		}
		if( ok ){
			S.insert( make_pair( cx , ct ) );
			D.insert( X[ n + 1 ] - X[ n ] );
		}
	}
	cout << S.size() << endl;
	bool first = true;
	for( set< ULL >::iterator it = D.begin(); it != D.end(); it++){
		if( first ) { first = false; cout << *it ;}
		else cout << " " << *it;
	}	
	cout << endl;
}
