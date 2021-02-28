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
    
    struct Node {
        int x;
        Node* next;
        Node* prev;

        Node(int i) {
            x = i;
            next = NULL;
            prev = NULL;
        }

        Node* remove() {

            if (next != NULL) next->prev = prev;

            if (prev != NULL) prev->next = next;

            delete(this);

            return NULL;
        }

        Node* insertAfter(Node* node) {
            node->next = next;
            node->prev = this;
            next = node;
            return node;
        }
    };

    int firstUniqChar(string s) {

        map<char, Node *> map_unique;
        int len = s.length();
        vector<int> stack;
        int stack_pos = 0;

        Node* head = new Node(-1);

        Node* tail = head;

        for (size_t i = 0; i < len; i++)
        {
            if (map_unique.find(s[i]) == map_unique.end()) {
                
                tail = tail->insertAfter(new Node(i));
                map_unique[s[i]] = tail;
                
            }
            else if (map_unique[s[i]] != NULL) {
                Node* current = map_unique[s[i]];
                if (tail == current) {
                    tail = current->prev;
                }
                map_unique[s[i]] = map_unique[s[i]]->remove();
            }

            
        }

        if (head->next == NULL) return -1;

        return head->next->x;

    }

    int firstUniqChar2(string s) {

        vector<int> count(26, 0);

        for (auto c : s) {
            count[c - 'a']++;
        }
        
        for (size_t i = 0; i < s.length(); i++)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};


int main()
{
    string s = "dddccdbba";

    Solution sol;

    int res = sol.firstUniqChar(s);

    cout << "Result: " << res << endl;

}

