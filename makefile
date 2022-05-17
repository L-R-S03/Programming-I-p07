#p07.cpp               File p07.cpp reads in the needed entered information from the user
                        #computations and uses other classes to conduct the amortization schedule

#Date07.h              File Date07.h defines class Date

#Date07.cpp            File Date07.cpp contains the implementation of member functions in class Date

#Amortization07.h      File Amortization07.h defines class Amortization

#Amortization07.cpp    File Amortization07.cpp contains the implementation of member functions in class
#                      Amortization

#p07make               File p07make contains instructions that compile and link the files of project p07
#-------------------------------------------------------------------------------------------------------
#object files
#--------------------------------------------------------------------------------------------------
obj     =       p07.o Amortization07.o Date07.o
#-------------------------------------------------------------------------------------------------
#Create executable file p07
#-------------------------------------------------------------------------------------------------
p07:    $(obj)
        g++ -o p07 $(obj) -lm
#-------------------------------------------------------------------------------------------------
#Create p07.o
#------------------------------------------------------------------------------------------------
p07.o:  p07.cpp Amortization07.h Date07.h
        g++ -c -g p07.cpp
#------------------------------------------------------------------------------------------------
#Create Amortization07.o
#------------------------------------------------------------------------------------------------
Amortization07.o:       Amortization07.cpp Amortization07.h
                        g++ -c -g Amortization07.cpp
#-------------------------------------------------------------------------------------------------
#Create Date07.o
#------------------------------------------------------------------------------------------------
Date07.o:       Date07.cpp Date07.h
                	g++ -c -g Date07.cpp

