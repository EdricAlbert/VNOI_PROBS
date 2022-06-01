#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int col[1004];
int r[1004];
int l[1004];
int res = 0;

void input(){
        for (int x, j=1; j<=m; j++){
            cin >> x;
            if (x == 0){
                col[j] = 0;
            } else {
                col[j]+=1;
            }
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    deque<pii> q;
    for (int i=1; i<=n; i++){
        input();
        // Find Left
        q.clear();
        for (int j=1; j<=m; j++){
            if (col[j] == 0){
                q.clear();
                l[j] = 0;
                continue;
            }
            int leftbest;
            if (q.empty()){
                leftbest = j;
            } else {
                leftbest = q.front().second;
            }
            while (!q.empty() && col[q.back().first] >= col[j]){
                q.pop_back();
            }
            if (q.empty()){
                l[j] = leftbest;
            } else {
                l[j] = q.back().first + 1;
            }
            q.push_back({j, l[j]});
        }
        // Find Right
        q.clear();
        for (int j=m; j>=1; j--){
            if (col[j] == 0){
                q.clear();
                r[j] = 0;
                continue;
            }
            int rightbest;
            if (q.empty()){
                rightbest = j;
            } else {
                rightbest = q.front().second;
            }
            while (!q.empty() && col[q.back().first] >= col[j]){
                q.pop_back();
            }
            if (q.empty()){
                r[j] = rightbest;
            } else {
                r[j] = q.back().first - 1;
            }
            q.push_back({j, r[j]});
        }
        for (int j=1; j<=n; j++){
            if (col[j] > 0){
                res = max(res, col[j] * (r[j] - l[j] + 1));
            }
        }
    }
    cout << res;
}
