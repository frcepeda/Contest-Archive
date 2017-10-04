import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int n = new Scanner(System.in).nextInt();

		BigInteger b = BigInteger.valueOf(1);

		for (int i = 2; i <= n; i++){
			BigInteger ii = BigInteger.valueOf(i);
			b = b.multiply(ii).divide(ii.gcd(b));
		}

		System.out.println(b);
	}
}
