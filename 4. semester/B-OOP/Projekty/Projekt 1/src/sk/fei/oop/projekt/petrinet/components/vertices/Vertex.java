package sk.fei.oop.projekt.petrinet.components.vertices;

import sk.fei.oop.projekt.petrinet.components.Component;

public abstract class Vertex extends Component {

    private String name;

    public Vertex(String name) {
        super();
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
