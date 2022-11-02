class Point {
    private int xPos, yPos;

    public Point(int x, int y) { // const
        xPos = x;
        yPos = y;
    }
    public void showPointInfo() {
        System.out.println("x: " + xPos);
        System.out.println("y: " + yPos);
    }
}

class Circle {
    private final double PI = 3.1415;
    private double rad;
    private Point center;

    public Circle(int x, int y, double r) { // const
        center = new Point(x, y);
        rad = r;
    }
    public double getArea() {
        return PI*rad*rad;
    }
    public double getPeri() {
        return PI*2*rad;
    }
    public void showCircleInfo() {
        System.out.println("** Circle Information **");
        center.showPointInfo();
        System.out.println("Radius : " + rad);
        System.out.println("Area : " + getArea());
        System.out.println("Perimeter : " + getPeri());
    }
}

public class Ch7practice01 {
    public static void main(String[] args) {
        Circle c = new Circle(2, 2, 4.2);
        c.showCircleInfo();   
    }
}
