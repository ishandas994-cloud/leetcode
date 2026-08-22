class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int num=n;
        int mul=1;
        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            mul*=digit;
            n /= 10;
        }
        if(num%(mul+sum)==0){
            return 1;
        }
        return 0;
    }
};