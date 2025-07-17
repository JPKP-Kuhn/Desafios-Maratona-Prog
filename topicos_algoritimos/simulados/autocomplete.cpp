#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  TrieNode* children[26];
  bool isLeaf;
  int prefixCount;

  TrieNode (){
    isLeaf = false;
    prefixCount = 0;
    for (int i = 0; i < 26; i++){
      children[i] = nullptr;
    }
  }

};
void insert(TrieNode* root, const string& key) {
  TrieNode* curr = root;
  for (char c : key) {
    if (curr->children[c - 'a'] == nullptr) {
      TrieNode* newNode = new TrieNode();
      curr->children[c - 'a'] = newNode;
    }
    curr = curr->children[c - 'a'];
    curr->prefixCount++;
  }
  curr->isLeaf = true;
}

int countPrefix(TrieNode *root, const string &key) {
  TrieNode *current = root;
  for (char c : key) {
    int index = c - 'a';
    if (current->children[index] == nullptr) {
      return 0;
    }
    current = current->children[index];
  }
  return current->prefixCount;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  TrieNode* root = new TrieNode();

  for (int i = 0; i < n; i++){
    string x;
    cin >> x;
    insert(root, x);
  }

  for (int i = 0; i < q; i++){
    string w;
    cin >> w;
    int c = countPrefix(root, w);
    cout << c << '\n';
  }

  return 0;
}
