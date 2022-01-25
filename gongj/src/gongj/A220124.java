package gongj;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.StringTokenizer;



public class A220124 {//2750

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int count = Integer.parseInt(br.readLine());
		int[] sor = new int[count];	
		for(int i=0;i<count;i++) {
			sor[i] =Integer.parseInt(br.readLine());
		}
		Arrays.sort(sor);
		
		for(int i=0;i<count;i++) {
			System.out.println(sor[i]);
		}
	}

}
