#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

void solve(){
    int n, m;cin>>n>>m;
    map<string,int> cp;
    map<string,map<string,int>> pe; // people interview
    map<string,set<string>> p;// company people
    FOR(i,0,n){
        string s;
        int y;
        cin>>s>>y;
        cp[s] = y;
    }
    FOR(i,0,m){
        string a,b;
        int y;
        cin>>a>>b>>y;
        if(p[b].count(a)){
            if(y - pe[b][a] >= cp[b])cout<<1;
            else cout<<0;
            pe[b][a] = y;
        }
        else {
            pe[b][a] = y;
            p[b].insert(a);
            cout<<1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //int t;cin>>t;
    //while(t--)
        solve();
    
    return 0;
}