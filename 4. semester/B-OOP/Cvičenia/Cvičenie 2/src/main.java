public class main {
    public static void main(String[] args) {
        System.out.println("IT WORKS!");

        Processor processor = new Processor("Intel Core i9-9900K","Intel 1151 Coffee Lake",3.6,8,16,600);
        Ram ram = new Ram("HyperX 10 Fury Black","DDR4",2,8,2400,45);
        MotherBoard motherBoard = new MotherBoard("GIGABYTE B360-HD3","Intel 1151 Coffee Lake","DDR4",4,4000,ram,50);
        Hdd hdd = new Hdd("Kingston SSDNow UV500 480 GB","SSD",480,500,520,30);
        PowerSupply powerSupply = new PowerSupply("Fractal Design Integra M","ATX 2.4",550);

        Computer computer = new Computer(motherBoard,processor,ram,hdd,powerSupply);
        computer.turnOn();
    }
}
