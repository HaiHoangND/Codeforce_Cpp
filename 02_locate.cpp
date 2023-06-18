#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int m[3000][3000];//direction of the coordinates before and after

int main(){
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T>0){
        int L, C;
        cin >> L >> C;
        vector<pair<int,int>> pre,last;//should be declared in outside of main
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) pre.push_back({i,j});
            }
        for(int i=0; i<L; i++)
            for(int j=0; j<C; j++){
                int temp;
                cin >> temp;
                if(temp) last.push_back({i,j});
            }
        int maxSl = 0;
        int lensPre = pre.size();
        int lensLast = last.size();
        for(int i=0; i<lensPre; i++)
            for(int j=0; j<lensLast; j++){
                int a = last[j].first - pre[i].first + N;
                int b = last[j].second - pre[i].second + N;
                m[a][b]++;
                maxSl = max(m[a][b],maxSl);
            }
        cout << maxSl << endl;
        T--;
        for(int i = 0; i < 3000; i++){
        	for(int j = 0; j < 3000; j++){
        		m[i][j] = 0;
			}
		}
    }

    return 0;
}
