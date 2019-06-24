package sk.fei.oop.projekt.petrinet.components.arcs;

public interface Input {

    public abstract void consumeTokensFromPlace();

    public abstract int canConsume();

}
