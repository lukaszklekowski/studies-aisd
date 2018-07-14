/**
 * Created by Lukasz on 2017-06-22.
 */
public class QueueNode<T extends Comparable<T>> {
    int v;
    T key;
    QueueNode(int v, T key){
        this.v = v;
        this.key = key;
    }

}
