import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine()); // 테스트 데이터

        int[] hotelHeight = new int[n]; // 호텔 층수
        int[] hotelRooms = new int[n]; // 각층의 방
        int[] guests = new int[n]; // 몇번째 손님
        for(int i=0; i<n; i++) {
            String[] tmp = br.readLine().split(" ");
            hotelHeight[i] = Integer.parseInt(tmp[0]);
            hotelRooms[i] = Integer.parseInt(tmp[1]);
            guests[i] = Integer.parseInt(tmp[2]);
           
        }

        int[] ansHeight = new int[n]; // 정답 층수
        int[] ansRooms = new int[n]; // 정답 방번호

        for(int i=0; i<n; i++) {
            if(guests[i] %hotelHeight[i]==0) {
                ansRooms[i] = guests[i]/ hotelHeight[i];
                ansHeight[i] = hotelHeight[i];
            } 
            else {
                ansRooms[i] = guests[i] / hotelHeight[i] +1; // 방은 1번부터 
                ansHeight[i] = guests[i] %hotelHeight[i]; // 층수
            }
        }
        
        // 방번호 출력: yy(층수) + xx(엘리베이터번호)
        for(int i=0; i<n; i++) {
            if(ansRooms[i] <10) {
                System.out.println(ansHeight[i] + "0" + ansRooms[i]);
                continue;
            }
            System.out.println(ansHeight[i] + "" + ansRooms[i]);
        }
    }
}