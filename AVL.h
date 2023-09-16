#include<iostream>
#include"SLL.h"
//#include"classes_nodes.cpp"
using namespace std;
#ifndef AVL_CPP
#define AVL_CPP

template <class T>
class avl_node {
public:
    T data;
    avl_node<T>* lchild, * rchild;
    SLL<int> carsList;
    avl_node(T e) {
        data = e;
        lchild = NULL;
        rchild = NULL;
    }
};

template <class T>
class AVL {
public:
    avl_node<T>* root;
    avl_node<T>* lock = NULL;
    avl_node<T>* plock = NULL;
    avl_node<T>* return_pointer = NULL;
    AVL() {
        root = NULL;
    }

    bool isEmpty();
    avl_node<T>* insert(T value, avl_node<T>* base,int index);
    //avl_node<T>* insert(T value, avl_node<T>* base);
    //avl_node<T>* insert(T value);
    int search(T value);
    avl_node<T>* search_node(T value);
    void preorder(avl_node<T>* cnode);
    void inorder(avl_node<T>* cnode);
    void postorder(avl_node<T>* cnode);
    int height(avl_node<T>* base);
    void delete_tree(avl_node<T>* base);
    void delete_node(T key);
    avl_node<T>* balance(avl_node<T>* node, T key);
    int balance_factor(avl_node<T>* node);
    avl_node<T>* leftshift(avl_node<T>* x);
    avl_node<T>* rightshift(avl_node<T>* x);
    avl_node<T>* rec_search(avl_node<T>* node, T plock_value);
};

template<typename T>
avl_node<T>* AVL<T>::rec_search(avl_node<T>* node, T plock_value) {

    if (plock_value < node->data) {
        node->lchild = rec_search(node->lchild, plock_value);
    }
    else if (plock_value > node->data) {
        node->rchild = rec_search(node->rchild, plock_value);
    }

    int balance_fact = balance_factor(node);
    if (balance_fact > 1) {
        if (balance_factor(node->lchild) >= 0)
            return rightshift(node);
        else {
            node->lchild = leftshift(node->lchild);
            return rightshift(node);
        }
    }
    else if (balance_fact < -1) {
        if (/*node->lchild != NULL &&*/ balance_factor(node->rchild) > 0) {
            node->rchild = rightshift(node->rchild);
            return leftshift(node);
        }
        else {
            return leftshift(node);
        }
    }
    else
        return node;
}


template<typename T>
void AVL<T>::delete_node(T key) {
    int cond = search(key);
    if (cond == 1 || cond == 4) {
        cout << "Value not found" << endl;
        return;
    }
    else if (cond == 3 || cond == 2) {
        if (lock->lchild == NULL && lock->rchild == NULL) { // value found in the leaf node
            if (plock->lchild == lock) {    //conditions if leaf node is left child
                //delete lock;
                plock->lchild = NULL;
            }
            else {                         //conditions if leaf node is right child
                //delete lock;
                plock->rchild = NULL;
            }
            lock = NULL;
            delete lock;
        }
        else if (lock->rchild == NULL || lock->lchild == NULL) {  //condition if any one of the child of found node is NULL 
            if (lock == root) {     //condition if node is the root node with only one subtree
                if (lock->lchild != NULL)
                    root = lock->lchild;
                else
                    root = lock->rchild;
            }
            else if (lock->rchild == NULL) { //condition if rchild is null 
                if (plock->rchild == lock) {
                    plock->rchild = lock->lchild;
                }
                else {
                    plock->lchild = lock->lchild;
                }
                lock = NULL;
                delete lock;
            }
            else {                     //condition if lchild is null
                if (plock->rchild == lock) {
                    plock->rchild = lock->rchild;
                }
                else {
                    plock->lchild = lock->rchild;
                }
                lock = NULL;
                delete lock;
            }
        }
        else {  //if both the child nodes are not null
            avl_node<T>* plock2, * lock2;
            plock2 = lock->lchild;
            lock2 = plock2->rchild;
            if (lock2 == NULL) {    //condition if the node to be replaced is the first node
                lock2 = plock2;
            }
            else {  // cond for finding the replacing node
                while (lock2->rchild != NULL) {
                    plock2 = lock2;
                    lock2 = lock2->rchild;
                }
                plock2->rchild = lock2->lchild;
                lock2->lchild = lock->lchild;
            }
            lock2->rchild = lock->rchild;
            if (lock != root) {     // replacing the replacement node
                if (plock->lchild == lock)
                    plock->lchild = lock2;
                else
                    plock->rchild = lock2;
            }
            else
                root = lock2;
            lock = NULL;
            delete lock;
        }
        root = rec_search(root, plock->data);
    }
}

template<typename T>
void AVL<T>::delete_tree(avl_node<T>* base) {
    if (base != NULL) {
        delete_tree(base->lchild);
        delete_tree(base->rchild);
        if (base == root)
            root = NULL;
        delete base;
    }
}


template<class T>
bool AVL<T>::isEmpty() {
    return root == NULL;
}
template<typename T>
void AVL<T>::preorder(avl_node<T>* cnode) {
    if (cnode != NULL) {
        cout << cnode->data << " ";
        preorder(cnode->lchild);
        preorder(cnode->rchild);
    }
}
template<typename T>
void AVL<T>::inorder(avl_node<T>* cnode) {
    if (cnode != NULL) {
        inorder(cnode->lchild);
        cout << cnode->data << " ";
        inorder(cnode->rchild);
    }
}
template<typename T>
void AVL<T>::postorder(avl_node<T>* cnode) {
    if (cnode != NULL) {
        postorder(cnode->lchild);
        postorder(cnode->rchild);
        cout << cnode->data << " ";
    }
}

//template<typename T>
//avl_node<T>* AVL<T>::return_pointer(avl_node<T>)S {
//    return S;
//    
//}

//template<typename T>
//avl_node<T>* AVL<T>::insert(T value, avl_node<T>* base) {
//
//    if (base == NULL) {
//        avl_node<T>* newnode = new avl_node<T>(value);
//        //return_pointer(avl_node<T>);
//        //return_pointer = newnode;
//        //newnode->carsList.insertAtEnd(index);
//        return newnode;
//    }
//    else if (value < base->data) {
//        base->lchild = insert(value, base->lchild);
//    }
//    else if (value > base->data) {
//        base->rchild = insert(value, base->rchild);
//    }
//    avl_node<T>* a = NULL;
//    if (value == base->data) {
//        //cout << "Duplicates not allowed" << endl;
//        //base->carsList.insertAtEnd(index);
//        //return_pointer = base;
//        return base;
//    }
//    a = balance(base, value);
//    return a;
//}

template<typename T>
avl_node<T>* AVL<T>::insert(T value, avl_node<T>* base,int index) {

    if (base == NULL) {
        avl_node<T>* newnode=new avl_node<T>(value);
        //return_pointer(avl_node<T>);
        return_pointer = newnode;
        newnode->carsList.insertAtEnd(index);
        return newnode;
    }
    else if (value < base->data) {
        base->lchild = insert(value, base->lchild, index);
    }
    else if (value > base->data) {
        base->rchild = insert(value, base->rchild,index);
    }
    avl_node<T>* a = NULL;
    if (value == base->data) {
        //cout << "Duplicates not allowed" << endl;
        base->carsList.insertAtEnd(index);
        return_pointer = base;
        return base;
    }
    a = balance(base, value);
    return a;
}

template<typename T>
avl_node<T>* AVL<T>::rightshift(avl_node<T>* x) {
    avl_node<T>* y = x->lchild;
    x->lchild = y->rchild;
    y->rchild = x;
    return y;
}

template<typename T>
avl_node<T>* AVL<T>::leftshift(avl_node<T>* x) {
    avl_node<T>* y = x->rchild;
    x->rchild = y->lchild;
    y->lchild = x;
    return y;
}

template<typename T>
int AVL<T>::height(avl_node<T>* base) {
    if (base == NULL) {
        return 0;
    }
    else {
        int lheight = height(base->lchild);
        int rheight = height(base->rchild);

        if (lheight > rheight)
            return lheight + 1;
        else return rheight + 1;
    }
}

template <typename T>
int AVL<T>::balance_factor(avl_node<T>* node) {
    int lheight = height(node->lchild);
    int rheight = height(node->rchild);
    int result_height = lheight - rheight;
    return result_height;
}
template<typename T>
avl_node<T>* AVL<T>::balance(avl_node<T>* node, T key) {

    if (node != NULL) {

        int balance_fact = balance_factor(node);
        if (balance_fact < -1  /*node->rchild != NULL*/ && node->rchild->data < key) {
            return leftshift(node);
        }
        else if (balance_fact > 1  /*node->lchild != NULL*/ && node->lchild->data > key) {
            return rightshift(node);
        }
        else if (balance_fact < -1  /*node->rchild != NULL*/ && node->rchild->data > key) {
            node->rchild = rightshift(node->rchild);
            return leftshift(node);
        }
        else if (balance_fact > 1  /*node->lchild != NULL*/ && node->lchild->data < key) {
            node->lchild = leftshift(node->lchild);
            return rightshift(node);
        }
        else return node;
    }
}

template<class T>
int AVL<T>::search(T value) {
    plock = NULL;
    lock = root;
    if (plock == NULL && lock == NULL) {
        return 1;	//an empty tree
    }
    else if (plock == NULL && root->data == value)
        return 2;	//value found in the root node
    while (lock != NULL /*&& lock->data < value*/) {
        if (lock->data == value)
            return 3;	//value found
        else if (value > lock->data) {
            plock = lock;
            lock = lock->rchild;
        }
        else {
            plock = lock;
            lock = lock->lchild;
        }
    }
    if (plock != NULL && lock == NULL)
        return 4;	//position of the value found at the end
}


template<class T>
avl_node<T>* AVL<T>::search_node(T value) {
    plock = NULL;
    lock = root;
    if (plock == NULL && lock == NULL) {
        return NULL;	//an empty tree
    }
    else if (plock == NULL && root->data == value)
        return lock;	//value found in the root node
    while (lock != NULL /*&& lock->data < value*/) {
        if (lock->data == value)
            return lock;	//value found
        else if (value > lock->data) {
            plock = lock;
            lock = lock->rchild;
        }
        else {
            plock = lock;
            lock = lock->lchild;
        }
    }
   
}




#endif


