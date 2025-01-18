package java11XXX;

import java.util.Scanner;

public class j11047 {
    public static void main(String[] args) {
        int N, K;
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();
        int[] coins = new int[N];
        for(int i = 0 ; i < N ; i++){
            coins[i] = scanner.nextInt();
        }
        int count = 0;
        for (int j = N-1; j >= 0 ; j--){
            if(coins[j] > K) continue;
            while(K >= coins[j]){
                K -= coins[j];
                count++;
            }
        }
        System.out.println(count);
        scanner.close();
    }
}
