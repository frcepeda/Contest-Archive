#include <cstdio>

// Taken from http://www.stanford.edu/~liszt90/acm/notebook.html
// Gauss-Jordan elimination with full pivoting.
//
// Uses:
//   (1) solving systems of linear equations (AX=B)
//   (2) inverting matrices (AX=I)
//   (3) computing determinants of square matrices
//
// Running time: O(n^3)
//
// INPUT:    a[][] = an nxn matrix
//           b[][] = an nxm matrix
//
// OUTPUT:   X      = an nxm matrix (stored in b[][])
//           A^{-1} = an nxn matrix (stored in a[][])
//           returns determinant of a[][]

#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

T GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  T det = 1;

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
	if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    if (pj != pk) det *= -1;
    irow[i] = pj;
    icol[i] = pk;

    T c = 1.0 / a[pk][pk];
    det *= a[pk][pk];
    a[pk][pk] = 1.0;
    for (int p = 0; p < n; p++) a[pk][p] *= c;
    for (int p = 0; p < m; p++) b[pk][p] *= c;
    for (int p = 0; p < n; p++) if (p != pk) {
      c = a[p][pk];
      a[p][pk] = 0;
      for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c;
      for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;      
    }
  }

  for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
    for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  }

  return det;
}
// End of section taken from Stanford's ACM notebook.

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		double Pf, Pb;
		scanf("%d %lf %lf", &N, &Pf, &Pb);

		if (N == 1){
			printf("0\n");
			continue;
		}

		Pf /= 100; Pb /= 100;

/* Explanation:
   The expected value of jumps from each cell can be expressed as
   E[i] = Pb*E[i-1] + (1-Pb-Pf)*E[i] + Pf*E[i+1] + 1
   with E[N-1] = 0. Writing all of the expected values yields a system
   of linear equations, which can be solved using Gaussian elimination.
 */
		VVT a(N), b(N);
		for (int i = 0; i < N; i++){
			b[i] = VT(1,-1);
			a[i] = VT(N,0);
			if (i == 0){
				a[i][i] = -Pf;
				a[i][i+1] = Pf;
			} else if (i == N-1){
				a[i][i] = 1;
				b[i][0] = 0;
			} else {
				a[i][i-1] = Pb;
				a[i][i] = -Pb - Pf;
				a[i][i+1] = Pf;
			}
		}

		GaussJordan(a,b);

		printf("%lf\n", b[0][0]);
	}
}
