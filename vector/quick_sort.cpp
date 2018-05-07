#include <iostream>
#include "vec.h"
// 35. Search Insert Position
int searchInsert(vector<int>& nums, int target) {
    int low(0), high(nums.size()-1);
    //int mid(0);
    while(low<=high) {
        int mid = (low+high)/2;
        if(nums[mid] < target){
            low = mid+1;
        } else if( nums[mid] > target) {
            high = mid-1;
        } else {
            return mid;
        }

    }
    return low;

}


int main (int argc, char** argv)
{



    return (0);
}
