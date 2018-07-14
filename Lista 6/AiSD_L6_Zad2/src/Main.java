import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;



class DSNode{
    int up;
    int rank;
    public void setUp (int n){this.up = n;}
    public void setRank(int n){this.rank = n;}
    public int getUp (){return up;}
    public int getRank(){return rank;}
}

class DSStruct{
    DSNode Z[];
    int up;
    int rank;

    DSStruct(int n){
        this.Z = new DSNode[n];
    }

    public void MakeSet(int v){
        Z[v] = new DSNode();
        Z[v].setRank(0);
        Z[v].setUp(v);
    }

    public int findSet(int v){
        if(Z[v].getUp() != v) Z[v].setUp(findSet(Z[v].getUp()));
        return Z[v].up;
    }

    public void UnionSets(QueueNode e){
        int ru, rv;

        ru = findSet(e.v1);
        rv = findSet(e.v2);
        if(ru != rv){
            if(Z[ru].getRank() > Z[rv].getRank()){
                Z[rv].setUp(ru);
            }else{
                Z[ru].setUp(rv);
                if(Z[ru].getRank() == Z[rv].getRank()) Z[rv].setRank(Z[rv].getRank()+1);
            }
        }
    }
}



public class Main {

    public static void Kruskal() throws IOException {
        String piece;

        double waga =0;
        int w=0;
        int k=0;

        int i;

        File inputFile = new File("Graph.txt");
        BufferedReader read = new BufferedReader(new FileReader(inputFile));
        piece = read.readLine();
        w = Integer.parseInt(piece);

        piece = read.readLine();

        k = Integer.parseInt(piece);

        DSStruct Z = new DSStruct(w);
        PriortyQueue q = new PriortyQueue(k);
        for(i = 0; i<w; i++){
            //System.out.println(i);
            Z.MakeSet(i);
        }

        while ((piece = read.readLine()) != null) {
            String dane[];
            dane = piece.split(" ");
            q.insert(q.q,new QueueNode(Integer.parseInt(dane[0]),Integer.parseInt(dane[1]),Double.parseDouble(dane[2])));
        }
        read.close();

        ArrayList<QueueNode> wyn = new ArrayList<QueueNode>();
        QueueNode edge;

        for(i = 1; i<w; i++){
            do{
                edge = q.extractMin(q.q);
            }while (Z.findSet(edge.v1) == Z.findSet(edge.v2));
            wyn.add(edge);
            waga = waga + (double)edge.key;
            Z.UnionSets(edge);
        }

        for(i =0; i<wyn.size(); i++){
            System.out.println(wyn.get(i).v1+" "+wyn.get(i).v2+" "+wyn.get(i).key);
        }
        System.out.println(waga);
    }


    public static void main(String args[]) throws IOException {

       Kruskal();
    }
}
