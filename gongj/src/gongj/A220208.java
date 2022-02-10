package gongj;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
//아직까지 몇몇메소드들은 검색해야됨.(아직덜외움)

public class A220208 {

	public static void main(String[] args) throws IOException{

	
	
	
	
	
	
	
	}
}


//Arrays.sort(a, (o1, o2) -> { //11651(밑의것 최근에생긴버전쪽 숫자 3부분만 손대면됨)
//if(o1[1] == o2[1]) {
//	return Integer.compare(o1[0], o2[0]);
//} else {
//	return Integer.compare(o1[1], o2[1]);
//}
//});



//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//11650 
//BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//StringTokenizer st;
//int count =Integer.parseInt(br.readLine());
//int[][] a = new int[count][2];
//
//for(int i=0;i<count;i++) {
//	st = new StringTokenizer(br.readLine()," ");
//	a[i][0]=Integer.parseInt(st.nextToken());
//	a[i][1]=Integer.parseInt(st.nextToken());
//}
////Arrays.sort(a,new Comparator<int[]>(){//이전버전
////	public int compare(int[] a1,int[] a2) {
////		if(a1[0]>a2[0]) {
////			return 1;
////		}
////		else if(a1[0]<a2[0]){
////			return -1;
////		}
////		else {
////			return a1[1]-a2[1];
////		}
////	}
////});
//Arrays.sort(a, (o1, o2) -> { //최근에 생긴버전
//	if(o1[0] == o2[0]) {
//		return Integer.compare(o1[1], o2[1]);
//	} else {
//		return Integer.compare(o1[0], o2[0]);
//	}
//});
//
//for(int i=0;i<count;i++) {
//	bw.write(a[i][0]+" "+a[i][1]+"\n");
//}
//bw.flush();
//bw.close();
//br.close();