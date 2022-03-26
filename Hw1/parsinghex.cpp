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
    string s;
    while(getline(cin,s)){
        for(int i=0;i<sz(s);i++){
            if(s[i]=='0' && (s[i+1]=='x' || s[i+1]=='X')){
                string c;
                for(int j=i+2;j<sz(s);j++){
                    if((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <= 'f') || (s[j] >= 'A' && s[j] <= 'F')){
                        c+=s[j];
                    }
                    else break;
                }
                ll ans=0,mul=1;
                reverse(all(c));
                for(int j=0;j<sz(c);j++){
                    if(c[j] >= '0' && c[j] <= '9'){
                        ans += (c[j]-'0')*mul;
                    }
                    else if(c[j] >= 'a' && c[j] <= 'f'){
                        ans += (c[j]-'a'+10)*mul;
                    }
                    else{
                        ans += (c[j]-'A'+10)*mul;
                    }
                    mul*=16;
                }
                //reverse(all(c));
                c+=s[i+1];c+=s[i];
                reverse(all(c));
                cout<<c<<' '<<ans<<endl;
            }
        }
    }
    return 0;
}
