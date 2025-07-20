class Solution {
public:
    double myPow(double x, int n) {
        return binaryExp(x, static_cast<long>(n));
    }
private:
    double binaryExp(double base, long expo) {
        if (expo == 0) {
            return 1;
        }
        if (expo < 0) {
            return 1.0 / binaryExp(base, -expo);
        } 
        if (expo % 2 == 1) {
            return base * binaryExp(base * base, (expo - 1) / 2);
        } else {
            return binaryExp(base * base, expo / 2);
        }
    }
};