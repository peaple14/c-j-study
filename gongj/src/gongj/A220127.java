package gongj;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class A220127 {

	public static void main(String[] args) throws IOException { // 1010
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st;
        
        for(int i=0; i<N; i++) {
        	st = new StringTokenizer(br.readLine()," ");
            double n = Integer.parseInt(st.nextToken());
            double m = Integer.parseInt(st.nextToken());
            double a = 1;
            double b = 1;
            for(double j=m; j>m-n; j--) {
                   a *= j;
               }    
            
            for(double k=n; k>0; k--) {
                b *= k;
            }
               System.out.printf("%.0f\n",a/b); 
    }
}

}
		
//	n!/(n-m)!*m!);���
//	BufferedReader br = new BufferedReader(new InputStreamReader (System.in));//1010 ������ long�� �Ѿ�� �����
//	
//	int N = Integer.parseInt(br.readLine());
//	long[] a = new long[N];
//	int ac=0;//a��ǥ
//	long zero = 0;
//	for(int i=0;i<N;i++) {
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
//		long m = Integer.parseInt(st.nextToken());
//		long n = Integer.parseInt(st.nextToken());
//		if(n==m) zero = 1; else zero = n-m;
//		a[ac] = (fact(n) / (fact(zero) * fact(m)));//���丮��� long�� �ξ� �Ѿ. ��)fact(39)
//		ac++;
//	}
//	for(int i=0;i<N;i++) {
//		System.out.println(a[i]);
//	}
//}
//public static long fact(long n) {
//	if (n <= 1)
//		return n;
//	else 
//		return fact(n-1) * n;
//}
	
	
	
//	BufferedReader br = new BufferedReader(new InputStreamReader (System.in));//3036
//	int N = Integer.parseInt(br.readLine());
//	int[] a = new int[N];
//	StringTokenizer st = new StringTokenizer(br.readLine()," ");
//	int k=0;//�ּҰ���� ����
//	for(int i=0;i<N;i++) {
//		a[i] = Integer.parseInt(st.nextToken());
//	}
//	for(int j=1;j<N;j++) {
//		k=a[0]*a[j]/gcd(a[0],a[j]);
//		System.out.println(k/a[j] +"/"+ k/a[0]);
//	}
//}
//
//public static int gcd(int a, int b) {//��Ŭ����˰���
//	 
//	while (b != 0) {
//		int r = a % b; 
//		a = b;
//		b = r;
//	}
//	return a;
//}


//BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 2981 ����
//int N = Integer.parseInt(br.readLine());
//int[] a = new int[N];
//int[] b = new int[N];//M �����Ұ�
//int bc = 0;//b��ǥ
//b[0] = 2;
//int save=0;
//for(int i=0;i<N;i++) {
//	a[i] = Integer.parseInt(br.readLine());
//}
//Arrays.sort(a);
//
//for(int i=2;i<a[0]+1;i++) {
//	for(int j=0;j<N;j++) {
//		if(a[j] % i == b[bc]) {
//			
//		}
//		}
//		
//	}