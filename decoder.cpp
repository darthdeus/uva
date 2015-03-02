#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

int main() {
  string s; while (getline(cin, s)) {
    for (auto c : s) {
      cout << (char)(c-7);
    }
    cout << endl;
  }
}
