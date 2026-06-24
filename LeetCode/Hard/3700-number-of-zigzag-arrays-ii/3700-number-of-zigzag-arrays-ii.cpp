class Solution {
    long long MOD = 1e9 + 7;

    std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
        int size = A.size();
        std::vector<std::vector<long long>> C(size, std::vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    std::vector<std::vector<long long>> power(std::vector<std::vector<long long>> A, long long p) {
        int size = A.size();
        std::vector<std::vector<long long>> res(size, std::vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1;
        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

    int getStateIndex(int val, int dir, int m) {
        return dir * m + val;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int totalStates = 2 * m;

        if (n == 1) return m;

        std::vector<std::vector<long long>> T(totalStates, std::vector<long long>(totalStates, 0));
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < j; ++k) {
                T[getStateIndex(k, 1, m)][getStateIndex(j, 0, m)] = 1;
            }
            for (int k = j + 1; k < m; ++k) {
                T[getStateIndex(k, 0, m)][getStateIndex(j, 1, m)] = 1;
            }
        }

        T = power(T, n - 2);

        std::vector<long long> initial(totalStates, 0);
        for (int k = 0; k < m; ++k) {
            initial[getStateIndex(k, 0, m)] = k;
            initial[getStateIndex(k, 1, m)] = m - 1 - k;
        }

        long long totalArrays = 0;
        for (int i = 0; i < totalStates; ++i) {
            long long finalStateWays = 0;
            for (int j = 0; j < totalStates; ++j) {
                finalStateWays = (finalStateWays + T[i][j] * initial[j]) % MOD;
            }
            totalArrays = (totalArrays + finalStateWays) % MOD;
        }

        return totalArrays;
    }
};