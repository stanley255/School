package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public class AdditionButton extends OperationButton {

    public AdditionButton(Calculator calculator) throws HeadlessException {
        super("+", calculator);
    }

    @Override
    public double calculate(double x, double y) {
        return x+y;
    }
}
