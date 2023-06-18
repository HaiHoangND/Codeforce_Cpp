#include <bits/stdc++.h>

using namespace std;

int N, M;
int c[20];
int A[20][20];
vector<int> pre[20];
int course[20];//xem khoa hoc nay gan cho ki hoc nao
bool cour[20];//xem khoa hoc nay da duoc day chua
int loadOfPeriod[6];
int minAns = 1e9;
//int maxLoad = -1;
int maxLoadAllPeriods = -1;

void input(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> c[i];
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> A[i][j];
			if(A[i][j] == 1) pre[j].push_back(i);
		}
	}
}

void solution(){
//	for(int i = 1; i <= M; i++){
//		maxLoad = max(maxLoad, loadOfPeriod[i]);
//	}
	minAns = min(maxLoadAllPeriods, minAns);
//	maxLoad = -1;
}

bool check(int v, int k){
	for(int i = 0; i < pre[k].size(); i++){
		int j = pre[k][i];
		if(cour[j] && course[j] >= v) return false;
	}
	return true;
}

void Try(int k){
	for(int v = 1; v <= M; v++){
		if(check(v, k)){
			course[k] = v;
			cour[k] = true;
			loadOfPeriod[v] += c[k];
			int Pre = maxLoadAllPeriods;
			maxLoadAllPeriods = max(maxLoadAllPeriods,loadOfPeriod[v]);
			if(k == N) solution();
			else{
				if(maxLoadAllPeriods < minAns) Try(k+1);
			}
			cour[k] = false;
			loadOfPeriod[v] -= c[k];
			maxLoadAllPeriods = Pre;
		}
	}
}

int main(){
	input();
	Try(1);
	cout << minAns;
	return 0;
}

