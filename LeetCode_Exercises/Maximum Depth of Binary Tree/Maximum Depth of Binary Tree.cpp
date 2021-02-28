// Reverse String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;
using std::stack;
using std::queue;
using std::max;

class Solution {


public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
        ListNode* addNext(ListNode* node) {
            if (this != NULL) {
                node->next = next;
                next = node;
            }
            return node;
        }

        ListNode* findNode(int pos) {

            ListNode* tmp = this;

            while (tmp != NULL)
            {
                if (tmp->val == pos) return tmp;
                tmp = tmp->next;
            }

            return NULL;
        }

        ListNode* traverse() {

            cout << "Result: ";

            ListNode* tmp = this;
            while (tmp != NULL)
            {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }

            cout << endl;

            return NULL;
        }
    };

public:
    TreeNode* createTree(vector<int> nums) {


        stack<TreeNode*> stack;
        queue<TreeNode*> queue;

        for (int i = nums.size() -1 ; i >= 0; i--)
        {
            if (nums[i] != -1) {
                stack.push(new TreeNode(nums[i]));
            }
            else {
                stack.push(NULL);
            }
            
        }

        TreeNode* head = stack.top();
        stack.pop();

        TreeNode* current;
        queue.push(head);

        while (queue.size() && stack.size()) {

            current = queue.front();
            queue.pop();
            if (current == NULL) continue;

            current->left = stack.top();
            queue.push(stack.top());
            stack.pop();

            current->right = stack.top();
            queue.push(stack.top());
            stack.pop();   
        }

        return head;
    }

public:
    int maxDepth(TreeNode* root) {

        if (root == NULL) return(0);

        stack<TreeNode*> stack;
        queue<TreeNode*> queue;
        
        int depth = 1;

        if (root->left != NULL) {
            depth = max(depth, 1 + maxDepth(root->left));
        }

        if (root->right != NULL) {
            depth = max(depth, 1 + maxDepth(root->right));
        }

        return depth;
    }
};


int main()
{
    vector<int> head{ 3,9,20,-1,-1,15,7 };
    int node = 3;

    Solution sol;

    Solution::TreeNode* root = sol.createTree(head);
    //listHead->traverse();

    int res = sol.maxDepth(root);


    //listHead->traverse();

    cout << "Result: " << res << endl;
}

