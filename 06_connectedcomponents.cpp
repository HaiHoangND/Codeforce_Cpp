#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;

int N;
int M;
vector<int> adj[MAXN];
int ans = 0;
bool visited[MAXN];

void input(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int j, k;
		cin >> j >> k;
		adj[j].push_back(k);
		adj[k].push_back(j);
	}
}

void dfs(int u){
	visited[u] = true;
	for(int i = 0; i < adj[u].size(); i++){
		if(!visited[adj[u][i]]){
			dfs(adj[u][i]);
		}
	}
}

void solve(){
	for(int i = 1; i <= N; i++){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}

