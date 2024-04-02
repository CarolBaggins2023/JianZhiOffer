#include <iostream>
#include <vector>

class Solution {
    
public:
    
    int InversePairs(std::vector<int>& nums) {
        MergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }

private:

    void MergeSort(std::vector<int> &nums, int l, int r) {
        if (l == r) {
            return;
        }

        int m = (l+r)/2;
        MergeSort(nums, l, m);
        MergeSort(nums, m+1, r);
        Merge(nums, l, m, r);
        int x = 1;
    }

    void Merge(std::vector<int> &nums, int l, int m, int r) {
        std::vector<int> tmp(r-l+1, 0);
        int i = l, j = m+1, k = 0;
        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
                cnt = (cnt + m + 1 - i) % P;
            }
        }
        while (i <= m) {
            tmp[k++] = nums[i++];
        }
        while(j <= r) {
            tmp[k++] = nums[j++];
        }

        i = 0;
        j = l;
        for (; i < tmp.size(); ++i, ++j) {
            nums[j] = tmp[i];
        }
    }

    long long cnt = 0;
    const long long P = 1000000007;
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::vector<int> nums{4,3,2,1};
    sol.InversePairs(nums);
    for (auto i : nums) {
        std::cout << i << " ";
    }
    
    return 0;
}
