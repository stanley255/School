import java.awt.*;

public class MojePlatno extends Canvas {
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Dimension d=getSize();
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
        }
    }
}
