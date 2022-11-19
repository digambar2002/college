# Expt No. 9 (B-03)
# Write a program to demonstrate view.

# View creation:-
use RMS_2;
select * from Passenger;
select * from Ticket;
# creating a view V2
create view v2 as
select * from Passenger
where Age>25;
select * from V2;

select * 
from Passenger;
insert into V2 values(688,'Korth',31,'Male',370,2120017791);
select * from V2;
select * from Passenger;

# updation
update v2        
set Age=39
where P_name='Alice';
select * from V2;
select * from Passenger;

#deletion
delete from V2
where P_name='Korth';
select * from V2;
select * from Passenger;
