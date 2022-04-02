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

set<pair<string,int>> ans;

void compute(string x){
    int a[4]={4,4,4,4};
    string y,k=x;
    int l=0,r=1;
    for(int i=0;i<x.size();i++)if(x[i]=='+'||x[i]=='-')y+=x[i];
    for(int i=0;i<x.size();i++){
        if(x[i]=='*'){
            a[l]*=a[r];
            a[r]=-1;
            for(int j=r;j<3;j++)swap(a[j],a[j+1]);
        }
        else if(x[i]=='/'){
            //if(a[l]%a[r])return;
            a[l]/=a[r];
            a[r]=-1;
            for(int j=r;j<3;j++)swap(a[j],a[j+1]);
        }
        else{
            l++;
            r++;
        }
    }
    x=y;
    for(int i=0;i<sz(x);i++){
        l=0;r=1;
        if(x[i]=='+'){
            a[l]+=a[r];
            a[r]=-1;
            for(int j=r;j<3;j++)swap(a[j],a[j+1]);
        }
        if(x[i]=='-'){
            a[l]-=a[r];
            a[r]=-1;
            for(int j=r;j<3;j++)swap(a[j],a[j+1]);
        }
    }
    string s="4";
    s+=' ';s+=k[0];s+=' ';s+='4';s+=' ';s+=k[1];s+=' ';s+='4';s+=' ';s+=k[2];s+=' ';s+='4';
    ans.insert({s,a[0]});
}

void solve(string x){
    if(x.size()==3){
        compute(x);
        return;
    }
    solve(x+'+');
    solve(x+'-');
    solve(x+'*');
    solve(x+'/');
}

int main(){
    INITIO()
    solve("");
    //for(auto it:ans)cout<<it.F<<" = "<<it.S<<endl;
    int n;
    int t;cin>>t;
    while(t--){
        cin>>n;
        int p=1;
        for(auto it:ans){
            if(it.S==n){
                cout<<it.F<<" = "<<it.S<<endl;
                p=0;
                break;
            }
        }
        if(p)cout<<"no solution"<<endl;
    }
    
    return 0;
}
