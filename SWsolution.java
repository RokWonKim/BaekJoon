import java.util.Scanner;

class SWsolution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			System.out.printf("#%d ", test_case);
            int sys = sc.nextInt();		//몇진법인지
            String nums = sc.next();		//진법으로 만든 수
            int sum = 0;			
            
            for (int j = 0; j < nums.length(); j++)	//진법**n 을 n-1로 나누면 무조건 나머지는 1 -> 약간 페르마의 소정리 느낌 
                sum += nums.charAt(j)-'0';		// so, a*진법**n의 a들만 다 더해서 나머지를 구하면댐
            System.out.println(sum%(sys-1));
		}
	}
}
