// Dijkstra_Algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int next_node(const vector<int>& T, const vector<int>& Visited)
{
    int v_min = -1;
    int m = numeric_limits<int>::max();
    for (int i = 0; i < T.size() ;i++) {
        auto it = find(Visited.cbegin(), Visited.cend(), i);
        if (T[i] < m && it == Visited.cend()) {
            m = T[i];
            v_min = i;
        }
    }

    return v_min;
}

int main()
{
    constexpr int inf = numeric_limits<int>::max();
    
    std::cout << inf << endl;

    vector<vector<int>> Connectivity = {
        {0,   3,   1,   3,   inf, inf},
        {3,   0,   4,   inf, inf, inf},
        {1,   4,   0,   inf, 7,   5},
        {3,   inf, inf, 0,   inf, 1},
        {inf, inf, 7,   inf, 0,   1},
        {inf, inf, 5,   1,   1,   0},
    };

    int start_node = 3;
    int v = start_node; // Стартовая вершина
    const unsigned int node_number = Connectivity.size();

    vector<int> Visited;
    Visited.push_back(v);
    vector<int> T(node_number, inf);
    T[v] = 0; // Нулевой вес для стартовой вершины
    vector<int> shortest_way(node_number, v);
    
    while (v != -1) {
        for (int j = 0; j < node_number ;j++) {
            
            auto it = find(Visited.cbegin(), Visited.cend(), j);
            if( it == Visited.cend()) {
                int w;
                if (Connectivity[v][j] == inf)
                    w = inf;
                else w = T[v] + Connectivity[v][j];

                if (w < T[j]) {
                    T[j] = w;
                    shortest_way[j] = v;
                }
            }

            
        }

        v = next_node(T, Visited);
        if (v != -1)
            Visited.push_back(v);
    }

    int start = start_node;
    int end = 5;
    int current = end;
    vector<int> way;
    way.push_back(current);
    while (current != start) {
        current = shortest_way[way.front()];
        way.insert(way.begin(), current);
    }

    cout << "T: ";
    for (int i : T)
        cout << i << " ";
    cout << endl;

    cout << "Shortest_way: ";
    for (int i : shortest_way)
        cout << i << " ";
    cout << endl;
    
    cout << "Way: ";
    for (int i : way)
        cout << i << " ";
    cout << endl;

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
