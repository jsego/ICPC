#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

/*int GCD(int a, int b){
	if( b == 0 ) return a;
	return GCD( b , a%b );
}*/

int main(){
	int kases; cin >> kases;
	while( kases-- ){
		int N; cin >> N;
		vector< pair< int , char > > v(N);
		long long w = 0, b = 0;//, g;
		for(int	i = 0; i < N; i++){
			cin >> v[i].first >> v[i].second;
			if( v[i].second == 'W' ) w += v[i].first;
			else b += v[i].first;
		}
		//g = GCD( w , b );
		//if( g == 0 ){
		if( w == 0 || b == 0 ){
			cout << max( w , b ) << endl;
			continue;
		}
		//w /= g; b /= g;
		long long aw = 0, ab = 0, res = 0;
		for(int i = 0; i < N ; i++){ //cout << "I: " << i << endl;
			if( v[i].second == 'W' ) aw += v[i].first;
			else ab += v[i].first;
			if( ab * w == aw * b && aw > 0 && ab > 0){
				res++; ab = aw = 0;
			}
			else if( w > b ){
				if( v[i].second == 'W' && ab * w < aw * b && ab > 0){
					long long x = (aw*b - (w * ab));
					if( x%b == 0 && x <= b*v[i].first ){
						res++; ab = 0; aw = x/b;
					}
				}
				else if( v[i].second == 'B' && ab*w > aw*b && aw > 0 ){
					long long x = (ab*w - aw*b);
					if( x%w == 0 && x <= w*v[i].first ){
						res++; ab = x/w; aw = 0;
					}
				}
			} 
			else if( b > w ){
				if( v[i].second == 'B' && ab * w > aw * b && aw > 0){
					long long x = (ab*w - (b * aw));
					if( x%w == 0 && x <= v[i].first * w ){
						res++; aw = 0; ab = x/w;
					}
				}
				else if( v[i].second == 'W' && ab * w < aw * b && ab > 0){
					long long x = (aw*b - (w * ab));
					if( x%b == 0 && x <= b*v[i].first ){
						res++; ab = 0; aw = x/b;
					}
				}
			}
			else if( b == w ){
				if( v[i].second == 'W' && ab < aw && ab > 0 ){
					long long x = aw - ab;
					if( x <= v[i].first ){
						res++; ab = 0; aw = x;
					}
				}
				else if( v[i].second == 'B' && ab > aw && aw > 0){
					long long x = ab - aw;
					if( x <= v[i].first ){
						res++; aw = 0; ab = x;
					}
				}
			}
			//cout<<"("<<w<<":"<<b<<")\t("<<aw<<":"<<ab<<")\t("<<v[i].second<<","<<v[i].first<<")\t"<<res<<endl;
		}
		cout << res << endl;
	}
}
