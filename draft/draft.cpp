// draft.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = { 1,2,3,4,5 };

    size_t v1_size = vec.size() / 2;
    size_t v2_size = vec.size() - v1_size;

    vector<int> v1(vec.cbegin(), vec.cbegin() + v1_size);
    vector<int> v2(vec.cbegin() + v1_size, vec.cend());

    for (auto i : v1) {
        cout << i << ' ';
    }
    cout << endl;
    for (auto i : v2) {
        cout << i << ' ';
    }
    cout << endl;
}

