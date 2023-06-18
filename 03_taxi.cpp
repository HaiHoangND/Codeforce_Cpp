#include <bits/stdc++.h>

using namespace std;

int n;
int c[24][24];
int cmin = 1e9;
int x[24];
bool visited[24];
int f = 0, f_best = 1e9;

void input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i <= 2*n; i++){
		for(int j = 0; j <= 2*n; j++){
			cin >> c[i][j];
			if(c[i][j] != 0) cmin = min(cmin, c[i][j]);
		}
	}
}

void updateBest(int k){
	if(c[x[k]][0] != 0 && f + c[x[k]][0] < f_best) f_best = f + c[x[k]][0];
}

bool check(int v, int k){
	if(visited[v] == true) return false;
	if(v > n){
		if(visited[v - n] == false) return false;
	}
	if(c[x[k-1]][v] == 0) return false;
	if(x[k-1] <= n && x[k-1] >= 1){
		if(v != x[k-1] + n) return false;
	}
	if(x[k-1] > n && v > n) return false;
	return true;
}

void Try(int k){
	for(int v = 1; v <= 2*n; v++){
		if(check(v,k)){
			x[k] = v;
			f += c[x[k-1]][x[k]];
			visited[v] = true;
			if(k == 2*n) updateBest(k);
			else{
				if(f_best > f + cmin*(2*n+1-k)) Try(k+1);
			}
			f -= c[x[k-1]][x[k]];
			visited[v] = false;
		}
	}
}

int main(){
	x[0] = 0;
	input();
	Try(1);
	cout << f_best;
	return 0;
}

