#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1001][1001];
int h1[1001];
int h2[1001];
long long res = 0;
int r[1001], l[1001];

typedef pair<int, int> pii;

void FindLeft(int x){
    deque<pii> q;
    int base;
    for (int i=1; i<=m; i++){
        if (h2[i] == 0){
            q.clear();
            continue;
        }
        if (q.empty()){
            base = i;
        } else {
            base = q.front().first;
        }
        while (!q.empty() && h2[q.back().second] >= h2[i]){
            q.pop_back();
        }
        if (q.empty()){
            l[i] = base;
        } else {
            l[i] = q.back().second + 1;
        }
        q.push_back({l[i], i});
    }
}

void FindRight(int x){
    deque<pii> q;
    int base;
    for (int i=m; i>=1; i--){
        if (h2[i] == 0){
            q.clear();
            continue;
        }
        if (q.empty()){
            base = i;
        } else {
            base = q.front().first;
        }
        while (!q.empty() && h2[q.back().second] >= h2[i]){
            q.pop_back();
        }
        if (q.empty()){
            r[i] = base;
        } else {
            r[i] = q.back().second - 1;
        }
        q.push_back({r[i], i});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        a[0][m] = -1e9;
    }
    for(int i=1; i<=n; i++){
        a[i][0] = -1e9;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            if (a[i-1][j] <= a[i][j]){
                h1[j]++;
            } else {
                h1[j] = 1;
            }
        }
        h2[1] = 0;
        for (int j=2; j<=m; j++){
            if (a[i][j-1] <= a[i][j]){
                h2[j]++;
            } else {
                h2[j] = 0;
            }
        }
        for (int j=1; j<=m; j++){
            h2[j] = min(h2[j], min(h1[j], h1[j-1]));
        }
        FindLeft(i);
        FindRight(i);
        for (int j=1; j<=m; j++){
            res = max(res, 1ll * h2[j] * (r[j] - l[j] + 2));
            res = max(res, 1ll * h1[j]);
        }
    }
    cout << res;
}
