#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int col[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int row[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool visited[1001][1001];
int dist[1001][1001];
int n, m, x, y, a, b;
const int INF = 1e9;

bool check(int x, int y){
    return (x>=1 && x<=n && y>=1 && y<=m);
}

int bfs(int &a, int &b){
    queue<pii> q;
    q.push({a, b});
    visited[a][b] = true;
    dist[a][b] = 0;
    while (!q.empty()){
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int i=0; i<8; i++){
            int _u = u + row[i];
            int _v = v + col[i];
            if (check(_u, _v) && !visited[_u][_v]){
                q.push({_u, _v});
                visited[_u][_v] = true;
                dist[_u][_v] = dist[u][v] + 1;
            }
        }
    }
    return dist[x][y];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("QUANMA.inp","r",stdin);
    freopen("QUANMA.out","w",stdout);
    cin >> n >> m;
    cin >> a >> b;
    cin >> x >> y;
    memset(visited, false, sizeof(visited));
    memset(dist, INF, sizeof(dist));
    long long res = bfs(a, b);
    if (res >= INF){
        cout << -1;
    } else {
        cout << res;
    }
}
