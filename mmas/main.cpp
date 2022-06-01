#include <bits/stdc++.h>

using namespace std;

string st;
int val[10000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> st;
    deque<int> q;
    val['C'] = 12;
    val['H'] = 1;
    val['O'] = 16;
    val['('] = 0;
    for (int i=0; i<st.size(); i++){
        if (st[i] == '('){
            q.push_back(val[st[i]]);
        } else
        if (st[i] == ')'){
            int sum = val[st[i]];
            int v = 1e9;
            while (v!=0){
                v = q.back();
                if (v!=0){
                    sum += v;
                }
                q.pop_back();
            }
            q.push_back(sum);
        } else
        if (st[i] == 'C' || st[i] == 'H' || st[i] == 'O'){
            q.push_back(val[st[i]]);
        } else
        {
            int v = q.back();
            q.pop_back();
            q.push_back(v*(st[i]-'0'));
        }
    }
    int res = 0;
    for (int i=0; i<q.size(); i++){
        res += q[i];
    }
    cout << res;
}
