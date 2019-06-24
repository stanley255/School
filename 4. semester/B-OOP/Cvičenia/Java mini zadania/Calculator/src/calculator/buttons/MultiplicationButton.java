package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public class MultiplicationButton extends OperationButton {

    public MultiplicationButton(Calculator calculator) throws HeadlessException {
        super("*", calculator);
    }

    @Override
    public double calculate(double x, double y) {
        return x*y;
    }
}
