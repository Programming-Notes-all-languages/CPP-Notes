#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect = {12,3,4,3,2,1,2,2,2,2,3,4,2,1};
    auto it = vect.begin();

    vect.erase(it);

    for (; it < vect.end(); it++)
        cout << *it;

    return 0;
}