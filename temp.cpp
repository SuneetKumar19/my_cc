#include <bits/stdc++.h>
using namespace std;
#define int  long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define gcd __gcd
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define min3(a,b,c) min(a,min(b,c))
#define mai3(a,b,c) mai(a,mai(b,c))
#define all(i) i.begin(),i.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define set_bit __builtin_popcount //gives number of set_bits
#define ff first
#define ss second
#define cases(t) int t;cin>>t; rep(casn,1,t+1)
#define el cout<<"\n";
#define deci(n) int n; scanf("%lld",&n);
#define decs(n) string n; cin>>n;
#define sz(v) v.size()
#define repit(m) for(auto it=m.begin();it!=m.end();it++)
#define cYES cout<<"YES\n";
#define cNO cout<<"NO\n";
#define ins insert
#define INF 1000000000000000000
#define NP 50000
//  cerr << "\nTime : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";

//  IIITA
//SUNEET KUMAR -->  ਸੁਨੀਤ 
 int power(int a,int x)
 {
         a%=mod;
        int res=1;
		while(x>0)
        {
            if(x&1)
            res=res*a%mod;
            a=a*a%mod;
            x>>=1;  
        }
		return res;
}
int mai(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}
int madd(int a,int b)
{
    int ans;
    ans=(a%mod+b%mod)%mod;
    return ans;
}
int mmult(int a,int b)
{
    int ans=1;
    ans=((a%mod)*(b%mod))%mod;
    return ans%mod;
}
int modinverse(int a)
{
    return power(a,mod-2);
}
int memo[200005][24],visit[200005],level[200005];
vector<int>v[200005];

void dfs(int s,int parent)
{
    visit[s]=1;
    memo[s][0]=parent;
    for(int i=1;i<=20;i++)
    {
        memo[s][i]=memo[memo[s][i-1]][i-1];
    }

    for(int i=0;i<v[s].size();i++)
    {
        if(visit[v[s][i]]==0)
        {
            level[v[s][i]]=level[s]+1;
            dfs(v[s][i],s);
        }
    }
}
int lca(int a,int b)
{
    // a->higher level
    if(level[a]<level[b])
    {
        swap(a,b);
    }

    for(int i=20;i>=0;i--)
    {
        if((level[a]-power(2,i))>=level[b])
        {
            a=memo[a][i];
        }
    }

    if(a==b)
    return a;

    for(int i=20;i>=0;i--)
    {
        if(memo[a][i]!=memo[b][i])
        {
            a=memo[a][i];
            b=memo[b][i];
        }
    }
    return memo[a][0];
}


signed main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    {
        memset(memo[i],-1,sizeof memo[i]);
    }

    dfs(1,1);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y);el
    }
}