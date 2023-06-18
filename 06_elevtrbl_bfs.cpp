#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;

int s, g, f, u, d;
queue<int> q;
int ans = -1;

struct bfs{
	bool x;
	int y;
};

bfs b[N];

void input(){
	cin >> f >> s >> g >> u >> d;
}

void solve(){
	q.push(s);
	b[s].x = true;
	b[s].y = 0;
	while(!q.empty()){
		int p = q.front();
		if(p - d >= 1 && b[p - d].x == false){
			q.push(p - d);
			b[p - d].x = true;
			b[p - d].y = b[p].y + 1;
		}
		if(p + u <= f && b[p + u].x == false){
			q.push(p + u);
			b[p + u].x = true;
			b[p + u].y = b[p].y + 1;
		}
		if(p + u == g || p - d == g){
			ans = b[g].y;
			break;
		}
		q.pop();
	}
	if(ans == -1) cout << "use the stairs";
	else cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}

