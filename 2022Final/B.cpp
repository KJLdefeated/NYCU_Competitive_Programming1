#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(a) (a.begin(),a.end())
int dx[4] = {0, 1, 0 ,-1}, dy[4] = {1, 0, -1, 0};
int n,m,Q;
char grid[505][505];
int cnt[105][505][505]={};

struct trp{
    int F;int S;int id;
};

vector<trp> tr;

void bfs(int i,int x, int y){
    queue<pii> q;
    q.push({x,y});
    cnt[i][x][y] = 0;
    while(q.size()){
        int a = q.front().F, b = q.front().S;
        q.pop();
        for(int k=0;k<4;k++){
            int fx = a + dx[k], fy = b + dy[k];
            if(fx>=0 && fx<n && fy>=0 && fy<n && grid[fx][fy] != '#'){
                if(cnt[i][fx][fy] == 1e9+5)q.push({fx,fy});
                cnt[i][fx][fy] = min(cnt[i][a][b] + 1, cnt[i][fx][fy]); 
            }
        }
    }
}
int tx,ty;

bool cmp(trp a, trp b){
    if(cnt[a.id][tx][ty] == cnt[b.id][tx][ty]) return a.id<b.id;
    return cnt[a.id][tx][ty] < cnt[b.id][tx][ty];
}

void solve(){
    cin>>n>>m>>Q;
    FOR(i,0,n)FOR(j,0,n)cin>>grid[i][j];
    FOR(i,0,m)FOR(j,0,n)FOR(k,0,n)cnt[i][j][k] = 1e9+5;
    FOR(i,0,m){
        int x,y;cin>>x>>y;
        x--;
        y--;
        tr.pb({x,y,i});
        bfs(i, x, y);
    }
    while(Q--){
        int x,y,k;
        cin>>x>>y>>k;
        x--;y--;
        tx = x; 
        ty = y;
        k--;
        sort(tr.begin(), tr.end(), cmp);
        int id = tr[k].id;
        if(cnt[id][x][y] == 1e9+5){
            cout<<-1<<endl;
        }
        else {
            cout<<id+1<<endl;
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