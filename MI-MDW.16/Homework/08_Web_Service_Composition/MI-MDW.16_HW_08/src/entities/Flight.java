package entities;

public class Flight {
    private int id;
    private String destination;
    private int capacity;
    private int occupied;
    private String dairport;
    private String aairport;

    Flight(){}

    public Flight(int id, String destination, int capacity, int occupied, String dairport, String aairport) {
            this.id = id;
            this.destination = destination;
            this.capacity = capacity;
            this.occupied = occupied;
            this.dairport = dairport;
            this.aairport = aairport;
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

    public String getDairport() {
            return dairport;
    }

    public void setDairport(String dairport) {
            this.dairport = dairport;
    }

    public String getAairport() {
            return aairport;
    }

    public void setAairport(String aairport) {  	
        this.aairport = aairport;
    }

   @Override
   public String toString() {
           return "Flight [id=" + id + ", destination=" + destination + ", capacity=" + capacity + ", occupied=" + occupied
                           + ", dairport=" + dairport + ", aairport=" + aairport + "]";
   }
}

