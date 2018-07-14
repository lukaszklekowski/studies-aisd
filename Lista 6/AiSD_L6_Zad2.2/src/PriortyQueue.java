/**
 * Created by Lukasz on 2017-06-22.
 */
public class PriortyQueue <T extends Comparable<T>>  {

    Queue q;

    PriortyQueue(int n){
        q = new Queue(n);
    }

    class Queue{
        int size;
        int capacity;
        int[] pos;
        QueueNode[] array;
        Queue(int V){
            this.array = new QueueNode[V];
            this.size = 0;
            this.capacity = V;
            this.pos = new int[V];
        }

    }

    public static int parent(int i){return i/2;}
    public static int right(int i){return 2*i + 1;}
    public static int left(int i){return 2*i;}

    public void heapify(Queue q, int i){

        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l<q.size && q.array[l].key.compareTo(q.array[smallest].key)<0){
            smallest = l;
        }

        if(r<q.size && q.array[r].key.compareTo(q.array[smallest].key)<0){
            smallest = r;
        }

        if(smallest!=i){
            QueueNode smallestNode = q.array[smallest];
            QueueNode iNode = q.array[i];

            q.pos[smallestNode.v] = i;
            q.pos[iNode.v] = smallest;

            QueueNode tmp = q.array[i];
            q.array[i] = q.array[smallest];
            q.array[smallest] = tmp;
            heapify(q,smallest);
        }
    }

    /*public void buildHeap(Edge tab[]){
        for(int i=heapSize/2; i>+1; i--){
            heapify(tab,i);
        }
    }*/
    public QueueNode extractMin(Queue q){
        if(q.size <1){
            System.out.println("Kopiec pusty");
            return null;
        }

        QueueNode root = q.array[0];

        QueueNode lastnode = q.array[q.size-1];

        q.array[0] = lastnode;
        q.pos[root.v] = q.size-1;
        q.pos[lastnode.v] = 0;
        q.size--;
        heapify(q,0);
        return root;
    }

    //q.array[parent(i)].key.compareTo(key.key)>0
    public void insert(Queue q, QueueNode key){
        int i = q.size;
        while (i>0 && q.array[parent(i)].key.compareTo(key.key)>0){
            q.array[i] = q.array[parent(i)];
            i = parent(i);
        }
        q.size++;
        q.array[i] = key;
        q.pos[q.array[i].v] = i;
    }

    //q.array[i].key.compareTo(q.array[parent(i)].key)<0
    public void decreaseKey(Queue q, int v, T key){
        if(key.compareTo((T) q.array[v].key) > 0){
            //System.out.println("Klucz większy");
            return;
        }
        int i = q.pos[v];
        QueueNode tmp;
        q.array[i].key = key;
        while(i>0 && q.array[i].key.compareTo(q.array[parent(i)].key)<0){
            q.pos[q.array[i].v] = parent(i);
            q.pos[q.array[parent(i)].v] = i;
            tmp = q.array[i];
            q.array[i] = q.array[parent(i)];
            q.array[parent(i)] = tmp;
            i=parent(i);
        }
    }
}
