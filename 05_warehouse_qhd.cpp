#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
const int MT = 101;
const int MD = 20;

int N, T, D;
int a[MN], t[MN];
int S[MN][MT];//la luong hang max lay duoc khi dung tai cac tram 1, ..., i voi tong thoi gian lay hang bang t

void input(){
	cin >> N >> T >> D;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++) cin >> t[i];
}

void solve(){
	for(int i = 1; i <= N; i++)
		for(int k = 0; k <= T; k++)
			S[i][k] = 0;
	
	S[1][t[1]] = a[1];
	
	for(int i = 2; i <= N; i++){
		for(int k = 0; k <= T; k++){
			
			if(k == t[i]) S[i][k] = a[i];
			else S[i][k] = 0;
			
			for(int j = i-D; j < i; j++){
				if(j >= 1 && k - t[i] >= 0){
					if(S[i][k] < S[j][k-t[i]] + a[i])
						S[i][k] = S[j][k-t[i]] + a[i];
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= T; j++){
			if(ans < S[i][j]) ans = S[i][j];
		}
	}
	cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}

