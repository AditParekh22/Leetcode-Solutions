class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int > > q;
        set<string> st(wordList.begin(), wordList.end());
        
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty())
        {
            string curr = q.front().first;
            int val = q.front().second;
            q.pop();

            if(curr == endWord)
                return val;

            for(int i=0; i<curr.size(); i++)
            {
                string temp = curr;
                for(char ch = 'a'; ch<='z'; ch++)
                {
                    temp[i] = ch; 
                    if(st.find(temp) != st.end())
                    {
                        st.erase(temp);
                        q.push({temp, val+1});
                    }
                }
            }

        }
        return 0;
        
    }
};