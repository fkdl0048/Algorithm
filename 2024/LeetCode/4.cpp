#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// 벡터로 해결하는 방법
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> merged;

    for(auto n : nums1)
    {
        merged.push_back(n);
    }

    for(auto n : nums2)
    {
        merged.push_back(n);
    }

    sort(merged.begin(), merged.end());

    int size = merged.size();

    if (size % 2 != 0)
        return static_cast<double>(merged[size / 2]);
    else
        return (static_cast<double>(merged[size / 2 - 1]) + static_cast<double>(merged[size / 2])) / 2.0;
}

void testCase()
{
    auto epsilon = 1e-9;  // 작은 허용 오차

    {
        vector<int> nums1{1, 2};
        vector<int> nums2{2};
        auto res = findMedianSortedArrays(nums1, nums2);
        assert(abs(res - 2.0) < epsilon);
    }
    {
        vector<int> nums1{1, 2};
        vector<int> nums2{3, 4};
        auto res = findMedianSortedArrays(nums1, nums2);
        assert(abs(res - 2.5) < epsilon);
    }

    cout << "Passed all test cases" << '\n';
}

int main()
{
    testCase();
    return 0;
}