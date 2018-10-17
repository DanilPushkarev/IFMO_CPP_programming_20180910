//Даны действительные коэффициенты a, b, c, при этом a != 0 . Решите квадратное уравнение ax2 + bx + c = 0 и выведите все его корни.
//
//Формат входных данных
//
//        Вводятся три действительных числа.
//Формат выходных данных
//        Если уравнение имеет два корня, выведите два корня в порядке возрастания, если один корень — выведите одно число, если нет корней — не выводите ничего.
//Sample Input:
//
//1
//-1
//-2
//Sample Output:
//
//-1 2

#include "t06_quad.h"
#include <iostream>
#include <cmath>

using namespace std;

int t06_quad() {
    int a,b,c,d;
    double x1,x2;
    cin >> a >> b >> c;
    d = b*b-4*a*c;
    if (d>0){
    x1 =((b*(-1))+sqrt(d))/(2*a);
    x2 =((b*(-1))-sqrt(d))/(2*a);
    cout << x2 << " " << x1;}
    else if (d==0){
        x1 =((b*(-1))+sqrt(d))/(2*a);
        cout << x1;
    }
};