import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		int n, day, month, year;
		GregorianCalendar g = new GregorianCalendar();
		
		while (true){
			try {
				n = in.nextInt();
				day = in.nextInt();
				month = in.nextInt();
				year = in.nextInt();
			} catch (Exception e) { break; }
			
			if (n == 0 && day == 0 && month == 0 && year == 0) break;
			
			g.set(year, month-1, day);
			g.add(Calendar.DAY_OF_MONTH, n);
			System.out.println(g.get(Calendar.DAY_OF_MONTH) + " " + (g.get(Calendar.MONTH)+1) + " " + g.get(Calendar.YEAR));
		}
	}
}