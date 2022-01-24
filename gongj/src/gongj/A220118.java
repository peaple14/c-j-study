package gongj;
import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

//대2때 못한과제
//이해하기위한 복잡함
class Mul{
	public static Mul mul;

	void M(int a,int b) {
		System.out.println(a*b);
	}
}

class Div extends Mul{
	void D(int a,int b) {
		System.out.println(a/b);
	}
}

class Minus extends Div{
	void M(int a,int b) {
		System.out.println(a-b);
	}
}

class Sum extends Minus{
	void S(int a,int b) {
		System.out.println(a+b);
	}
}

class Cal extends Sum{
	String sign;
	int a=0,b=0;
	void go(String N,int a,int b) {
		switch (N) {
		case "+" : Sum sum = new Sum();
		sum.S(a, b);
		break;
		
		case"-":Minus minus = new Minus();
		minus.M(a, b);
		break;
		
		case"/":Div div = new Div();
		div.D(a, b);
		break;
		
		case"*":Mul mul = new Mul();
		mul.M(a,b);
		break;
			
		}
	}
}

public class A220118 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String N = br.readLine();
		int a = Integer.parseInt(br.readLine());
		int b = Integer.parseInt(br.readLine());
		Cal cal = new Cal();
		cal.go(N, a, b);
	}

}