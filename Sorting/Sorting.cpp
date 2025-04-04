// Sorting.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include "simpletimer.h"

using namespace std;

// Сортировка выбором
void choise_sorting(vector<int>& vec)
{
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                int temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
            }
        }
    }
}



vector<int> merge_vec(vector<int>& v1, vector<int>& v2)
{
    size_t total_size = v1.size() + v2.size();
    vector<int> merge(total_size);
    
    vector<int>::iterator it_v1(v1.begin());
    vector<int>::iterator it_v2(v2.begin());

    for (auto it = merge.begin(); it != merge.end(); ++it) {
        if (it_v1 != v1.end() && (it_v2 == v2.end() || *it_v1 <= *it_v2)) {
            *it = *it_v1;
            it_v1++;
        }
        else {
            *it = *it_v2;
            it_v2++;
        }
    }

    return merge;
}

// Сортировка слиянием
vector<int> merge_sorting(const vector<int>& vec)
{
    if (vec.size() < 2)
        return vec;

    size_t v1_size = vec.size() / 2;
    size_t v2_size = vec.size() - v1_size;

    vector<int> v1(vec.cbegin(), vec.cbegin() + v1_size);
    vector<int> v2(vec.cbegin() + v1_size, vec.cend());

    if (v1.size() > 1)
        v1 = merge_sorting(v1);
    if (v2.size() > 1)
        v2 = merge_sorting(v2);

    return merge_vec(v1, v2);
}

int main()
{
    //Генератор
    random_device rd;
    mt19937 gen(1);
    uniform_int_distribution<int> dist1(5, 10);
    uniform_int_distribution<int> dist2(1, 1e6);

    vector<int> v1(500000);
    std::generate(v1.begin(), v1.end(), [&]() { return dist2(gen); });

    vector<int> v2(v1);

    {
        SimpleTimer t;
        v1 =merge_sorting(v1);
    }

    {
        SimpleTimer t;
        choise_sorting(v2);
    }
    

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
