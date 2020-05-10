exe : Test1.cpp Test2.cpp Test3.cpp Person.o Employee.o Student.o Account.o CurrentAccount.o SavingsAccount.o Bank.o Quaternion.o Complex.o
	g++ Test1.cpp Person.o Employee.o Student.o -o test1 
	g++ Test2.cpp Account.o CurrentAccount.o SavingsAccount.o Bank.o -o test2
	g++ Test3.cpp Quaternion.o Complex.o -o test3

Account.o : Account.cpp
	g++ -c Account.cpp

Bank.o : Bank.cpp
	g++ -c Bank.cpp

Complex.o : Complex.cpp
	g++ -c Complex.cpp

CurrentAccount.o : CurrentAccount.cpp
	g++ -c CurrentAccount.cpp

Employee.o : Employee.cpp
	g++ -c Employee.cpp

Person.o : Person.cpp
	g++ -c Person.cpp

Quaternion.o : Quaternion.cpp
	g++ -c Quaternion.cpp

SavingsAccount.o : SavingsAccount.cpp
	g++ -c SavingsAccount.cpp

Student.o : Student.cpp
	g++ -c Student.cpp