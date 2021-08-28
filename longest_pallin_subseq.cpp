class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        
        
        int m = s.size();
        vector<vector<int>> dp(m+1,vector<int> (m+1,0));
        int maxlen = 1;
        
        //TC - O(M^2)
        
        
        for(int len = 1;len <= m;len++)
        {
            for(int start  = 0;start + len - 1 < m;start++)
            {
                int end = start + len -1;
                if(len == 1)
                {
                    dp[start][end] = 1;
                }
                else 
                {
                    if(s[start] == s[end])
                    {
                        dp[start][end] = 2 + dp[start+1][end-1];
                        maxlen = max(maxlen,dp[start][end]);
                    }
                    else 
                    {
                        dp[start][end] = max(dp[start+1][end],dp[start][end-1]);
                    }
                }
            }
        }
        
        return maxlen;
        
    }
};
