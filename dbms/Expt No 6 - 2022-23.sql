# Experiment No. 6
# SQL Queries: The queries should involve Set Operations and Set Comparisons.

use RMS_2;
select database();
select * from Ticket;
select * from Passenger;
select * from Train;

# Set Operations:- Union
select PNR from Passenger 
union
select PNR from Ticket;
select PNR from Passenger 
union all
select PNR from Ticket;
select PNR from Passenger 
union all
select PNR from Ticket
order by PNR desc;

# Set Operations:- Intersect
select *
from Passenger;
select Passenger.P_name, Ticket.Tktamt
from Passenger
join ticket
on Passenger.PNR = Ticket.PNR;

# join on
select Train.Trainno,Tname
from Ticket join Train 
on Train.Trainno = Ticket.Trainno;

# left join
select Ticket.Trainno,Tname
from Ticket  
left join Train 
on Train.Trainno=Ticket.Trainno;

# Right join
select Train.Trainno,Tname
from Ticket  
right join Train 
on Train.Trainno=Ticket.Trainno;

# Set comparison
select P_name, Age 
from Passenger 
where Age > some
							(select Age 
                            from Passenger 
                            where Gender='Male');

select P_name, Age
from Passenger 
where Age > any
							(select Age 
                            from Passenger 
                            where Gender='Male');
select P_name, Age 
from Passenger 
where Age > all
						(select Age 
                        from Passenger 
                        where Gender='Male');
	
# Set Membership - IN, NOT IN
select * 
from Train
where Class in('Sleeper');
select * 
from Train
where Class not in('Sleeper');
select * 
from Train
where Class in('Sleeper', 'AC');
