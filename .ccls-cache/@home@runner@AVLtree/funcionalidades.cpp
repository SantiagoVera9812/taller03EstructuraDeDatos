#include "funcionalidades.h"

int contarNodosAux(AVL::Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + contarNodosAux(root->left) + contarNodosAux(root->right);
    }
}

int contarNodos(AVL avl) {
    AVL::Node* root = avl.getRoot();
    return contarNodosAux(root);
}

int KthSmallest(AVL avl, int k) {
    AVL::Node* root = avl.getRoot();
    if (root == nullptr) {
        return -1; // or some other error code
    }
    int count = contarNodosAux(root->left);
    if (k == count + 1) {
        return root->key;
    } else if (k <= count) {
        AVL leftSubtree(root->left);  // create a temporary AVL object
        return KthSmallest(leftSubtree, k);
    } else {
        AVL rightSubtree(root->right);  // create a temporary AVL object
        return KthSmallest(rightSubtree, k - count - 1);
    }
}

double findMedian(AVL avl) {
    int n = contarNodos(avl.getRoot());
    if (n == 0) {
        return 0;
    }
    if (n % 2 == 0) {
        int k = n / 2;
        int first = KthSmallest(avl.getRoot(), k);
        int second = KthSmallest(avl.getRoot(), k + 1);
        return (double)(first + second) / 2.0;
    } else {
        int k = n / 2 + 1;
        return (double)KthSmallest(avl.getRoot(), k);
    }
}




