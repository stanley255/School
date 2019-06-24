import javax.swing.*;
import java.awt.*;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.io.*;
import java.util.LinkedHashMap;
import java.util.Map;

public class PaintFrame extends JFrame {

    Rectangle2D.Double rect;
    Point2D.Double o;
    private LinkedHashMap<String, Color> colors = new LinkedHashMap<String, Color>(){{
        put("Black", Color.BLACK);
        put("Red",Color.RED);
        put("Green",Color.GREEN);
        put("Blue",Color.BLUE);
        put("Orange",Color.ORANGE);
        put("Yellow",Color.YELLOW);
        put("Pink",Color.PINK);
    }};

    public PaintFrame() throws HeadlessException {
        super("Mini Paint");
        setSize(500,500);
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        Choice choiceList = new Choice();
        for (Map.Entry<String,Color>color:colors.entrySet()) {
            choiceList.add(color.getKey());
        }

        Panel panel = new Panel();

        panel.add(choiceList);

        PaintCanvas paintCanvas = new PaintCanvas();
        this.add("Center",paintCanvas);

        choiceList.addItemListener(e -> paintCanvas.setCurrentColor(colors.get(e.getItem().toString())));

        RectangleButton rectangleButton = new RectangleButton(paintCanvas);
        panel.add(rectangleButton);

        EllipseButton ellipseButton = new EllipseButton(paintCanvas);
        panel.add(ellipseButton);

        LineButton lineButton = new LineButton(paintCanvas);
        panel.add(lineButton);

        // Save & Load Buttons
        Button saveButton = new Button("Save");
        saveButton.addActionListener(e->{
            try {
                FileOutputStream f = new FileOutputStream(new File("myObjects.txt"));
                ObjectOutputStream o = new ObjectOutputStream(f);
                for (Drawable drawable : paintCanvas.getDrawables()) {
                    o.writeObject(drawable);
                }
                o.close();
                f.close();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        });

        Button loadButton = new Button("Load");
        loadButton.addActionListener(e-> {
            paintCanvas.setDrawables(null);
            try {
                FileInputStream fi = new FileInputStream(new File("myObjects.txt"));
                ObjectInputStream oi = new ObjectInputStream(fi);
                while (true) {
                    try {
                        Drawable loadedDrawable = (Drawable) oi.readObject();
                        paintCanvas.addDrawable(loadedDrawable);
                    }
                    catch(EOFException ex) {
                        oi.close();
                        break;
                    }
                }
                oi.close();
                fi.close();
            } catch (IOException | ClassNotFoundException e1) {
                e1.printStackTrace();
            }
        });

        panel.add(saveButton);
        panel.add(loadButton);

        this.add("North",panel);

        setVisible(true);
    }

}
