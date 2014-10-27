#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

int d = -1;
map<string,int> M; //word - identifier
int C[20005][7]; //identifier - day => total per day
int R[20005];
pair<int,string> pis[20005];

int main(){
	string line;
	string w;
	map<string,int>::iterator it;
	int total = 0;
	bool sorted = true;
	for(int i=0;i<20005;i++){R[i] = 0; for(int j=0;j<7;j++) C[i][j] = 0;}

	while(getline(cin,line)){
		if(line.length() == size_t(0))continue;
		if(line == "<text>"){
			sorted = false;
			d = (d+1)%7;
			for(int i=0;i<total;i++){
				R[i] -= C[i][d]; C[i][d] = 0;
			}
			while(getline(cin,line) && line != "</text>"){
				istringstream iss(line);
				while(iss>>w){
					if(int(w.length()) < 4) continue;
					it = M.find(w);
					if(it == M.end()){
						M[w] = total; 
						it = M.find(w);
						total++;
					}
					C[it->second][d]++;
					R[it->second]++;
				}
			}
		}
		else{//top
			istringstream iss(line);
			int n;
			iss>>w>>n;
			if(!sorted){
				int pos = 0;
				for(it = M.begin(); it != M.end();it++){
					pis[pos] = make_pair(-R[it->second],it->first);
					pos++;
				}
				sort(pis, pis+pos);
			}
			int v = -pis[n-1].first;
			sorted = true;
			cout<<"<top "<<n<<">"<<endl;
			int p = 0;
			while(p < total && -pis[p].first >= v && -pis[p].first > 0){
				cout<<pis[p].second<<" "<<-pis[p].first<<endl;
				p++;
			}
			cout<<"</top>"<<endl;
		}
	}	
}
