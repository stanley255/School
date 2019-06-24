package Game;

import Players.Player;

public class Game {

    private int TURN_COUNTER = 0;

    public static void start() {
        System.out.println("Hra začala!");
    }

    //public void playerTurn(Player p1, )

    public void turn(Player p1, Player p2) {
        TURN_COUNTER++;
        System.out.println(TURN_COUNTER + ". sa začína!");
        //System.out.println("Na rade je " + p1.get);
    }

}
