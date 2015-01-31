// Accepted
// Java es una basura y .stripTrailingZeros() no funciona. Tuve que implementar el mÃ­o.


import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main
{
	public static void main (String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int t = s.nextInt();
		
		while (t-- > 0){
			BigDecimal b = BigDecimal.ZERO;
			
			while (true){
				BigDecimal a = s.nextBigDecimal();
				if (a.equals(BigDecimal.ZERO)) break;
				b = b.add(a);
			}
			
			String c = b.toPlainString();
			
			int i = c.length();
			
			if (c.indexOf('.') != -1){
				for (i = c.length()-1; i >= 0; i--)
					if (c.charAt(i) != '0') break;
				if (c.charAt(i) != '.') i++;
			}
				
			System.out.println(c.substring(0,i));
		}
	}
}