#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'

int n,m, cnt[5005][5005]={};
char a[5005][5005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    cin>>n>>m;
    FOR(i,0,n)FOR(j,0,m)cin>>a[i][j];
    FOR(i,0,n){
        for(int j=m-1;j>=0;j--){
            if(a[i][j]!='1')cnt[i][j] = cnt[i][j+1] + 1;
        }
    }
    /*
    FOR(i,0,n){
        FOR(j,0,m)cout<<cnt[i][j];
        cout<<endl;    
    }
    */
    int ans=0;
    FOR(j,0,m){
        stack<pii> s;
        s.push({0,0});
        for(int i=0;i<=n;i++){
            while(s.top().F > cnt[i][j]){
                pii top = s.top();
                s.pop();
                ans = max(ans, max(cnt[i][j] * (i - top.second + 1), top.F * (i-s.top().S)));
            }
            s.push({cnt[i][j], i+1});
        }
    }
    cout<<ans<<endl;
    return 0;
}