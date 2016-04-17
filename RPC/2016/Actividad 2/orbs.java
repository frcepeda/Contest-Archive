import java.util.*;
import java.math.*;
import java.text.*;

class orbs {
	public static void main(String args[]){
		Scanner s = new Scanner(System.in);

		int T = s.nextInt();
		int precision = 5;

		BigDecimal zero = BigDecimal.valueOf(0);
		BigDecimal one = BigDecimal.valueOf(1);
		BigDecimal two = BigDecimal.valueOf(2);
		DecimalFormat df = new DecimalFormat("#0.00000");
		BigDecimal dp[][] = new BigDecimal[1400][1400];
		
		while (T-- > 0){
			int S = s.nextInt();
			int F = s.nextInt();
			int L = s.nextInt();

			dp[0][L-1] = one;
			for (int i = 0; i < L-1; i++)
				dp[0][i] = zero;

			for (int i = 1; i < S; i++){
				dp[i][L-1] = one;
				for (int j = 0; j < L-1; j++)
					dp[i][j] = dp[i-1][j+1].add(dp[i-1][0])
					                       .divide(two,
					                               precision,
					                               RoundingMode.HALF_EVEN);
			}

			BigDecimal twop = two.pow(S-1);
			BigDecimal p = dp[S-1][0].multiply(
				twop.divide(twop.subtract(one),
				            precision, RoundingMode.HALF_EVEN)
			);
			BigDecimal ans = zero;

			for (int i = 1; i <= F; i++)
				ans = ans.add(one.subtract(ans).multiply(p));

			System.out.println(df.format(ans));
		}
	}
}
