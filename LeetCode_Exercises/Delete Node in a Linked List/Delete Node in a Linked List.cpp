// Reverse String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;

class Solution {

    
public:
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode *addNext(ListNode* node) {
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
    ListNode* createList(vector<int> nums) {

        if (nums.size() == 0) return NULL;

        ListNode* head = new ListNode(nums[0]);
        ListNode* tail = head;
        for (size_t i = 1; i < nums.size(); i++)
        {
            tail = tail->addNext(new ListNode(nums[i]));
        }

        return head;
    }

public:
    void deleteNode(ListNode* node) {

       /* node->val = node->next->val;
        node->next = node->next->next;*/

        *node = *node->next;

    }
};


int main()
{
    vector<int> head{ 1,2,3,4 };
    int node = 3;

    Solution sol;

    Solution::ListNode* listHead = sol.createList(head);
    listHead->traverse();
    
    Solution::ListNode* listNode = listHead->findNode(node);

    sol.deleteNode(listNode);

    listHead->traverse();

    cout << endl;
}

