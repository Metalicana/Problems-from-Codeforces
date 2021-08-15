#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define eps 1e-9
#define maxn 100000
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
bool check(int mask,int i){return ((1<<i)&mask);}
int Set(int mask,int i){return mask | (1<<i);}

ll add(ll a, ll b)
{
  if(a+b<MOD)return a+b;
  return (a+b)%MOD;
}
ll mul(ll a, ll b)
{
  if(a*b < MOD)return a*b;
  return (a*b)%MOD;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int mx = 600005;

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE
struct segtree
{
  pii tree[(mx<<2)];
  pii prop[(mx<<2)];
  void reset()
  {
    memset(tree,0,sizeof tree);
    memset(prop,0,sizeof prop);
  }
  void propagate(int node,int b,int e)
  {
    if (prop[node].x == 0)
    			return;
    		tree[node] = max(tree[node], prop[node]);
    		if (b != e) {
    			prop[node*2] = max(prop[node*2], prop[node]);
    			prop[node*2+1] = max(prop[node*2+1], prop[node]);
    		}
    		prop[node].x = 0;
  }
  void update(int node,int b,int e,int i,int j, pii x)
  {
    propagate(node,b,e);
    if(b>j||e<i)return;

    if(b>=i&&e<=j)
    {
      prop[node] = max(x,prop[node]);
      propagate(node,b,e);
      return;
    }
    update(node*2,b,(b+e)/2,i,j,x);
    update(node*2+1,1+(b+e)/2,e,i,j,x);
    if(tree[node*2].x > tree[node*2+1].x)tree[node] = tree[node*2];
    else tree[node] = tree[node*2+1];
  }
  pii query(int node,int b,int e,int i,int j)
  {
    propagate(node,b,e);
    if(b>j || e< i)return pii(0,0);
    if(b >= i && e <= j)return tree[node];
    pii x = query(node*2,b,(b+e)/2,i,j);
    pii y = query(node*2+1,1+(b+e)/2,e,i,j);
    if(x.x > y.x)return x;
    return y;
  }

}seg;
int m,n,row,col;
vector <pii> grid[mx];
vector <int> ara;
int to[mx];
int res[mx];
bool ok[mx];
void solve(int test)
{
  scanf("%d%d",&n,&m);
  int a,b,c;
  for(int i=0;i<m;i++)
  {
    scanf("%d%d%d",&a,&b,&c);
    grid[a].emplace_back(b,c);
    ara.pb(b);
    ara.pb(c);
  }
  sort(ara.begin(),ara.end());
  ara.erase(unique(ara.begin(), ara.end()), ara.end());
  c = ara.sz;

  seg.reset();
  pii curmx=pii(0,0),cur;
  int ans = -5;
  for(int i=n;i;i--)
  {
    curmx = pii(0,0);
    for(auto &[eta,kemne] : grid[i])
    {
      eta = lower_bound(ara.begin(),ara.end(),eta) - ara.begin();
      kemne = lower_bound(ara.begin(),ara.end(),kemne) - ara.begin();
      cur = seg.query(1,0,c-1,eta,kemne);
      if(curmx.x < cur.x)curmx=cur;
    }
    curmx.x++;
    ans = max(ans, curmx.x);
    to[i] = curmx.y;
    res[i] = curmx.x;
    curmx.y = i;

    for(auto &[how, why] : grid[i])
    {
      seg.update(1,0,c-1,how,why,curmx);
    }
  }
  printf("%d\n",n-ans);
  for(int i=1; i<=n; i++) {
      if(res[i] == ans) {
         ok[i] = 1;
         int j = i;
         while(to[j]) {
            j = to[j];
            ok[j] = 1;
         }
         break;
      }
   }
   for(int i=1; i<=n; i++) if(!ok[i]) printf("%d ", i);

}
void test()
{
  int t=1;
  for(int test=1;test<=t;test++)
  {
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
