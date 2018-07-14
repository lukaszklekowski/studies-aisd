import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;


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

    public static void Djikstra(int start) throws IOException {
        String piece;
        int w=0;
        int k;
        File inputFile = new File("Graph.txt");
        BufferedReader read = new BufferedReader(new FileReader(inputFile));

        piece = read.readLine();
        w = Integer.parseInt(piece);
        Graph g = new Graph(w);
        PriortyQueue q = new PriortyQueue(w);
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
        double[] dist = new double[V];
        for(int i =0; i<V; i++){
            parent[i] = -1;
        }

        dist[start] = 0;
        q.insert(q.q,new QueueNode(start,dist[0]));

        for(int i = 0; i<V;++i){
            if(i!=start) {
                dist[i] = Double.MAX_VALUE;
                q.insert(q.q, new QueueNode(i, dist[i]));
            }

        }

        q.q.size = V;

        while(!isEmpty(q.q)){

            QueueNode min = q.extractMin(q.q);


            int u = min.v;
            ListNode p = g.A[u].head;
            while(p!=null){
                int v = p.dest;

                if(isInMinHeap(q.q,v) && dist[u]!=Double.MAX_VALUE && p.weight+dist[u] < dist[v]){

                    dist[v] = dist[u] + p.weight;
                    key[v] = p.weight;
                    parent[v] = u;
                    q.decreaseKey(q.q,v,dist[v]);

                }
                p = p.next;
            }

        }
        parent[start] = -2;
        ArrayList<Integer> a = new ArrayList<>();
        for(int i =0; i<parent.length; i++){
            boolean ispath = true;
            if(i!=start) {
                int j = i;
                a.add(i);
                while (j != start && parent[j]!=-1) {
                    j = parent[j];
                    a.add(0, j);
                }
                if(parent[j]==-1) ispath = false;
                if(ispath) {
                    System.out.print(start+" to " + i + " " + dist[i] + " ");
                    for (int kk = 0; kk < a.size() - 1; kk++) {
                        System.out.print(a.get(kk) + " -> " + a.get(kk + 1) + "  " + key[a.get(kk + 1)] + " ");
                    }
                }else{
                    System.out.print(start+" to " + i +" Brak ścieżki");
                }
                a.clear();
                System.out.println("");
            }
        }
        System.out.println();
    }



    public static void main(String args[]) throws IOException {
        Djikstra(1);
    }
}
