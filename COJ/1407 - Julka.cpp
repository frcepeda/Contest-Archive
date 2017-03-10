import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < 10; i++){
            BigInteger s = new BigInteger(in.next());
            BigInteger z = new BigInteger(in.next());
            BigInteger a = s.add(z).divide(BigInteger.valueOf(2));
            BigInteger b = a.subtract(z);
            System.out.println(a);
            System.out.println(b);
        }
    }
}
