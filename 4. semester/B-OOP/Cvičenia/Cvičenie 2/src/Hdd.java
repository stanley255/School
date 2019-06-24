public class Hdd {
    String name;
    String type;
    int capacity;
    int writeSpeed;
    int readSpeed;
    int consumption;

    public Hdd(String name, String type, int capacity, int writeSpeed, int readSpeed, int consumption) {
        this.setName(name);
        this.setType(type);
        this.setCapacity(capacity);
        this.setWriteSpeed(writeSpeed);
        this.setReadSpeed(readSpeed);
        this.setConsumption(consumption);
    }

    public void setName(String name) {
        if(StringUtils.isEmpty(name)) {
            throw new IllegalArgumentException("Name of HDD could not be empty!");
        }
        this.name = name;
    }

    public void setType(String type) {
        if(StringUtils.isEmpty(type)) {
            throw new IllegalArgumentException("Type of HDD could not be empty!");
        }
        this.type = type;
    }

    public void setCapacity(int capacity) {
        if(capacity <= 0) {
            throw new IllegalArgumentException("Enter valid number for capacity!");
        }
        this.capacity = capacity;
    }

    public void setWriteSpeed(int writeSpeed) {
        if(writeSpeed <= 0) {
            throw new IllegalArgumentException("Enter valid number for write speed!");
        }
        this.writeSpeed = writeSpeed;
    }

    public void setReadSpeed(int readSpeed) {
        if(readSpeed <= 0) {
            throw new IllegalArgumentException("Enter valid number for read speed!");
        }
        this.readSpeed = readSpeed;
    }

    public void setConsumption(int consumption){
        if(consumption <= 0) {
            throw new IllegalArgumentException("Enter valid number for consumption!");
        }
        this.consumption = consumption;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public int getCapacity() {
        return capacity;
    }

    public int getWriteSpeed() {
        return writeSpeed;
    }

    public int getReadSpeed() {
        return readSpeed;
    }

    public int getConsumption() { return consumption; }
}
