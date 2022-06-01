#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

long long res = 0;
int a[1001];
int col_o[1001], r_o[1001], l_o[1001];
int col_z[1001], r_z[1001], l_z[1001];
int n, m;

void solve(int col[], int r[], int l[]){
    deque<pii> q;
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
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[j];
            if (a[j] == 1){
                col_o[j]++;
                col_z[j] = 0;
            } else {
                col_o[j] = 0;
                col_z[j]++;
            }
        }
        solve(col_o, r_o, l_o);
        solve(col_z, r_z, l_z);
        for (int j=1; j<=n; j++){
            long long tmp1, tmp2;
            if ((r_o[j] - l_o[j] + 1) >= col_o[j]){
                tmp1 = col_o[j];
            } else {
                tmp1 = -1;
            }
            if ((r_z[j] - l_z[j] + 1) >= col_z[j]){
                tmp2 = col_z[j];
            } else {
                tmp2 = -1;
            }
        res = max(res, max(tmp1, tmp2));
        }
    }
    cout << res;
}
