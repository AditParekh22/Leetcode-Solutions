class Solution {
public:
    int maxEqualFreq(vector<int>& v) {
        int n=v.size();
        int ans=1;
        map<int,int>mp; //freq of elements
        map<int,int>mpp; //freq of freq
        for(int i=0;i<n;++i)
        {
            int old=mp[v[i]]; //prev freq
            ++mp[v[i]];
            if(mpp[old]>0)
            --mpp[old];
            if(mpp[old]==0) mpp.erase(old);
            ++mpp[mp[v[i]]];

            int a=mpp.begin()->first;
            int b=mpp.rbegin()->first;

            if(mpp.size()==1 && ((a==1)|| (mpp[a]==1))) ans=max(ans,i+1);
            else if(mpp.size()==2 && ((b==a+1 && mpp[b]==1) || (mpp[a]==1 && a==1)))
            ans=max(ans,i+1);
        }
        return ans;
    }
};