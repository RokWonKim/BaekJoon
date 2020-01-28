#include<iostream>
 
using namespace std;

struct node{
    int value;
    node *right;
    node *left;
};

void printnode(node* root) {
    if (root == NULL)
        return;
    printnode(root->left);
    printnode(root->right);
    cout << root->value << '\n';
}

int main(void){
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 0;
    cin >> num;

    node* root  = new node;
    root->value = num;
    root->left = NULL;
    root->right = NULL;

    node *point;
    while(cin >> num) {
        point = root;

        node* inode = new node;
        inode->value = num;
        inode->left = NULL;
        inode->right = NULL;

        while(1) {
            if (num < point->value) {
                if(point->left == NULL) {
                    point->left = inode;
                    break;
                }
                else
                    point = point->left;
            }
            else {
                if(point->right == NULL) {
                    point->right = inode;
                    break;
                }
                else
                    point = point->right;
            }

        }
    }

    printnode(root);
    
    return 0;
}