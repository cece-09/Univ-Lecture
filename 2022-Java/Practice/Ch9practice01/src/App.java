class Box {
    private String c;
    Box(String c) {
        this.c = c;
    }
    public String show() {
        return c;
    }
    public String toString() {
        return c;
    }
}

public class App {
    public static void main(String[] args) {
        System.out.printf("%5d %10f %s\n", 10, 3.14, "string");
    }
}
