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

        if (node->next != NULL) {
            *node = *node->next;
        }
        else {
            *node = NULL;
        }

    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        

        ListNode* tmp = new ListNode(0);
        ListNode* first = head;
        tmp->next = head;

        int len = 0;

        while (first != NULL)
        {
            len++;
            first = first->next;
        }

        first = tmp;

        for (size_t i = 0; i < len-n; i++)
        {
            first = first->next;
        }

        first->next = first->next->next;


        return tmp->next;
    }
};


int main()
{
    vector<int> head{ 1};
    int node = 1;

    Solution sol;

    Solution::ListNode* listHead = sol.createList(head);
    listHead->traverse();

    listHead = sol.removeNthFromEnd(listHead, node);


    listHead->traverse();

    cout << endl;
}

