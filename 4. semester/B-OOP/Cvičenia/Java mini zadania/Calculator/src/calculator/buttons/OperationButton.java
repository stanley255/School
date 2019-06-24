package calculator.buttons;

import calculator.Calculator;
import calculator.Executable;

import java.awt.*;

public abstract class OperationButton extends CalculatorButton implements Executable {

    public OperationButton(String label, Calculator calculator) throws HeadlessException {
        super(label, calculator);
        addActionListener(e-> {
            calculator.setOperator(this);
        });
    }
}
