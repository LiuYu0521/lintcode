class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        long long res=1;//用int的话中间会溢出
        long long base=a;

        if(n==0){
            return 1%b;
        }

        while(n){
            int bi=n%2;
            n/=2;
            if(bi){
                res=(res*base)%b;
            }
            base=(base*base)%b;
        }

        return res;
    }
};
