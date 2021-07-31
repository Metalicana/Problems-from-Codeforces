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

int m,n,row,col,x,y;
int jk[3][3][200005];
char s[200005];
void solve(int test)
{
  scanf("%d%d%s",&n,&m,s);
  memset(jk,0,sizeof jk);
  for(int i=0;i<3;i++)//this is the mod value
  {
    for(int j=0;j<3;j++)//this is the letter
    {
      for(int q=0;q<n;q++)
      {
        jk[i][j][q] = (q%3==i && s[q]-'a'==j)?1 : 0;
        if(q!=0)jk[i][j][q] += jk[i][j][q-1];
      }
    }
  }

  while(m--)
  {
    scanf("%d%d",&x,&y);
    x--;
    y--;
    if(y-x+1==1)printf("0\n");
    else if(y-x+1==2)
    {
      if(s[x]!=s[y])printf("0\n");
      else printf("1\n");
    }
    else
    {
      string g = "abc";
      int cost;
      int final_cost = 3000000;
      while(true)
      {
        cost = y-x+1;
        for(int q=0;q<3;q++)
        {
          if(x==0)cost -= jk[q][g[q]-'a'][y];
          else cost -= (jk[q][g[q]-'a'][y]-jk[q][g[q]-'a'][x-1]);
        }
        final_cost=min(final_cost,cost);
        if(!next_permutation(g.begin(),g.end()))break;
      }
      printf("%d\n",final_cost);


    }
  }
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
