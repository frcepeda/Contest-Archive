import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main
{
	public static void main (String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		while (true){
			int b = s.nextInt();
			if (b == 0) break;
			
			BigInteger p = s.nextBigInteger(b);
			BigInteger m = s.nextBigInteger(b);
			
			System.out.println(p.mod(m).toString(b));
		}
	}
}