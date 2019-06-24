import java.awt.*;

public class MojePlatno extends Canvas {
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        Dimension d=getSize();
        int w=d.width,h=d.height;
        Rectangle rectangle = new Rectangle(10,10,100,50);
        /* Rectangle */
        g.setColor(new Color(255,20,130));
        g.drawRect(10,10,100,50);
        /* Line */
        int x1=100,y1=100,x2,y2,theta=1;
        g.setColor(new Color(0, 10, 255));
        //g.drawLine(200,200,200+x1,200-y1);
        for (int i = 0; i < 360; i++) {
            try {
                Thread.sleep(1000);
                g.setColor(getBackground());
                g.clearRect(0, 0, w, h);

            } catch (InterruptedException e) {}
            g.setColor(new Color(0, 10, 255));
            x2=((int)(x1*Math.cos(i*Math.PI/180)))-((int)(y1* Math.sin(i*Math.PI/180)));
            y2=((int)(x1*Math.sin(i*Math.PI/180)))+((int)(y1* Math.cos(i*Math.PI/180)));
            g.drawLine(200,200,200+x2,200-y2);
        }
        /* Oval */
        g.setColor(new Color(255, 85, 13));
        g.drawOval(10,200,50,50);
        /* Polygon */
        int[] polyX= new int[5];
        int[] polyY= new int[5];
        int N = 5;
        int r = 50;
        int polyXoffset = 100;
        int polyYoffset = 400;
        for (int i = 0; i < 5; i++) {
            polyX[i] = (int) (r * Math.cos(2*Math.PI*i/N))+polyXoffset;
            polyY[i] = (int) (r * Math.sin(2*Math.PI*i/N))+polyYoffset;
        }
        Polygon polygon = new Polygon(polyX,polyY,5);
        g.setColor(new Color(100,153,34));
        g.fillPolygon(polygon);
        g.drawPolygon(polygon);
    }
}
