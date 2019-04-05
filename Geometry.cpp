// Credits : Utkarsh Saxena 
// Handle : usaxena

#include<bits/stdc++.h>
using namespace std;
#define fre freopen("0.in", "r", stdin), freopen("0.out", "w", stdout)
#define MOD 1000000007
#define LL signed long long int

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define ford(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
#define fora(it,x) for(auto it:x)
#define PI 3.14159265
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

double INF = 1e100;
double EPS = 1e-12;
struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(int x, int y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(double c) const { return PT(x * c, y * c); }
  PT operator/(double c) const { return PT(x / c, y / c); }
};
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p) { return PT(-p.y, p.x); }
PT RotateCW90(PT p) { return PT(p.y, -p.x); }
PT RotateCCW(PT p, double t) {
  return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS)
    return a;
  r = dot(c - a, b - a) / r;
  if (r < 0)
    return a;
  if (r > 1)
    return b;
  return a + (b - a) * r;
}
// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z, double a, double b,
                          double c, double d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
// determine if line segment from a to b intersects with

// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return true;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return false;
    return true;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0)
    return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0)
    return false;
  return true;
}
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b = b - a;
  d = c - d;
  c = c - a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b * cross(c, d) / cross(b, d);
}
vector< pair<PT, PT> > V;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  a %= b;
  return gcd(b, a);
}
int Int(double x) {
  if (ceil(x) - x < x - floor(x))
    return ceil(x);
  return floor(x);
}
bool isInt(double x) { return fabs(Int(x) - x) <= EPS; }

int main(){
  cout<<"hello"<<endl;
  return 0;
}
