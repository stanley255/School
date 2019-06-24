public class Processor {
    String name;
    String socket;
    double frequency;
    int    coresCount;
    int    threadsCount;
    int    consumption;

    public Processor(String name, String socket, double frequency, int coresCount, int threadsCount, int consumption) {
        this.setName(name);
        this.setSocket(socket);
        this.setFrequency(frequency);
        this.setCoresCount(coresCount);
        this.setThreadsCount(threadsCount);
        this.setConsumption(consumption);
    }

    private void setName(String name) {
        if(StringUtils.isEmpty(name)) {
            throw new IllegalArgumentException("Name of processor could not be empty!");
        }
        this.name = name;
    }

    private void setSocket(String socket) {
        if(StringUtils.isEmpty(socket)) {
            throw new IllegalArgumentException("Socket of processor could not be empty!");
        }
        this.socket = socket;
    }

    private void setFrequency(double frequency) {
        if (frequency <= 0.0) {
            throw new IllegalArgumentException("Enter valid frequency of processor!");
        }
        this.frequency = frequency;
    }

    private void setCoresCount(int coresCount) {
        if (coresCount <= 0) {
            throw new IllegalArgumentException("Enter valid number of cores!");
        }
        this.coresCount = coresCount;
    }

    private void setThreadsCount(int threadsCount) {
        if (threadsCount <= 0) {
            throw new IllegalArgumentException("Enter valid number of threads!");
        }
        this.threadsCount = threadsCount;
    }

    private void setConsumption(int consumption) {
        if (threadsCount <= 0) {
            throw new IllegalArgumentException("Enter valid consumption!");
        }
        this.consumption = consumption;
    }

    public String getName() {
        return name;
    }

    public String getSocket() {
        return socket;
    }

    public double getFrequency() {
        return frequency;
    }

    public int getCoresCount() {
        return coresCount;
    }

    public int getThreadsCount() {
        return threadsCount;
    }

    public int getConsumption() {
        return consumption;
    }
}
