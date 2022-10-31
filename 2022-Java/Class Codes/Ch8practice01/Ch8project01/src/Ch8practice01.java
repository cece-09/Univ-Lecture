class InstCnt {
    static int instNum = 0; // 클래스 변수 static

    InstCnt() {
        instNum++;
        System.out.println("인스턴스 생성 : " + instNum);
    }
}

public class Ch8practice01 {
    public static void main(String[] args) throws Exception {
        InstCnt cnt1 = new InstCnt();
        InstCnt cnt2 = new InstCnt();
        InstCnt cnt3 = new InstCnt();
    }
}
