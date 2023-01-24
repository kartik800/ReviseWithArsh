/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int left(MountainArray &arr, int low, int high, int target){
        while(low <= high){
            int mid = (low + high)/2;

            if(arr.get(mid) == target) return mid;
            else if(arr.get(mid) < target) low = mid +1;
            else high = mid -1;
        }
        return -1;
    }
    int right(MountainArray &arr, int low, int high, int target){
        while(low <= high){
            int mid = (low + high)/2;

            if(arr.get(mid) == target) return mid;
            else if(arr.get(mid) > target) low = mid +1;
            else high = mid -1;
        }
        return -1;
    }
    int peak(MountainArray &arr, int n){
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;

            if(mid != n-1 && arr.get(mid) < arr.get(mid+1)) low=mid+1;
            else high = mid-1; 
        }
        return low;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int p = peak(mountainArr, n);

        int l = left(mountainArr, 0, p, target);
        int r = right(mountainArr, p+1, n-1, target);

        if(l == -1 && r== -1) return -1;
        else if(l == -1 && r != -1) return l;
        else if(l != -1 && r == -1) return r;
        return min(l,r);
        
    }
};