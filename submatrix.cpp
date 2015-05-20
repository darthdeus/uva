#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <limits>

using namespace std;

struct sum {
  int i1, j1, i2, j2;
  long s;

  bool operator<(const struct sum& rhs) const {
    return this->s < rhs.s;
  }
};

int ROW, COL;
int *src;
int *sums;

long sum_between(int i1, int j1, int i2, int j2) {
  if (i1 == 0 && j1 == 0) {
    return sums[COL * i2 + j2];
  } else if (i1 == 0) {
    return sums[COL * i2 + j2] - sums[COL * i2 + j1 - 1];
  } else if (j1 == 0) {
    return sums[COL * i2 + j2] - sums[COL * (i1 - 1) + j2];
  } else {
    return sums[COL * i2 + j2] - sums[COL * (i1 - 1) + j2] -
           sums[COL * i2 + j1 - 1] + sums[COL * (i1 - 1) + j1 - 1];
  }
}

// O(n) vypocet maximalniho souctu 1D pole. Zaroven resi
// pokud jsou vsechny zaporne.
long maxsum(int length, int arr[], int& start, int& end) {
  start = 0;
  end = 0;
  int negindex = 0;

  long max = 0, curr = 0;
  int negmax = numeric_limits<int>::min();
  bool neg = true;

  for (int i = 0; i < length; i++) {
    if (curr == 0) {
      start = i;
      end = i;
    }

    curr = curr + arr[i];

    if (arr[i] > negmax) {
      negmax = arr[i];
      negindex = end = i;
    }

    if (curr < 0) {
      curr = 0;
      start = i;
    }

    if (curr > max) {
      max = curr;
      end = i;
    }

    if (arr[i] > 0) neg = false;
  }


  // Protoze si zaporna `curr` premazeme, nenasli bychom maximum
  // v poli s pouze zapornymi cisly.
  if (neg) {
    start = end = negindex;
    return negmax;
  } else {
    return max;
  }
}

int main() {
  scanf("%d", &ROW);

  COL = ROW;

  // int q,w;
  // int ff[] = { 1, -1, 1, -0 };
  // cout << maxsum(4, ff, q, w) << " " << q << " " << w << endl << endl;

  int input;

  src = new int[ROW * COL];

  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL; c++) {
      scanf("%d", &input);
      src[COL * r + c] = input;
    }
  }

  // Predpocitame si prefixove soucty pro jednotlive sloupce
  sums = new int[ROW * COL];
  for (int c = 0; c < COL; c++) {
    for (int r = 0; r < ROW; r++) {
      // Prvni radek je potreba resit zvlast kvuli rozsahu matice.
      if (r == 0) {
        sums[c] = src[c];
      } else {
        sums[r * COL + c] = sums[(r-1) * COL + c] + src[r * COL + c];
      }
    }
  }

  long max = 0;
  long curr = 0;
  int r1, c1, r2, c2;

  for (int i = 0; i < ROW; i++) {
    for (int j = i; j < ROW; j++) {
      int start = 0;
      int sum = 0;
      int l = 0;

      for (int c = 0; c < COL; c++) {
        if (i > 0) {
          sum += sums[COL * j + c] - sums[COL * (i - 1) + c];
        } else {
          sum += sums[COL * j + c];
        }

        // Prepocitame prefixovy soucet dal, pokud nam klesne.
        if (sum < start) {
          l = c + 1;
          start = sum;
        }

        curr = sum - start;

        // Kdyz mame vetsi aktualne soucet, stejne jako Kadane alg.
        if (curr > max) {
          r1 = i; c1 = l;
          r2 = j; c2 = c;
          max = curr;
        }
      }
    }
  }

  printf("%ld\n", max);
  // printf("%ld\n%d %d\n%d %d", max, r1+1, c1+1, r2+1, c2+1);
  return 0;
}
