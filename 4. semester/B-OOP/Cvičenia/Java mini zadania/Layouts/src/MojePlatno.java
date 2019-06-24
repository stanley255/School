import java.awt.*;
import java.awt.geom.Ellipse2D;

public class MojePlatno extends Canvas {
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        /*Dimension d=getSize();
        int w=d.width,h=d.height;
        int i=0;
        Color C;
        while (i<=w-1-i && i<=h-1-i) {
            // vytvor novu farbu
            if (2*i<256)
                C=new Color(2*i,255-2*i,255);
            else
                C=Color.yellow;
            g.setColor(C); // nastav farbu
            g.drawRect(i,i,w-1-2*i,h-1-2*i);
            i++;
        }*/
        Graphics2D g2 = (Graphics2D) g;
        Dimension d = getSize();
        int w = (int) d.getWidth();
        int h = (int) d.getHeight();
        Color c = Color.yellow;
        g2.setColor(c);
        Ellipse2D.Double e = new Ellipse2D.Double(w/2-w/4,h/2-h/4,w/2,h/2);
        g2.fill(e);
    }
}
