package gongj;
import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class A220113 { 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 
		int N = Integer.parseInt(br.readLine());//횟수 받기
		StringTokenizer st = new StringTokenizer(br.readLine()," ");//공백을 기준으로 문자열분리
		
		int index = 0;//배열숫자
		int[] arr = new int[N];//배열생성
		while(st.hasMoreTokens()) {//토큰 다 받을때까지
			arr[index] = Integer.parseInt(st.nextToken());//토큰 계속 넣어주고
			index++;//배열위치 바꿔주고
		}
		
		Arrays.sort(arr);//배열 오름차순 정렬
		System.out.print(arr[0] + " " + arr[N - 1]);//첫번째와 마지막으로
	}

//	public static void main(String[] args) { //10818 
//		int a=0;
//		int arr[];
//		int max=-1000001;
//		int low=1000001;
//		Scanner sc=new Scanner(System.in);
//		a=sc.nextInt();
//		arr = new int[a];
//		
//		for(int i=0;i<a;i++) {
//			arr[i]=sc.nextInt();
//		}
//		
//		for (int i=0;i<a;i++){
//			if(arr[i]>max) {
//				max=arr[i];
//			}
//			if(arr[i]<low) {
//				low=arr[i];
//			}
//		}
//		Arrays.sort(arr);//배열 정리하는것. 첫번째,마지막하면됨.
//		System.out.println(low +" "+ max);
//	}
	
	
//	public static int add(int[] scores) { 
//		int sum=0;
//		for(int i=0;i<3;i++) {
//			sum+=scores[i];
//		}
//		return sum;
//		
//	}
//	
//	public static void main(String[] args) 
//	{
//		int[] scores;
//		scores = new int[]{83,90,87};
//		int sum1=0;
//		for(int i=0;i<3;i++) {
//			sum1+=scores[i];
//		}
//		System.out.println("총합:" + sum1);
//		
//		int sum2 = add(new int[] {83,90,87});
//		System.out.println("총합:" + sum2);
//		System.out.println();
//		}		
//		int a=0;
//		Scanner sc = new Scanner(System.in);
//		a=sc.nextInt();
//		for (int i = 1; i <= a; i++) {
//			System.out.println(i);
//		}
		

}


