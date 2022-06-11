#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(), a.end() 
#define FOR(i,a,b) for(int i=a;i<b;i++)
const int N = 1e5+5;

int n,q, op=0;

struct dsu{
    int f[N],st[N];
    ll cnt[N] = {}, siz[N] = {}, tot=0;
    int find(int x){
        if(x == f[x])return x;
        return f[x] = find(f[x]);
    }

    void unio(int x,int y){
        x = find(x);
        y = find(y);
        if(x!=y){
            f[x] = y;
            cnt[y] += cnt[x];
            siz[y] += siz[x];
        }
    }

}a,b;

int main(){
    //freopen("in.txt", "r", stdin);
    cin>>n>>q;
    a.tot = b.tot = 0;
    FOR(i,0,n){cin>>b.cnt[i];b.st[i] = a.siz[i] =1;a.f[i] = i;}
    FOR(i,0,n){cin>>a.cnt[i];a.st[i] = 0;b.siz[i] =1;b.f[i] = i;}
    vector<pii> qey;
    while(q--){
        int u,v;cin>>u;
        if(u == 1){
            cin>>v;
            v--;
            qey.pb({1,v});
            b.st[v] = 0;
        }
        else {
            op++;
            qey.pb({2,0});
        }
    }

    ll sum = 0,  k = 0;
    FOR(i,0,n){
        if(b.st[i]){
            sum += b.cnt[i];
            k++;
        }
        else {
            b.tot += sum * k;
            k=0;
            sum=0;
        }
    }
    b.tot += sum * k;
    
    FOR(i,1,n){
        if(b.st[i] && b.st[i-1]) b.unio(i,i-1);
    }
    vector<ll> ans(op, 0);
    //low to turn off
    int id = 0;
    for(auto [u,x]:qey){
        if(u == 1){
            if(x+1 < n && a.st[x+1]){
                int g = a.find(x+1);
                a.tot -= a.cnt[g] * a.siz[g];
                a.unio(x+1,x);
            }
            if(x-1 >=0 && a.st[x-1]){
                int g = a.find(x-1);
                a.tot -= a.cnt[g] * a.siz[g];
                a.unio(x-1,x);
            }
            a.st[x] = 1;
            int fr = a.find(x);
            a.tot += a.cnt[fr] * a.siz[fr];
        }
        else {
            ans[id++] += a.tot;
        }
    }

    reverse(qey.begin(), qey.end());

    for(auto [u,x]:qey){
        if(u == 1){
            if(x+1 < n && b.st[x+1]){
                int g = b.find(x+1);
                b.tot -= b.cnt[g] * b.siz[g];
                b.unio(x+1,x);
            }
            if(x-1 >=0 && b.st[x-1]){
                int g = b.find(x-1);
                b.tot -= b.cnt[g] * b.siz[g];
                b.unio(x-1,x);
            }
            b.st[x] = 1;
            int fr = b.find(x);
            b.tot += b.cnt[fr] * b.siz[fr];
        }
        else {
            ans[--id] += b.tot;
            //cout<<b.tot<<endl;
        }
    }
    //reverse(all(ans));
    for(auto it:ans)cout<<it<<endl;
    return 0;
}