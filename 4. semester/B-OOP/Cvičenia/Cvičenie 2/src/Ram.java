public class Ram {
    String name;
    String memoryType;
    int    sticksCount;
    int    memoryCapacity;
    int    frequency;
    int    consumption; // of one unit

    public Ram(String name, String memoryType, int sticksCount, int memoryCapacity, int frequency, int consumption) {
        this.name = name;
        this.memoryType = memoryType;
        this.sticksCount = sticksCount;
        this.memoryCapacity = memoryCapacity;
        this.frequency = frequency;
        this.consumption = consumption;
    }

    public void setName(String name) {
        if(StringUtils.isEmpty(name)) {
            throw new IllegalArgumentException("Name of ram could not be empty!");
        }
        this.name = name;
    }

    public void setMemoryType(String memoryType) {
        if(StringUtils.isEmpty(memoryType)) {
            throw new IllegalArgumentException("Type of ram could not be empty!");
        }
        this.memoryType = memoryType;
    }

    public void setSticksCount(int sticksCount) {
        if (sticksCount <= 0) {
            throw new IllegalArgumentException("Enter valid number of RAM stricks!");
        }
        this.sticksCount = sticksCount;
    }

    public void setMemoryCapacity(int memoryCapacity) {
        if (memoryCapacity <= 0) {
            throw new IllegalArgumentException("Enter valid memory capacity!");
        }
        this.memoryCapacity = memoryCapacity;
    }

    public void setFrequency(int frequency) {
        if (frequency <= 0) {
            throw new IllegalArgumentException("Enter valid frequency of RAM!");
        }
        this.frequency = frequency;
    }

    public void setConsumption(int consumption) {
        if (consumption <= 0) {
            throw new IllegalArgumentException("Enter valid consumption of RAM!");
        }
        this.consumption = consumption;
    }

    public String getName() {
        return name;
    }

    public String getMemoryType() {
        return memoryType;
    }

    public int getSticksCount() {
        return sticksCount;
    }

    public int getMemoryCapacity() {
        return memoryCapacity;
    }

    public int getFrequency() {
        return frequency;
    }

    public int getConsumption() {
        return consumption;
    }
}
