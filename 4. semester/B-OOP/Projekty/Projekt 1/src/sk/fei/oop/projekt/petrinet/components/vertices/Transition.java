package sk.fei.oop.projekt.petrinet.components.vertices;

public final class Transition extends Vertex {

    public Transition(String name) {
        super(name);
    }

    public Transition() {
        super("");
    }

    @Override
    public String toString() {
        return this.getName().equals("") ? Long.toString(this.getId()) : this.getName();
    }
}
