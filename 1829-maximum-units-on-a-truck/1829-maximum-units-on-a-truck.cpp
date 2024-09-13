class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truckSize){

        vector<pair<int, int> > arr;
        int n = box.size();

        for(int i=0; i<n; i++)
            arr.push_back({box[i][1], box[i][0]});
        
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        long long int ans = 0;

        int i=0;
        while(truckSize>0 && i<n){
            long long units = arr[i].first;
            long long boxes = arr[i].second;
            cout << units << " " << boxes << endl;
            if(truckSize-boxes>=0){
                ans += boxes * units;
                truckSize -= boxes;
            }else{
                ans += truckSize * units;
                truckSize = 0;
            }
            cout << truckSize << endl;
            i++;
        }

        return ans;
    }
};