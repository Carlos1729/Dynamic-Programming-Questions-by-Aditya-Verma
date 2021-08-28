class Solution {
public:
    
//     int lcs(string t1,string t2,int m,int n)
//     {
//         if(m == 0 || n == 0)
//             return dp[m][n] = 0;
        
        
//         if(dp[m][n] != -1)
//             return dp[m][n];
        
//         if(t1[m-1] == t2[n-1])
//         {
//             return dp[m][n] = 1+lcs(t1,t2,m-1,n-1);
//         }
        
//         else 
//         {
//             return dp[m][n] = max(lcs(t1,t2,m,n-1),lcs(t1,t2,m-1,n));
//         }
//     }
    
    int longestCommonSubsequence(string t1, string t2) {
        
        
        //Subse1uences of string 1 and all subsequences of string 2 then basically maintain a map of both of them and find ou the common longer one
        //O(2^n*l) time
        
//         Recursion — Big O(2^N)
// Memoization — O(N) — time, O(N) — space
// Bottoms Up — O(N) — time, O(1) — space
        
//                        lcs("AXYT", "AYZX")
//                        /                 \
//          lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
//          /                              /               
// lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")
            
            
        
//         We can clearly see that we are recomputing there lcs between AXY and AYZ we can store this and use it only once instead 
        
//         a b c d e     - max of these both the strings 
//         a c d 
        
        
        int m = t1.length();
        int n = t2.length();
        
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(int i = 0;i <= m;i++)
        {
            for(int j = 0;j <= n;j++)
            {
                if(i == 0)
                    dp[i][0] = 0;
                else if(j == 0)
                    dp[0][j] = 0;
                else if(t1[i-1] == t2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        // return dp[m][n];
        
        
        
        return dp[m][n];
        
        //tc - o(n^2)
        //sc - o(n^2)
    }
};
