[POC] 1, 1.1, 1.2, 1.2.1
Application [1] [POC]
    ::Driver Registration::
    ::Login:: 

    ::Driver Registration:: [1.1][POC] 
        - page title
        - form : name, password, email, phone, 
                 car_number, car_model, car_type 
            - fields: (caption, error message(s))
                name {required}
                password {required, strength}
                email {required, isEmail, isExist}
                phone {required, 10-digits isPhoneNumber, isExist}
                car_number {required, isExist}
                car_model {required}
                car_type {selectable}
        - on form submit: 
            - allow to edit field / group of fields !XXX
            - OR Confirm  
            - OR Exit  
        - after form submit:
            - successful message 
                "Driver named Minhaj registered successfully"
    ::Login:: [1.2] [POC]
        - page title
        - form : username, password (caption, error message(s))
            - fields 
                username {required}
                password {required}
            - on form submit 
                - Logging Into App 
                OR
                - Invalid Username / Password message.
            - after form submit: 
                - successful message welcoming the user
                    "Successfully logged in, welcome Minhaj"
                - DISPATCH / ROUTE to the page 
        ::Driver Page::
            ::Home Page:: [1.2.1] [POC]
                - page title
                Welcome minhaj!
                Car: TN48 Z1020, Innova, SUV, Parking:[10-Feb-2025 10:00-21:00, Spot: GR-001 / Not Parked]
                Reservation History ![last 10 - sort by date desc]
                    Date    Start Time      End Time    Amount 
                Nav Pages: 
                    [1] View/Edit Profile [2] Do Reservation / [3] Pay and Unpark 
                    [4] Change Password 
                    [99] Logout 
            ::Do Reservation:: [1.2.1.2] 
                - page title
                Welcome minhaj!
                Car: TN48 Z1020, Innova, SUV, Parking: Not Parked
                 - form : date, start_time, end_time
                    - fields 
                        date {required, isDate}
                        start_time {required, isTime}
                        end_time {required, isTime}
                    - on form submit: 
                        - allow to edit field / group of fields !XXX
                        - OR Confirm  
                        - OR Exit  
                    - after form submit:
                        - parking spot is allocated
                        - successful message 
                            "Reservation successful, spot GR-001 reserved under the name Minhaj"
                            - booking number is generated
            ::Pay and Unpark:: [1.2.1.3]
                - page title
                Welcome minhaj!
                Car: TN48 Z1020, Innova, SUV, Parking:10-Feb-2025 10:00-21:00, Spot: GR-001
                 - form : pay_mode 
                    - fields                        
                        actual_end_time {required, isTime} !!!{display <systetime>}
                        duration {display <calculated>}
                        amount  {display <calculated>}
                        pay_mode {selectable}
                    - on form submit: 
                        - OR Confirm  
                        - OR Exit  
                    - after form submit:
                        - successful message 
                            "Unparking successful, Thank you Minhaj for using our service"
                            - payment receipt number is generated
            ::Driver Profile:: [1.2.1.1]
                - page title
                - form : name, email, phone, 
                        car_number, car_model, car_type !!if no parking history 
                    - fields: (caption, error message(s))
                        name {required}
                        email {required, isEmail, isExist}
                        phone {required, 10-digits isPhoneNumber, isExist}
                        car_number {required, isExist}
                        car_model {required}
                        car_type {selectable}
                - on form submit: 
                    - allow to edit field / group of fields !XXX
                    - OR Confirm  
                    - OR Exit  
                - after form submit:
                    - successful message 
                        "Profile updated successfully"
            ::Change Password:: [1.2.1.4]
                - page title
                - form : old_password, new_password
                    - fields: (caption, error message(s))
                        old_password {required}
                        new_password {required, strength}
                - on form submit: 
                    - OR Confirm  
                    - OR Exit  
                - after form submit:
                    - successful message 
                        "Password changed successfully"
                        - logout 
        ::Admin Page::
            ::Home Page:: [1.2.2]
                - page title
                Welcome Minhaj! 
             -Nav Pages: 
                    [1] Admins Management [2] Floor Management [3] Spot Management 
                    [4] Bookings History [5] Payments History
                    [99] Logout 
            ::Admins Management:: [1.2.2.1]
                -Nav Pages: 
                        [1] Create [2] Edit [3] Display [4] Delete
                        [5] Change Password 
                        [99] Exit 
                ::Create Admin:: [1.2.2.1.1]
                    - page title
                    - form : name, email, phone, password, role
                        - fields: (caption, error message(s))
                            name {required}
                            password {required, strength}
                            email {required, isEmail, isExist}
                            phone {required, 10-digits isPhoneNumber, isExist}
                    - on form submit: 
                    - allow to edit field / group of fields !XXX
                    - OR Confirm  
                    - OR Exit  
                    - after form submit:
                        - successful message 
                            "Admin Minhaj is created successfully"
                ::Edit Admin:: [1.2.2.1.2]
                    -page title 
                    Search by phone number:
                        phone {required, 10-digits isPhoneNumber, isExist}
                    -form : name, email, phone, role, new name, new email, new phone, new role
                    - fields: (caption, error message(s))
                            - if exist
                            name {display}
                            email {display}
                            phone {display}
                            role {display}
                            - edit
                            new name {required}
                            new email {required, isEmail, isExist}
                            new phone {required, 10-digits isPhoneNumber, isExist}
                            new role {required}
                    - on form submit:
                        - OR Confirm  
                        - OR Exit 
                    - after form submit:
                        - successful message 
                            "Updated the details successfully"
                ::Delete Admin:: [1.2.2.1.4]
                    -page title 
                     Search by phone number:
                        phone {required, 10-digits isPhoneNumber, isExist}
                    -form : name, email, phone, role
                    - fields: (caption, error message(s))
                            - if exist
                            name {display}
                            email {display}
                            phone {display}
                            role {display}
                    - on form submit:
                        - OR Confirm  
                        - OR Exit 
                    - after form submit:
                        - successful message
                            "Admin deleted successfully"
                ::Display all admin:: [1.2.2.1.3]
                       Name       Email                Phone          Role
                       -------    ---------           -------        -----------
                        Minhaj     minhaj@gmail.com    9867453289     Admin
                        Sana       sana@gmail.com      8976234589     Admin
                ::Exit:: 
                ::Change Password:: [1.2.2.1.5]
                    - page title
                    - form : old_password, new_password
                        - fields: (caption, error message(s))
                            old_password {required}
                            new_password {required, strength}
                    - on form submit: 
                        - OR Confirm  
                        - OR Exit  
                    - after form submit:
                        - successful message
                            "Password changed successfully"
                ::Exit::
            ::Floor Management:: [1.2.2.2]
                ::Home Page:: 
                    -page title
                    -Nav Pages:
                        [1] Create [2] Edit [3] Search [4] Delete 
                        [5] Display Spots Availability
                        [99] Exit
                ::Create Floor ::[1.2.2.2.1]
                    form : floor number
                    fields : (caption, error message(s))
                        -floor number{required , isExist}
                    -on form submit:
                        -OR Confirm
                        -OR Exit
                    -after form submit:
                        - successful message
                            "Floor GR-001 created successfully"
                ::Edit Floor:: [1.2.2.2.2]
                      -form : floor number, new floor number
                        -fields:
                            -floor number{required , isExist}
                            -new floor number{required , isexist}
                        -on form submit:
                            -OR Confirm
                            -OR Exit
                        -after form submit:
                            - successful message
                                "Floor number updated successfully"
                ::Search Floor::  [1.2.2.2.3]
                    -fields:
                    -Search by floor number{required , isExist}
                    --------------------------------------------------------------
                    Floor id             Spot id
                    --------------------------------------------------------------
                    BS1        BS1-S001    BS1-S002    BS1-S003   BS1-S004  BS1-S00
                    ---------------------------------------------------------------

                :: Delete Floor ::  [1.2.2.2.4]
                      -form : floor number
                        -fields:
                            -Search by floor Number{required , isExist}
                        -on form submit:
                            -OR Confirm
                            -OR Exit
                        -after form submit:
                            - successful message
                                "Floor GR-001 deleted successfully"
                ::Display Spots Availability::  [1.2.2.2.5]
                    -form : floor number
                    -fields:
                        -floor number {required , isExist} 
                            Floor id                    Available Spot id
                            ----------------------------------------------------------------
                            BS1        BS1-S001    BS1-S002    BS1-S003   BS1-S004  BS1-S005
                            GR1        GR1-S001    GR1-S002    GR1-S001   GR1-S001  GR1-S005
                            GR2        GR2-S001    GR2-S002    GR2-S003   GR2-S004  GR2-S005 

                ::Exit:: 
            ::Spot Management:: [1.2.2.3] 
                ::Home Page:: [1.2.2.3]
                    -page title
                    -Nav Pages: 
                        [1] Create [2] Edit [3] Search [4] Delete 
                        [99] Exit  
               ::Create Spot::  [1.2.2.3.1]
                    - form : Floor number, Spot id, Spot Charge per hr($),  Availability of spot
                    - fields: Floor number: {required }
                            Spot id: {required} 
                            Spot Charge per hr($): {required}
                            Availability of spot
                     - ON form submit: 
                        - allow to edit field / group of fields !XXX
                        - OR Confirm  
                        - OR Exit 
                     - after form submit:
                        -successful message 
                            "Spot S001 created successfully"
               ::Edit Spot::  [1.2.2.3.2]
                     - form : Spot id, New spot id
                       - fields: Spot id: {required}
                                New spot id:{required}
                        - ON form submit: 
                            - OR Confirm  
                            - OR Exit 
                     - after form submit:
                        -successful message 
                            "Updated the spot id successfully"
               ::Delete Spot:: [1.2.2.3.3]
                    form : Spot id
                      - fields: Spot id: {required }
                     - ON form submit: 
                         - OR Confirm  
                         - OR Exit 
                     - after form submit:
                        -successful message 
                            "Spot S001 deleted successfully"
               ::Display all Spot:: [1.2.2.3.4]
                       Floor id      Spot        Charge      Status
                       ---------    ---------     -------   -----------
                        BS          BS-S001       10$        available
                        GR          GR-S002       10$        available
                        GR          GR-S003       10$        available

               ::Exit:: [1.2.2.3.5]
             ::Bookings History:: [1.2.2.4]
                    ::Today Bookings:: 
                        -----------------------------------------------------------------------------
                        |Time       |Car               |Driver       |Parking                       |
                        -----------------------------------------------------------------------------
                         10:00       TN 45 Z1020        Minhaj       GR-001 10:00-21:00
                         06:00       TN 45 Z1020        Babu         GR-001 03:00-05:00

                    ::Bookings By Date::
                        - page title
                        - form : date
                        - fields: (caption, error message)
                            date {required}
                        - on form submit:
                        --------------------------------------------------------------------------
                        |Time       |Car             |Driver      |Parking                       |
                        --------------------------------------------------------------------------
                         10:00       TN 45 Z1020      Minhaj       GR-001  10:00-21:00
                         07:00       TN 45 Z1020      Minhaj       GR-001  03:00-05:00
                         10:00       TN 45 Z1020      Minhaj       GR-001  10:00-21:00
                         07:00       TN 45 Z1020      Minhaj       GR-001  07:00-09:00

                    ::Exit::  
                        Go to Admin Page.
            ::Payments History:: [1.2.2.5]
                    ::Today Payments::
                        ----------------------------------------------------------------------
                        |Time       |Car                |Driver      |Parking     |Amount    |
                        ----------------------------------------------------------------------
                         10:00       TN  45 Z1020        Minhaj       GR-001       1000   

                    ::Payments By Date::
                        - page title
                        - form : date
                        - fields: (caption, error message)
                            date {required}
                        - on form submit:
                        ----------------------------------------------------------------------
                        |Time       |Car                |Driver      |Parking     |Amount    |
                        ----------------------------------------------------------------------
                         10:00       TN  45 Z1020        Minhaj       GR-001       1000
                         10:00       TN  45 Z1020        Minhaj       GR-001       800

                    ::Exit::
            Return to Admin page 

    
