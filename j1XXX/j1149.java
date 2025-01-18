package j1XXX;

import java.util.Scanner;

public class j1149 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[][] house = new int[N][3];
        for (int i = 0 ; i < N ;i++){
            house[i][0] = scanner.nextInt();
            house[i][1] = scanner.nextInt();
            house[i][2] = scanner.nextInt();
        }

        int[][] dp = new int[N][3];
        dp[0][0] = house[0][0];
        dp[0][1] = house[0][1];
        dp[0][2] = house[0][2];

        for (int i = 1; i < N ; i++){
            dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + house[i][0];
            dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + house[i][1];
            dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + house[i][2];
        }

        System.out.println(Math.min(Math.min(dp[N-1][0],dp[N-1][1]),dp[N-1][2]));


        scanner.close();
    }
}
