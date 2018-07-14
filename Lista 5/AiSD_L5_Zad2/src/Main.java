import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;


public class Main {
    static int count=0;

    public static String LCS(String a, String b){
        String subsequence="";
        int aLength = a.length();
        int bLength = b.length();
        int C[][] = new int[aLength + 1][bLength + 1];

        for(int i=0; i<aLength; i++){
            C[i][0] = 0;
        }
        for(int i=0; i<bLength; i++){
            C[0][i] = 0;
        }

        for(int i = 1; i<=aLength; i++){
            for(int j = 1; j<=bLength; j++){
                if(a.charAt(i-1)==b.charAt(j-1)){
                    C[i][j] = C[i-1][j-1] + 1;
                }else{
                    C[i][j] = Math.max(C[i][j-1], C[i-1][j]);
                }
                count++;
            }
        }

        while(aLength>0 && bLength>0){
            if (C[aLength][bLength]==C[aLength-1][bLength]){
                aLength--;
            }else{
                if(C[aLength][bLength] == C[aLength][bLength-1]){
                    bLength--;
                }else{
                    subsequence = String.valueOf(a.charAt(aLength-1)) + subsequence;
                    aLength--;
                    bLength--;
                }
            }
            count++;
        }
        return subsequence;
    }

    public static void main(String[] args){
        System.out.println("Najdluzszy podciag : " + LCS("abaabbaaa", "babab"));
        try {
            BufferedWriter write = new BufferedWriter(new FileWriter("LSC.txt"));


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
                LCS(w1,w2);
                w1="";
                w2="";
            }
            output = output + String.valueOf(size)+ " " + String.valueOf(count/1000)+ "\n";
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
