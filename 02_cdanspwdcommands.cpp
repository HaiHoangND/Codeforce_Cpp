#include <bits/stdc++.h>

using namespace std;

int n;
char c[10];//dung de nhap cd vs pwd
vector<string> vt;//de chua cac cum tu giua 2 dau /
string str;//de nhap sau cd
//queue<string> q;

void solve(){
	cin >> n;
	for(int j = 1; j <= n; j++){
		fflush(stdin);
		scanf("%s", &c);
		string s = "";
		s += string(c);
		if(s == "cd"){
			cin >> str;
			for(int i = 0; i < str.length(); i++){
				string s1 = "";
				if(str[i] == '.' && str[i+1] == '.'){
					vt.pop_back();
					i += 2;
				}
				while((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
					s1 += str[i];
					i++;
				}
				if(s1 != "") vt.push_back(s1);
			}
		}
		else if(s == "pwd"){
			cout << "/";
			for(int i = 0; i < vt.size(); i++){
				cout << vt[i] << "/";
			}
			cout << endl;
		}
	}
//	while(!q.empty()){
//		cout << q.front();
//		q.pop();
//		cout << endl;
//	}
}

int main(){
	solve();
	return 0;
}

