#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <list>
#include <string.h>
#include <sstream>
using namespace std;
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FILE        freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define eb          emplace_back
#define all(a)      a.begin(),a.end()
#define rall(a)      a.rbegin(),a.rend()
#define sz(a)       (int)a.size()
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
#define ever        ;;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
typedef                pair<long,long> pll;
const int Inf     = 1e9+9;
const int Mod     = 1e9+7;
const int N       = 1e5+9;
const int dx[4] = {0, 1,  0, -1};
const int dy[4] = {1, 0, -1,  0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------

void solve(){
    vector<int> a(4);
    int t;int x,y;
    FOR(i,0,4){
        scanf("%d.%d",&x,&y);
        a[i]=x*100+y;
    }
    scanf("%d.%d",&x,&y);
    t=x*100+y;
    sort(all(a));
    if(a[1]+a[2]+a[3] <= t*3)printf("infinite\n");
    else if(a[0]+a[1]+a[2] > t*3)printf("impossible\n");
    else{
        int ans=t*3-a[1]-a[2];
        int res=ans%100;
        if(res<10)printf("%d.0%d\n",ans/100,res);
        else printf("%d.%d\n",ans/100,res);
    }
}


int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        solve();
    //}
    return 0;
}
