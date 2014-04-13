/*
* Javier Segovia
* Accepted in 0.019
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair


//Return an ordered string without whitespaces, 
//all the anagrams must match with the same string
string anag(string s){
	sort(s.begin(),s.end());
	return s.substr(s.find_first_not_of(' '));
}

int main(){
	int T;
	string s; 

	cin>>T; //first integer input
	getline(cin,s); //first endline input
	getline(cin,s); //first blankline input

	while(T--){//run all the test cases
		
		vector<string> vs; //vector to save original phrases
		map<string,string> ms; //map to save original phrases and associated anagram

		while(getline(cin,s)){
			if(s == "") break; //finish of the test case
			vs.PB(s); 
			ms[s] = anag(s);
		}

		//order the phrases lexicographicaly
		sort(vs.begin(),vs.end());

		int tam = int(vs.SL);

		//compare each pair
		for(int i=0;i<tam;i++){
			for(int j=i+1;j<tam;j++){
				if(ms[vs[i]] == ms[vs[j]]) 
					cout<<vs[i]<<" = "<<vs[j]<<endl; //print all the pair matches
			}		
		}
		
		//tricky endline
		if(T) cout<<endl;
	}
}
