#include <iostream>
#include <cmath>
#include <iomanip>
#include "LinkedList.h"

double find_cos (double x, double e=0.01, int k = 1, double tmp = 1, double res = 1){
    //recursion function for find cos x
    tmp = -tmp * x*x / ((2*k) * (2*k -1));
    res += tmp;
    //std::cout << tmp << ' ' << res << '\n';
    if (fabs(tmp) > e)  res = find_cos(x, e, k+1, tmp, res);
    return res;
}

bool is_palindrom(std::pair<std::string, std::string> p){
    return p.first == p.second;
}

std::pair<std::string, std::string> check_palindrom(Node *node){
    //find string from start to end in linked list
    //find string from end to start in linked list
    std::string s_start = "", s_end="";
    std::pair<std::string, std::string> tmp;
    s_start += node->data;
    if (node->next != nullptr) tmp = check_palindrom(node->next);
    s_start = (tmp.first != "")? s_start + tmp.first : s_start;
    s_end += node->data;
    s_end = (tmp.second != "")? tmp.second + s_end : s_end;
    return {s_start, s_end};
}

int main(){
    int choice;
    std::cout << "Enter 1 - for cos, 2 - for palindrom:";
    std::cin >> choice;
    if (choice == 1){
        while (true){
            std::cout << "Enter x(int) and e: ";
            int x; std::cin >> x;
            double e;   std::cin >> e;
            std::cout << (find_cos(x, e)) << '\n';
        }
    } else if (choice == 2){
        while (true){
            std::string s;
            std::cout << "Enter string for list: ";
            std::cin >> s;
            LinkedList t = LinkedList(s);
            std::cout << std::boolalpha; //output true/false
            std::cout << is_palindrom(check_palindrom(t.head)) << '\n';
        }
    }
    return 0;
}