package gongj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Map;


public class A220128 {
	public static void main(String[] args) throws IOException {//2751
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int count = Integer.parseInt(br.readLine());
		int[] sor = new int[count];	
		for(int i=0;i<count;i++) {
			sor[i] =Integer.parseInt(br.readLine());
		}
		Arrays.sort(sor);
		
		for(int val : sor) {
			bw.write(val+"\n");
		}
		br.close();
		bw.flush();
		bw.close();
	
	}
	
}



//	BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); //1676
//	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//	int N=Integer.parseInt(br.readLine());
//	int t = 0;
//	int f = 0;
//	for (int i = 1; i <= N; i++) {
//		int n = i;
//		while (n % 2 == 0) {	
//			t++;
//			n /= 2;
//		}
//		while (n % 5 == 0) {	
//			f++;
//			n /= 5;
//		}
//	}
//	bw.write(f < t ? f +"\n":t +"\n");
//	
//	br.close();
//	bw.flush();//bw를 쓸경우 필수로 작성.아님출력안됨
//	bw.close();

//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//9375
//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
////BufferedWriter는 은근히 쓰기쉽고 빠름.
//int all = Integer.parseInt(br.readLine());
//for(int i=0;i<all;i++) {
//	HashMap<String, Integer> map = new HashMap<>();
//	int sall = Integer.parseInt(br.readLine());
//	for(int j=0;j<sall;j++) {
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
//		st.nextToken();
//		String key= st.nextToken();
//		map.put(key, map.getOrDefault(key, 0) + 1);//map의 기능중하나
//	}
//	 int count = 1;
//        for (int val : map.values())//향상된 for문
//            count *= val + 1;//입거나 안입거나 하는경우 더하고  곱하기.
//        bw.write(count - 1 + "\n");//아무것도 안입는경우 빼기
//   }
//br.close();//이제부터 하기 중요.
//bw.flush();
//bw.close();



//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//9375 이방법을 쓰면 최대 for20중첩을 써야할수도있음.
//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//StringBuilder sb = new StringBuilder();
//char[] a = new char[30];
//
//int all = Integer.parseInt(br.readLine());
//for(int i=0;i<all;i++) {
//	int sall = Integer.parseInt(br.readLine());
//	String[] name=new String[sall];
//	
//	for(int j=0;j<sall;j++) {
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
//		st.nextToken();
//		name[j] = st.nextToken();
//	}
//	int count = sall;
//	
//	for(int j=0;j<sall-1;j++) {//2개 고를시
//		for(int k=j+1;k<sall;k++) {
//			if(!name[j].equals(name[k])) {
//				count++;
//			}
//		}
//	}
//	bw.write(count);//map으로 다시도전
//		
//	
//}	
//br.close();
//bw.flush();
//bw.close();


