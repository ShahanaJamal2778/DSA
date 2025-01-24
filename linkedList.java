import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

public class linkedList {
    private Node head;
    private int size;
    private int dsize;
    private dNode head2;
    private dNode tail;


    class Node{
        String data;
        Node next;
        public Node(String data){
            this.data=data;
            size++;
        }

    }


    class dNode {
        String data;
        Node next;
        Node previous;

        public dNode(String data) {
            this.data = data;
            dsize++;
        }

    }
    public int get_size_of_doubly_linked_list(){
        return dsize;
    }


    public void push_front(String data){
        dNode newNode=new dNode(data);
        dsize++;
        if(head2==null){
            tail=newNode;
            head2=newNode;
        }else{
            newNode.next=head2;
            head2.previous=newNode;
            head2=newNode;

        }
    }
    public void push_back(String data){
        dNode newNode=new dNode(data);
        dsize++;
        if(head2==null){
            tail=newNode;
            head2=newNode;
            return;
        }else{
            newNode.previous=tail;
            tail.next=newNode;
            tail=newNode;

        }
    }

    public void pop_front() {
//        dNode temp=head2; in case of c++
        if(head2==null){
            System.out.print("your list is empty");
            return;
        }
        dsize--;
        if(head2==tail){
            head2=null;
            tail=null;
            return;
        }
        head2 = head2.next;
        head2.previous = null;
//            temp.next=null;
//            delete temp;
    }


    public void pop_back(){
        if(tail==null){
            System.out.println("your list is empty");
            return;
        }
        dsize--;
        if(head2==tail){
            head2=null;
            tail=null;
            return;
        }
        tail=tail.previous;
        tail.next=null;

    }


    public void print2() {
        if (head2 == null) {
            System.out.print("linked list is empty");
            return;
        }
        dNode currNode = head2;
        while (currNode != null) {
            System.out.print(currNode.data + " ->");
            currNode = currNode.next;
        }
        System.out.println("Null");

    }


        public void add_First(String data) {
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
                return;
            } else {
                newNode.next = head;
                head = newNode;
            }
        }


        public void add_last(String data) {
            Node newNode = new Node(data);
            if (head == null) {
                head = newNode;
                return;
            }
            Node currentNode = head;
            while (currentNode.next != null) {
                currentNode = currentNode.next;
            }
            currentNode.next = newNode;

        }

        public void print() {
            if (head == null) {
                System.out.print("linked list is empty");
                return;
            }
            Node currNode = head;
            while (currNode != null) {
                System.out.print(currNode.data + " ->");
                currNode = currNode.next;
            }
            System.out.println("Null");

        }

        public void deleteFirst() {
            if (head == null) {
                System.out.println("linked list is empty");
                return;
            }
            head = head.next;
            size--;
        }

        public void deleteLast() {
            if (head == null) {
                System.out.println("linked list is empty");
                return;
            }
            size--;
            if (head.next == null) {
                head = null;
                return;

            }
            Node firstnode = head;
            Node secondNode = head.next;
            while (secondNode.next != null) {
                firstnode = firstnode.next;
                secondNode = secondNode.next;
            }
            firstnode.next = null;

        }

        public int get_size() {
            return size;
        }

        public void insert(int index, String data) {
            Node newNode = new Node(data);
            Node currNode = head;
            int i = 0;
            while (i < index) {
                currNode = currNode.next;
                i++;
            }
            newNode.next = currNode.next;
            currNode.next = newNode;

        }

        public static void main(String[] args) {

            linkedList l1 = new linkedList();
            l1.add_First("this");
            l1.add_First("is");
            l1.add_last("list2");
            l1.add_last("list");

            l1.deleteFirst();
            l1.deleteLast();
            l1.insert(1, "linkedlist3");
            l1.print();

            ArrayList<Character> a = new ArrayList<Character>();
            a.add('@');
            a.add('$');
            a.add('*');
            a.add('&');
            Collections.shuffle(a);
            System.out.print(a);

            LinkedList<String> l2 = new LinkedList<String>();
            l2.addFirst("this");
            l2.add("is");
            System.out.println(l2);
            for (String s : l2) {
                System.out.print(s);
            }


            linkedList doubly_linked_list=new linkedList();
            linkedList doubly_linked_list_empty=new linkedList();

            doubly_linked_list.push_front("this");
            doubly_linked_list.push_front("is");
            doubly_linked_list.push_back("doubly");
            doubly_linked_list.push_back("linked list");
            doubly_linked_list.pop_front();
            doubly_linked_list.pop_back();
            doubly_linked_list.get_size_of_doubly_linked_list();
            doubly_linked_list_empty.pop_front();
            doubly_linked_list_empty.pop_back();
            doubly_linked_list_empty.get_size_of_doubly_linked_list();
            doubly_linked_list.print2();
        }

    }
