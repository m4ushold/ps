import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        int a=0, b=0;
        for(char c : s.toCharArray()) {
            if(c=='A') a++;
            else b++;
        }

        if(a==b) System.out.println("Tie");
        else System.out.println(a>b ? 'A' : 'B');
    }
}