#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};


class LRUCache: Cache{
    
    
    public:
    LRUCache(int c){
        cp = c;
        head = nullptr;
        tail = nullptr;
    };

    void set(int k, int val){
        
        // of no key fund
        if (mp.find(k) == mp.end()){
            add_new_key(k, val);
            
        } else {
            update_key(k, val);
        }
        
    }
    
    int get(int k){
        
        if (mp.find(k) == mp.end()){
        
            return -1;
        }
        else {
            Node* node = mp[k];
            
            move_to_head(node);
            
            return node->value;
        }

    }
    
    private:
    
    void move_to_head(Node* node){
        
        if (node != head){

            if (node->next){
                node->next->prev = node->prev;
            }
            
            if (node->prev){
                node->prev->next = node->next;
            }
            
            if (tail == node){
                tail = node->prev;
            }
            
            // clear prev of new head
            node->prev = nullptr;
            // move in front of the head of the list
            node->next = head;
            head = node;
        }

    }
    
    void update_key(int k, int val){
        
        // get the node and update value
        Node* node = mp[k];
        node->value = val;
        
        // move to head if not there already
        
        move_to_head(node);
       

    }
    
    void add_new_key(int k, int val){
        Node* node = new Node(k, val);
        
        // add to map
        mp[k] = node;
        
        if (mp.size() == 1){
            head = node;
            tail = node;
        }
        else {
            // add to the head of the list
            node->next = head;
            head->prev = node;
            head = node;
        }
        
        // cut list
        if (mp.size() > cp){
    
            mp.erase(tail->key);
            
            tail = tail->prev;
            
            delete tail->next;
            
            tail->next = nullptr;
            
            
            
        }

    }
    
    
};

int main() {

    ifstream input;
    
    string testfile = "test_1.txt";
    
    input.open(testfile, ios::in);
    
    cout << filesystem::current_path() << endl;

    int n, capacity,i;
    input >> n >> capacity;
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
      string command;
      input >> command;
      if(command == "get") {
         int key;
         input >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         input >> key >> value;
         l.set(key,value);
      }
    }
    return 0;
}
