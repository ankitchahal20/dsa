class Solution {
public:

    bool isMatchRecursive(string s, int n, string p, int m){

        // both s and p exhausted
        if(m == 0 && n == 0) return true;

        // s is not exhausted but string p is exhausted i.e. return false;
        if(n>0 && m==0) return false;

        // s is exhausted and string p is not exhausted .i.e. p is empty string
        // now entire p is * then only you can match s to p.
        if(n == 0 && m>0){
            while(m>0){
                cout<<p[m]<<endl;
                if(p[m-1]!='*')
                {
                    return false;
                }
                m--;
            }
            return true;
        } 

        if(s[n-1] == p[m-1] || p[m-1]=='?'){
            return isMatchRecursive(s, n-1, p, m-1);
        } else {
            if(p[m-1]=='*'){
                return isMatchRecursive(s, n-1, p, m) || isMatchRecursive(s, n, p, m-1);
            } else {
                return false;
            }
        }
    }

    bool isMatchRecursiveMemomization(string &s, int n, string &p, int m, vector<vector<int>> &dp){

        // both s and p exhausted
        if(m == 0 && n == 0) return true;

        // s is not exhausted but string p is exhausted i.e. return false;
        if(n>0 && m==0) return false;

        // s is exhausted and string p is not exhausted .i.e. p is empty string
        // now entire p is * then only you can match s to p.
        if(n == 0 && m>0){
            while(m>0){
                if(p[m-1]!='*')
                {
                    return false;
                }
                m--;
            }
            return true;
        } 

        if(dp[n][m] != -1 ){
            return dp[n][m];
        }


        if(s[n-1] == p[m-1] || p[m-1]=='?'){
            return dp[n][m] = isMatchRecursiveMemomization(s, n-1, p, m-1, dp);
        } else {
            if(p[m-1]=='*'){
                return dp[n][m]= isMatchRecursiveMemomization(s, n-1, p, m, dp) || isMatchRecursiveMemomization(s, n, p, m-1, dp);
            } else {
                return dp[n][m] = false;
            }
        }
    }

    bool isMatchTabulation(string s, int n, string p, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        dp[0][0] = true;
        for(int i=1;i<=n;i++) dp[i][0]=false;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            dp[0][i]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1]; 
                } else{
                    if(p[j-1]=='*'){
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    } else{
                        dp[i][j] = false;
                    }
                }
            }
        }

        return dp[n][m];
    }

    bool isMatchTabulationSpaceOptimized(string s, int n, string p, int m){
        vector<int> curr(m+1, 0);
        vector<int> prev(m+1, 0);
        

        prev[0]=1;
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            prev[i]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j] = prev[j-1]; 
                } else{
                    if(p[j-1]=='*'){
                        curr[j] = prev[j] || curr[j-1];
                    } else{
                        curr[j] = false;
                    }
                }
            }
            prev = curr;
        }

        return prev[m];
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // recursive solution
        // return isMatchRecursive(s, n, p, m);

        // recursive memomization
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return isMatchRecursiveMemomization(s, n, p, m, dp);

        // tabulation solution
        //return isMatchTabulation(s, n, p, m);

        return isMatchTabulationSpaceOptimized(s, n, p, m);
    }
};
