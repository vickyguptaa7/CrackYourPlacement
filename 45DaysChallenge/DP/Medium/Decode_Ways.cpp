class Solution
{
public:
    int helper(int indx, string &s, vector<int> &dp)
    {
        if (indx == s.size())
            return 1;

        if (s[indx] == '0')
            return 0;

        if (dp[indx] != -1)
            return dp[indx];

        int ways = helper(indx + 1, s, dp);
        if (indx + 1 != s.size() && stoi(s.substr(indx, 2)) <= 26)
        {
            ways += helper(indx + 2, s, dp);
        }
        return dp[indx] = ways;
    }

    int numDecodings(string s)
    {
        vector<int> dp(s.size(), -1);
        return helper(0, s, dp);
    }
};