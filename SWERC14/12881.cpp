#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define X first
#define Y second

int n, w, h, l;
string T[11];
bool P[11][11];
bool C[11][11];
pair<int,int> R[5];
int G;

int getState(){
	vector<pair<int,int> > vp;
	for(int i=1;i<n;i++) vp.push_back(R[i]);
	sort(vp.begin(),vp.end());
	vp.push_back(R[0]);
	int res = 0;
	for(int i=0;i<n;i++){
		res  = (res*101 + vp[i].X*10 + vp[i].Y);
	}
	return res;
}

void extract_state(int st){
	for(int i=0;i<h;i++) 
		for(int j=0;j<w;j++) 
			P[i][j] = C[i][j];

	for(int i=0;i<n;i++){
		int rp = st%101;
		R[i].X = rp/10; R[i].Y = rp%10;
		st/=101;
		P[R[i].X][R[i].Y] = false;
		//cout<<"\tI:"<<i<<"=>("<<R[i].X<<","<<R[i].Y<<")";
	} //cout<<endl;
}

int move_down(int r){
	int i = R[r].X+1; 
	while(i < h && P[i][R[r].Y]){
		i++;
	}i--;
	int backup = R[r].X;
	R[r].X = i;
	int res = getState();
	R[r].X = backup;
	return res;
}

int move_up(int r){
	int i = R[r].X-1;
	while(i >= 0 && P[i][R[r].Y]){
		i--;
	}i++;
	int backup = R[r].X;
	R[r].X = i;
	int res = getState();
	R[r].X = backup;
	return res;

}

int move_left(int r){
	int j = R[r].Y-1;
	while(j >= 0 && P[R[r].X][j]){
		j--;
	}j++;
	int backup = R[r].Y;
	R[r].Y = j;
	int res = getState();
	R[r].Y = backup;
	return res;	
}

int move_right(int r){
	int j = R[r].Y+1;
	while(j < w && P[R[r].X][j]){
		j++;
	}j--;
	int backup = R[r].Y;
	R[r].Y = j;
	int res = getState();
	R[r].Y = backup;
	return res;
}

int bfs(int s){ //cout<<G<<endl;
	set<int> seen; //seen states
	seen.insert(s);
	vector<int> b; 
	b.push_back(s); // state
	b.push_back(0); // steps
	int csta, cste, p = 0, nsta;
	while(p < int(b.size())){ //cout<<b.size()<<endl;
		csta = b[p++]; cste = b[p++];
		//cout<<csta<<" "<<cste<<endl;
		extract_state(csta); //saved in global vars
		//Next states for the i-th robot
		for(int i=0;i<n;i++){
			//Next state moving down
			nsta = move_down(i);//cout<<"DOWN "<<nsta<<endl;
			if(nsta%101 == G) return cste+1;
			if(cste+1 < l && seen.find(nsta) == seen.end()){
				seen.insert(nsta);
				b.push_back(nsta); 
				b.push_back(cste+1); 
			}
			//Next state moving up
			nsta = move_up(i);//cout<<"UP "<<nsta<<endl;
			if(nsta%101 == G) return cste+1;
			if(cste+1 < l && seen.find(nsta) == seen.end()){
				seen.insert(nsta);
				b.push_back(nsta);
				b.push_back(cste+1);
			}
			//Next state moving left
			nsta = move_left(i);//cout<<"LEFT "<<nsta<<endl;	
			if(nsta%101 == G) return cste+1;
			if(cste+1 < l && seen.find(nsta) == seen.end()){
				seen.insert(nsta);
				b.push_back(nsta); 
				b.push_back(cste+1);
			}
			//Next state moving right
			nsta = move_right(i);//cout<<"RIGHT "<<nsta<<endl;
			if(nsta%101 == G) return cste+1;
			if(cste+1 < l && seen.find(nsta) == seen.end()){
				seen.insert(nsta);
				b.push_back(nsta); 
				b.push_back(cste+1);
			}
		}
	}//cout<<"END"<<endl;
	return -1;
}

int main(){
	while(cin>>n>>w>>h>>l){
		for(int i=0;i<h;i++){
			cin>>T[i];			
			for(int j=0;j<w;j++){
				C[i][j] = true;
				if(T[i][j] > '0' && T[i][j] < '5') {
					R[int(T[i][j]-'0')-1] = make_pair(i,j);
				}
				else if(T[i][j] == 'W') C[i][j] = false;
				else if(T[i][j] == 'X') G = i*10 + j;
			}
		}
		int initialState = getState();
		//cout<<initialState<<" "<<initialState%101<<endl;
		int res = bfs(initialState);
		if(res == -1) cout<<"NO SOLUTION"<<endl;
		else cout<<res<<endl;
	}
}
