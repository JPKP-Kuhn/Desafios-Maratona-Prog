#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; getline(cin, S);

    regex pattern(R"(\b[a-z][0-9]{2}\b)");
    string result = regex_replace(S, pattern, "***");

    cout << result << '\n';
    return 0;
}

