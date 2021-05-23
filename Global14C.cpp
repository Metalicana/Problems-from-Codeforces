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
pii tree[400005];
vector<int>ans;
int m,n,row,col,x,y;
void init(int node,int b,int e)
{
  if(b==e)
  {
    tree[node].x=0;//x is min height
    tree[node].y=0;//y is max height
    return;
  }
  int l = node*2;
  int r = l+1;
  int m =(b+e)/2;
  init(l,b,m);
  init(r,m+1,e);
  tree[node].x = min(tree[l].x,tree[r].x);
  tree[node].y = max(tree[l].y,tree[r].y);
}
void update(int node,int b,int e,int y)
{
  if(b==e)
  {
    ans.pb(b);
    tree[node].x+=y;
    tree[node].y+=y;
    return;
  }
  int l = node*2;
  int r = l+1;
  int m =(b+e)/2;
  if(tree[l].x <= tree[r].x)update(l,b,m,y);
  else update(r,m+1,e,y);
  tree[node].x = min(tree[l].x,tree[r].x);
  tree[node].y = max(tree[l].y,tree[r].y);
}
void solve(int test)
{
  scanf("%d%d%d",&m,&n,&x);
  ans.clear();
  init(1,0,n-1);
  for(int i=0;i<m;i++)
  {
    scanf("%d",&y);
    update(1,0,n-1,y);
  }
  if(tree[1].y - tree[1].x > x)printf("NO\n");
  else
  {
     printf("YES\n");
     for(auto sex : ans)printf("%d ",sex+1);
     printf("\n");
  }
}
void test()
{
  int t;
  scanf("%d",&t);
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
