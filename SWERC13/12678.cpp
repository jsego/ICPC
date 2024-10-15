// A - Mixing Colours
// TLE in Codeforces
// WA in Kattis (& long double is TLE)

#include <bits/stdc++.h>

using namespace std;


double Game[501][501][101]; // (from, to, color)
string color_names[101];

int main(){
	int R; 
	while(cin >> R){
		string color;
		map<string,int> Colors;
		int idxs[3];
		
		// Read the production rules
		vector<pair<int,int>> production_rules[101];
		int total_colors = 0;
		for(int r = 0; r < R; ++r){
			for(int i=0; i<3; ++i){
				cin >> color;
				auto it = Colors.find(color);
				if(it == Colors.end()){
					Colors[color] = total_colors;
					color_names[total_colors] = color;
					//cout << "Color #" << total_colors << "=" << color << '\n';
					idxs[i] = total_colors++;
				}
				else idxs[i] = it->second;
			}
			production_rules[idxs[2]].emplace_back(make_pair(idxs[0],idxs[1]));
			production_rules[idxs[2]].emplace_back(make_pair(idxs[1],idxs[0]));
		}
		
		int games; cin >> games;
		while(games--){
			int total_tokens; cin >> total_tokens;
			// Reset game values
			for(int i=0;i<total_tokens;++i)
				for(int j=0; j<total_tokens; ++j)
					for(int k=0; k<total_colors; ++k)
						Game[i][j][k] = 0.0;
			// Read the input tokens for the current game
			for(int c = 0; c < total_tokens; ++c){
				while(cin >> color, color != "END"){
					auto it = Colors.find(color);
					cin >> Game[c][c][it->second];
				}	
			}
			
			// Solve current game
			double max_c;
			for(int step = 1; step < total_tokens; ++step){
				for(int i = 0, j = step; j < total_tokens; ++i, ++j){  // i=from; j=to
					for(int mid=i; mid<j; ++mid){ 
						// production [i,mid] + [mid+1,j]
						for(int c=0; c<total_colors; ++c){ 
							// iterate over production rules of color=c
							max_c = 0.0;
							for(auto&& [a,b] : production_rules[c]){
								max_c = max(max_c, Game[i][mid][a]*Game[mid+1][j][b]);
								max_c = max(max_c, Game[i][mid][b]*Game[mid+1][j][a]);
							}
							//cout << "[" << i << "," << mid << "]+["<<(mid+1) <<","<<j<<"]["<<c<<"] = "<<max_c<<'\n';
							Game[i][j][c] = max(Game[i][j][c], max_c);
						}
					}
				}
			}
			
			// Print max color if that exists
			double max_val = 0.0;
			int color_idx = -1;
			for(int c=0; c<total_colors; ++c){
				if(Game[0][total_tokens-1][c] > max_val){
					max_val = Game[0][total_tokens-1][c];
					color_idx = c;
				}
			}
			//cout << max_val << endl;
			if(color_idx == -1){ cout << "GAMEOVER\n"; continue;}
			cout << color_names[color_idx] << '\n';
		}
	}
	
}
