#include <bits/stdc++.h>
using namespace std;

int main()
{
  ll n, k, q, mid, x;
  cin >> n >> k;
  string s;
  cin >> s;
  priority_queue<tuple<ll, ll, ll>>pq;
  pq.push({n, -1, -n});
  map<ll, ll>v;
  for (ll i = 1; i <= k; i++)
  {
   ll gap = get<0>(pq.top());
   ll start = -(get<1>(pq.top()));
   ll end = -(get<2>(pq.top()));
   pq.pop();
   if (gap % 2 == 0)
   {
    mid = (start + end) / 2;
    if (s[i - 1] == 'R')
    {
     mid++;
     v[mid] = i;
     if (end - mid > 0) {
      pq.push({end - mid, -(mid + 1), -(end)});
    }
    pq.push({mid - start, -start, -(mid - 1)});
  }
  else if (s[i - 1] == 'L')
  {
   v[mid] = i;
   if (mid - start > 0) {
    pq.push({mid - start, -(start), -(mid - 1)});
  }
  pq.push({end - mid, -(mid + 1), -(end)});
}
}
else
{
  mid = (start + end) / 2;
  v[mid] = i;
  if (mid - start > 0)
   pq.push({mid - start, -(start), -(mid - 1)});
 if (end - mid > 0)
   pq.push({end - mid, -(mid + 1), -(end)});
}
}
cin >> q;
while (q--)
{
 cin >> x;
 if (v[x] != 0)
  cout << v[x] << endl;
else
  cout << -1 << endl;
}
return 0;
}
