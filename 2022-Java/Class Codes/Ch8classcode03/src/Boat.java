class Car {    
    void myCar() {
        System.out.println("this is my car");
    }
}

public class Boat {
    public static void main(String[] args){
        Car c = new Car();
        c.myCar();
        // myBoat();
        // 오류가 발생한다. static .. main 함수는 가장 먼저 생성, 실행되므로,
        // 아직 void myBoat() 메소드가 없다.

        // 이를 방지하려면 아래와 같이 인스턴스를 먼저 만들고 실행
        Boat b = new Boat();
        b.myBoat();
    }
    void myBoat() {
        System.out.println("This is my boat");
    }
}