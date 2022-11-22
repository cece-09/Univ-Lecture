import java.util.*;

class EngWord {
    private String word;
    private String meaning;

    public EngWord(String word, String meaning) {
        this.word = word;
        this.meaning = meaning;
    }

    public Boolean checkWord(String word) {
        return (this.word.equals(word) ? true : false);
    }

    public String getWord() {
        return word;
    }

    public String toString() {
        return meaning;
    }
}

class Dictionary {
    private int max;
    private int curr;
    private EngWord[] dictionary;
    Scanner sc;

    public Dictionary(int max) {
        this.max = max;
        this.curr = 0;
        dictionary = new EngWord[max];
        sc = new Scanner(System.in);
    }

    private Boolean checkFull() {
        return max == curr ? true : false;
    }

    private Boolean checkWord(String word) {
        for (int i = 0; i < curr; i++) {
            if (dictionary[i].checkWord(word)) {
                return true;
            }
        }
        return false;
    }

    private void appendWord(String word, String meaning) {
        dictionary[curr] = new EngWord(word, meaning);
        this.curr++;
    }

    private String findWord(String word) {
        for (int i = 0; i < curr; i++) {
            if (dictionary[i].checkWord(word)) {
                return dictionary[i].toString();
            }
        }
        return null;
    }

    public void start() {
        String word;
        String meaning;
        while (true) {
            System.out.println("EngKor Dictionary (" + curr + "/" + max + " words)");
            System.out.print("[Add Word:New word/ Find Word:Contained word/ Exit: Type \"exit\"] Input Word: ");
            word = sc.nextLine();

            if (word.equals("exit")) {
                sc.close();
                return;
            } else if (checkFull() == true) {
                System.out.println("The dictionary is full.");
            } else if (checkWord(word) == true) {
                System.out.println(findWord(word));
            } else {
                System.out.print("Type meaning of word \"" + word + "\" :");
                meaning = sc.nextLine();
                appendWord(word, meaning);
            }
            System.out.println();
        }
    }
}

public class Project06 {
    public static void main(String[] args) throws Exception {
        Dictionary d = new Dictionary(5);
        d.start();
    }
}
