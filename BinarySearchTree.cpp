#include <iostream>

class Node{
public:
    int data;
    Node *left;
    Node *right;
};

class Tree{
public:
    Node *insert(Node *tree,int value){
        if(tree == NULL){ // If there is no tree.
            Node *root = new Node;
            root -> left = NULL;
            root -> right = NULL;
            root -> data = value;
            return root;
        }
        if(tree -> data < value){//We have to add right side.
            tree -> right = insert(tree -> right,value);
            return tree;
        }
        if(tree -> data > value){
            tree -> left = insert(tree -> left,value);
            return tree;
        }
    }

    void print(Node *tree){
        //Infix notation.
        if(tree == NULL)
            return;
        print(tree -> left);
        std::cout << tree -> data << " ";
        print(tree -> right);

    }

    int search(Node *tree,int value){
        if(tree == NULL)
            return -1;
        if(tree -> data == value)
            return 1;
        if(search(tree -> left,value) == 1)
            return 1;
        if(search(tree -> right,value) == 1)
            return 1;
        return -1;
    }

    int max(Node *tree){
        while(tree -> right != NULL){
            tree = tree -> right;
        }
        return tree -> data;
    }

    int min(Node *tree){
        while(tree -> left != NULL){
            tree = tree -> left;
        }
        return tree -> data;
    }

    Node *deletee(Node *tree,int value){
        if(tree == NULL)
            return NULL;
        if(tree -> data == value){
            if(tree -> left == NULL && tree -> right == NULL)
                return NULL;
            if(tree -> right != NULL){
                tree -> data = min(tree -> right);
                tree -> right = deletee(tree -> right,min(tree -> right));
                return tree;
            }
            tree -> data = max(tree -> left);
            tree -> left = deletee(tree -> left,max(tree -> left));
            return tree;
        }
        if(tree -> data < value){
            tree -> right = deletee(tree -> right,value);
            return tree;
        }
        tree -> left = deletee(tree -> left,value);
        return tree;

    }

};

int main(){
    Node *tree = NULL;
    Tree tr1;
    tree = tr1.insert(tree,15);
    tree = tr1.insert(tree,14);
    tree = tr1.insert(tree,9);
    tree = tr1.insert(tree,7);
    tree = tr1.insert(tree,23);
    tree = tr1.insert(tree,11);
    tree = tr1.insert(tree,32);
    tree = tr1.insert(tree,43);
    tree = tr1.insert(tree,34);
    tree = tr1.insert(tree,65);
    tr1.print(tree); //7 9 11 14 15 23 32 34 43 65 [LNR]
    std::cout << "\nSearching 23.. : " << tr1.search(tree,23) << std::endl;
    std::cout << "Searching 550.. : " << tr1.search(tree,550) << std::endl;
    std::cout << "Maximum value : " << tr1.max(tree) << std::endl;
    std::cout << "Minimum value : " << tr1.min(tree) << std::endl;
    tree = tr1.deletee(tree,14);
    std::cout << "Delete 14.." << std::endl;
    tr1.print(tree);
}
