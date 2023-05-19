# Airlines Management System in C
A C Language based project on Airlines Management System.

# Introduction
The mini-project “Airlines Management System Project” is a console application using the C programming language. This project compiles in VSCode with the GCC compiler. In this console application, you can do basic passenger record tasks like adding the passenger information, view the added passengers, search the passengers, ..etc.
The notion of Airline Manangement is based on making and canceling flight bookings. Users may simply book flights, cancel reservations, and look up information. It has a variety of booking alternatives. This tiny project has fewer features, but they are the most important ones.

# Explanation
When it comes to the features of airline booking, the system requires information such as the Passenger's Name, Passport Number, and Email Address. A reservation is made once all of these steps have been completed. The system delivers a seat number as evidence of reservation. To check tickets, the user must first submit a seat number, after which the system will search the database for the appropriate tickets and provide the results. The technology makes canceling a flight reservation simple; the user only has to enter their Passport number and seat number.

### Structures:
- `Airlines`: Structure representing airline reservations, containing fields for passport number, name, destination, seat number, email, and a pointer to the next reservation.

### Functions:
- `details()`: Function to input passenger details such as passport number, name, email, and destination.
- `reserve(int x)`: Function to reserve a seat by creating a new reservation and storing passenger details.
- `savefile()`: Function to save the reservation details to a file named "AirlinesRecords".
- `display()`: Function to display all the reservation details.
- `cancel()`: Function to cancel a reservation based on the passport number provided.
- `main()`: The main function to run the Airlines Reservation System.

### Functionality:
- Reservation:
  - Allows users to reserve a seat by entering their passport number, name, email, and destination.
  - Assigns a unique seat number to each reservation.
- Cancellation:
  - Enables users to cancel a reservation by providing their passport number.
- Display Records:
  - Displays all the reservation details, including passport number, name, email, seat number, and destination.
- Saving Records:
  - Saves all the reservation details to a file named "AirlinesRecords" for future retrieval.

### Menu:
- The program presents a menu-driven interface to the user with the following options:
  1. Reservation
  2. Cancel
  3. Display Records
  4. Exit

### File Handling:
- The program uses file handling to save and load reservation details from the "AirlinesRecords" file.

Overall, the provided code implements a basic Airlines Reservation System in C, allowing users to reserve seats, cancel reservations, and display and save reservation details to a file.
Airline Booking was created with the help of the C programming language, as well as various variables and strings. The simplest method for airplane bookings is provided by this little project.
