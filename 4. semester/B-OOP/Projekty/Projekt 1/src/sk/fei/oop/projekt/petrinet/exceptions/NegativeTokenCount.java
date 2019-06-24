package sk.fei.oop.projekt.petrinet.exceptions;

public class NegativeTokenCount extends RuntimeException {

    public NegativeTokenCount() {
        super("Place's token count cannot be negative number!");
    }

}
