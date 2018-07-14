public class Main {

    public static void main(String[] args) {
        PrioityQueue q = new PrioityQueue(5);
        q.insert(q.q,new QueueNode(0,12));
        q.insert(q.q,new QueueNode(1,11));
        q.insert(q.q,new QueueNode(2,14));
        q.insert(q.q,new QueueNode(3,8));
        q.insert(q.q,new QueueNode(4,7));

        QueueNode qn = q.extractMin(q.q);
        System.out.println(qn.v + " " + qn.key);
        q.decreaseKey(q.q,1,4);

        qn = q.extractMin(q.q);
        System.out.println(qn.v + " " + qn.key);
    }
}
