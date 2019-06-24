import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.io.Serializable;

public final class MyLine extends Line2D.Double implements Drawable,Colorable, Serializable {

    Color color;

    public MyLine(double x1, double y1, double x2, double y2) {
        super(x1, y1, x2, y2);
    }

    public MyLine(double x1, double y1, double x2, double y2, Color color) {
        super(x1, y1, x2, y2);
        this.color = color;
    }

    public MyLine(Point2D p1, Point2D p2) {
        super(p1, p2);
    }

    public MyLine(Point2D p1, Point2D p2, Color color) {
        super(p1, p2);
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
        g.draw(this);
    }
}
