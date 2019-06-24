import java.awt.*;
import java.awt.geom.Rectangle2D;

public class MyCross extends Rectangle2D.Double implements Drawable,Colorable {

    Color color;

    public MyCross(double x, double y, double w, double h) {
        super(x, y, w, w);
    }

    public MyCross(double x, double y, double w, double h, Color color) {
        super(x, y, w, w);
        this.color = color;
    }

    @Override
    public Color getColor() {
        return this.color;
    }

    @Override
    public void setColor(Color color) {
        this.color = color;
    }

    @Override
    public void draw(Graphics2D g) {
        g.setColor(color);
        double w = this.width;
        double third = w/3;
        g.fill(new Rectangle2D.Double(this.getX()+third,this.getY(),third,w));
        g.fill(new Rectangle2D.Double(this.getX(),this.getY()+third,w,third));
    }
}
