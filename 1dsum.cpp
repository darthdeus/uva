#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);

    vector<int> data;
    int i;
    while (true) {
      ss >> i;

      if (i == -999999) break;
      data.push_back(i);
    }

    int sum = 0, ans = 0;

    for (auto x : data) {
      sum += x;
      ans = max(ans, sum);
      if (sum < 0) sum = 0;
    }

    cout << ans << endl;
  }

}
