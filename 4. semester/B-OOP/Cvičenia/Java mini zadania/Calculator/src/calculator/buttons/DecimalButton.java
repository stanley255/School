package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public class DecimalButton extends CalculatorButton {

    public DecimalButton(Calculator calculator) throws HeadlessException {
        super(".", calculator);
        addActionListener(e->{
            if (calculator.getOperator() == null) {
                String firstOperand = calculator.getStringValueOfFirstOperand();
                if (firstOperand.contains(".")) {
                    return;
                }
                calculator.setFirstOperand(firstOperand+".");
                calculator.getDisplay().setText(firstOperand+".");
            } else {
                String secondOperand = calculator.getStringValueOfSecondOperand();
                if (secondOperand.contains(".")) {
                    return;
                }
                calculator.setSecondOperand(secondOperand+".");
                calculator.getDisplay().setText(secondOperand+".");
            }
        });
    }
}
