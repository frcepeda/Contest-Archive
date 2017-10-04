import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner s = new Scanner(System.in);
		HashMap<Integer,String> h = new HashMap<>();
		HashMap<Integer,String> w = new HashMap<>();

		h.put(0, "January");
		h.put(1, "February");
		h.put(2, "March");
		h.put(3, "April");
		h.put(4, "May");
		h.put(5, "June");
		h.put(6, "July");
		h.put(7, "August");
		h.put(8, "September");
		h.put(9, "October");
		h.put(10, "November");
		h.put(11, "December");

		w.put(1, "Sunday");
		w.put(2, "Monday");
		w.put(3, "Tuesday");
		w.put(4, "Wednesday");
		w.put(5, "Thursday");
		w.put(6, "Friday");
		w.put(7, "Saturday");

		while (s.hasNext()){
			int d = s.nextInt();
			String b = s.next();
			int y = (int) new BigInteger(s.next()).subtract(BigInteger.valueOf(2000))
				                                      .mod(BigInteger.valueOf(420*400)).longValue();

			int m;
			for (m = 0; !h.get(m).equals(b); m++);

			System.out.println(
					w.get(new GregorianCalendar(y+2000, m, d).get(Calendar.DAY_OF_WEEK))
					);
		}
	}
}
