#include <bits/stdc++.h>

using namespace std;

int N;
bool visited[10];
int a[10];
int ans = 0;
int b[] = {100, 10, 2, 1000, 100, 10, -100};

void input(){
	cin >> N;
}

void solution(){
	int sum = 0;
	for(int i = 1; i <= 7; i++){
		sum += a[i]*b[i-1];
	}
	if(sum == N + 62) ans++;
}

bool check(int v, int k){
	if(visited[v]) return false;
	return true;
}

void Try(int k){
	for(int v = 1; v <= 9; v++){
		if(check(v, k)){
			a[k] = v;
			visited[v] = true;
			if(k == 7) solution();
			else Try(k+1);
			visited[v] = false;
		}
	}
}

int main(){
	input();
	Try(1);
	cout << ans;
	return 0;
}

