// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> // order_of_key and find_by_order

class Solution {
public:
    #define ll long long 
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            pos[nums2[i]] = i;
        }

        ordered_set s;
        vector<ll> pref(n), suff(n);
        for(ll i=0;i<n;i++){
            ll curr_pos = pos[nums1[i]];

            pref[i] = s.order_of_key(curr_pos);

            s.insert(curr_pos);
        }
        s.clear();

        for(ll i=n-1;i>=0;i--){
            ll curr_pos = pos[nums1[i]];

            suff[i] = s.size() - s.order_of_key(curr_pos);

            s.insert(curr_pos);
        }
        ll ans = 0;
        for(ll i=0;i<n;i++){
            ans += pref[i]*suff[i];
        }
        return ans;

        
    }
};
