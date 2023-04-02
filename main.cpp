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
int main(){
    LinkedList t = LinkedList("1234re");
    t.show_list();
    //std::cout << std::setprecision(2); //ouput 2 num after dot
    //std::cout << (find_cos(0, 0.01)) << '\n';
    return 0;
}