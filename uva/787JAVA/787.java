import java.util.Scanner;
import java.math	.BigInteger;

class Main{
	public static void main(String[] args){
		Scanner S = new Scanner(System.in);
		while(S.hasNextInt()){
			BigInteger x = S.nextBigInteger(), ans, firstN, mul, poss;
			
			ans = x;
			firstN = (x.signum() < 0  ? x : BigInteger.ZERO);
			if(x.equals(BigInteger.ZERO))
				mul = BigInteger.ONE;
			else
				mul = x;
			
			x = S.nextBigInteger();
			
			while(!x.equals(BigInteger.valueOf(-999999))){
				if(x.equals(BigInteger.ZERO)){
					if(x.compareTo(ans) == 1)
						ans = x;
					firstN = BigInteger.ZERO;
					mul = BigInteger.ONE;
				}
				else{
					mul = mul.multiply(x);
					if(mul.signum() > 0){
						if(mul.compareTo(ans) == 1)
						ans = mul;
					}
					else{
						if(firstN.equals(BigInteger.ZERO)){
							firstN = mul;
							poss = mul;
						}
						else{
							poss = mul.divide(firstN);
						}
						if(poss.compareTo(ans) == 1)
							ans = poss;
					}
				}
				
				
				x = S.nextBigInteger();
			}
			System.out.println(ans.toString());
		}
	}
}
