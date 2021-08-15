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

int m,n,row,col;

void solve(int test)
{
  cin >> row >> col >> m;
  if(row%2==1)//vertical bias horizontal pieces needed
  {
    n = (row*col)/2 - m;
    //vertical pieces need to be odd.
    if(m==0)cout<<"NO\n";
    else if(n == 0)cout<<"YES\n";
    else
    {
      int bruh = (row-1)>>1;
      bruh *= col;
      if(bruh<n)cout<<"NO\n";
      else
      {
        if(n%2==1)cout<<"NO\n";
        else
        {
          if(row==1)cout<<"NO\n";
          else cout<<"YES\n";
        }
      }

    }

  }
  else if(col%2==1)//vertical pieces needed pieces needed
  {
    if((row*col)/2 - m == 0)cout<<"NO\n";
    else if(m == 0)cout<<"YES\n";
    else
    {
      int bruh = (col-1)>>1;
      bruh *= row;//how many horizontal pieces can fit at best
      if(bruh<m)
      {
        cout <<"NO\n";
      }
      else
      {
        if(m%2==1)cout<<"NO\n";
        else
        {
          if(col==1)cout<<"NO\n";
          else cout<<"YES\n";
        }
      }

    }
  }
  else
  {
    if(m%2==1)printf("NO\n");
    else printf("YES\n");
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
