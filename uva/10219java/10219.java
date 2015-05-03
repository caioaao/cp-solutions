import java.util.Scanner;
import java.math.BigInteger;
import static java.lang.Math.*;

class Main{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		while(s.hasNextInt()){
			int n = s.nextInt(), k = s.nextInt();
			
			BigInteger num = BigInteger.ONE, den = BigInteger.ONE;
			int stop = max(k,n-k);
			for(int i = n; i > stop; i--){
				num = num.multiply(BigInteger.valueOf(i));
			}
			
			stop = min(k,n-k);
			for(int i = 2; i <= stop; i++){
				den = den.multiply(BigInteger.valueOf(i));
			}
			BigInteger ans = num.divide(den);
			System.out.println(ans.toString().length());
		}
	}
}
