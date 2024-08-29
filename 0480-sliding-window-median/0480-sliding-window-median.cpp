class Solution {
public:
    multiset<double> minH;
    multiset<double, greater<double>> maxH;
    
    void balanceHeaps()
    {
        if(maxH.size() > minH.size())
        {
            minH.insert(*maxH.begin());  
            maxH.erase(maxH.begin());
        }
    }
    
    double getMedian(int k)
    {
        if(k%2 == 0)
            return (*minH.begin() + *maxH.begin())*0.5;
        else return *minH.begin();
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        vector<double> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i >= k) // Only delete element from one of the heaps
            {
                if(minH.find(nums[i-k]) != minH.end()) minH.erase(minH.find(nums[i-k]));
                else maxH.erase(maxH.find(nums[i-k]));
            }
            
            // The idea here is very simple: First we insert the current element in the min heap
            // The we insert the top of min heap to max heap
            // Then we balance the heaps i.e. move element from max to min heap if max heap has
            // greater size
            minH.insert(nums[i]);
            maxH.insert(*minH.begin());
            minH.erase(minH.begin());
            
            balanceHeaps();            
            
            if(i >= k-1) ans.push_back(getMedian(k)); 
        }
        
        return ans;
    }
};