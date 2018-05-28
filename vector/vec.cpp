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

    // (1) At this point, low > high. That is, low >= high+1
    // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
    // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
    //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
    return low;
}


// Quick Sort
int partition(vector<int> &vec, int start, int end) {
    int piv_index = start+1;
    int pivot = vec[start];

    for(int i = start+1; i <= end; i++) {
        if(vec[i] > pivot) {
            swap(vec[i], vec[piv_index]);
            piv_index++;
        }
    }

    swap(vec[start], vec[piv_index-1]);

    return piv_index-1;
}

void quick_sort(vector<int> &vec, int start, int end) {
    if(start < end) {
        int pivot = partition(vec, start, end);

        quick_sort(vec, start, pivot-1);
        quick_sort(vec, pivot+1, end);
    }
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> res; res.reserve(2);
    for(int i = 0; i < nums.size(); i++) {
        if(map.find(nums[i]) == map.end()) {
            map[target-nums[i]] = i;
        } else {
            res[0] = map[nums[i]];
            res[1] = i;
            return res;
        }
    }
    //return res;
}

int main (int argc, char** argv)
{

//    vector<int> vec;
//    int N = 100;
//    for(int i = 0; i < N; i++)
//        vec.push_back(rand()%1000);


//    for(int i = 0; i < N; i++)
//        std::cout << vec[i] << " ";

//    std::cout << std::endl;


//    quick_sort(vec, 0, vec.size()-1);


//    for(int i = 0; i < N; i++)
//        std::cout << vec[i] << " ";

//    std::cout << std::endl;

    vector<int> vec({2,7,11,15});

    auto res = twoSum(vec, 9);

    for(int i = 0; i < 2; i++)
        std::cout << res[i] << " ";

    std::cout << std::endl;

    return (0);
}
