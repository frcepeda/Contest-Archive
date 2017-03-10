import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		while (in.hasNext()){
			BigInteger N = new BigInteger(in.next());
			BigInteger C = new BigInteger(in.next());
			BigInteger M = new BigInteger(in.next());

			/*
			int C = in.nextInt();
			int M = in.nextInt();
			int ans = 1;

			for (; nonzero(); div2()){
				if (odd())
					ans = (ans * C) % M;
				C = (C * C) % M;
			}
			*/

			System.out.println(C.modPow(N, M));
		}
	}
}
