import javax.swing.*;
import java.awt.*;
import java.awt.geom.Point2D;
import java.util.LinkedHashMap;
import java.util.Map;

public class PaintFrame extends JFrame {
    Point2D.Double o;
    final String colorIntro = "Current color: ";
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

        Label colorLabel = new Label(colorIntro+"Black");

        PaintCanvas paintCanvas = new PaintCanvas();
        this.add("Center",paintCanvas);

        choiceList.addItemListener(e -> {
            colorLabel.setText(colorIntro+e.getItem());
            paintCanvas.setCurrentColor(colors.get(e.getItem().toString()));
        });

        CrossButton crossButton = new CrossButton(paintCanvas);
        panel.add(crossButton);

        LineButton lineButton = new LineButton(paintCanvas);
        panel.add(lineButton);

        panel.add(choiceList);
        panel.add(colorLabel);

        ColorChangeButton colorChangeButton = new ColorChangeButton(paintCanvas);
        panel.add(colorChangeButton);

        this.add("North",panel);

        setVisible(true);
    }

}
