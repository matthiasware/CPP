#include <iostream>
#include <string>
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
*/

std::string LCS(std::string &X, std::string &Y, int m, int n) {
  if (m == 0 or n == 0)
    return "";
  if (X[m - 1] == Y[n - 1])
    return LCS(X, Y, m - 1, n - 1) + X[m - 1];
  std::string A = LCS(X, Y, m - 1, n);
  std::string B = LCS(X, Y, m, n - 1);
  return (A.length() > B.length()) ? A : B;
}
int main() {
  std::string X{"A11B11C1D11"};
  std::string Y{"2AB222C222D"};
  std::string lcs = LCS(X, Y, X.length(), Y.length());
  std::cout << lcs << std::endl;
}