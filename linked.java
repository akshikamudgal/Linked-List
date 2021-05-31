package com.example.li;
import java.util.Scanner;
    public class linked {
        class Node
        {
            int data;
            Node next;
            public Node(int data)
            {
                this.data=data;
                this.next=null;
            }
        }

        Node head=new Node(4);
        int count=0;
        Scanner sc=new Scanner(System.in);

        void createlist(int n)
        {
            Node newnode,temp;
            int i,data;

            if(head==null)
            {
                System.out.println("cannot allocate");
                System.exit(0);
            }
            //else part

            System.out.println("enter data of first node: ");
            data=sc.nextInt();
            head.data=data;
            head.next=null;
            temp=head;
            for(i=2;i<n+1;i++)
            {
                newnode=new Node(data);
                if(newnode==null)
                {
                    System.exit(0);
                }
                System.out.println("enter data fo node "+i);
                data=sc.nextInt();
                newnode.data=data;
                newnode.next=null;
                temp.next=newnode;
                temp=newnode;
            }


        }
        public void traverse()
        {   Node temp;
            if(head==null)
            {
                System.exit(0);
            }
            temp=head;
            while(temp!=null)
            {
                System.out.println(temp.data+" ");

                temp=temp.next;
                count++;
            }
            System.out.println("count: "+count);

        }

        void insertatbegin()
        {
            System.out.println("inserting at beginning: ");
            Node newnode=new Node(1);
            int data;
            System.out.println("enter data: ");

            newnode.data=sc.nextInt();
            newnode.next=head;
            head=newnode;

        }
        void insertatend()
        {   Node temp;
            Node newnode=new Node(1);
            int data;
            System.out.println("adding node at end: ");
            System.out.println("enter data: ");
            newnode.data=sc.nextInt();
            newnode.next=null;
            temp=head;
            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newnode;

        }
        void insertatlocation()
        {
            int pos,i,data;
            i=1;
            Node newnode=new Node(3);
            Node temp=new Node(1);
            System.out.println("adding node at specific location: ");
            System.out.println("enter position: ");
            pos=sc.nextInt();
            if(pos>count)
            {
                System.out.println("invalid position ");
                System.exit(0);
            }
            else
            {    temp=head;
                while(i<pos)
                {
                    temp=temp.next;
                    i++;
                }
            }
            System.out.println("enter data for node: ");
            newnode.data=sc.nextInt();
            newnode.next=temp.next;
            temp.next=newnode;
        }
        public void print()
        {   Node temp;
            if(head==null)
            {
                System.exit(0);
            }
            temp=head;
            while(temp!=null)
            {
                System.out.println(temp.data+" ");

                temp=temp.next;

            }


        }


        public static void main(String[] args) {
            // TODO Auto-generated method stub

            int n;
            Scanner sc=new Scanner(System.in);
            System.out.println("enter no.of nodes: ");
            n=sc.nextInt();

            linked sll2=new linked();
            sll2.createlist(n);
            sll2.traverse();
//		sll2.insertatbegin();
//		sll2.insertatend();
            sll2.insertatlocation();
            sll2.print();



        }
    }
