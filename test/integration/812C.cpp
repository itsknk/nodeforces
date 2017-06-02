/**
 * @Author: Krishna Kalubandi <krishna>
 * @Date:   2017-06-01T20:11:24+05:30
 * @Email:  krishnakalubandi@gmail.com
 * @Filename: 812C.cpp
 * @Last modified by:   krishna
 * @Last modified time: 2017-06-01T20:11:37+05:30
 */

#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define rep(i, n) \
  for (int i = 0; i < n; ++i)
#define loop(i, x, y) \
  for (int i = x; i < y; ++i)
#define gc getchar
#define mp make_pair
#define pll pair < ll, ll >
#define vi vector < int >
#define vll vector < ll >
#define mii map < int, int >
#define mll map < ll, ll >
#define pb push_back
#define all(a) a.begin(), a.end()
#define MAX 5003
#ifdef DEBUG
   # define LOG(args ...) { dbg, args; }
#else // ifdef DEBUG
  # define LOG(args ...) // Just strip off all debug tokens
#endif // ifdef DEBUG
struct debugger
{
  template<typename T>debugger& operator,(const T& v)
  {
    cerr << v << " ";
    return *this;
  }
} dbg;

template<typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p)
{
  return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
  bool first = true;

  os << "[";

  for (unsigned int i = 0; i < v.size(); i++)
  {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const std::set<T>& v)
{
  bool first = true;

  os << "[";

  for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
  {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}

template<typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& v)
{
  bool first = true;

  os << "[";

  for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii)
  {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}

ll gcd(ll a, ll b) {
  return (b == 0) ? a : gcd(b, a % b);
}

ll n, S;

ll cost(int k, vll a) {
  cout<< "~" << "k is " << k << endl;
  ll sum = 0;
  vll costs(a.size());

  for(int i = 0; i < a.size(); i++) {
    costs[i] = a[i] + 1LL * (i + 1) * k;
  }

  sort(costs.begin(), costs.end());

  for (int i = 0; i < k; i++) {
    sum += costs[i];
  }

  return sum;
}

ll search(int l, int r, vll a, ll S) {
  if (l == r) return cost(l, a) <= S ? l : l - 1;

  ll k = (l + r) / 2;
  ll cst = cost(k, a);

  if (cst <= S) return search(k + 1, r, a, S);

  else return search(l, k, a, S);
}


int main() {
  cin >> n >> S;

  vll a;

  rep(i, n) { ll x; cin >> x; a.push_back(x); }

  ll k = search(0, n, a, S);

  cout << k << " " << cost(k, a) << endl;
  return 0;
}
