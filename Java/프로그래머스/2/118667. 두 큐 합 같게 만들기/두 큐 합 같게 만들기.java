import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int count = 0; // 작업의 개수(insert + pop)
        // 초기 합
        long sum1=0;
        for(int num: queue1) {
            sum1+= num;
        }
        long sum2=0;
        for(int num: queue2) {
            sum2 +=num;
        }
        
        // 큐로 변경   
        Queue<Integer> q1 = new LinkedList<>();
        for(int num: queue1) {
            q1.add(num);
        }
        Queue<Integer> q2 = new LinkedList<>();
        for(int num: queue2) {
            q2.add(num);
        }
        
        // 불가능한 케이스 제거
        long total = sum1 + sum2;
        if(total%2 != 0) return -1; // 음수
        long target = total /2; // 목표값
        
        // 반복 제한(무한루프 방지)
        int limit = queue1.length *3;
        
        while(count <=limit) {
            if(sum1 == target)
                return count;
            if(sum1 > target) {
                // 1번에서 2번
                int tmp = q1.poll();
                q2.add(tmp);
                sum1 -= tmp;
                sum2 +=tmp;
            } else {
                // 2번에서 1번
                int tmp = q2.poll();
                q1.add(tmp);
                sum2 -=tmp;
                sum1 +=tmp;
            }
            
            count++;
        }
        
        return -1;
    }
}