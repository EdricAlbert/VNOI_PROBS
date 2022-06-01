#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int n, m;
int col[1001];
long long res = 0;
int l[1001];
long long save[1001];

void FindLeft(){
    deque<pii> q;
    int base;
    for (int i=1; i<=m; i++){
        if (q.empty()){
            base = i;
        } else {
            base = q.front().first;
        }
        while (!q.empty() && col[q.back().second] >= col[i]){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
    string st;
    for (int i=1; i<=n; i++){
        cin >> st;
        st = " " + st;
        for (int j=1; j<=m; j++){
            if (st[j]=='1'){
                col[j]++;
            } else {
                col[j] = 0;
            }
        }
        FindLeft();
        for (int j=1; j<=m; j++){
            save[j] = 1ll * col[j] * (j - l[j] + 1) + save[l[j]-1];
            res+= save[j];
        }
    }
    cout << res;
}
