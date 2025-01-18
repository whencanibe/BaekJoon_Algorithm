package j1XXX;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

//BinaryTree 구현. 삽입, 전,중,후 위 순위 구현
class BinaryTree {
    private Map<Character, Node> tree;

    public BinaryTree(){
        tree = new HashMap<>();
    }

    public void addNode(char root, char left, char right){
        Node node = new Node(left, right);
        tree.put(root,node);
    }

    public void preorder(char node, StringBuilder result){
        if(node == '.') return;
        char nextLeft = tree.get(node).left;
        char nextRight = tree.get(node).right;
    
        result = result.append(node);
        preorder(nextLeft, result);
        preorder(nextRight, result);
    }

    public void inorder(char node, StringBuilder result){
        if(node == '.') return;
        char nextLeft = tree.get(node).left;
        char nextRight = tree.get(node).right;
        inorder(nextLeft, result);
        result = result.append(node);
        inorder(nextRight, result);
    }

    public void postorder(char node, StringBuilder result){
        if(node == '.') return;
        char nextLeft = tree.get(node).left;
        char nextRight = tree.get(node).right;
        
        postorder(nextLeft, result);
        postorder(nextRight, result);
        result = result.append(node);
    }

    private class Node {
        char left;
        char right;
        Node(char left, char right){
            this.left = left;
            this.right = right;
        }
    }
}

public class j1991 {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();

        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        scanner.nextLine(); // nextInt() 다음에는 무조건 nextLine 으로 개행 제거!!!!
        // root L child R child 입력받기
        for (int i = 0; i < N; i++) {
            if(scanner.hasNextLine()){
                String input = scanner.nextLine();
                char root = input.split(" ")[0].charAt(0);
                char left = input.split(" ")[1].charAt(0);
                char right = input.split(" ")[2].charAt(0);
                bt.addNode(root, left, right);
            }
        }

       // 각각의 순회 결과를 저장할 StringBuilder를 초기화
       StringBuilder preOrderResult  = new StringBuilder();
       StringBuilder inOrderResult   = new StringBuilder();
       StringBuilder postOrderResult = new StringBuilder();

       // 실제로 전위/중위/후위 순회를 수행
       bt.preorder('A', preOrderResult);
       bt.inorder('A', inOrderResult);
       bt.postorder('A', postOrderResult);

       // 결과 출력
       System.out.println(preOrderResult);
       System.out.println(inOrderResult);
       System.out.println(postOrderResult);
        scanner.close();
    }
}
