import java.util.List;
import java.util.ArrayList;

public class MotherBoard {
    String    name;
    String    socket;
    String    memoryType;
    int       ramSlotsCount;
    int       maxRamFrequency;
    List<Ram> ramSticks;
    int       consumption;

    public MotherBoard(String name, String socket, String memoryType, int ramSlotsCount, int maxRamFrequency, Ram ram, int consumption) {
        this.setName(name);
        this.setSocket(socket);
        this.setMemoryType(memoryType);
        this.setRamSlotsCount(ramSlotsCount);
        this.setMaxRamFrequency(maxRamFrequency);
        this.setRamSticks(ram);
        this.setConsumption(consumption);
    }

    public void setName(String name) {
        if(StringUtils.isEmpty(name)) {
            throw new IllegalArgumentException("Name of mother board could not be empty!");
        }
        this.name = name;
    }

    public void setSocket(String socket) {
        if(StringUtils.isEmpty(socket)) {
            throw new IllegalArgumentException("Socket of mother board could not be empty!");
        }
        this.socket = socket;
    }

    public void setMemoryType(String memoryType) {
        if(StringUtils.isEmpty(memoryType)) {
            throw new IllegalArgumentException("Memory type of mother board could not be empty!");
        }
        this.memoryType = memoryType;
    }

    public void setRamSlotsCount(int ramSlotsCount) {
        if(ramSlotsCount <= 0) {
            throw new IllegalArgumentException("Enter valid number of RAM slots!");
        }
        this.ramSlotsCount = ramSlotsCount;
    }

    public void setMaxRamFrequency(int maxRamFrequency) {
        if(maxRamFrequency <= 0) {
            throw new IllegalArgumentException("Enter valid number for RAM frequency!");
        }
        this.maxRamFrequency = maxRamFrequency;
    }

    public void setRamSticks(Ram ram) {
        if (ram.getSticksCount() > ramSlotsCount){
            throw new IllegalArgumentException("Mother board cannot accept more then "+ramSlotsCount+"!");
        }
        if (ram.getFrequency() > maxRamFrequency){
            throw new IllegalArgumentException("Mother board does not support that high frequency!");
        }
        if (!ram.getMemoryType().equals(memoryType)) {
            throw new IllegalArgumentException("Mother board does not support this type of RAM type!");
        }
        this.ramSticks = new ArrayList<>();
        for (int i = 0; i < ram.getSticksCount(); i++){
            this.ramSticks.add(ram);
        }
    }

    public void setConsumption(int consumption) {
        if(consumption <= 0) {
            throw new IllegalArgumentException("Enter valid number for consumption!");
        }
        this.consumption = consumption;
    }

    public String getName() {
        return name;
    }

    public String getSocket() {
        return socket;
    }

    public String getMemoryType() {
        return memoryType;
    }

    public int getRamSlotsCount() {
        return ramSlotsCount;
    }

    public int getMaxRamFrequency() {
        return maxRamFrequency;
    }

    public List<Ram> getRamSticks() {
        return ramSticks;
    }

    public int getConsumption() {
        return consumption;
    }
}
