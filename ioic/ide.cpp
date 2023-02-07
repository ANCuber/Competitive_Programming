#include <ctype.h> // toupper
#include <stdio.h>
#include <string.h> // memcpy

#define N 4

int T;

void solve() {
  unsigned i;
  char a[N * 2] = {};
  char b[N * 2] = {};

  struct T {
    unsigned v, i;
  } s1, s2;

  scanf("%s%s", a, b);

  s1.v = 0, s1.i = 1;
  for (i = 0; i < sizeof('a'); ++i)
    s1.v = s1.v + (((unsigned)toupper(a[i])) << (i * 3));
  s2.v = 0, s2.i = 2;
  for (i = 0; i < sizeof('b'); ++i)
    s2.v = s2.v + (((unsigned)toupper(b[i])) << (i * 3));

  if (s2.v < s1.v) {
    memcpy(&s1, &s2, sizeof(T));
  }

  printf("%u %u\n", s1.v, s1.i);
}

int main() {
  int kase;
  scanf("%d", &T);
  for (kase = 0; kase < T; ++kase) {
    printf("Case %d: ",
           kase /
/*!*/ 100 /*?*/
    );
    solve();
  }
  return 0;
}

