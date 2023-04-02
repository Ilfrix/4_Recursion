#include <limits>
#include <iostream>
#include <algorithm>
struct Node{
    //base structure
    char data;
    int size;
    Node* next;

    Node(){
        this->data = ' ';
        this->size = 0;
        this->next = nullptr;
    }

    Node (char data){
        this->data = data;
        this->next = nullptr;
    }
    Node (char data, int s){
        this->data = data;
        this->size = s;
        this->next = nullptr;
    }
    ~Node(){
        delete this;
    }
};

struct LinkedList
{
    //structure of list
    Node *head;
    LinkedList(){
        this->head = nullptr;
    }
    LinkedList(std::string s){
        this->head = nullptr;
        size_t s_len = s.size();
        for (int i = s_len - 1; i >= 0; --i){
            push_front(s[i], s_len);
        }
    }
    ~LinkedList(){
        while(head != nullptr)  pop_front();
    }

    void push_front(char data, int size_s){
        //push node with data before first elemet of current list (support)
        Node *new_node = new Node(data, size_s);
        new_node->next = head;
        head = new_node;
    }
    void push_front(char data){
        //push node with data before first elemet of current list (support)
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    void remove_max(){
        //remove element with maximum data
        int cur_max = std::numeric_limits<int>::min();
        Node *ptr = head;
        Node *max_ptr = new Node();
        for (Node* node = head; node->next != nullptr; node=node->next){
            if (node -> data > cur_max){
                cur_max = node -> data;
                max_ptr = ptr;
            }
            ptr = node;
        }
        if (max_ptr == head){
            head = max_ptr->next;
        }
        else{
            max_ptr->next = max_ptr->next->next;
        }
        
    }

    void pop_front(){
        //delete first element in list (support)
        head = head->next;
    }
    void clear(){
        //clear list (support)
        while (head != nullptr) pop_front();
    }
    bool check_equal(){
        //check, there are two equel element in list
        Node *first_ptr = head;
        while (first_ptr != nullptr){
            Node *second_ptr = first_ptr->next;
            while (second_ptr != nullptr){
                if (first_ptr->data == second_ptr-> data)
                    return true;
                second_ptr = second_ptr->next;
            }
            first_ptr = first_ptr->next;
            delete second_ptr;
        }
        return false;
    }
    void show_list(){
        //show all list (support from task)
        for (Node* node = head; node != nullptr; node=node->next)
            std::cout << node->data << ' ' << node->size << '\n';
    }
    void move_last_to_start(){
        //move last element to start(last element will be first, head = old last element) (support from task)
        Node *node = head;
        for (; node->next->next != nullptr; node=node->next) {}
        node->next->next = head;
        head = node->next;
        node->next = nullptr;
    }
};
