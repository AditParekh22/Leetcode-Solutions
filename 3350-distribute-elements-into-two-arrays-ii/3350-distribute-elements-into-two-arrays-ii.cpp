#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans, arr1, arr2;
        ordered_set s1, s2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        s1.insert({nums[0], 0});
        s2.insert({nums[1], 1});

        for(int i=2; i<nums.size(); i++)
        {
            // cout << nums[i] << endl;
            int ele1 = s1.size() - (s1.order_of_key({nums[i]+1, 0}));
            int ele2 = s2.size() - (s2.order_of_key({nums[i]+1, 0}));

            if(ele2 > ele1 || (ele1 == ele2 && s1.size() > s2.size())){
                // cout << ele1 << " " << ele2 << " " << s1.size() << " " <<  s2.size()<< "a" << endl;
                arr2.push_back(nums[i]);
                s2.insert({nums[i], i});
            }
            else
            {
                // cout << ele1 << " " << ele2 << " " << "b" << endl;
                arr1.push_back(nums[i]);
                s1.insert({nums[i], i});
            }
        }
        // cout << endl;

        ans = arr1;

        for(auto it: arr2)
            ans.push_back(it);

        return ans;
    }
};