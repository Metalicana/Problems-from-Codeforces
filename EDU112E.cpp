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

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

int mx = 300005;
int m,n,row,col;
vector<pii>ranges(mx);
struct segtree
{
  #define LEFT (node << 1)
  #define RIGHT (node<< 1 | 1)
  #define MID ((b+e)>>1)
  vector<int>tree;
  vector<int>prop;
  void init(int n)
  {
    tree.resize(n<<4);
    prop.resize(n<<4);
    fill(tree.begin(),tree.end(),0);
    fill(prop.begin(),prop.end(),0);
  }
  void propagate(int node,int b,int e)
  {
    if(prop[node]!=0)
    {
      tree[node] += prop[node];
      if(b!=e)
      {
        prop[LEFT] += prop[node];
        prop[RIGHT] += prop[node];
      }
    }
    prop[node]=0;
  }
  int query(int node,int b,int e,int i,int j)
  {
    propagate(node,b,e);
    if(b>j||e<i)return MOD;
    if(b>=i&&e<=j)return tree[node];
    return min(query(LEFT,b,MID,i,j),query(RIGHT,MID+1,e,i,j));
  }
  void update(int node,int b,int e,int i,int j,int x)
  {
    propagate(node,b,e);
    if(b>j||e<i)return;
    if(b>=i&&e<=j)
    {
      prop[node]+=x;
      propagate(node,b,e);
      return;
    }
    update(LEFT,b,MID,i,j,x);
    update(RIGHT,MID+1,e,i,j,x);
    tree[node] = min(tree[LEFT],tree[RIGHT]);
  }
}seg;
struct segment
{
  int b,e,val;
}ara[300005];
bool cmp(segment a, segment b)
{
  return a.val < b.val;
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  seg.init(m);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d%d",&ara[i].b,&ara[i].e,&ara[i].val);
  }
  sort(ara,ara+n,cmp);
  int ans = MOD;
  for(int i=0,j=0;j<n&&i<n;j++)
  {
  //  trace2(i,j)
    seg.update(1,1,m-1,ara[j].b,min(m-1,ara[j].e-1),1);
    if(seg.query(1,1,m-1,1,m-1)>0)
    {
      ans = min(ans,ara[j].val - ara[i].val);
      while(i <= j)
      {
        seg.update(1,1,m-1,ara[i].b,min(ara[i].e-1,m-1),-1);
        if(seg.query(1,1,m-1,1,m-1)<=0)
        {
          //trace2(i,j)
          ans = min(ans,ara[j].val - ara[i].val);
          //seg.update(1,1,m-1,ara[i].b,min(m-1,ara[i].e-1),1);
          i++;
          break;
        }
        i++;
      }
    }

  }
  printf("%d\n",ans);
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
