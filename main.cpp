#include <iostream>
#include <cmath>
#include <iomanip>
#include "LinkedList.h"

double find_cos (double x, double e=0.01, int k = 1, double tmp = 1, double res = 1){
    tmp = -res * tmp / fabs(tmp) * x*x / ((2*k) * (2*k -1));
    res += tmp;
    //std::cout << tmp << ' ' << res << '\n';
    if (fabs(tmp) > e)  res = find_cos(x, e, k+1, tmp, res);
    return res;
}

bool is_palindrom(std::pair<std::string, std::string> p){
    return p.first == p.second;
}

std::pair<std::string, std::string> check_palindrom(Node *node){
    static std::string s_start = "", s_end="";
    s_start += node->data;
    if (node->next != nullptr)    check_palindrom(node->next);
    s_end += node->data;
    return {s_start, s_end};
}
int main(){
    LinkedList t = LinkedList("qwertyytrewq");
    //std::cout << std::boolalpha; //output true/false
    std::cout << is_palindrom(check_palindrom(t.head));
    //std::cout << a.first << ' ' << a.second << '\n';
    //std::cout << std::setprecision(2); //ouput 2 num after dot
    //std::cout << (find_cos(0, 0.01)) << '\n';
    return 0;
}