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
const int dx[6] = {0, 1, 1, 0, -1, -1};
const int dy[6] = {1, 0, -1, -1, 0, 1};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
int sub(int a, int b) {return (a - b) % 6 + ((a >= b) ? 0 : 6);}
// -----------------------------------------------------------------------------------------------------

int main(){
    INITIO()
    int n,m,p;
    cin>>n>>m>>p;
    vector<int>a(n),b(m);
    FOR(i,0,n)cin>>a[i];
    FOR(i,0,m)cin>>b[i];
    vector<double> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans.pb(a[i]*1.0/b[j]*1.0);
        }
    }
    sort(all(ans));
    //for(auto it:ans)cout<<it<<endl;
    //cout<<endl;
    for(int i=1;i<sz(ans);i++){
        //cout<<ans[i]<<' '<<ans[i-1]<<' '<<ans[i]/a[i-1] <<endl;
        if((ans[i]-ans[i-1])/ans[i-1] > p*1.0/100){
            cout<<"Time to change gears!"<<endl;
            return 0;
        }
    }
    cout<<"Ride on!"<<endl;
    return 0;
}
