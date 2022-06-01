#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int a[30001];
int n;
int r[30001], l[300001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    deque<pii> q;
    while (t--){
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        //Find Left
        int leftbest;
        q.clear();
        for (int i=1; i<=n; i++){
            if (q.empty()){
                leftbest = i;
            } else {
                leftbest = q.front().second;
            }
            while (!q.empty() && a[q.back().first] >= a[i]){
                q.pop_back();
            }
            if (q.empty()){
                l[i] = leftbest;
            } else {
                l[i] = q.back().first + 1;
            }
            q.push_back({i, l[i]});
        }
        //Find Right;
        int rightbest;
        q.clear();
        for (int i=n; i>=1; i--){
            if (q.empty()){
                rightbest = i;
            } else {
                rightbest = q.front().second;
            }
            while (!q.empty() && a[q.back().first] >= a[i]){
                q.pop_back();
            }
            if (q.empty()){
                r[i] = rightbest;
            } else {
                r[i] = q.back().first - 1;
            }
            q.push_back({i, r[i]});
        }
        long long res = 0;
        int v1 = 0;
        int v2 = 0;
        for (int i=1; i<=n; i++){
            long long tmp = 1ll * a[i] * (r[i] - l[i] + 1);
            if (tmp > res){
                res = tmp;
                v1 = r[i];
                v2 = l[i];
            }
        }
        cout << res << " " << v2 << " " << v1 << '\n';
    }
}
