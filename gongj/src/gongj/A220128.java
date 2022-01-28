package gongj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.util.Map;


public class A220128 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//9375
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		//BufferedWriter는 은근히 쓰기쉽고 빠름.
		int all = Integer.parseInt(br.readLine());
		for(int i=0;i<all;i++) {
			HashMap<String, Integer> map = new HashMap<>();
			int sall = Integer.parseInt(br.readLine());
			for(int j=0;j<sall;j++) {
				StringTokenizer st = new StringTokenizer(br.readLine()," ");
				st.nextToken();
				String key= st.nextToken();
				map.put(key, map.getOrDefault(key, 0) + 1);//map의 기능중하나
			}
			 int count = 1;
	            for (int val : map.values())//향상된 for문
	                count *= val + 1;//입거나 안입거나 하는경우 더하고  곱하기.
	            bw.write(count - 1 + "\n");//아무것도 안입는경우 빼기
	       }
		br.close();//이제부터 하기 중요.
		bw.flush();
		bw.close();
	}
}

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


