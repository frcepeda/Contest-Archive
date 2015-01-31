import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args)
	{
		Scanner s = new Scanner(System.in);
		int c = s.nextInt();
		
		while (c-- > 0)
			System.out.println(s.nextBigInteger().modPow(s.nextBigInteger(), s.nextBigInteger()));
	}
}