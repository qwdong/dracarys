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


int divide(int dividend, int divisor) {

    if(dividend == std::numeric_limits<int>::min() && divisor == -1)return std::numeric_limits<int>::max();
    int result = dividend/divisor;
    return result;
}

int main (int argc, char** argv)
{
    std::cout << divide(10, 3) << std::endl;
    std::cout << (10/3) << std::endl;
    int a = 10, b = 3;

    cout << a/b << std::endl;
    return (0);
}
