/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.io.*;
import java.util.*;
import java.lang.*;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        /** TODO: 문제 설명
         * 길이 N 의 알파벳 소문자로 이루어진 문자열이 주어진다.
         * 당신은 이 문자열에서 “fox” 라는 부분 문자열을 지우는 것을 반복할 수 있다.
         * 예를 들어, “aafoxbb” 라는 문자열에서 fox를 지우면 “aabb” 가 된다.
         * 한편, “fzozx” 는 “fox” 가 연속해 있지 않기 때문에 “zz” 로 바꿀 수 없다.
         * 당신은 부분 문자열을 적절히 지워서 문자열의 길이를 최소화하려고 한다. 그 때의 길이는 얼마인가?
         */

        /** TODO: 입력
         * 첫 번째 줄에 테스트 케이스의 수 TC가 주어진다.
         * 이후 TC개의 테스트 케이스가 새 줄로 구분되어 주어진다.
         * 각 테스트 케이스는 다음과 같이 구성되었다.
         *     -  첫 번째 줄에 정수 N이 주어진다. (1 ≤ N ≤ 200000)
         *     -  두 번째 줄에 길이 N 의 알파벳 소문자로 이루어진 문자열이 주어진다.
         */

        for(int test_case = 1; test_case <= T; test_case++) {
            /**
             * @n 선언
             * @text 선언(문자열로)
             * @answer 결과값 선언 후 출력
             */

            int n = Integer.parseInt(br.readLine());
            String text = br.readLine();

            int answer = findMinLength(n, text);

            System.out.println(answer);
        }
    }

    // 길이찾기(
    public static int findMinLength(int n, String text) {
        // 처음 입력값 가져와서
        Stack<Character> stack = new Stack<>();
        for(int i=0; i<n; i++) {
            stack.push(text.charAt(i));

            // peek: 가장 위의 값 반환
            if(stack.size() >= 3 && stack.peek() == 'x') {
                if(stack.get(stack.size()-3) == 'f'
                    && stack.get(stack.size()-2) == 'o') {
                    stack.pop();
                    stack.pop();
                    stack.pop();
                }
            }
        }

        return stack.size();
    }

}