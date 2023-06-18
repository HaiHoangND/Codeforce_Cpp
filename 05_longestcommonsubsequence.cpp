#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;

int n, m;
int X[MAX], Y[MAX];
int S[MAX][MAX];

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> X[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> Y[i];
	}
}

void solve(){
//	if(X[1] == Y[1]) S[1][1] = 1;
//	else S[1][1] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(X[i] == Y[j]) S[i][j] = S[i-1][j-1] + 1;
			else S[i][j] = max(S[i-1][j], S[i][j-1]);
		}
	}
	cout << S[n][m];
}

int main(){
	input();
	solve();
	return 0;
}

