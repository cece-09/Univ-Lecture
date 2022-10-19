class Point {
    private int xPos, yPos;

    // const
    public Point(int x, int y) {
        xPos = x;
        yPos = y;
    }

    public void showPointInfo() {
        System.out.println("x: " + xPos + "  y: " + yPos);
    }
}

class Circle {
    private final double PI = 3.14;
    private Point location;
    private double area;
    private double len;

    // const
    public Circle(int x, int y, double r) {
        location = new Point(x, y);
        area = r * r * PI;
        len = 2 * r * PI;
    }

    public void showCircleInfo() {
        location.showPointInfo();
        System.out.println("area is " + area);
        System.out.println("len is " + len);
    }
}

public class Ch7practice01 {
    public static void main(String[] args) {
        Circle c = new Circle(2, 2, 4.2);
        c.showCircleInfo();   
    }
}
