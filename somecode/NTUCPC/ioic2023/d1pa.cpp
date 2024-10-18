#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

namespace {

using llf = long double;
using PTF = complex<llf>;

const llf eps = 1e-8;

llf dot(PTF a, PTF b) { return real(conj(a) * b); }
PTF project(PTF p, PTF q) { return dot(p, q) * q / dot(q, q); }
llf Sqrt(llf x) {
  if (llf v = sqrt(x); isnan(v))
    return 0;
  else
    return v;
}

struct L {
  PTF st, ed, dir;
  L(PTF s, PTF e) : st(s), ed(e), dir(e - s) {}
};

vector<PTF> interCircle(const L &l, const PTF &c, llf r) {
  PTF ft = l.st + project(c - l.st, l.dir);
  if (llf dis = abs(c - ft); dis > r + eps)
    return {};
  else if (llf d = Sqrt(r * r - dis * dis); d == 0)
    return {ft};
  else {
    PTF vec = l.dir * d / abs(l.dir);
    return {ft + vec, ft - vec};
  }
};

} // namespace

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int x1, y1, x2, y2;
  int x0, y0, r;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x0 >> y0 >> r;
  L l(PTF(x1, y1), PTF(x2, y2));
  PTF c(x0, y0);
  auto p = interCircle(l, c, r);
  if (p.empty()) {
    cout << "none\n";
  } else {
    for (auto pi : p)
      cout << fixed << setprecision(10) << pi.real() << " " << pi.imag()
           << '\n';
  }
  return 0;
}
