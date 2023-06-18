//#include <bits/stdc++.h>
//
//using namespace std;
//
//int m, n, a = 0;
//vector<int> course[100];//moi phan tu la mot khoa hoc gom cac giao vien co the day duoc
//int conflict[100];//khoa hoc xung dot
//int c[100]; //xem moi khoa hoc duoc day boi ai
//bool cour[100];//xem khoa hoc nay duoc day chua
//int teacherLoad[100];//tai trong cua moi giao vien
//int maxLoad = -1;
//int minAns = 1e6 + 5;
//
//void input(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> m >> n;
//	for(int i = 1; i <= m; i++){
//		int k;
//		cin >> k;
//		for(int j = 0; j < k; j++){
//			int t;
//			cin >> t;
//			course[t].push_back(i);
//		}
//	}
//	int k;
//	cin >> k;
//	for(int i = 0; i < k; i++){
//		int p, q;
//		cin >> p >> q;
//		conflict[p] = q;
//		conflict[q] = p;//bai nay sai o cho nay, mot khoa hoc co the co nhieu khoa hoc xung dot
//	}
//}
//
//bool check(int v, int k){
//	if(cour[k]) return false;
//	if(course[k][v] == c[conflict[k]] && cour[conflict[k]] ) return false;
//	return true;
//}
//
//void solution(){
////	for(int i = 1; i <= m; i++){
////		if(maxLoad < teacherLoad[i]) maxLoad = teacherLoad[i];
////	}
//	minAns = min(minAns, maxLoad);
//	maxLoad = -1;
//}
//
//void Try(int k){
//	for(int v = 0; v < course[k].size(); v++){
//		if(check(v, k)){
//			c[k] = course[k][v];
//			teacherLoad[c[k]]++;
//			int pre = maxLoad;
//			maxLoad = max(teacherLoad[c[k]], maxLoad);
////			cout << "**" << "teacherLoad[" << c[k] << "] = " << teacherLoad[c[k]] << endl;
//			cour[k] == true;
//			if(k == n) solution();
//			else Try(k+1);
//			cour[k] == false;
//			teacherLoad[c[k]]--;
//			maxLoad = pre;
//		}
//	}
//}
//
//int main(){
//	input();
//	Try(1);
//	if(minAns == 1e6+5) cout << -1;
//	else cout << minAns;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int MAX = 40;

int n, m;
int course[MAX]; // course a assign for teacher course[a]
int theTeacherChoose[MAX]; // Which teacher choose this course?
vector<vector<int> > listOfCourse; // list of course teacher can teach
vector<vector<int> > listOfPairsOfConflicting; // list of pairs(course) of conflicting
int theLoadOfTeacher[MAX];
int theLoadMaxOfTeacher = 0;
int minAll = 2147483647;

/*enter data from standand input*/
void inputData(){
    int k;
    cin >> m >> n;
    listOfCourse.resize(m);
    for(int i=0; i<m; i++){
        cin >> k;
        for(int j=0; j<k; j++){
            int temp;
            cin >> temp;
            listOfCourse[i].push_back(temp);
        }
    }

    cin >> k;
    listOfPairsOfConflicting.resize(n+1);
    for(int i=0; i<k; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        listOfPairsOfConflicting[temp1].push_back(temp2); // course temp1 config with temp2
        listOfPairsOfConflicting[temp2].push_back(temp1); // if course temp1 config temp2, so course temp2 config with temp1 too
    }

}

/*recursive backtracking*/
//check procedure
bool check(int a, int i){ // Khoa hoc a duoc gan cho thay giao i
    int tick = 0;
    for(int j=0; j<listOfCourse[i].size(); j++)
        if(listOfCourse[i].at(j) == a)
            tick++;
    if(tick == 0) return false;

    for(int j=0; j<listOfPairsOfConflicting[a].size(); j++){
        if(course[listOfPairsOfConflicting[a].at(j)] == i && listOfPairsOfConflicting[a].at(j) < a)
            return false;
    }
    return true;
}

void solution(){
    minAll = min(minAll,theLoadMaxOfTeacher);
}

void TRY(int a){
    for(int i=0; i<m; i++){
        if(check(a,i)){
            course[a] = i;
            theLoadOfTeacher[i]++;
            int pre = theLoadMaxOfTeacher;
            theLoadMaxOfTeacher = max(theLoadMaxOfTeacher,theLoadOfTeacher[i]);

            if(a==n) solution();
            else
                if(theLoadMaxOfTeacher < minAll ) TRY(a+1);

            theLoadOfTeacher[i]--;
            theLoadMaxOfTeacher = pre;
        }
    }
}

int main(){
    inputData();
    TRY(1);
    cout << minAll;

    return 0;
}
