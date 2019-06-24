import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.io.Serializable;

public final class MyEllipse extends Ellipse2D.Double implements Drawable,Colorable, Serializable {

    Color color;

    public MyEllipse(double x, double y, double w, double h) {
        super(x, y, w, h);
    }

    public MyEllipse(double x, double y, double w, double h, Color color) {
        super(x, y, w, h);
        this.color = color;
    }

    @Override
    public Color getColor() {
        return color;
    }

    @Override
    public void setColor(Color color) {
        this.color = color;
    }

    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);
        g.fill(this);
        g.draw(this);
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
