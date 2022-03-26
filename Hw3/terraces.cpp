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
#define sz(a)       (int)a.size()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
#define ever        ;;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
const double Eps  = 1e-8;
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
int sub(int a, int b) {return (a - b) % 6 + ((a >= b) ? 0 : 6);}
// ----------------------------------------------------------------------------------------------------
int a[505][505],b[505][505]={};

void solve(){
    int n,m;cin>>n>>m;
    swap(n,m);
    FOR(i,0,n)FOR(j,0,m)cin>>a[i][j];
    int ans=0;
    FOR(i,0,n)FOR(j,0,m){
        for(int k=0;k<4;k++){
            int x=i+dx[k],y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m){
                if(a[i][j] > a[x][y]){
                    b[i][j]=1;
                }
            }
        }
    }
    FOR(i,0,n)FOR(j,0,m){
        if(b[i][j]){
            queue<pii> q;
            q.push({i,j});
            while(!q.empty()){
                int i=q.front().F,j=q.front().S;q.pop();
                for(int k=0;k<4;k++){
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0 && x<n && y>=0 && y<m && !b[x][y]){
                        if(a[x][y]==a[i][j]){
                            b[x][y]=1;
                            q.push({x,y});
                        }
                    }
                }
            }
        }
    }
    FOR(i,0,n)FOR(j,0,m)if(!b[i][j])ans++;
    cout<<ans<<endl;
}

int main(){
    INITIO()
    //int n;cin>>n;
    //while(n--){
        solve();
    //}
    return 0;
}
