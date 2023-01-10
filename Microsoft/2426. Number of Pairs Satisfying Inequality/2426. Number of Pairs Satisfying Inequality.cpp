class Solution {
private:
    long long count = 0;
private:
    void countNumberofPairs(vector<int>&nums, int start, int mid, int end, int diff){
        int l = start;
        int r = mid +1;
        while(l <= mid && r <= end){
            if(nums[l] <= nums[r] + diff){
                count += (end- r + 1);
                l++; 
            }
            else{
                r++;
            }
        }
        // sort 
        sort(nums.begin() + start, nums.begin() + end+1);
    }
    void mergeSort(vector<int>&nums, int start, int end, int diff){
        if(start == end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums, start, mid, diff);
        mergeSort(nums, mid+1, end, diff);

        countNumberofPairs(nums,start, mid, end, diff);
        return;
        
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            nums[i] = nums1[i] - nums2[i];
        }
        mergeSort(nums, 0, n-1,diff);
        return count;
        
    }
};