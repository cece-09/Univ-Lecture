class Box {
    private int num;
    private String name;

    public Box(int num, String name) {
        this.num = num;
        this.name = name;
    }

    public int getBoxNum() {
        return num;
    }

    public String getBoxName() {
        return name;
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        /* in */
        Box[][] arr = {
                { new Box(101, "Coffee"), new Box(102, "Computer") },
                { new Box(201, "Apple"), new Box(202, "Play") },
                { new Box(301, "Study"), new Box(302, "Room") }
        };

        /* out */
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                System.out.print(arr[i][j].getBoxNum() + " : " + arr[i][j].getBoxName() + "\t");
            }
            System.out.println();
        }
    }
}
