import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()){
			int n = sc.nextInt(), a = sc.nextInt();
			BigInteger powA = BigInteger.ONE, ans = BigInteger.ZERO;
			for(int i = 1; i <= n; i++){
				powA = powA.multiply(BigInteger.valueOf(a));
				ans = ans.add(powA.multiply(BigInteger.valueOf(i)));
			}
			System.out.println(ans);
		}
	}
}
