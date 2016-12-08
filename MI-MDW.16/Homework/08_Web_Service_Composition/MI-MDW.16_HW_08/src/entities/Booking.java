package entities;

import java.io.Serializable;

public class Booking implements Serializable{

		private static final long serialVersionUID = 1L;		
		private String type;
        private String name;
        private String destination;

        Booking(){}
        Booking(String type, String name, String destination){
                this.setType(type);
                this.setName(name);
                this.setDestination(destination);
        }
        public String getType() {
                return type;
        }
        public void setType(String type) {
                this.type = type;
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
        @Override
		public String toString() {
			return "Booking [type=" + type + ", name=" + name + ", destination=" + destination + "]";
		}
}

