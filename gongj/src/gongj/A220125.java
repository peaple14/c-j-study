package gongj;
import java.io.BufferedReader;
import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.StringTokenizer;

public class A220125 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));//1934
		int N = Integer.parseInt(br.readLine());
		for(int i=0;i<N;i++) {
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());	 
		int c=1;//최대공약수용 계산용
		int GCD = 1;//최대공약수
		int LCM = 1;//최소공배수
		while(true) {//최대공약수구하기
			if(a%c==0 && b%c==0) {
				GCD = c;
			}
			c++;
			if(c>45001) break;
		}
		if(a==b) LCM = a;
		else LCM = GCD*(a/GCD)*(b/GCD);
		System.out.println(LCM);
		}
	}

}


//BufferedReader br = new BufferedReader(new InputStreamReader (System.in));//2609
//StringTokenizer st = new StringTokenizer(br.readLine());
//int a = Integer.parseInt(st.nextToken());
//int b = Integer.parseInt(st.nextToken());	
//int c=1;//최대공약수용 계산용
//int GCD = 1;//최대공약수
//int LCM = 1;//최소공배수
//while(true) {//최대공약수구하기
//	if(a%c==0 && b%c==0) {
//		GCD = c;
//	}
//
//	c++;
//	if(c>10001) break;
//}
//if(a==b) LCM = a;
//else LCM = GCD*(a/GCD)*(b/GCD);
//System.out.println(GCD+" "+LCM);





//BufferedReader br = new BufferedReader(new InputStreamReader (System.in));//1037
//int N = Integer.parseInt(br.readLine());
//StringTokenizer st = new StringTokenizer(br.readLine());
//int[] k = new int[N];
//for(int i=0;i<N;i++) {
//	k[i] = Integer.parseInt(st.nextToken());
//}
//Arrays.sort(k);
//System.out.println(k[0]*k[N-1]);
//br.close();