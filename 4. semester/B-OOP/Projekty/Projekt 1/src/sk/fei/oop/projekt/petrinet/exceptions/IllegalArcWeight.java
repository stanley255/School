package sk.fei.oop.projekt.petrinet.exceptions;

public class IllegalArcWeight extends RuntimeException {

    public IllegalArcWeight() {
        super("Arc's weight cannot be 0 or less!");
    }

}
