class Car {
    private String number;
    private String model;
    private String color;
    private int currSpeed;
    private int currGear;

    // constructor
    public Car(String n, String m, String c) {
        number = n;
        model = m;
        color = c;
        currSpeed = 0;
        currGear = 1;
    }

    // change gear
    public int changeGear(int g) {
        if(g > 0 && g < 4) { // g is 1 or 2 or 3
            currGear = g;
            setGearSpeed();
        }
        display();
        return currGear;
    }

    // eccelerate
    public int speedUp(int s) {
        currSpeed += s;
        setGearSpeed();
        display();
        return currSpeed;
    }

    // decelerate
    public int speedDown(int s) {
        currSpeed -= s;
        if( currSpeed < 0) {
            currSpeed = 0;
        }
        else setGearSpeed();
        display();
        return currSpeed;
    }

    // set speed considering current gear setting
    public void setGearSpeed() {
        if(currSpeed > currGearMaxSpeed()) {
            currSpeed = currGearMaxSpeed();
        }
        else if (currSpeed < currGearMinSpeed()) {
            currSpeed = currGearMinSpeed();
        }
    }

    // return minimum speed on current gear
    public int currGearMinSpeed() {
        if(currGear == 1) {
            return 0;
        }
        else if(currGear == 2) {
            return 30;
        }
        else if(currGear == 3) {
            return 50;
        }
        else {
            return currSpeed;
        }
    }

    // return maximum speed on current gear
    public int currGearMaxSpeed() {
        if(currGear == 1) {
            return 50;
        }
        else if(currGear == 2) {
            return 80;
        }
        else if(currGear == 3) {
            return 120;
        }
        else {
            return currSpeed;
        }
    }

    // display
    public void display() {
        System.out.println("Lisense Number:" + number + "  Model:" + model + "  Color:" + color);
        System.out.println("Gear Level: " + currGear + "     Current Speed:" + currSpeed + "km/s");
        System.out.println();
    }
}


// main function
public class Project04 {
    public static void main(String[] args) {
        Car c1 = new Car("A123", "Ferrari Monza", "Red");

        c1.changeGear(1);
        c1.speedUp(20);
        c1.speedDown(40);
    }
}
