#include <iostream>
#include "common.h"
//64. Minimum sum path
int minPathSum(vector<vector<int>   >& grid) {
    vector<vector<int> > sum = grid;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[i].size(); j++) {
            if(i-1>=0 && j-1>=0) {
                grid[i][j] += (grid[i-1][j] < grid[i][j-1] ? grid[i-1][j] : grid[i][j-1]);
            } else if(i-1>=0) {
                grid[i][j] += grid[i-1][j];
            } else if(j-1>=0) {
                grid[i][j] += grid[i][j-1];
            } else {
                //grid[i][j] = grid[0][0];
            }

            cout << i << " " << j << " " << grid[i][j] << endl;
            if(i==(grid.size()-1) && j==(grid[i].size())-1) return grid[i][j];
        }
    }


}

int main (int argc, char** argv)
{


    vector<vector<int> > grid;

    vector<int> v1({1, 2}), v2({1, 1});

    grid.push_back(v1);
    grid.push_back(v2);

    cout << minPathSum(grid) << endl;
    return (0);
}
