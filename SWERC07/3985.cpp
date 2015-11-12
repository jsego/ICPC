#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>

#define LE length()
#define SL size()
#define PB push_back
#define INF 1000000000
#define THRESH 25
using namespace std;

int main(){
    int kases; cin>>kases; 
	bool first=true;
    while( kases-- ){

        if(first) first = false;
        else cout << endl;

        int N, I, F, M, x, y, cost; 
		cin >> N >> I >> F >> M;
        vector< vector<int> > adj(N, vector<int>() ); 

        for(int i = 0; i < M; i++){
            cin >> x >> y >> cost;
			adj[ x ].PB( y ); 
			adj[ x ].PB( cost );
        }
		
        int d[ 301 ], cont[ 301 ]; 
		for(int i = 0; i < 301; i++){ 
			d[ i ] = INF; 
			cont[ i ]=0;
		}

		int cn, nn, nc, posi = 0; 
        list< int > l; 
		l.PB( I ); 
		d[ I ]=0;

        while( l.SL > 0 ){
            cn = l.front(); //current node
			l.pop_front(); 
			posi = 0;
            for(size_t i = 0; i < adj[ cn ].SL; i += 2){
				nn = adj[ cn ][ i ]; // next node
				nc = adj[ cn ][ i + 1 ]; // next cost
				if( d[ nn ] > nc + d[ cn ] ){
                	d[ nn ] = nc + d[ cn ];
                    l.PB( nn );
                    posi = max( posi , ++cont[ nn ] );
                }
            }
            if( posi > THRESH )
				break;
        }
		
        if( d[ F ] >= INF || posi > THRESH ) cout << "infinity" << endl;
        else cout<< d[F] <<endl;
    }
}
