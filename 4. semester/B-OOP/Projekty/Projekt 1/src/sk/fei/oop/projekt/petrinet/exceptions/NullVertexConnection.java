package sk.fei.oop.projekt.petrinet.exceptions;

public class NullVertexConnection extends RuntimeException {

    public NullVertexConnection() {
        super("Arc cannot connect null vertex!");
    }
}
