//#include <bits/stdc++.h>
//
//using namespace std;
//const int MAX = 1e6 + 5;
//
//int N, M;
//int a[MAX];
//
//void input(){
//	cin >> N >> M;
//	for(int i = 0; i < N; i++){
//		cin >> a[i];
//	}
//	sort(a, a + N);
//}
//
//int solve(int left, int right, int l, int r){
//	long long sum = 0;
//	int mid = (left + right)/2;
//	int m = (l + r)/2;
//	if(mid == left || mid == right) return mid;
////	if(m == l || m == r) return a[m];
//	for(int i = l; i <= m; i++){
//		if(a[i] > mid) sum += (a[i] - mid);
////		else sum += 0;
//	}
//	if(sum < M) solve(mid, right, m ,r);
//	else if(sum > M) solve(left, mid, l, m);
//	else return mid;
//}
//
//int main(){
//	input();
//	cout << solve(a[0], a[N-1], 0, N-1);
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const long long  MAX = 1000000;

long long  N, M;
long long  height[MAX];
long long  maxHeight;

void input(){
    cin >> N >> M;
    maxHeight = 0;
    for(long long  i=0; i<N; i++){
        cin >> height[i];
        maxHeight = max(maxHeight,height[i]);
    }
}

// caculated meter of wood in total
long long  totalMeterWood(long long  cut){
    long long  sum = 0;
    for(long long  i=0; i<N; i++){
        long long  tmp = height[i] - cut;
        if(tmp < 0) tmp = 0;
        sum += tmp;
    }
    return sum;
}

long long  solve(long long  left, long long  right){
    long long  mid = (left + right) / 2;
    long long  total = totalMeterWood(mid);

    if(right - left == 1 || total == M){
        return mid;
    } else {
        if(total < M) return solve(left,mid);
        else return solve(mid,right);
    }
}

int  main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    cout << solve(0,maxHeight);
}
