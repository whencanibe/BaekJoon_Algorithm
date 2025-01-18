package java2XXX;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class j2749 {
    static int MOD = 1000000;
    static int[] dp = new int[MOD * 2];

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(reader.readLine());

        int pisanoNumber = getPisano();

        N %= pisanoNumber;

        System.out.println(dp[(int) N]);
        reader.close();
    }

    public static int getPisano() {
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i < MOD * 2; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

            if (dp[i] == 1 && dp[i - 1] == 0) {
                return i - 1; // i가 아니라 i-1
            }
        }
        return -1;
    }
}
