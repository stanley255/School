public class Computer {
    MotherBoard motherBoard;
    Processor processor;
    Ram ram;
    Hdd hdd;
    PowerSupply powerSupply;
    boolean isTurnedOn;

    public Computer(MotherBoard motherBoard, Processor processor, Ram ram, Hdd hdd, PowerSupply powerSupply) {
        this.setMotherBoard(motherBoard);
        this.setProcessor(processor);
        this.setRam(ram);
        this.setHdd(hdd);
        this.setPowerSupply(powerSupply);
        this.isTurnedOn = false;
    }

    public void setMotherBoard(MotherBoard motherBoard) {
        if (motherBoard == null){
            throw new IllegalArgumentException("Enter valid mother board!");
        }
        this.motherBoard = motherBoard;
    }

    public void setProcessor(Processor processor) {
        if (processor == null){
            throw new IllegalArgumentException("Enter valid processor!");
        }
        this.processor = processor;
    }

    public void setRam(Ram ram) {
        if (ram == null){
            throw new IllegalArgumentException("Enter valid RAM!");
        }
        this.ram = ram;
    }

    public void setHdd(Hdd hdd) {
        if (hdd == null){
            throw new IllegalArgumentException("Enter valid HDD!");
        }
        this.hdd = hdd;
    }

    public void setPowerSupply(PowerSupply powerSupply) {
        if (powerSupply == null){
            throw new IllegalArgumentException("Enter valid power supply!");
        }
        this.powerSupply = powerSupply;
    }

    public MotherBoard getMotherBoard() {
        return motherBoard;
    }

    public Processor getProcessor() {
        return processor;
    }

    public Ram getRam() {
        return ram;
    }

    public Hdd getHdd() {
        return hdd;
    }

    public PowerSupply getPowerSupply() {
        return powerSupply;
    }

    public boolean isTurnedOn() {
        return isTurnedOn;
    }

    public int getConsumption(){
        return hdd.getConsumption() + motherBoard.getConsumption() + processor.getConsumption() + ram.getConsumption();
    }

    public void turnOn() {
        if (hdd == null || motherBoard == null || powerSupply == null || processor == null || ram == null){
            throw new IllegalArgumentException("Component of computer is missing!");
        }
        if (this.getConsumption()>powerSupply.getWatts()){
            throw new IllegalArgumentException("Components are consuming too much power! Computer cannot turn on!");
        }
        this.isTurnedOn = true;
    }
}
