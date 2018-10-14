##  author: Peng Tian Xiang 
##  student NO:201730683314
##  e-mail: 1070280566@qq.com
##  development environment:Ubuntu 18


##This is the documentation of the Car Management Program.


##File Organization
##
##
--CarDatabase.txt:
        This file record all information of all cars added from user console.
     Every time the program begin running,it will read this file to memory for
     user query. And to simplify database updating, I decide to rewrite this file
     every time the program normally exiting, though seems clumsy. In case that 
     the program terminates wrongly, I prepare another file as the back-up file.

--CarDatabase.txt.swap:
        This is the back-up of CarDatabase.txt.

--Interface.h: 
        This file defines a Interface class which controls the Word User Interface
    (I call it WUI) and the Car LList generated every time the programm begins running
    from CarDatabase.txt. Also here I define some error handing and input handing 
    methods.

--Interface.cpp:
        This file contains all implementation of the methods in Interface class. 

--Car.h Car.cpp:
        These define the Car class and a Date structure. 
        A car contains the following attributes:
            --hash 
                    The hash code generated when a car object is created automatically
                to identify a car, which is normally used when updating , deleting or 
                searching a car.
            --band:string
                    The band of the car. 
            --model:string
                    The model of the car.
            --color:string
                    The color of the car.
            --license:string
                    The license of the car.
            --producedTime:Date
                    Time the car is produced.
        A date contains the following attributes:
            --year:int
                    The year of the date.
            --month:int
                    The month of the date.
            --day:int 
                    The day of the date.

--config.h global.h:
        In config.h some independent variables and macros are defined. 
    Such as the database file path and some error macro.Also some typedefs 
    are defined here.
        In global.h some dependent vairiales are defined such as some variable
    of interface class,which has to depend on Interface.h.

--Hash.h:
        Here a Hash class is defined, which provides a method to generate 
    a variable-length hash code.

--List.h LList.h:
        List.h defines a virtual base class List for LList.h.
        LList.h defines a Link-Based List inherited from List.

--main.cpp
        The entrance of the program.

--makefie
    --default 
            Directly try to compile the files.
    --clean 
            Clean generated binary file.
    --record
            Compile the files and redirect the error message to error.log

--error.log
        If in some cases there is so much wrong message,I will redirect the 
    information to this file to analyse them carefully. 
