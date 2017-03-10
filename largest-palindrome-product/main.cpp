class Solution {
public:
    bool isPalindrome(int64_t n) {
        int64_t r = 0;
        for (int64_t x = n; x != 0; r = r*10 + x%10, x /= 10);
        return r == n;
    }
    
    int ipow(int n) { //n [1,8]
        int res = 1;
        for (; n > 0; n--)
            res *= 10;
        return res;
    }
    
    int largestPalindrome(int n) {
        if (n == 1)return 9;  //special
        int maxn = ipow(n) -1;
        int minn = maxn / 10;
        for (int i = maxn; i > minn; --i) {
            int64_t left = i;
            int right = 0;
            for (int h = i; h != 0; right = right*10 + h%10, left *= 10, h/=10);
            int64_t pd = left + right; //palindrome constructed
            
            for (int j = maxn; j > minn; --j) {
                int k = pd / j;
                if (k < minn || j < k)break;  //invalid
                if (pd % j == 0) {
                    //cout << pd << endl;
                    return pd % 1337;
                }
            }
        }
        return 0;
    }
};
