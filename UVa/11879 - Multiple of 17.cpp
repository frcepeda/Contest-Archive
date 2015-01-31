import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main
{
	public static void main (String[] args)
	{
		Scanner s = new Scanner(System.in);
		BigInteger sv = BigInteger.valueOf(17);
		
		while (s.hasNext()){
			BigInteger n = new BigInteger(s.next());
			if (n.equals(BigInteger.ZERO)) break;
			System.out.println(n.mod(sv).equals(BigInteger.ZERO) ? 1 : 0);
		}
	}
}