package calculator;

import calculator.buttons.*;

import javax.swing.*;
import java.awt.*;

public class CalculatorFrame extends JFrame {

    public CalculatorFrame() throws HeadlessException {
        super("Calculator");
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);
        setSize(330,470);
        Panel displayPanel = new Panel();
        Panel controlPanel = new Panel(new GridLayout(0,4));

        // Display panel configuration
        TextArea display = new TextArea("0",1,25,TextArea.SCROLLBARS_NONE);
        Font font = new Font("Segoe Script", Font.PLAIN, 22);
        display.setEditable(false);
        display.setFont(font);
        displayPanel.add(display);

        // Create calculator
        Calculator calculator = new Calculator(display);

        // Control panel configuration
        DigitButton zero = new DigitButton(0,calculator);
        DigitButton one = new DigitButton(1,calculator);
        DigitButton two = new DigitButton(2,calculator);
        DigitButton three = new DigitButton(3,calculator);
        DigitButton four = new DigitButton(4,calculator);
        DigitButton five = new DigitButton(5,calculator);
        DigitButton six = new DigitButton(6,calculator);
        DigitButton seven = new DigitButton(7,calculator);
        DigitButton eight = new DigitButton(8,calculator);
        DigitButton nine = new DigitButton(9,calculator);

        controlPanel.add(new JLabel(""));
        controlPanel.add(new BackspaceButton(calculator));
        controlPanel.add(new ClearButton(calculator));
        controlPanel.add(new AdditionButton(calculator));
        controlPanel.add(seven);
        controlPanel.add(eight);
        controlPanel.add(nine);
        controlPanel.add(new SubstractionButton(calculator));
        controlPanel.add(four);
        controlPanel.add(five);
        controlPanel.add(six);
        controlPanel.add(new MultiplicationButton(calculator));
        controlPanel.add(one);
        controlPanel.add(two);
        controlPanel.add(three);
        controlPanel.add(new DivisionButton(calculator));
        controlPanel.add(new JLabel(""));
        controlPanel.add(zero);
        controlPanel.add(new DecimalButton(calculator));
        controlPanel.add(new EvaluationButton(calculator));

        this.add("North",displayPanel);
        this.add("Center",controlPanel);
        setVisible(true);
    }
}
