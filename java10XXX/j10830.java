package java10XXX;

import java.util.Scanner;

public class j10830 {
    
    static int MOD = 1000;
    
    public static int[][] mulMat(int[][] A, int[][]B){
        int n = A.length;
        int[][] result = new int[n][n];
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ;j++){
                for(int k = 0 ; k < n; k++){
                    result[i][j] += A[i][k] * B[k][j];
                    result[i][j] %= MOD;
                }
            }
        }
        return result;
    }

    public static int[][] powMat(int[][]mat, long power){
        int n = mat.length;
        int[][] result = new int[n][n];
        for(int i = 0 ; i < n; i++){
            result[i][i] = 1;
        }

        while(power > 0){
            if(power % 2 == 1){
                result = mulMat(result, mat);
            }
    
            mat = mulMat(mat, mat);
            power /= 2;
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long B = scanner.nextLong();

        int[][] arr = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = scanner.nextInt();
            }
        }

        int[][] result = powMat(arr, B);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.print("\n");
        }

        scanner.close();
    }
}
