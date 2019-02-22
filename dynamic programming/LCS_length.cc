#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
/*
https://www.techiedelight.com/longest-common-subsequence/
The longest common subsequence (LCS) problem is the problem of finding the
longest subsequence
that is present in given two sequences in the same order. i.e. find a longest
sequence
which can be obtained from the first original sequence by deleting some items,
and from the second original sequence by deleting other items.

Given sequences:
X : ABCBDAB
Y : BDCABA

1) Case 1: X & Y end with the same char: X[m] = Y[m]:
        -> LCS(X, Y) = LCS(X[1,n-1], Y[1,m-1]) + X[m]

2) Case 2: X & Y do not end with the same char: X[m] != Y[m]:
        -> LCS(X, Y) = maximum[LCS(X[1,m-1], Y[1,n]), LCS(X[1,m], Y[1,n-1])]


Additionally, in order to prevent repeated calculations, use lookups!
*/

int LCS_length(std::string &X, std::string &Y, int m, int n) {
  if (m == 0 or n == 0)
    return 0;
  if (X[m - 1] == Y[n - 1])
    return LCS_length(X, Y, m - 1, n - 1) + 1;
  return std::max(LCS_length(X, Y, m - 1, n), LCS_length(X, Y, m, n - 1));
}

int LCS_length_lookup(std::string &X, std::string &Y, int m, int n,
                      auto &lookup) {
  if (m == 0 or n == 0)
    return 0;
  std::string key = std::to_string(m) + "|" + std::to_string(n);
  if (lookup.find(key) == lookup.end())
  {
    if (X[m - 1] == Y[n - 1])
      lookup[key] = 1 + LCS_length_lookup(X, Y, m - 1, n - 1, lookup);
    else
      lookup[key] = std::max(LCS_length_lookup(X, Y, m - 1, n, lookup), LCS_length_lookup(X, Y, m, n - 1, lookup));
  }
  return lookup[key];
}

// std::string LCS(std::string &X, std::string &Y, int m, int n) {
//   if (m == 0 or n == 0)
//     return "";
//   if (X[m - 1] == Y[n - 1])
//     return LCS(X, Y, m - 1, n - 1) + X[m - 1];
//   std::string A = LCS(X, Y, m - 1, n);
//   std::string B = LCS(X, Y, m, n - 1);
//   return (A.length() > B.length()) ? A : B;
// }
int main() {
  std::string X{"A11B11C1D111111EF1"};
  std::string Y{"2AB222C222D22E2F"};

  auto start = std::chrono::high_resolution_clock::now();
  int l1 = LCS_length(X, Y, X.length(), Y.length());
  std::chrono::duration<float> elapsed = std::chrono::high_resolution_clock::now() - start;
  std::cout << "Without Lookup:  " << l1 << " - " << elapsed.count() << std::endl;

  std::unordered_map<std::string, int> lookup;
  start = std::chrono::high_resolution_clock::now();
  int l2 = LCS_length_lookup(X, Y, X.length(), Y.length(), lookup);
  elapsed = std::chrono::high_resolution_clock::now() - start;

  std::cout << "With Lookup:     " << l2 << " - " << elapsed.count() << std::endl;
}