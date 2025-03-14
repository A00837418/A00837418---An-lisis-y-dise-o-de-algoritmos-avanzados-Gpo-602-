#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> suffixArray(const string &s) {
    int n = s.size();
    vector<int> suffixes(n);

  
    for (int i = 0; i < n; ++i) {
        suffixes[i] = i;
    }

   
    sort(suffixes.begin(), suffixes.end(), [&s, n](int i, int j) {
        return s.compare(i, n - i, s, j, n - j) < 0;
    });

    return suffixes;
}

int main() {
   
    string s;
    getline(cin, s);

   
    vector<int> result = suffixArray(s);

    
    for (int i : result) {
        cout << i + 1 << endl;  
    }

    return 0;
}