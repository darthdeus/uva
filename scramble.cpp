#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
  string line;
  while (getline(cin, line)) {
    istringstream ss{line};

    string s;
    string res;
    while (ss >> s) {
      reverse(s.begin(), s.end());
      res += s + " ";
    }

    res.erase(res.length() - 1, 1);
    cout << res << endl;
  }
}

