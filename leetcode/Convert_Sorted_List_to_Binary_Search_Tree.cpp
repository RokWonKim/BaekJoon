/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* inputNode(TreeNode* node, TreeNode* t) {
    if (t == NULL) t = node;
    else if (t->val > node->val) t->left = inputNode(node, t->left);
    else t->right = inputNode(node, t->right);
    return t;
}
TreeNode* makeTreeNode(int left, int right, vector<int> v, TreeNode* t) {
    int mid_index = (left+right) /2;
    if (left < right) {
        if(t == NULL) t = new TreeNode(v[mid_index]);
        else {
            TreeNode* node = new TreeNode(v[mid_index]);
            t = inputNode(node, t);
        }
        t = makeTreeNode(left, mid_index-1, v, t);
        t = makeTreeNode(mid_index+1, right, v, t);
    }
    if (left == right) {
        TreeNode* node = new TreeNode(v[mid_index]);
        t = inputNode(node, t);
    }
    return t;
}
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int number = 0;
        int i = 0;
        while (p != NULL) {
            number++;
            p = p->next;
        }
        if (number == 0) return NULL;
        
        p = head;
        vector<int> v(number);
        
        while (p != NULL) {
            v[i] = p->val;
            i++;
            p = p->next;
        }
        TreeNode* t;
        t = makeTreeNode(0,number-1,v, t);
        return t;
    }
};
