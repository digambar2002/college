# Experiment No. 5
# SQL Queries: The queries should involve SQL feature such as aggregate functions,
# group by clause, having clause, order by clause

use RMS_2;
select database();

#Aggregate functions:-
select * from ticket;
select avg(Tktamt) 
from Ticket;
select avg(Tktamt) as Avg_Tkt_Amt 
from Ticket;
select min(Tktamt)
from Ticket;
select max(Tktamt)
from Ticket;
select sum(Tktamt) as Total_Amt 
from Ticket;
select count(P_ID) as No_Of_Passengers 
from Passenger;

# use of logical conditions
select * from passenger;
select * 
from Passenger
where Age between 20 and 22 AND Gender='Male';
select * 
from Passenger
where Age between 20 and 30
AND(Gender='Male' OR Gender='Female');

# use of order by clause
select * 
from Passenger 
order by P_name;
select * 
from Passenger 
order by P_name desc;
select * 
from Passenger 
order by Gender asc;
select * 
from Passenger 
order by Gender asc, P_ID desc;

# use of Grpoup by clause
select * 
from Passenger;
select Gender,avg(Age) f
from Passenger 
group by Gender;
select Gender,count(P_ID) as No_Of_Passengers 
from Passenger 
group by Gender;

# use of having clause
select Gender,avg(Age) as Avg_Age 
from Passenger 
group by Gender 
having Avg_Age >20;

select Passenger.Gender,avg(Ticket.Tktamt)as Avg_Amt 
from Ticket 
join Passenger       # you can use inner join
on Ticket.PNR=Passenger.PNR
group by Gender
having avg(Tktamt)>350;
