#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {

  while (true) {
    string line;
    getline(cin, line);

    if (line == "") break;

    stringstream ss{line};
    vector<int> list;
    int n;
    ss >> n;
    while (n--) {
      int x;
      ss >> x;
      list.push_back(x);
    }

    vector<int> diffs;
    for (size_t i = 0; i < list.size() - 1; i++) {
      int val = abs(list[i] - list[i + 1]);
      diffs.push_back(val);
    }

    sort(begin(diffs), end(diffs));

    bool ok = true;

    for (size_t i = 0; i < diffs.size(); i++) {
      if (i+1 != diffs[i]) {
        ok = false;
      }
    }

    if (ok) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }
  }
}
