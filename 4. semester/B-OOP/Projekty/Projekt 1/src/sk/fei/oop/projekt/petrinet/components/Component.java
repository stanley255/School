package sk.fei.oop.projekt.petrinet.components;
import java.math.BigInteger;
import java.util.UUID;
public abstract class Component {

    private long id;

    public Component() {
        String idString = String.format("%040d", new BigInteger(UUID.randomUUID().toString().replace("-", ""), 16)).substring(0,20);
        this.id = Long.parseLong(idString);
    }

    public long getId() {
        return this.id;
    }

}
