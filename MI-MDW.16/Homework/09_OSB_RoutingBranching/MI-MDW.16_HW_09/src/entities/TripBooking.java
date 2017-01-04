package entities;


public class TripBooking {

        private int id;
        private int tripId;
        private String name;
        private String destination;

        public TripBooking(){}
        public TripBooking(int id, int tripId, String name, String destination){
                this.setId(id);
                this.setTripId(tripId);
                this.setName(name);
                this.setDestination(destination);
        }
        public int getId() {
                return id;
        }
        public void setId(int id) {
                this.id = id;
        }
        public int getTripId() {
                return tripId;
        }
        public void setTripId(int tripId) {
                this.tripId = tripId;
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
