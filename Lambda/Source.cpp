// C++ implementation to find  
// minimum number of deletions  
// to make a sorted sequence 
#include <iostream>
#include <conio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Point
{
    double x;
    double y;
};



int main()
{
    setlocale(LC_ALL, "Russian");
    vector<Point> vec;
   
    Point p0;

    cout << "Введите координаты точки: ";
    cin >> p0.x;
    cin >> p0.y;

    int n;
    cout << "Ввежите количество вершин для n угольника:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        Point p;
        cout << "Введите координаты : " << i << "-ой вершины:" << endl;
        cin >> p.x;
        cin >> p.y;
        vec.push_back(p);
    }
    Point last;
    last.x = vec[0].x;
    last.y = vec[0].y;

    vec.push_back(last);


    auto it = adjacent_find(vec.begin(), vec.end(), [p0](Point p1, Point p2) {
        double k, c;

        if (p1.x == p2.x)
        {
            return (p0.x == p1.x && p0.y >= min(p1.y, p2.y) && p1.x <= max(p1.y, p2.y));
        }

        k = (p2.y - p1.y) / (p2.x - p1.x);
        c = p1.y - k * p1.x;

        return p0.y == p0.x * k + c;
        });

    if (it == vec.end())
        cout << "Не принадлежит";
    else cout << "Принадлежит";

    return 0;
}