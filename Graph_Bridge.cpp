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
#define cases(t) int t;scanf("%lld",&t); rep(casn,1,t+1)
#define el cout<<endl;
#define deci(n) int n; scanf("%lld",&n);
#define decs(n) string n; cin>>n;
#define sz(v) v.size()
#define repit(m) for(auto it=m.begin();it!=m.end();it++)
#define ins insert
 #define INF 1000000000000000000
//  cerr << "\nTime : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
 
 
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
    return b;
    else 
    {
        return a;
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
    return ans;
}
int modinverse(int a)
{
    return power(a,mod-2);
}
vector<int>v[100005];
int visit[100005],parent[100005],disc[100005],low[100005];
int etime=1;
// bridges in a given graph
map<pair<int,int>,int>marked;
void dfs(int s,int p)
{
    visit[s]=1;
    disc[s]=etime;
    low[s]=etime;
    etime++;
    for(int i=0;i<v[s].size();i++)
    {
        if(visit[v[s][i]]==0)
        {
            parent[v[s][i]]=s;
            dfs(v[s][i],s);
            low[s]=min(low[s],low[v[s][i]]);
            if(low[v[s][i]]>disc[s])
            {
                marked[{min(v[s][i],s),max(s,v[s][i])}]++;
            }
        }
        else if(parent[s]!=v[s][i])
        {
                low[s]=min(low[s],disc[v[s][i]]);
        }
    }   
}
 
signed main()
{
     int n,m;
     cin>>n>>m;
      vector<pair<int,int>>vx;
     for(int i=1;i<=m;i++)
     {
         int x,y,w;cin>>x>>y; 
          v[x].pb(y);
          v[y].pb(x);
         vx.pb({min(x,y),max(x,y)});
     }
     for(int i=1;i<=n;i++)
     {
         if(visit[i]==0)
         {
             dfs(i,-1);
         }
     }
    //  dfs(1,-1);
     int x;
     cin>>x;
     int count=0;
     for(int i=0;i<x;i++)
     {
         int z;
         cin>>z;
         if(marked.find(vx[z-1])!=marked.end())
         {
             count++;
         }
     }
     cout<<count;el
}
