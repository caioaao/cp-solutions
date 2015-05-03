import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		List<BigInteger> facs = new ArrayList<BigInteger>();
		
		facs.add(BigInteger.ONE);
		
		for(int i = 1; i <= 1000; i++){
			facs.add(facs.get(i-1).multiply(BigInteger.valueOf(i)));
		}
		
		while(sc.hasNextInt()){
			int n = sc.nextInt();
			System.out.print(n);
			System.out.println('!');
			System.out.println(facs.get(n));
		}
	}
}
