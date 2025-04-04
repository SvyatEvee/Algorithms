// Floyd_algorithm.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

list<int> get_path(const vector<vector<int>>& P, int end, int start)
{
    int u = end;
    int v = start;
    list<int> path;
    path.push_back(end);
    while (u != v) {
        u = P[u][v];
        path.push_front(u);
    }

    return path;
}


int main()
{
    constexpr int inf = numeric_limits<int>::max();

    std::cout << inf << endl;

    /*vector<vector<int>> v = {
        {0,   3,   1,   3,   inf, inf},
        {3,   0,   4,   inf, inf, inf},
        {1,   4,   0,   inf, 7,   5},
        {3,   inf, inf, 0,   inf, 1},
        {inf, inf, 7,   inf, 0,   1},
        {inf, inf, 5,   1,   1,   0},
    };*/


    vector<vector<int>> v = {
        {0,   1,   -1},
        {1,   0,   -2},
        {-1,   -2,   0},
    };


    size_t N = v.size();
    vector<vector<int>> P(N, vector<int>({ 0, 1, 2}));

    for (int k = 0; k < N ;k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int d;
                if (v[i][k] == inf || v[k][j] == inf) 
                    d = inf;              
                else d = v[i][k] + v[k][j];

                if (d < v[i][j]) {
                    v[i][j] = d;
                    P[i][j] = k;
                }
            }
        }
    }

    int start = 0;
    int end = 2;
   /* list<int> path = get_path(P, end, start);*/


    cout << "v: " << endl;
    for (auto i : v) {
        for (int j : i) {
            cout << j << " ";
        }
       cout << endl;
    }

    cout << endl;
    cout << "P: " << endl;
    for (auto i : P) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    /*cout << endl;
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;*/


    /*cout << "T: ";
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
    cout << endl;*/
}

