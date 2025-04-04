#include <iostream>
#include <vector>
#include <limits>
#include <list>

using namespace std;

constexpr int INF = numeric_limits<int>::max();
constexpr int NEG_INF = numeric_limits<int>::min();

list<int> get_path(const vector<vector<int>>& P, int start, int end) {
    list<int> path;
    if (P[start][end] == -1) return path; // Нет пути

    path.push_front(end);
    while (start != end) {
        end = P[start][end];
        path.push_front(end);
    }
    return path;
}

int main() {
    /*vector<vector<int>> graph = {
        {0,   5,   INF, 1},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {-4,  INF, INF, 0}
    };*/

    /*vector<vector<int>> graph = {
    {0,   4,   INF, 2,   INF},
    {1,   0,   -3,  INF, INF},
    {INF, INF, 0,   0,   5},
    {INF, -1,  INF, 0,   INF},
    {6,   INF, -2,  INF, 0}
    };*/

    vector<vector<int>> graph = {
        // 0    1    2    3    4    5    6
        { 0,   5,  INF, INF, INF, INF,   1 },  // 0 → 1, 0 → 6
        {INF,  0,  -2,  INF, INF, INF, INF },  // 1 → 2
        {INF, INF,  0,  -1,  INF, INF, INF },  // 2 → 3
        {INF,  1,  INF,  0,  INF, INF, INF },  // 3 → 1 (замыкает отрицательный цикл)
        {INF, INF, INF, INF,  0,   1,  INF },  // 4 → 5 (начало изолированного цикла)
        {INF, INF, INF, INF,  1,   0,  INF },  // 5 → 4 (изолированный цикл 4→5→4)
        {INF, INF, INF, INF, INF, INF,  0 }    // 6 (изолированная вершина)
    };

    


    size_t N = graph.size();
    vector<vector<int>> dist = graph;
    vector<vector<int>> P(N, vector<int>(N, -1));

    // Инициализация матрицы предков
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) P[i][j] = i;
            else if (graph[i][j] != INF) P[i][j] = i;
        }
    }

    // Алгоритм Флойда-Уоршелла
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }

    // Вывод результатов
    cout << "dist:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] == INF) cout << "INF\t";
            else if (dist[i][j] == NEG_INF) cout << "-INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << endl;
    }


    // Проверка на отрицательные циклы
    for (int k = 0; k < N; ++k) {
        if (dist[k][k] < 0) { // Обнаружен отрицательный цикл через вершину k
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    // Если вершина j достижима из k и k достижима из i,
                    // то путь i->j может быть бесконечно уменьшен
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[k][k] < 0) {
                        dist[i][j] = NEG_INF; // Только тогда помечаем как -INF
                        P[i][j] = -1;
                    }
                }
            }
        }
    }

    // Вывод результатов
    cout << "dist:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] == INF) cout << "INF\t";
            else if (dist[i][j] == NEG_INF) cout << "-INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << endl;
    }

    //// Пример получения пути
    //cout << "\nПуть из 0 в 3: ";
    //auto path = get_path(P, 0, 3);
    //if (path.empty()) cout << "не существует";
    //else if (dist[0][3] == NEG_INF) cout << "может быть бесконечно уменьшен";
    //else {
    //    for (int v : path) cout << v << " ";
    //}
    //cout << endl;

    return 0;
}