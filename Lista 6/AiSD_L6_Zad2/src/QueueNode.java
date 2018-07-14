/**
 * Created by Lukasz on 2017-06-22.
 */
public class QueueNode<T extends Comparable<T>> {
    int v1;
    int v2;
    T key;
    QueueNode(int v1, int v2, T key){
        this.v1 = v1;
        this.v2 = v2;
        this.key = key;
    }
}
