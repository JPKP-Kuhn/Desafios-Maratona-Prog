#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define _                                                                      \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

using ll = long long;
using vll = vector<ll>;

struct noh {
  ll val;
  noh *left, *right;

  noh(ll v) {
    val = v;
    left = right = nullptr;
  }
};

noh *insert(noh *root, ll x) {
  if (root == nullptr)
    return new noh(x);

  if (x < root->val) {
    root->left = insert(root->left, x);
  } else {
    root->right = insert(root->right, x);
  }

  return root;
}

void preorder(noh *root) {
  if (!root)
    return;

  cout << ' ' << root->val;
  preorder(root->left);
  preorder(root->right);
}

void inorder(noh *root) {
  if (!root)
    return;

  inorder(root->left);
  cout << ' ' << root->val;
  inorder(root->right);
}

void postorder(noh *root) {
  if (!root)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << ' ' << root->val;
}

int main() {
  _ ll t;
  cin >> t;
  ll caso{};
  while (t--) {
    ll n;
    cin >> n;
    ll raiz;
    cin >> raiz;
    n--;
    noh *bst = new noh(raiz);
    while (n--) {
      ll x;
      cin >> x;
      insert(bst, x);
    }

    cout << "Case " << ++caso << ":\n";
    cout << "Pre.:";
    preorder(bst);
    cout << '\n';
    cout << "In..:";
    inorder(bst);
    cout << '\n';
    cout << "Post:";
    postorder(bst);
    cout << "\n\n";
  }

  return 0;
}
