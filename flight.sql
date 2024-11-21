CREATE TABLE customer (
    customer_id NUMBER PRIMARY KEY,
    customer_name VARCHAR2(100) NOT NULL,
    customer_town VARCHAR2(100) NOT NULL
);

-- Airline Table
CREATE TABLE airline (
    airline_id NUMBER PRIMARY KEY,
    airline_name VARCHAR2(100) NOT NULL
);

-- Seat Table
CREATE TABLE seat (
    seat_id NUMBER PRIMARY KEY,
    seat_number VARCHAR2(10) NOT NULL,
    seat_price NUMBER NOT NULL
);

-- Meal Table
CREATE TABLE meal (
    meal_id NUMBER PRIMARY KEY,
    meal_name VARCHAR2(100) NOT NULL,
    price NUMBER NOT NULL
);

-- Booking Table
CREATE TABLE booking (
    booking_id NUMBER PRIMARY KEY,
    booking_number VARCHAR2(50) NOT NULL,
    flight_number VARCHAR2(50) NOT NULL,
    flight_date DATE NOT NULL,
    departure_time VARCHAR2(20) NOT NULL,
    arrival_time VARCHAR2(20) NOT NULL,
    departure_city VARCHAR2(100) NOT NULL,
    arrival_city VARCHAR2(100) NOT NULL,
    ticket_price NUMBER NOT NULL,
    seat_class VARCHAR2(20) NOT NULL,
    customer_id NUMBER NOT NULL,
    airline_id NUMBER NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
    FOREIGN KEY (airline_id) REFERENCES airline(airline_id)
);

commit;

-- Booking Seat Table
CREATE TABLE booking_seat (
    seat_id NUMBER,
    seat_number VARCHAR2(10) NOT NULL,
    price NUMBER NOT NULL,
    booking_id NUMBER NOT NULL,
    PRIMARY KEY (seat_id, booking_id),
    FOREIGN KEY (seat_id) REFERENCES seat(seat_id),
    FOREIGN KEY (booking_id) REFERENCES booking(booking_id)
);

-- Booking Meal Table
CREATE TABLE booking_meal (
    meal_id NUMBER,
    meal_name VARCHAR2(100) NOT NULL,
    price NUMBER NOT NULL,
    quantity NUMBER NOT NULL,
    amount NUMBER NOT NULL,
    booking_id NUMBER NOT NULL,
    PRIMARY KEY (meal_id, booking_id),
    FOREIGN KEY (meal_id) REFERENCES meal(meal_id),
    FOREIGN KEY (booking_id) REFERENCES booking(booking_id)
);


Insert into customer

INSERT INTO customer VALUES (1, 'Aravind', 'Chennai');
INSERT INTO customer VALUES (2, 'Aravind', 'Bangalore');

Insert into airline

INSERT INTO airline VALUES (1, 'Air India');
INSERT INTO airline VALUES (2, 'SpiceJet');

Insert into seat

INSERT INTO seat VALUES (1, '12A', 5000);
INSERT INTO seat VALUES (2, '12B', 5000);
INSERT INTO seat VALUES (3, '12C', 5000);
INSERT INTO seat VALUES (4, '1A', 8000);
INSERT INTO seat VALUES (5, '1B', 8000);

Insert into meal

INSERT INTO meal VALUES (1, 'Veg Meal', 300);
INSERT INTO meal VALUES (2, 'Chicken Meal', 500);
INSERT INTO meal VALUES (3, 'Coffee', 100);

Insert into booking
select * from booking;
desc booking;
INSERT INTO booking VALUES (2, 'B002', 'SG345', TO_DATE('2024-11-22', 'YYYY-MM-DD'), 
    '5:00 PM', '7:00 PM', 'Bangalore', 'Mumbai', 16000, 'Business', 2, 2);


INSERT INTO booking VALUES (1, 'B001', 'SG305', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 
    '4:00 PM', '8:00 PM', 'Bangalore', 'Kochi', 14000, 'Business', 1, 1);

Insert into booking_seat

INSERT INTO booking_seat VALUES (1, '12A', 5000, 1);
INSERT INTO booking_seat VALUES (2, '12B', 5000, 1);
INSERT INTO booking_seat VALUES (3, '12C', 5000, 1);
INSERT INTO booking_seat VALUES (4, '1A', 8000, 2);
INSERT INTO booking_seat VALUES (5, '1B', 8000, 2);

Insert into booking_meal

INSERT INTO booking_meal VALUES (1, 'Veg Meal', 300, 2, 600, 1);
INSERT INTO booking_meal VALUES (2, 'Chicken Meal', 500, 1, 500, 1);
INSERT INTO booking_meal VALUES (3, 'Coffee', 100, 3, 300, 1);

INSERT INTO booking_meal VALUES (1, 'Veg Meal', 300, 1, 300, 2);
INSERT INTO booking_meal VALUES (2, 'Chicken Meal', 500, 2, 1000, 2);



ALTER TABLE booking 
ADD (
    show_date_time DATE , 
    aadhaar_id VARCHAR2(12)
);



Step 2: Update Script




UPDATE booking

SET show_date_time = TO_DATE('20-Nov-2024 10:00 AM', 'DD-Mon-YYYY HH:MI AM'),
    aadhaar_id = '123456789012'
WHERE booking_id = 1;  -- Assuming booking_id = 1 for Flight AI102


UPDATE booking
SET show_date_time = TO_DATE('22-Nov-2024 05:00 PM', 'DD-Mon-YYYY HH:MI PM'),
    aadhaar_id = '123456789012'
WHERE booking_id = 2;  -- Assuming booking_id = 2 for Flight SG345



CREATE TABLE ticket (
    ticket_id NUMBER PRIMARY KEY,
    seat_number VARCHAR2(10),
    seat_price NUMBER
);

food Table

CREATE TABLE food (
    item_id NUMBER PRIMARY KEY,
    item_name VARCHAR2(50),
    price NUMBER
);

booking Table

CREATE TABLE booking_movie (
    booking_id NUMBER PRIMARY KEY,
    movie_name VARCHAR2(50),
    theatre_name VARCHAR2(50),
    number_of_tickets NUMBER,
    total_ticket_amount NUMBER,
    total_food_amount NUMBER,
    total_amount NUMBER,
    customer_id NUMBER
);

booking_ticket Table

CREATE TABLE booking_ticket (
    booking_ticket_id NUMBER PRIMARY KEY,
    booking_id NUMBER,
    ticket_id NUMBER,
    seat_number VARCHAR2(10),
    seat_price NUMBER,
    FOREIGN KEY (booking_id) REFERENCES booking_movie(booking_id),
    FOREIGN KEY (ticket_id) REFERENCES ticket(ticket_id)
);

booking_food Table

CREATE TABLE booking_food (
    booking_food_id NUMBER PRIMARY KEY,
    booking_id NUMBER,
    food_item_id NUMBER,
    quantity NUMBER,
    food_price NUMBER,
    total_amount NUMBER,
    FOREIGN KEY (booking_id) REFERENCES booking(booking_id),
    FOREIGN KEY (food_item_id) REFERENCES food(item_id)
);



-- Insert for the first booking (Rubber Ball movie at Star Theatre)
INSERT INTO booking_movie (
    booking_id, movie_name, theatre_name, 
    number_of_tickets, total_ticket_amount, 
    total_food_amount, total_amount, customer_id
)
VALUES (
    1, 'Rubber Ball', 'Star Theatre', 
    3, 360, 
    2*20 + 3*50,  -- food amount: 2 Samosas and 3 Popcorns
    360 + (2*20 + 3*50),  -- total amount: ticket + food
    101  -- customer_id
);

-- Insert for the second booking (Superhit Movie at CinemaWorld)
INSERT INTO booking_movie (
    booking_id, movie_name, theatre_name, 
    number_of_tickets, total_ticket_amount, 
    total_food_amount, total_amount, customer_id
)
VALUES (
    2, 'Superhit Movie', 'CinemaWorld', 
    2, 400, 
    100 + 2*50,  -- food amount: 1 Burger + 2 Soft Drinks
    2*400 + (100 + 2*50),  -- total amount: ticket + food
    102  -- customer_id
);

select * from booking_movie;

-- Insert food items into the food table if they are missing
INSERT INTO food (item_id, item_name, price) VALUES (1, 'Samosa', 20);   -- Food Item 1: Samosa
INSERT INTO food (item_id, item_name, price) VALUES (2, 'Popcorn', 50);  -- Food Item 2: Popcorn
INSERT INTO food (item_id, item_name, price) VALUES (3, 'Burger', 100);  -- Food Item 3: Burger
INSERT INTO food (item_id, item_name, price) VALUES (4, 'Soft Drink', 50); -- Food Item 4: Soft Drink






INSERT INTO booking_food (
    booking_food_id, booking_id, food_item_id, quantity, food_price, total_amount
)
VALUES (
    booking_food_seq.NEXTVAL, 1, 1, 2, 20, 40  -- 2 Samosas, Rs. 20 each, Total: Rs. 40
);



INSERT INTO booking_food (
    booking_food_id, booking_id, food_item_id, quantity, food_price, total_amount
)
VALUES (
    booking_food_seq.NEXTVAL, 1, 2, 3, 50, 150  -- 3 Popcorns, Rs. 50 each, Total: Rs. 150
);

-- Insert food for the second booking (Superhit Movie at CinemaWorld)
-- For 1 Burger (food_item_id = 3) and 2 Soft Drinks (food_item_id = 4)
INSERT INTO booking_food (
    booking_food_id, booking_id, food_item_id, quantity, food_price, total_amount
)
VALUES (
    booking_food_seq.NEXTVAL, 2, 3, 1, 100, 100  -- 1 Burger, Rs. 100, Total: Rs. 100
);

INSERT INTO booking_food (
    booking_food_id, booking_id, food_item_id, quantity, food_price, total_amount
)
VALUES (
    booking_food_seq.NEXTVAL, 2, 4, 2, 50, 100  -- 2 Soft Drinks, Rs. 50 each, Total: Rs. 100
);


-- Inserting data into the ticket table
INSERT INTO ticket (ticket_id, seat_number, seat_price) VALUES (1, 'A1', 100);
INSERT INTO ticket (ticket_id, seat_number, seat_price) VALUES (2, 'A2', 100);
INSERT INTO ticket (ticket_id, seat_number, seat_price) VALUES (3, 'B1', 120);
INSERT INTO ticket (ticket_id, seat_number, seat_price) VALUES (4, 'B2', 120);
INSERT INTO ticket (ticket_id, seat_number, seat_price) VALUES (5, 'C1', 150);
INSERT INTO ticket (ticket_id, seat_number, seat_price) VALUES (6, 'C2', 150);




-------------------------------------QUERIES------------------------


//Top Earning Theatres

SELECT 
    b.theatre_name,
    SUM(b.total_amount) AS total_earnings
FROM 
    booking_movie b
GROUP BY 
    b.theatre_name
ORDER BY 
    total_earnings DESC;



//Total Food Ordered for Each Booking

SELECT 
    b.booking_id,
    b.movie_name,
    SUM(bf.total_amount) AS total_food_expenses
FROM 
    booking_movie b
JOIN 
    booking_food bf ON b.booking_id = bf.booking_id
GROUP BY 
    b.booking_id, b.movie_name;




//Total Quantity of Each Food Item Sold

SELECT 
    f.item_name,
    SUM(bf.quantity) AS total_quantity_sold
FROM 
    food f
JOIN 
    booking_food bf ON f.item_id = bf.food_item_id
GROUP BY 
    f.item_name
ORDER BY 
    total_quantity_sold DESC;



//Highest Revenue Generating Movie

SELECT 
    movie_name
FROM 
    booking_movie
WHERE 
    total_amount = (SELECT MAX(total_amount) FROM booking);



