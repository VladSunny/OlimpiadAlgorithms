// https://informatics.msk.ru/mod/statements/view.php?id=86666#1

#include <iostream>
#include <random>

using namespace std;

mt19937 rng(52);

struct Node {
    int key, priority;
    Node *left, *right;

    Node(int key) {
        this->key = key;
        priority = rng();
        left = right = nullptr;
    }

    Node(int key, int priority) {
        this->key = key;
        this->priority = priority;
        left = right = nullptr;
    }
};

pair<Node*, Node*> split(Node* v, int x) {
    if (v == nullptr) return {nullptr, nullptr};

    if (x >= v->key) {
        auto [r_new, r] = split(v->right, x);
        v->right = r_new;
        return {v, r};
    } else {
        auto [l, l_new] = split(v->left, x);
        v->left = l_new;
        return {l, v};
    }
}

Node* merge(Node* l, Node* r) {
    if (l == nullptr) return r;
    if (r == nullptr) return l;

    if (l->priority > r->priority) {
        Node* r_new = merge(l->right, r);
        l->right = r_new;
        return l;
    } else {
        Node* l_new = merge(l, r->left);
        r->left = l_new;
        return r;
    }
}

Node* insert(Node* v, int x) {
    auto [l, r] = split(v, x);
    return merge(merge(l, new Node(x)), r);
}

Node* erase(Node* v, int x) {
    auto [l, r] = split(v, x);
    auto [m, r_new] = split(r, x + 1);
    return merge(l, r_new);
}

int main() {



    return 0;
}

