import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        // survey: RT CF JM AN 등 서베이 문제
        HashMap<Character, Integer> pointMap = new HashMap<>();
        pointMap.put('R', 0);
        pointMap.put('T', 0);
        pointMap.put('C', 0);
        pointMap.put('F', 0);
        pointMap.put('J', 0);
        pointMap.put('M', 0);
        pointMap.put('A', 0);
        pointMap.put('N', 0);
        
        for(int i=0; i<survey.length; i++){
            // choices: 0~7까지(0이면 왼쪽 +3, 7이면 오른쪽 +3)
            char left = survey[i].charAt(0); // survey문자열의 문자 꺼내기
            char right =survey[i].charAt(1);
            
            if(choices[i] ==4) {
                //0점
                continue;
            }
            else if (choices[i] < 4){
                // 왼쪽(4-choice)
                int score = 4-choices[i];
                pointMap.put(left, pointMap.get(left) + score);
            }
                
            else if(choices[i] >4){
                // 오른쪽(choice-4)
                int score = choices[i]-4;
                pointMap.put(right, pointMap.get(right) + score);
            }
        }
        
        // hashmap의 결과값 기반 결과 출력
        String ans="";
        // 동일하면 알파벳순
        if(pointMap.get('R') >= pointMap.get('T')) ans +='R';
        else ans +='T';
        if(pointMap.get('C') >= pointMap.get('F')) ans +='C';
        else ans +='F';
        if(pointMap.get('J') >= pointMap.get('M')) ans +='J';
        else ans +='M';
        if(pointMap.get('A') >= pointMap.get('N')) ans +='A';
        else ans +='N';
        
        return ans;
    }
}