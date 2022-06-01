#include <bits/stdc++.h>

using namespace std;

map<long long, int> same;
deque<int> q;
long long res = 0;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    int x;
    cin >> x;
    q.push_back(x);
    same[x] = 1;
    for (int i=2; i<=n; i++){
        cin >> x;
        while (!q.empty() && x >= q.back()){
            res += same[q.back()];
            if (x != q.back()){
                same[q.back()] = 0;
            }
            q.pop_back();
        }
        if (!q.empty()) res++;
        q.push_back(x);
        same[x]++;
    }
    cout << res;
}
