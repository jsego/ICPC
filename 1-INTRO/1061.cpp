/*
* Javier Segovia
* Accepted in 0.015
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

string A[4] = {"O","A","B","AB"};
string S[2] = {"-","+"};
vector<int> C[16]; //possibilites of the unknown child
vector<int> P[16]; //possibilities of the unknown parent

int getval(string &s){
	if(s == "O") return 0;
	if(s == "A") return 1;
	if(s == "B") return 2;
	return 3; //AB
}

string getRes(string p1,string p2,string ch){
	string res="";
	vector<string> vs;

	//If the first parent is missing
	if(p1 == "?"){
		char s1 = p2[int(p2.LE)-1], s2 = ch[int(ch.LE)-1];
		int start = 0; 
		if(s1 == '-' && s2 == '+') start++;
		p2 = p2.substr(0,int(p2.LE)-1);
		ch = ch.substr(0,int(ch.LE)-1);
		int c = getval(ch),p = getval(p2);
		//Get the position of the relation
		int pos = c<<2|p;
		for(int i=0;i<int(P[pos].SL);i++){
			for(int j=start;j<2;j++){
				vs.PB((A[P[pos][i]]+S[j]));
			}
		}
	}
	//If the second parent is missing
	else if(p2 == "?"){
		char s1 = p1[int(p1.LE)-1], s2 = ch[int(ch.LE)-1];
		int start = 0; 
		if(s1 == '-' && s2 == '+') start++;
		p1 = p1.substr(0,int(p1.LE)-1);
		ch = ch.substr(0,int(ch.LE)-1);
		int c = getval(ch),p = getval(p1);
		//Get the position of the relation
		int pos = c<<2|p;
		for(int i=0;i<int(P[pos].SL);i++){
			for(int j=start;j<2;j++){
				vs.PB((A[P[pos][i]]+S[j]));
			}
		}
	}
	//If the child is missing
	else{
		int rep = 2;
		//If both parents are negative, the child must be negative too
		if(p1[int(p1.LE)-1] == '-' && p2[int(p2.LE)-1] == '-') rep--;
		p1 = p1.substr(0,int(p1.LE)-1);
		p2 = p2.substr(0,int(p2.LE)-1);
		int c = getval(p2),p = getval(p1);
		//Get the position of the relation
		int pos = c<<2|p;
		//Append each combination in the resultant vector
		for(int i=0;i<int(C[pos].SL);i++){
			for(int j=0;j<rep;j++){
				vs.PB((A[C[pos][i]]+S[j]));
			}
		}
	}

	
	if(int(vs.SL) == 0) res = "IMPOSSIBLE"; //Return IMPOSSIBLE if there is no results
	else if(int(vs.SL) == 1) res = vs[0]; //Don't use brackets if there is only one result
	else{   //Append in the correct form the results
		res = "{"+vs[0];
		for(int i=1;i<int(vs.SL);i++) res+=", "+vs[i];
		res += "}";			
	}
	return res;
}

int main(){
	//Fill the parent and child possibilities (precalculated relations)
	vector<int> v; 
	v.PB(0); 
	C[0] = v; //0
	v.PB(1); 
	C[1] = C[4] = C[5] = v; //0-1
	v.PB(2);
	P[0] = P[1] = P[2] = v;	//0-1-2
	v.PB(3);
	C[6] = C[9] = P[5] = P[7] = P[10] = P[11] = v; //0-1-2-3
	v.erase(v.begin());
	C[7] = C[11] = C[13] = C[14] = C[15] = P[15] = v;//1-2-3
	v.erase(v.begin());
	P[8] = P[9] = P[13] = v;//2-3
	v.clear(); v.PB(1); v.PB(3);
	P[4] = P[6] = P[14] = v;//1-3
	v.clear(); v.PB(0); v.PB(2);
	C[2] = C[8] = C[10] = v; //0-2
	v.clear(); v.PB(1); v.PB(2);
	C[3] = C[12] = v; //1-2
	
	int kase = 1;
	string p1,p2,ch;
	//Main Loop
	while(cin>>p1>>p2>>ch && p1 != "E"){
		string res = getRes(p1,p2,ch);
		
		cout<<"Case "<<kase++<<":";
		if(p1 == "?") cout<<" "<<res<<" "<<p2<<" "<<ch<<endl;
		else if(p2 == "?") cout<<" "<<p1<<" "<<res<<" "<<ch<<endl;
		else cout<<" "<<p1<<" "<<p2<<" "<<res<<endl;
	}

}
