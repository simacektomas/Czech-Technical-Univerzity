package entities;

public class Trip {
    private int id;
    private String destination;
    private int capacity;
    private int occupied;
    private String instructor;

    Trip(){}

    public Trip(int id, String destination, int capacity, int occupied, String instructor) {
            super();
            this.id = id;
            this.destination = destination;
            this.capacity = capacity;
            this.occupied = occupied;
            this.instructor = instructor;
    }

    public int getId() {
            return id;
    }

    public void setId(int id) {
            this.id = id;
    }

    public String getDestination() {
            return destination;
    }

    public void setDestination(String destination) {
            this.destination = destination;
    }

    public int getCapacity() {
            return capacity;
    }

    public void setCapacity(int capacity) {
            this.capacity = capacity;
    }

    public int getOccupied() {
            return occupied;
    }

    public void setOccupied(int occupied) {
            this.occupied = occupied;
    }

    public String getInstructor() {
            return instructor;
    }

    public void setInstructor(String instructor) {
            this.instructor = instructor;
    }

    @Override
    public String toString() {
            return "Trip [id=" + id + ", destination=" + destination + ", capacity=" + capacity + ", occupied=" + occupied
                            + ", instructor=" + instructor + "]";
    }
}