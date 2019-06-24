public class PowerSupply {
    String name;
    String type;
    int    watts;

    public PowerSupply(String name, String type, int watts) {
        this.name = name;
        this.type = type;
        this.watts = watts;
    }

    public void setName(String name) {
        if(StringUtils.isEmpty(name)) {
            throw new IllegalArgumentException("Power supply name could not be empty!");
        }
        this.name = name;
    }

    public void setType(String type) {
        if(StringUtils.isEmpty(type)) {
            throw new IllegalArgumentException("Type of power supply could not be empty!");
        }
        this.type = type;
    }

    public void setWatts(int watts) {
        if(watts <= 0) {
            throw new IllegalArgumentException("Enter valid number of power supply watts!");
        }
        this.watts = watts;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public int getWatts() {
        return watts;
    }
}
