import java.util.*;

class AccountMenu {
    private BankAccount account1;
    private BankAccount account2;
    private int menu;
    private int amount;
    Scanner sc;

    public AccountMenu(
            String n1, String a1, int b1,
            String n2, String a2, int b2) {
        sc = new Scanner(System.in);
        account1 = new BankAccount(n1, a1, b1);
        account2 = new BankAccount(n2, a2, b2);
        go();
    }
    
    // 한 번에 모두 실행
    private void go() {
        showAccount();
        showMenu();
        doMenu();
    }

    // 계좌 정보 출력
    private void showAccount() {
        System.out.println("Account1: ");
        account1.showInfo();
        System.out.println("Account2: ");
        account2.showInfo();
    }
    // 계좌 메뉴 출력
    private void showMenu() {
        System.out.print(
                "1. Deposit A1   2. Deposit A2   3. Withdraw A1   4. Withdraw A2   5. Transfer A1->A2   6. Transfer A2->A1   0.Exit : ");
        setMenu(sc.nextInt());
    }
    // 메뉴 입력값 handle
    private void setMenu(int n){
        if (n >= 0 && n <= 6) {
            menu = n;
        }  
        else {
            System.out.println("Error: enter a right number");
            showMenu();
        }
    }

    // 메뉴 실행
    private void doMenu() {
        if(menu == 0){
            sc.close(); // do nothing
            return;
        }
        amount = setAmount();
        if(menu == 1) {            
            account1.deposit(amount);
        }
        else if(menu == 2) {
            account2.deposit(amount);
        }
        else if(menu == 3) {
            account1.withdraw(amount);
        }
        else if(menu == 4) {
            account2.withdraw(amount);
        }
        else if(menu == 5) {
            account1.bankTransfer(account2, amount);
        }
        else {
            account2.bankTransfer(account1, amount);
        }
        // 메뉴 실행 후 무한반복
        System.out.println();
        go();
    }
    // 사용자로부터 금액 입력
    private int setAmount(){
        System.out.print("How much do you want [menu"+ menu + "] ");
        return sc.nextInt();
    }
}

class BankAccount {
    private String account;
    private String name;
    private int balance;

    public BankAccount(String n, String a, int b) {
        name = n;
        account = a;
        balance = b;
    }
    public void showInfo() {
        System.out.println(" Name: " + name +
                ", Account: " + account +
                ", Balance: " + balance);
    }
    public void bankTransfer(BankAccount other, int amount) {
        withdraw(amount);
        other.deposit(amount);
    }
    public void deposit(int amount) {
        balance += amount;
    }
    public void withdraw(int amount) {
        if (balance >= amount) {     
            balance -= amount;
        } else {                // 잔액 >= 출금액
            System.out.println("Balance is not enough");
            System.out.println("Current balance: " + balance);
        }
    }
}

public class Project05 {
    public static void main(String[] args) {
        AccountMenu am = new AccountMenu("Hong", "111-1234", 10000, "Kim", "111-5678", 2000);
    }
}
