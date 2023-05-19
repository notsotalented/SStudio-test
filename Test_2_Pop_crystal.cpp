#include <iostream>
#include <set>

using namespace std;

void printgrid(int rows, int cols,int gems[][3]) {
    cout << "GRID:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j =0; j < cols; j++) {
            cout << gems[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int countExplodedGems(int rows, int cols, int gems[][3], int hits[])  {
    set <int> validPos[2]; //create a set to save the validPos
    int result = 0;
    int target = gems[hits[0]][hits[1]];
    int pointer[2] = {0};
    
    if (target == 1) {
        validPos[result].insert(hits[0]); validPos[result].insert(hits[1]);
        result+=1;
    }   
    
    /*for (int i = 0; i < 1; i++) {
            cout << "Elements at index " << i << ": ";
      
            // Print the array of sets
            for (auto x : validPos[i])
                cout << x << " ";
      
            cout << endl;
    }   */

    return result;
}

int main()
{
    int rows = 3;
    int cols = 3;
    
    int gems[3][3] = {{1,2,3},{1,1,1},{2,2,2}}; //grid
    
    int hits[2]={1, 2}; //target
    
    printgrid(rows,cols,gems);
    
    cout << "RESULT:" << countExplodedGems(rows,cols,gems,hits);
    
    return 0;
}