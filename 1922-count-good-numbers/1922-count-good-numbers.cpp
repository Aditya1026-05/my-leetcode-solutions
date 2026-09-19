class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long x, long long n){

        if(n == 0)
            return 1;

        long long half = modPow(x, n / 2);

        long long result = (half * half) % MOD;

        if(n % 2 == 1)
            result = (result * x) % MOD;

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_positions = (n+1)/2;
        long long odd_positions = (n)/2;

        return (modPow(5, even_positions) * modPow(4, odd_positions)) % MOD;
    }
};