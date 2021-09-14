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
const int mxn = 200005;
int m,n,row,col,k,x,y;
int verS[mxn],horS[mxn];
int verR[mxn],horR[mxn];
map<int,int> horM,verM;
vector<pii>points;
bool cmp(pii a, pii b)
{
  return a.y < b.y;
}
void solve(int test)
{
  scanf("%d%d%d",&n,&m,&k);
  for(int i=0;i<n;i++)scanf("%d",&verS[i]);//X coordinate of the i'th vertical street
  for(int i=0;i<m;i++)scanf("%d",&horS[i]);//Y coordinate of the i'th horizontal street
  memset(verR,0,sizeof verR);
  memset(horR,0,sizeof horR);

  points.clear();
  for(int i=0;i<k;i++)
  {
    scanf("%d%d",&x,&y);
    points.pb({x,y});
  }
  horM.clear();
  verM.clear();
  sort(points.begin(),points.end());
  int prev=0;
  ll bruh = 0;
  for(auto [x,y] : points)
  {
    row = upper_bound(horS,horS+m,y) - horS;
    col = upper_bound(verS,verS+n,x) - verS;
    if(prev!=col-1)
    {
      horM.clear();
    }
    if(horS[row-1] == y && verS[col-1] == x)
    {
      prev = col-1;
      continue;
    }//junction alert
    else if(horS[row-1]==y)//lives in the horizontal street
    {
      verR[col-1]++;
      horM[y]++;
      bruh += (horM[y]-1);
    }
    prev = col-1;
    //trace(prev)
  }
  //trace(bruh)
  sort(points.begin(),points.end(),cmp);
  prev=0;
  for(auto [x,y] : points)
  {
    row = upper_bound(horS,horS+m,y) - horS;
    col = upper_bound(verS,verS+n,x) - verS;
    if(prev!=row-1)verM.clear();
    if(horS[row-1] == y && verS[col-1] == x)
    {
      prev = row - 1;
      continue;
    }//junction alert
    else if(verS[col-1]==x)//lives in the horizontal street
    {
      horR[row-1]++;
      verM[x]++;
      bruh += (verM[x]-1);
    }
    prev = row-1;
  }
  long long ans = 0;
  for(int i=0;i<n;i++)ans += ((ll)verR[i]*(ll)(verR[i]-1))/2;
  for(int i=0;i<m;i++)ans += ((ll)horR[i]*(ll)(horR[i]-1))/2;
  printf("%I64d\n",ans-bruh);
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
