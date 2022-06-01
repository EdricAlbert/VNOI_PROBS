#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii>

void solve(){
    priority_queue<
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("TAITRONG.inp","r",stdin);
    freopen("TAITRONG.out","w",stdout);
    cin >> n >> m >> s >> t;
    for (int u, v, w, i=1; i<=m; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    solve();
}
