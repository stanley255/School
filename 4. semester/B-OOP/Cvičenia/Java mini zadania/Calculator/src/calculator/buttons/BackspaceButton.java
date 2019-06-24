package calculator.buttons;

import calculator.Calculator;

import java.awt.*;

public class BackspaceButton extends CalculatorButton{

    public BackspaceButton(Calculator calculator) throws HeadlessException {
        super("<-", calculator);
        addActionListener(e->{
            if (calculator.getOperator() == null) {
                String firstOperator = calculator.getStringValueOfFirstOperand();
                if (firstOperator.equals("0")) {
                    return;
                }
                if (firstOperator.length() == 1) {
                    calculator.setFirstOperand("0");
                    calculator.getDisplay().setText("0");
                    return;
                }
                calculator.setFirstOperand(firstOperator.substring(0,firstOperator.length()-1));
                calculator.getDisplay().setText(firstOperator.substring(0,firstOperator.length()-1));
            } else {
                String secondOperator = calculator.getStringValueOfSecondOperand();
                if (secondOperator.equals("0")) {
                    return;
                }
                if (secondOperator.length() == 1) {
                    calculator.setSecondOperand("0");
                    calculator.getDisplay().setText("0");
                    return;
                }
                calculator.setSecondOperand(secondOperator.substring(0,secondOperator.length()-1));
                calculator.getDisplay().setText(secondOperator.substring(0,secondOperator.length()-1));
            }
        });
    }
}
