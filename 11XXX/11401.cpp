// https://www.acmicpc.net/problem/11401
#include <iostream>
#include <vector>

const int MOD = 1000000007;

// 빠른 거듭제곱을 이용한 모듈러 역원 계산
uint64_t modularExponentiation(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // 지수가 홀수인 경우
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // 밑을 제곱
        exp /= 2; // 지수를 절반으로 줄임
    }
    return result;
}

// 팩토리얼과 모듈러 역원을 계산
void factorialAndInv(int N, std::vector<uint64_t>& fact, std::vector<uint64_t>& inv) {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD; // 팩토리얼 계산
    }

    // 마지막 팩토리얼의 역원 계산
    inv[N] = modularExponentiation(fact[N], MOD - 2, MOD);

    // 이전 팩토리얼의 역원을 역순으로 계산
    for (int i = N - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int main() {
    int N, K;
    std::cin >> N >> K;

    // 팩토리얼과 역원을 저장할 벡터 준비
    std::vector<uint64_t> fact(N + 1); // 0부터 N까지 저장
    std::vector<uint64_t> inv(N + 1);  // 0부터 N까지 역원 저장

    // 팩토리얼과 역원 계산
    factorialAndInv(N, fact, inv);

    // N! / ((N-K)! * K!) mod MOD 계산
    uint64_t res = fact[N] * inv[N - K] % MOD * inv[K] % MOD;

    std::cout << res << std::endl;

    return 0;
}
