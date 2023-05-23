#include <iostream>
#include <bits/stdc++.h>

const int ROWS = 7; //Hard-coded for convinient, please change accordingly
const int COLS = 12;
const int NUM_GEMS = 35;

using namespace std;

//INIT
int gems_grid[ROWS][COLS] = {};

int gems[NUM_GEMS][3] = {{2, 6, 1},{0, 6, 1},{4, 6, 1},{4, 10, 2},{5, 8, 2},{2, 11, 2},{0, 7, 1},{2, 5, 1},{2, 7, 1},{5, 7, 1},{3, 8, 2},{5, 10, 2},{2, 4, 1},{0, 10, 2},{2, 9, 2},{0, 8, 2},{0, 9, 2},{3, 11, 2},{4, 5, 1},{1, 8, 2},{5, 5, 1},{3, 10, 2},{2, 2, 1},{4, 8, 2},{3, 6, 1},{1, 10, 2},{4, 9, 2},{5, 6, 1},{2, 8, 2},{3, 5, 1},{2, 3, 1},{2, 10, 2},{3, 7, 1},{4, 7, 1},{0, 5, 1}};

vector<pair<int,int>> hits = {{2, 2}, {2, 9}, {2, 2}, {0, 0}, {0, 1}, {0, 2}, {0, 3}};

void printGrid(int rows, int cols,int gems[][COLS]) {
    cout << "GRID:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << gems[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void translateGems(int gems_grid[][COLS], int gems[][3]) {
    for (int i = 0; i < NUM_GEMS; i++) {
        gems_grid[gems[i][0]][gems[i][1]] = gems[i][2];
        //cout << "CORD: " << "[" << gems[i][0] << "," << gems[i][1] << "] = " << gems[i][2] << endl;
    }
}

void travel_dfs(int gems[][COLS], int i, int j, vector<pair<int,int>>& visited, vector<pair<int,int>>& result, pair<int,int> coordinate) {
    bool contains = 0, bound_i = 0, bound_j = 0, not_equal = 0;
    pair<int, int> item = {i,j};

    //cout << "[" << i << "," << j << "]";

    if (i >= ROWS || i < 0) bound_i = 1;
    if (j >= COLS || j < 0) bound_j = 1;
    if (bound_i || bound_j) {
        //cout << " BOUND!" << endl;
        return;
    }

    if (find(visited.begin(), visited.end(), item) != visited.end()) contains = 1;
    if (gems[i][j] != gems[coordinate.first][coordinate.second]) not_equal = 1;
    if (contains || not_equal) {
        //cout << " LATER!" << endl;
        return;
    }

    if(gems[i][j] == 0) return;

    visited.push_back({i, j});
    result.push_back({i, j});

    //cout << " CHECK!" << endl;

    travel_dfs(gems, i + 1, j, visited, result, coordinate);
    travel_dfs(gems, i - 1, j, visited, result, coordinate);
    travel_dfs(gems, i, j + 1, visited, result, coordinate);
    travel_dfs(gems, i, j - 1, visited, result, coordinate);    
}

int countExplodedGems(int rows, int cols, int gems[][COLS], vector<pair<int,int>> hits)  {
    int result = 0;
    set<pair<int,int>> final;

    for (int it = 0; it < hits.size(); it++) {
        pair<int, int> coordinate = {hits[it].first, hits[it].second};
        
        vector<pair<int, int>> res;
        vector<pair<int, int>> visited;

        travel_dfs(gems, coordinate.first, coordinate.second, visited, res, coordinate);

        for (int it = 0; it < res.size(); it++) {
            pair<int, int> coordinate = {res[it].first, res[it].second};

            //cout << "[" << coordinate.first << "," << coordinate.second << "]" << endl;

            final.insert(coordinate);
        }
    }

    return result = final.size();
}

int main()
{
    translateGems(gems_grid, gems); //IRRELEVANT TO THE ACTUAL PERFORMANCE

    int result = countExplodedGems(ROWS, COLS, gems_grid, hits); //MAIN TO-DO

    //printGrid(ROWS,COLS,gems_grid);

    cout << "RESULT:" << endl << result << endl;
    
    return 0;
}