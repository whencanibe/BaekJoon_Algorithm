package java2XXX;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class j2933 {

    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static int R, C;

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        R = scanner.nextInt();
        C = scanner.nextInt();
        char[][] mineral = new char[R][C];

        for (int i = 0; i < R; i++) {
            mineral[i] = scanner.next().toCharArray();
        }

        int count = scanner.nextInt();
        int[] heights = new int[count];

        for (int i = 0; i < count; i++) {
            heights[i] = scanner.nextInt();
        }

        for (int i = 0; i < count; i++) {
            if (i % 2 == 0) {
                throwLeft(mineral, heights[i]);
            } else {
                throwRight(mineral, heights[i]);
            }
            fallDown(mineral);
        }
        for (int i = 0; i < R; i++) {
            System.out.println(String.copyValueOf(mineral[i]));
        }
        scanner.close();
    }

    public static void throwLeft(char[][] mineral, int height) {
        for (int i = 0; i < C; i++) {
            if (mineral[height - 1][i] == 'x') {
                mineral[height-1][i] = '.';
                return;
            }
        }
    }

    public static void throwRight(char[][] mineral, int height) {
        for (int i = C - 1; i >= 0; i--) {
            if (mineral[height - 1][i] == 'x') {
                mineral[height-1][i] = '.';
                return;
            }
        }
    }

    public static void fallDown(char[][] mineral) {
        // 붙어있는거 확인해서 visited true로 만듦
        boolean[][] visited = new boolean[R][C];
        for (int i = 0; i < C; i++) {
            if (mineral[R - 1][i] == 'x' && !visited[R - 1][i]) {
                dfs(mineral, visited, i, R - 1);
            }
        }

        // visited false 이면서 'x' 인 애들의 위치를 배열에 담음
        List<int[]> cluster = new ArrayList<>();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (visited[i][j] == false && mineral[i][j] == 'x') {
                    cluster.add(new int[] { j, i }); // x, y : 0 based index
                }
            }
        }

        if (cluster.isEmpty()) {
            return;
        }

        // 그 클Y러스터 중에 제일 낮은 y좌표를 가진 애들을 찾아서 얼만큼 떨어져야하는지 거리를 계산함
        int minDist = Integer.MAX_VALUE;
        for (int[] cell : cluster) {
            int x = cell[0];
            int y = cell[1];

            int distance = 0;
            while (y + distance + 1 < R && mineral[y + distance + 1][x] == '.') {
                distance++;
            }
            minDist = Math.min(minDist, distance);
        }

        for (int i = 0; i < cluster.size(); i++) {
            System.out.println("x : " + cluster.get(i)[0] + " y : " + cluster.get(i)[1]);
        }
        // 실제로 떨어뜨려서 . 와 x 를 다시 씀
        for (int[] cell : cluster) {
            mineral[cell[1]][cell[0]] = '.'; // 원래 위치 초기화
        }
        for (int[] cell : cluster) {
            mineral[cell[1] + minDist][cell[0]] = 'x'; // 새로운 위치에 배치
        }
        
    }

    public static void dfs(char[][] mineral, boolean visited[][], int x, int y) {
        if (mineral[y][x] == 'x') {
            visited[y][x] = true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visited[ny][nx] && mineral[ny][nx] == 'x') {
                    dfs(mineral, visited, nx, ny);
                }
            }
        }
    }

}
