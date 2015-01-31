import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		
		int T = s.nextInt();
		BigInteger f[] = new BigInteger[21];
		
		f[0] = BigInteger.ONE;
		for (int i = 1; i < 21; i++)
			f[i] = f[i-1].multiply(BigInteger.valueOf(i));
		
		for (int i = 1; i <= T; i++){
			String str = s.next();
			BigInteger ans = f[str.length()];
			char c[] = str.toCharArray();
			Arrays.sort(c);
			
			int j, l = 0;
			for (j = 1; j <= c.length; j++){
				if (j >= c.length || c[j] != c[j-1]){
					ans = ans.divide(f[j-l]);
					l = j;
				}
			}
			
			System.out.println("Data set " + i + ": " + ans);
		}
	}
}