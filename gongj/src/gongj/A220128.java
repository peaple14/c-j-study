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
		//BufferedWriter�� ������ ���⽱�� ����.
		int all = Integer.parseInt(br.readLine());
		for(int i=0;i<all;i++) {
			HashMap<String, Integer> map = new HashMap<>();
			int sall = Integer.parseInt(br.readLine());
			for(int j=0;j<sall;j++) {
				StringTokenizer st = new StringTokenizer(br.readLine()," ");
				st.nextToken();
				String key= st.nextToken();
				map.put(key, map.getOrDefault(key, 0) + 1);//map�� ������ϳ�
			}
			 int count = 1;
	            for (int val : map.values())//���� for��
	                count *= val + 1;//�԰ų� ���԰ų� �ϴ°�� ���ϰ�  ���ϱ�.
	            bw.write(count - 1 + "\n");//�ƹ��͵� ���Դ°�� ����
	       }
		br.close();//�������� �ϱ� �߿�.
		bw.flush();
		bw.close();
	}
}

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


