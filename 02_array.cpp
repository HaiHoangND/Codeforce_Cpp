#include <bits/stdc++.h>

using namespace std;

int a[105];
int n;
vector<int> sets[5];

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 0) sets[3].push_back(a[i]);
		else if(a[i] > 0) sets[2].push_back(a[i]);
		else sets[1].push_back(a[i]);
	}
}

void solve(){
	int m = sets[2].size();
	if(m == 0){
		sets[2].push_back(sets[1][sets[1].size() - 1]);
		sets[2].push_back(sets[1][sets[1].size() - 2]);
		sets[1].pop_back();
		sets[1].pop_back();
	}
	m = sets[1].size();
	if(m % 2 == 0){
		int j = sets[1][m-1];
		sets[1].pop_back();
		sets[3].push_back(j);
	}
	for(int i = 1; i <= 3; i++){
		cout << sets[i].size() << " ";
		for(int j = 0; j < sets[i].size(); j++){
			cout << sets[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	input();
	solve();
	return 0;
}

