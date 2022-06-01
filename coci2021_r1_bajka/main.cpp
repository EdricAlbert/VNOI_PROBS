#include <bits/stdc++.h>

using namespace std;

int dp[302][302];
int n, m;
string a, b;
const int INF = 1e9;

void check(int i){
    for (int j=1; j<=n; j++){
        if (a[j] == b[i]){
            for (int z=1; z<=n; z++){
                if (z!=j && a[z] == a[j]){
                    dp[i][j] = min(dp[i][j], dp[i][z] + abs(z-j));
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int tmp1, tmp2;
    memset(dp, INF, sizeof(dp));
    for (int i=0; i<=301; i++){
        dp[0][i] = 0;
    }
    for (int i=1; i<=m; i++){
        // Xét phương án 1
        for (int j=1; j<=n; j++){
            if (a[j] == b[i]){
                // Check if b[i-1] is on the left side
                if (b[i-1] == a[j-1] || i==1){
                    tmp1 = dp[i-1][j-1];
                } else {
                    tmp1 = INF;
                }
                // Check if b[i-1] is on the right side
                if (b[i-1] == a[j+1] || i==1){
                    tmp2 = dp[i-1][j+1];
                } else {
                    tmp2 = INF;
                }
                dp[i][j] = min(tmp1, tmp2) + 1;
            }
        }
        // Xét phương án 2
        check(i);
    }
    int res = INF+INF;
    for (int i=1; i<=n; i++){
        if (a[i] == b[m]) res = min(res, dp[m][i]);
    }
    if (res>=INF){
        cout << -1;
    } else
    cout << res - 1;
}
