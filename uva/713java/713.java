import static java.lang.Math.*;
import java.math.BigInteger;
import java.util.Scanner;
import java.lang.StringBuilder;
import java.util.StringTokenizer;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		while(T-- > 0){
			//~ System.out.println(sc.nextLine());
			StringTokenizer line = new StringTokenizer(sc.nextLine());
			String _a = line.nextToken(), _b = line.nextToken();
			
			
			BigInteger a = new BigInteger(new StringBuilder(_a).reverse().toString()),
					   b = new BigInteger(new StringBuilder(_b).reverse().toString());
			String ans = new StringBuilder((a.add(b)).toString()).reverse().toString();
			int start = 0;
			while(ans.charAt(start) == '0') start++;
			System.out.println(ans.substring(start,ans.length()));
		}
	}
}
