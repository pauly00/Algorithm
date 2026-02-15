
import java.io.*;

public class Main {
    static int count = 0; // 답의 개수
    static boolean isRight = false;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[] question = new int[n]; // 질문 개수
        int[] strikeArray = new int[n]; // 스트라이크 개수
        int[] ballArray = new int[n]; // 볼 개수

        for (int i = 0; i < n; i++) {
            String[] tmp = br.readLine().split(" ");
            question[i] = Integer.parseInt(tmp[0]);
            strikeArray[i] = Integer.parseInt(tmp[1]);
            ballArray[i] = Integer.parseInt(tmp[2]);
        }

        // 전체 경우의 수(brute force)
        for(int numbers = 111; numbers <= 999; numbers++) {
            
            // 자릿수 검사
            int[] number = new int[3];
            int tmp = numbers;
            for(int i=2; i>=0; i--) {
                number[i] = tmp %10;
                tmp/=10;
            }

            // 자릿수 조건(0이나 동일한 숫자일 시 무시)
            if(number[0] == 0 ||
                number[1] == 0 ||
                number[2] == 0 ||
                number[0] ==number[1] ||
                number[1] == number[2] ||
                number[2] == number[0]
                ) continue;
            
            isRight=true;

            
            // 야구조건
            for(int j=0; j<n; j++) {

                // 자릿수 분리(목표 숫자)
                int a = number[0];
                int b = number[1];
                int c = number[2];
                
                // 자릿수 분리(질문 숫자)
                int q = question[j];
                int qa = q/100;
                int qb = (q /10)%10;
                int qc = q%10;

                int strike = 0;
                if(a==qa) strike++; // 백의자리
                if(b==qb) strike++; // 십의자리
                if(c==qc) strike++; // 일

                // 공통 숫자
                int common=0;
                if(a==qa || a==qb || a==qc) common++;
                if(b==qa || b==qb || b==qc) common++;
                if(c==qa || c==qb || c==qc) common++;
                
                // 볼은 공통수에서 스트라이크 제외(숫자가 있기만 하면 되므로)
                int ball = common-strike;

                // 개수가 안맞으면 후보값이 틀림
                if(strike != strikeArray[j] ||
                    ball != ballArray[j]
                ) {
                    isRight=false;
                    break;
                }
            }
            if(isRight) count++;
        }

        System.out.print(count);
    }
}