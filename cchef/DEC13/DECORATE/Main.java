import java.util.Scanner;
import java.lang.StringBuilder;
import static java.lang.Math.*;
import java.math.BigInteger;
import java.util.Hashtable;

public class Main{
	public static String preprocess(String S){
		StringBuilder sb = new StringBuilder();
		boolean first = true;
		for(int i = 0, n = S.length(); i < n; i++){
			if(!first) sb.append('#');
			first = false;
			sb.append(S.charAt(i));
		}
		return sb.toString();
	}
	
	public static BigInteger longestPalindrome(String S){
		String T = preprocess(S);
		//~ System.out.println(T);
		int n = T.length(), C = 0, R = 0;
		int P[] = new int[n];
		BigInteger amt = BigInteger.ZERO;
		Hashtable<String, Boolean> pals = new Hashtable<String, Boolean>();
		
		for(int i = 0; i < n; i++){
			int i_mirror = 2*C - i;
			
			P[i] = ((R > i) ? min(R-i, P[i_mirror]) : 0) + (T.charAt(i) == '#' ? 1 : 0);
			
			while(i + P[i] < T.length() && i - P[i] >= 0 && T.charAt(i + P[i]) == T.charAt(i - P[i])){
				if(T.charAt(i + P[i]) != '#' && pals.get(T.subSequence(i - P[i], i + P[i] + 1)) == null){
					pals.put(T.subSequence(i - P[i], i + P[i] + 1).toString(), new Boolean(true));
					//~ System.out.println("Teste:" + T.subSequence(i - P[i], i + P[i]+1).toString());
					amt = amt.add(BigInteger.ONE);
				}
				P[i]+=2;
			}
			P[i]= max(0, P[i]-2);
			if(i + P[i] > R){
				C = i;
				R = i + P[i];
			}
		}
		
		return amt;
	}
	
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		String T;
		while(s.hasNextLine()){
			T = s.nextLine();
			int N = s.nextInt(); s.nextLine();
			//~ System.out.println(T);
			BigInteger P = longestPalindrome(T);
			BigInteger mult;
			for(int i = 1; i <= N; i++){
				mult = P;
				
			}
		}
	}
}
