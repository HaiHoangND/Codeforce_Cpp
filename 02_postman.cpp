//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, k, x, m;
//priority_queue <pair<int, int>> pq_p;//prioritize max first value//positive
//priority_queue <pair<int, int>> pq_n;//negative
//
//void input(){
//	cin >> n >> k;
//	for(int i = 0; i < n; i++){
//		cin >> x >> m;
//		if(x >= 0) pq_p.push({x, m});
//		else pq_n.push({abs(x), m});
//	}
//}
//
//void solve(){
//	unsigned long long d = 0;//distance
//	while(!pq_p.empty()){
//		int temp = k;
//		long long t = pq_p.top().second / temp;
//		if(!t) d += 2*pq_p.top().first;
//		else{
//			d += 2*t*pq_p.top().first;
//			if(pq_p.top().second - t*temp == 0){
//				temp = 0;
//				pq_p.pop();
//			}
//			else{
//				int i = pq_p.top().first;
//				int j = pq_p.top().second - t*temp;
//				pq_p.pop();
//				pq_p.push({i, j});
//			}
//		}
//		while(temp > 0 && !pq_p.empty()){
//			if(temp >= pq_p.top().second){
//				temp -= pq_p.top().second;
//				pq_p.pop();
//			}
//			else{
//				int i = pq_p.top().first;
//				int j = pq_p.top().second - temp;
//				pq_p.pop();
//				pq_p.push({i, j});
//				temp = 0;
//			}
//		}
//	}
//	while(!pq_n.empty()){
//		int temp = k;
//		long long t = pq_n.top().second / temp;
//		if(!t) d += 2*pq_n.top().first;
//		else{
//			d += 2*t*pq_n.top().first;
//			if(pq_n.top().second - t*temp == 0){
//				temp = 0;
//				pq_n.pop();
//			}
//			else{
//				int i = pq_n.top().first;
//				int j = pq_n.top().second - t*temp;
//				pq_n.pop();
//				pq_n.push({i, j});
//			}
//		}
//		while(temp > 0 && !pq_n.empty()){
//			if(temp >= pq_n.top().second){
//				temp -= pq_n.top().second;
//				pq_n.pop();
//			}
//			else{
//				int i = pq_n.top().first;
//				int j = pq_n.top().second - temp;
//				pq_n.pop();
//				pq_n.push({i, j});
//				temp = 0;
//			}
//		}
//	}
//	cout << d;
//}
//
//int main(){
//	input();
//	solve();
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const long long MAX = 10000005;
long long n,k;
long long mPos[MAX];
long long mNeg[MAX];

/*Tinh quang duong*/
long long qd(long long m[]){
    long long i = MAX - 1;
    unsigned long long tqd = 0; // Tong quang duong
    long long c = 0; // Luong du thua (so du)
    while(i>0){
        while(m[i] == 0 && i>0) i--;
        if(i == 0) break;

        long long thuong;
        m[i] = m[i] - c;
        if(m[i]<0){
            c = -m[i];
            m[i] = 0;
        }else{
            c = m[i] % k;
            if(c!=0) c = k - c;
            thuong = m[i] / k;
            if(c>0){
                tqd = tqd + 2*(thuong+1)*i;
            }else{
                tqd = tqd + 2*thuong*i;
            }
        }
        i--;
    }
    
    return tqd;
}

int main(){
    /*Doc du lieu*/
    cin >> n >> k;
    for(long long i=0; i<n; i++){
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        if(temp1 > 0) mPos[temp1] = temp2;
        else {
            temp1 = abs(temp1);
            mNeg[temp1] = temp2;
        }
    }

    /*In ket qua*/
    cout << qd(mPos) + qd(mNeg);
    return 0;
}
