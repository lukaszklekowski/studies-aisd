import java.io.*;
import java.util.Random;


public class Main {
    static int count = 0;

    public static int min(int a, int b, int c){
        if(c < b && c < a)
            return c;
        if(b < a && b < c)
            return b;
        else return a;
    }


    public static int editDistance(String a, String b) {
        int cost;
        int aLength = a.length();
        int bLength = b.length();
        int dist[][] = new int[aLength + 1][bLength + 1];

        for (int i = 0; i <= aLength; i++) {
            dist[i][0] = i;
        }
        for (int i = 0; i <=bLength; i++) {
            dist[0][i] =i;
        }
        for(int i=1; i<=aLength; i++){
            for(int j = 1; j<=bLength; j++){
                if(a.charAt(i-1)==b.charAt(j-1)){
                    cost=0;
                }else {
                    cost=1;
                }
                dist[i][j] = min(dist[i-1][j]+1, dist[i][j-1]+1, dist[i-1][j-1]+cost);
                count++;
            }
        }

        return dist[aLength][bLength];
    }

    public static String[] wordHelper(String in){
        String word = "";
        String words[] = new String[3];
        int count = 0;
        try{
            BufferedReader b = new BufferedReader(new FileReader("dict.txt"));
            while ((word = b.readLine()) != null){
                if(helperDist(in, word) <= 2){
                    words[count] = word;
                    count++;
                }
                if(count == 3)
                    return words;
            }
        }catch(IOException ex){
            System.out.println("IO Exception");
        }catch(NumberFormatException ex){
            System.out.println("Wrong format of te input");
        }

        return words;
    }


    public static int helperDist(String a, String b){
        int prim = editDistance(a, b);
        int sec = editDistance(b, a);
        if(prim < sec)
            return prim;
        else return sec;
    }


    public static void main(String[] args){
        System.out.println("Odległość między 'abaabbaaa' i 'babab': " + editDistance("abaabbaaa", "babab"));
        System.out.println("Odległość między 'granat' i 'granit': " + editDistance("granat", "granit"));
        String words[] = wordHelper("mercedes");
        if(words[0] != null) {
            System.out.println("Podobne słowa:");
            System.out.println(words[0]);
            if(words[1] != null){
                System.out.println(words[1]);
                if(words[2] != null){
                    System.out.println(words[2]);
                }
            }
        }

        try {
            BufferedWriter write = new BufferedWriter(new FileWriter("EditDistance.txt"));


            String output="";
            Random r = new Random();
            String w1 = "";
            String w2 = "";
            int size = 10;
            count =0;
            for(int i=0; i<50; i++){
                for(int j=0;j<1000;j++){
                    for(int k = 0; k <size; k++){
                        w1 = w1 + String.valueOf(r.nextInt(9));
                    }
                    for(int k = 0; k <size; k++){
                        w2 = w2 + String.valueOf(r.nextInt(9));
                    }
                    editDistance(w1,w2);
                    w1="";
                    w2="";
                }
                output = output + String.valueOf(size)+ " " + String.valueOf(count/1000)+ "\n";
               // System.out.printf(output);
                size = size+10;
                count=0;
            }
            write.write(output);
            write.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }



}
