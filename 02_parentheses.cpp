//#include <bits/stdc++.h>//wrong on case )( because opening and closing brackets are not considered
//
//using namespace std;
//
//int t;
//int a[200];
//
//void input(){
//	cin >> t;
//	a['('] = 1; a[')'] = 6;
//	a['['] = 2; a[']'] = 5;
//	a['{'] = 3; a['}'] = 4;
//}
//
//void solve(){
//	string s;
//	stack<int> st;
//	while(t--){
//		fflush(stdin);
//		cin >> s;
//		st.push(a[s[0]]);
//		for(int i = 1; i < s.length(); i++){
//			if(!st.empty()){
//				if(a[s[i]] == 7 - st.top()){
//					st.pop();
//				}else{
//					st.push(a[s[i]]);
//				}	
//			}else{
//				st.push(a[s[i]]);
//			}
//		}
//		if(!st.empty()){
//			while(!st.empty()){
//				st.pop();
//			}
//			cout << 0;
//		}else cout << 1;
//		cout << endl;
//	}
//}
//
//int main(){
//	input();
//	solve();
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;

// Kiem tra ngoac mo va ngoac dong
// ngoac mo ( "(","{","[" ) -> true
// ngoac dong -> false
bool checkNgoac(char c){
    if(c == '(' || c == '{' || c == '[')
        return true;
    else return false;
}

// Kiem tra cung bo
// vi du : "(" va ")" la cung mot bo -> tra ve true
// khac bo thi tra ve false
bool checkBo(char c1, char c2){
    if(c1 == '(' && c2 == ')')
        return true;
    if(c1 == '{' && c2 == '}')
        return true;
    if(c1 =='[' && c2 == ']')
        return true;
    return false;
}

// Xu ly tung bo test
void handling(string str){
    stack<char> st;
    int lens = str.length();

    for(int i=0; i<lens; i++){
        if(st.empty()){
            // Neu stack dang rong, ma lai them vao 1 ngoac dong -> false
            if(!checkNgoac(str[i])){
                cout << "0" << endl;
                return;
            } else {
                st.push(str[i]);
                continue;
            }
        } else {
            char temp1 = st.top();
            char temp2 = str[i];
            // Neu dinh stack va phan tu them vao la 1 bo thi lay phan tu o dinh ngan xep ra va xet tiep
            if(checkBo(temp1,temp2)){
                st.pop();
                continue;
            } else {
                if(checkNgoac(temp2)){
                    st.push(str[i]);
                    continue;
                } else {
                    cout << "0" << endl;
                    return;
                }
            }
        }
    }

    if(st.empty()) cout << "1" << endl;
    else cout << "0" << endl;

}

int main(){
    int n;
    string str;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        handling(str);
    }

    return 0;
}
