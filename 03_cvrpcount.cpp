#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 20;
const int MAX_K = 10;
int N;//Number of clients
int K;//Number of trucks
int Q;//Capacity of a truck
int d[MAX_N];//d[v] is the demand of client v
int y[MAX_K];//y[k] is the first client on route k
int x[MAX_N];//x[v] is the next point of point v
bool visited[MAX_N];
int load[MAX_N];//load[k] is total demand of clients on route k
int segments;
int ans = 0;

//void solution(){
//	for(int k = 1; k <= K; k++){
//		cout << "Route[" << k << "]: 0";
//		int v = y[k];
//		while(v > 0){
//			cout << " - " << v;
//			v = x[v];
//		}
//		cout << " - 0" << endl;
//	}
//	cout << "---------------------" << endl;
//}

bool checkX(int v, int u, int k){
	if(v == 0) return true;
	if(visited[v] == true) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void TryX(int u, int k){//try all values for x[u] on route k
	for(int v = 0; v <= N; v++){
		if(checkX(v,u,k)){
			x[u] = v;
			visited[v] = true;
			load[k] += d[v];
			segments += 1;
			if(v == 0){
				if(k == K){
					if(segments == N+K) ans++;
				}else{
					TryX(y[k+1], k+1);
				}
			}else{//v is a client
				TryX(v,k);
			}
			visited[v] = false;
			load[k] -= d[v];
			segments -= 1;
		}
	}
}

bool checkY(int v, int k){
	if(visited[v] == true) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void TryY(int k){//Try all values for y[k] (y[1] < y[2] < ... < y[k])
	for(int v = y[k-1] + 1; v <= N; v++){
		if(checkY(v, k)){
			y[k] = v;
			load[k] += d[v];
			visited[v] = true;
			segments += 1;
			if(k == K){
				TryX(y[1],1);
			}else{
				TryY(k+1);
			}
			load[k] -= d[v];
			visited[v] = false;
			segments -= 1;
		}
	}
}

void input(){
	cin >> N >> K >> Q;
	for(int i = 1; i <= N; i++){
		cin >> d[i];
	}
}

void solve(){
	for(int i = 1; i <= N; i++) visited[i] = false;
	for(int k = 1; k <= K; k++) load[k] = 0;
	segments = 0;
	y[0] = 0;
	TryY(1);
}

int main(){
//	cout << "cvrp" << endl;
	input();
	solve();
	cout << ans;
	return 0;
}

