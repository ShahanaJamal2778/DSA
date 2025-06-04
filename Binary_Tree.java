
public class Binary_Tree {

     public static class Node {
        int data;
        Node left;
        Node right;
        Node(int val){
            this.data=val;
    }


       public static Node insert(Node root,int val) {
        if(root==null){
            root=new Node(val);
           return root;
        }
        if(root.data>val){
            root.left=insert(root.left, val);

        }
        else{
            root.right=insert(root.right,val);
        }
        return root;
       }

       public static void inorder(Node root){
            if(root==null){
                return;
            }
            inorder(root.left);
            System.out.println(root.data+" ");
           inorder(root.right);
       }


       public static void main(String[] args){
        int values[]={3,4,5,67,78,90,1};
           Node root = null;


        for(int i=0;i<values.length;i++){
          root=insert(root,values[i]);
        }
inorder(root);

    }



    }












}
