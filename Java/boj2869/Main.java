// B1
// 나무막대 올라가기

import java.util.*;
// a: 낮에 올라가는 높이, b: 밤에 미끄러지는 높이, v: 나무막대의 높이
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int up = sc.nextInt(); // a
        int down = sc.nextInt(); // b
        int height = sc.nextInt(); // v

        // 마지막날 제외 거리 / 하루 거리
        int count = (height - down) / (up - down);

        // 잔여 거리가 남으면 +1일
        if ((height - down) % (up - down) != 0) {
            count++;
        }

        System.out.println(count);
    }
}