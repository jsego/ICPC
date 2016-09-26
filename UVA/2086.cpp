/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){
	string s;
	while (cin>>s,s!=".") {
		map<string,string> M;
		vector<string> names;
		vector<int> nums;
		vector<bool> pos;
		int numi;
		string ac="";
		
		while (s[int(s.LE)-1] != '.') {
			if( (s[0]>='0' && s[0]<='9') || s[0] == '-'){
				istringstream iss(s.substr(0,s.LE -1 ));
				iss>>numi;
				nums.PB(numi);
				pos.PB(false);
			}
			else {
				ac="";
				for (int j=0; j+1<int(s.LE); j++) {
					if(s[j]>='a' && s[j]<='z') ac.PB(s[j]);
					else ac.PB(s[j]-'A'+'a');
				}
				//cout<<"AC: "<<ac<<endl;
				M[ac] = s.substr(0,s.LE-1);
				names.PB(ac);
				pos.PB(true);
			}
			cin>>s;
		}
		if( (s[0]>='0' && s[0]<='9') || s[0] == '-'){
			istringstream iss(s.substr(0,s.LE -1 ));
			iss>>numi;
			nums.PB(numi);
			pos.PB(false);
		}
		else {
			ac="";
			for (int j=0; j+1<int(s.LE); j++) {
				if(s[j]>='a' && s[j]<='z') ac.PB(s[j]);
				else ac.PB(s[j]-'A'+'a');
			}
		//	cout<<"AC: "<<ac<<endl;

			M[ac] = s.substr(0,s.LE-1);
			names.PB(ac);
			pos.PB(true);
		}
		
		sort(names.begin(),names.end());
		sort(nums.begin(),nums.end());
		
		int cont1=0,cont2=0;
		for (int i=0; i<int(pos.SL); i++) {
			if(pos[i]) cout<<M[names[cont1++]];
			else cout<<nums[cont2++];
			if(i+1 == int(pos.SL)) cout<<"."<<endl;
			else cout<<", ";
		}
	}
}