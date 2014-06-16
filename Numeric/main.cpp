#include <vector>
#include <iostream>

using namespace std;
// from http://www.blog.highub.com/c-plus-plus/c-parse-split-delimited-string/
// usage:
// split (string_to_modify, delimiting_char, string_to_store_results)
void split(const string& s, char c, vector<string>& v) {
  string::size_type i = 0;
  string::size_type j = s.find(c);
  while(j != string::npos) {
    v.push_back(s.substr(i, j-i));
    i = j++;
    j = s.find(c, j);
    if (j == string::npos)
      v.push_back(s.substr(i, s.length()));
  }
}

int main() {
  string s = "Account Name|Address 1|Address 2|City";
  vector<string> v;
  split(s, '|', v);

  // display results
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }
}