package entities;

public class FlightBooking {

        private int id;
        private int flightId;
        private String name;
        private String destination;

        public FlightBooking(){}
        public FlightBooking(int id, int flightId, String name, String destination){
                this.setId(id);
                this.setFlightId(flightId);
                this.setName(name);
                this.setDestination(destination);
        }
        public int getId() {
                return id;
        }

        public void setId(int id) {
                this.id = id;
        }

        public int getFlightId() {
                return flightId;
        }

        public void setFlightId(int flightId) {
                this.flightId = flightId;
        }

        public String getName() {
                return name;
        }

        public void setName(String name) {
                this.name = name;
        }

        public String getDestination() {
                return destination;
        }

        public void setDestination(String destination) {
                this.destination = destination;
        }
}

