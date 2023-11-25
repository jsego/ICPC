#include <bits/stdc++.h>

using namespace std;

int main(){
	int W, H;
	while(cin >> W >> H){
		bool possible = true;
		int h, offset = 0, empty;
		for(int w=0; w<W; ++w){
			cin >> h;
			if(not possible) continue; // unsolvable already
			if(h+offset > H){possible=false; continue;} // overlap
			empty = (H-(h+offset));
			if((empty&1)==0){offset=max(0,offset-1);} // if even, reduce offset
			else{++offset;}
			if((w+1==W) and (offset != 0)){possible=false;} // last case
		}
		cout << (possible?"possible\n":"impossible\n");
	}
}
