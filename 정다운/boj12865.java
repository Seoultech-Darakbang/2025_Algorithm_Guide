import java.util.ArrayList;
import java.util.Scanner;

class Stuff{
    private int weight, value;

    public Stuff(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }
    public int getWeight() {return weight;}
    public int getValue() {return value;}
}

class Bag{
    private ArrayList<Stuff> stuffs = new ArrayList<Stuff>();
    private int maxWeight, totalWeight = 0;
    private int maxCount, totalCount = 0;
    private int totalValue = 0;

    public Bag(int count, int weight) {
        maxWeight = weight;
        maxCount = count;
    }
    public void addStuff(Stuff e){
        if((e.getWeight()+totalWeight<=maxWeight)&&(++totalCount<=maxCount)) {
            stuffs.add(e);
            totalCount++;
            totalValue += e.getValue();
            totalWeight += e.getWeight();
        }
    }
    public int getValue() {return totalValue;}
}

public class Java12865 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        ArrayList<Stuff> stuffs = new ArrayList<Stuff>();
        String str = sc.nextLine();
        int maxCount = Integer.parseInt(str.split(" ")[0]);
        int maxWeight = Integer.parseInt(str.split(" ")[1]);
        int maxValue = 0;
        for(int i=0; i<maxCount; i++) {
            str = sc.nextLine();
            stuffs.add(new Stuff(Integer.parseInt(str.split(" ")[0]), Integer.parseInt(str.split(" ")[1])));
        }
        for(int i=0; i<maxCount; i++) {
            Bag tempBag = new Bag(maxCount, maxWeight);
            tempBag.addStuff(stuffs.get(i));
            for(int j=0; j<maxCount; j++) {
                if(i != j) tempBag.addStuff(stuffs.get(j));
            }
            if(maxValue<tempBag.getValue()) maxValue = tempBag.getValue();
        }
        System.out.println(maxValue);
    }
}