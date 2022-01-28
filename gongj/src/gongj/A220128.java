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
//	bw.flush();//bw�� ����� �ʼ��� �ۼ�.�ƴ���¾ȵ�
//	bw.close();

//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//9375
//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
////BufferedWriter�� ������ ���⽱�� ����.
//int all = Integer.parseInt(br.readLine());
//for(int i=0;i<all;i++) {
//	HashMap<String, Integer> map = new HashMap<>();
//	int sall = Integer.parseInt(br.readLine());
//	for(int j=0;j<sall;j++) {
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
//		st.nextToken();
//		String key= st.nextToken();
//		map.put(key, map.getOrDefault(key, 0) + 1);//map�� ������ϳ�
//	}
//	 int count = 1;
//        for (int val : map.values())//���� for��
//            count *= val + 1;//�԰ų� ���԰ų� �ϴ°�� ���ϰ�  ���ϱ�.
//        bw.write(count - 1 + "\n");//�ƹ��͵� ���Դ°�� ����
//   }
//br.close();//�������� �ϱ� �߿�.
//bw.flush();
//bw.close();



//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//9375 �̹���� ���� �ִ� for20��ø�� ����Ҽ�������.
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
//	for(int j=0;j<sall-1;j++) {//2�� ����
//		for(int k=j+1;k<sall;k++) {
//			if(!name[j].equals(name[k])) {
//				count++;
//			}
//		}
//	}
//	bw.write(count);//map���� �ٽõ���
//		
//	
//}	
//br.close();
//bw.flush();
//bw.close();


