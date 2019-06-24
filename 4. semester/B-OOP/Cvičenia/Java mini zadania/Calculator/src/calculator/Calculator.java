package calculator;

import java.awt.*;
import java.text.DecimalFormat;

public class Calculator {

    private TextArea display;
    private String firstOperand = "0";
    private String secondOperand = "0";
    private Executable operator;

    public Calculator(TextArea display) {
        this.display = display;
    }

    public double getFirstOperand() {
        return Double.parseDouble(firstOperand);
    }

    public double getSecondOperand() {
        return Double.parseDouble(secondOperand);
    }

    public String getStringValueOfFirstOperand() {
        return firstOperand;
    }

    public String getStringValueOfSecondOperand() {
        return secondOperand;
    }


    public Executable getOperator() {
        return operator;
    }

    public void setFirstOperand(String firstOperand) {
        if (firstOperand != null && firstOperand.length() >= 2) {
            String lastTwo = firstOperand.substring(firstOperand.length() - 2);
            if (lastTwo.equals(".0")){
                this.firstOperand = firstOperand.substring(0,firstOperand.length()-2);
                return;
            }
        }
        this.firstOperand = firstOperand;
    }

    public void setSecondOperand(String secondOperand) {
        this.secondOperand = secondOperand;
    }

    public void setOperator(Executable operator) {
        this.operator = operator;
    }

    public TextArea getDisplay() {
        return display;
    }


    public double trimNumber(double number) {
        DecimalFormat df = new DecimalFormat("#.##");
        return Double.parseDouble(df.format(number));
    }

    public void appendDigit(int digit) {
        if (operator != null) {
            secondOperand = appendDigit(secondOperand,digit);
            display.setText(secondOperand);
        } else {
            firstOperand = appendDigit(firstOperand,digit);
            display.setText(firstOperand);
        }
    }

    String appendDigit(String base, int append) {
        if ((base.equals("") || base.equals("0"))) {
            return String.valueOf(append);
        }
        return base + append;
    }

    public void reset() {
        display.setText("0");
        this.firstOperand = "0";
        this.secondOperand = "0";
        this.operator = null;
    }

}
