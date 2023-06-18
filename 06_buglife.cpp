//#include<bits/stdc++.h>//bai nay check cho ca do thi khong lien thong
//using namespace std;
//const int MAX = 2005;
//
//int n, m; // n vertex, m edge
//vector< vector<int> > vt;
//int color[MAX]; // 1 : red, 2 : blue
//set<int> s;
//
//void input(){
//    cin >> n >> m;
//    vt.resize(n+1);
//	for(int i = 1; i <= n; i++){
//		vt[i].clear();
//		s.insert(i);
//	}
//	vt.clear();
//    for(int i=0; i<m; i++){
//        int tmp1, tmp2;
//        cin >> tmp1 >> tmp2;
//
//        vt[tmp1].push_back(tmp2);
//        vt[tmp2].push_back(tmp1);
//    }
//
//    for(int i=1; i<=n; i++) color[i] = 0; // no color
//}
//
//bool solve(){
//    queue<int> q;
//    q.push(1);
//    color[1] = 1;
//
//    while(!q.empty()){
//        int x = q.front(); q.pop();
//        s.erase(x);
//        for(int v : vt[x]){
//            if(color[v] == 0){
//                q.push(v);
//                if(color[x] == 1){
//                    color[v] = 2;
//                } else if(color[x] == 2){
//                    color[v] = 1;
//                }
//            } else {
//                if(color[v] == color[x]) return false;
//            }
//        }
//        if(q.empty() && s.size() != 0){//van con dinh thi them tiep
//        	int a = *s.begin();
//        	q.push(a);
//        	color[a] = 1;
//		}
//    }
//
//    return true;
//}
//
//int main(){
//    int t;
//    cin >> t;
//    for(int i = 1; i <= t; i++){
//    	input();
//    	cout << "Scenario #" << i << ":" << endl;
//    	if(solve()) cout << "No suspicious bugs found!" << endl;
//    	else cout << "Suspicious bugs found!" << endl;
//	}
//    return 0;
//}
#include<bits/stdc++.h>//loi giai nay sai, loi giai tren dung
using namespace std;//thu voi bo test 1 5 4 1 2 3 4 4 5 5 3
const int MAX = 2004;

int n, m;
vector< vector<int> > listEdge;
int mark[MAX];

void input(){
    cin >> n >> m;

    listEdge.erase(listEdge.begin(), listEdge.end());
    listEdge.resize(n+1);
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        listEdge[tmp1].push_back(tmp2);
        listEdge[tmp2].push_back(tmp1);
    }

    for(int i=0; i<=n; i++) mark[i] = 0;
}

bool solve(){
    queue<int> q;
    q.push(1);
    mark[1] = 1;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : listEdge[x]){
            if(mark[v] == 0){
                if(mark[x] == 1) mark[v] = 2;
                else mark[v] = 1;
                q.push(v);
            } else {
                if(mark[v] == mark[x]) return false;
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;

    int cnt = 1;
    while(T > 0){
        input();

        cout << "Scenario #" << cnt << ":" << endl;
        if(solve()) cout << "No suspicious bugs found!";
        else cout << "Suspicious bugs found!";

        cout << endl;

        cnt++;
        T--;
    }

    return 0;
}
