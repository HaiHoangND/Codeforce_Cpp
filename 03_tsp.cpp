#include <bits/stdc++.h>

using namespace std;

int n, m, i, j, dmin = 1e9;
int c;
int d[100][100];//distance between 2 cities
bool visited[100];
int x[100];//cities
int f = 0, f_best = 1e9;

void input(){
	cin >> n >> m;
	for(int h = 2; h <= n; h++){
		visited[h] = false;
	}
	for(int h = 1; h <= n; h++){
		for(int g = 1; g <= n; g++){
			d[h][g] = 0;
		}
	}
	for(int h = 0; h < m; h++){
		cin >> i >> j >> c;
		d[i][j] = c;
		if(dmin > c) dmin = c;
	}
}

void updateBest(int k){
	if(d[x[k]][1] != 0 && f + d[x[k]][1] < f_best) f_best = f + d[x[k]][1];
}

bool check(int v, int k){
	if(visited[v]) return false;
	if(d[x[k-1]][v] == 0) return false;
	return true;
}

void Try(int k){
	for(int v = 2; v <= n; v++){
		if(check(v, k)){
			x[k] = v;
			f += d[x[k-1]][x[k]];
			visited[v] = true;
			if(k == n) updateBest(k);
			else{
				if(f_best > dmin*(n-k+1) + f) Try(k+1);
			}
			visited[v] = false;
			f -= d[x[k-1]][x[k]];
		}
	}
}

int main(){
	input();
	x[1] = 1;
	Try(2);
	cout << f_best;
	return 0;
}

