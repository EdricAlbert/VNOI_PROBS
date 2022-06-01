#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[17001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;

    while (t--){
        cin >> n >> k;
        deque<int> q;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        for (int i=1; i<=n; i++){
            while(!q.empty() && a[q.back()] >= a[i]){
                q.pop_back();
            }
            while (!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            q.push_back(i);
            if (i>=k){
                cout << a[q.front()] << " ";
            }
        }
        cout << '\n';
    }
}
