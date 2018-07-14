import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


/**
 * Created by Lukasz on 2017-06-01.
 */

public class Main {

    static class ListNode{

        int dest;
        double weight;
        ListNode next;

        ListNode(int dest, double weight){
            this.dest = dest;
            this.weight = weight;
        }
    }

    static class HeadList{
        ListNode head;
            HeadList(ListNode head){
                this.head = head;
            }

    }

    static class Graph{

       HeadList A[];
        int V;

        Graph(int n){
            this.V = n;
            A = new HeadList[n];
            for(int i = 0; i<n; i++){
                A[i] = new HeadList(null);
            }

        }


    }


    public static void addEdge(Graph g, int src, int dest, double weight){
        ListNode p = new ListNode(dest, weight);
        p.next = g.A[src].head;
        g.A[src].head = p;

        p = new ListNode(src, weight);
        p.next = g.A[dest].head;
        g.A[dest].head = p;
    }

    public static boolean isInMinHeap(PriortyQueue.Queue q, int v)
    {
        if (q.pos[v] < q.size)
            return true;
        return false;
    }
    public static boolean isEmpty(PriortyQueue.Queue q)
    {
        return q.size == 0;
    }

    public static void Prim() throws IOException {
        String piece;
        int w=0;
        int k;
        File inputFile = new File("Graph.txt");
        BufferedReader read = new BufferedReader(new FileReader(inputFile));

        piece = read.readLine();
        w = Integer.parseInt(piece);
        Graph g = new Graph(8);

        PriortyQueue q = new PriortyQueue(8);
        boolean[] visited = new boolean[w];
        for(int i =0; i<w; i++){
            visited[i] = false;
        }
        piece = read.readLine();
        k = Integer.parseInt(piece);


        while ((piece = read.readLine()) != null) {
            String dane[];
            dane = piece.split(" ");
            addEdge(g,Integer.parseInt(dane[0]),Integer.parseInt(dane[1]),Double.parseDouble(dane[2]));

        }
        read.close();


        int V = g.V;
        int[] parent = new int[V];
        double[] key = new double[V];

        key[0] = 0;
        q.insert(q.q,new QueueNode(0,key[0]));
        for(int i = 1; i<V;++i){
            parent[i] =-1;
            key[i] = Double.MAX_VALUE;
            q.insert(q.q,new QueueNode(i,key[i]));
        }

        q.q.size = V;

        while(!isEmpty(q.q)){

            QueueNode min = q.extractMin(q.q);

            int u = min.v;
            ListNode p = g.A[u].head;
            while(p!=null){
                int v = p.dest;

                if(isInMinHeap(q.q,v) && p.weight < key[v]){

                    key[v] = p.weight;
                    parent[v] = u;
                    q.decreaseKey(q.q,v,key[v]);

                }
                p = p.next;
            }

        }

        double weight=0;

        for(int i =1; i<parent.length; i++){
            weight = weight+key[i];
            System.out.println(parent[i] + " - "+ i+ "  "+key[i]);
        }
        System.out.println();
    }

    public static void main(String args[]) throws IOException {
        Prim();

    }
}
