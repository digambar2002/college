# Experiment No. 4
# SQL DML queries: Use of SQL DML queries to retrieve, insert, delete and update the database.

show databases;
use RMS_2;
select database();
desc Ticket;
select * from Ticket;

# Inserting Records
insert into Ticket values(308123905,596,'20:04:15','20:07:19',21673,420,70,'CNF');
insert into Ticket values(1265577771,136,'12:47:10','12:50:10',22154,376,15,'CNF');
insert into Ticket values(1975364587,245,'07:40:15','07:45:58',19134,298,63,'CNF');
insert into Ticket values(2110755678,169,'16:20:38','16:24:34',27139,380,37,'CNF');
insert into Ticket values(2120017791,101,'04:35:10','04:40:10',12139,289,12,'CNF');
select * from Ticket;

insert into Passenger values(201,'John',21,'Male',596,308123905);
insert into Passenger values(217,'Mark',24,'Male',136,1265577771);
insert into Passenger values(239,'Alice',29,'Female',245,1975364587);
insert into Passenger values(340,'Jenny',32,'Female',169,2110755678);
insert into Passenger values(367,'Tony',24,'Male',101,2120017791);
select * from Passenger;

insert into Train values(11071, 'Kamyani Express','Superfast', 'Sleeper', 233, 'S2');
insert into Train values(12178, 'Gitanjali Express','Superfast', 'Sleeper', 193, 'S7');
insert into Train values(12124, 'Rajdhani Express','Express', 'AC', 233, 'A1');
insert into Train values(21353, 'Pungab Mail','Superfast', 'AC', 193, 'A2');
insert into Train values(12139, 'Sewagram Express','Express', 'Sleeper', 255, 'S5');
select * from train;

# Retreival 
select * from Passenger;
select P_ID,P_name 
from Passenger 
where Gender='Male';
select P_ID,P_name 
from Passenger 
where Gender='Female';
select P_ID,P_name, age 
from Passenger 
where Age between 25 and 35;
select P_ID,P_name, Age 
from Passenger 
where Age < 24 and Gender='Male' ;
select * from Passenger;

# use of distinct clause
select Age 
from Passenger;
select distinct Age 
from Passenger;
select P_name, Age 
from Passenger;
select distinct P_name, Age 
from Passenger;

# use of order by clause
select * 
from Passenger;
select * 
from Passenger 
order by Age;
select * 
from Passenger 
order by Age asc;
select * 
from Passenger 
order by Age desc;
select * 
from Passenger 
order by Age asc, P_ID desc;

# use of between operator
select * 
from Passenger 
where Age between 25 and 35;

# use of like operator
select * 
from Passenger 
where Gender like 'M%';
select * 
from Passenger 
where Gender like 'F%';

# use of IN operator
select * 
from ticket;
select * 
from ticket 
where Trainno in(21673,12139, 19134);

# use of is null 
select * 
from ticket 
where Ticket_ID is null;
select * 
from ticket 
where Ticket_ID is not null;

# Update 
select * from Passenger;
update Passenger 
set P_name='Barry' 
where P_ID=201;
update Passenger set P_name='Natasha' where P_ID=340;
select * from Passenger;

# Deletion
insert into Ticket values(2146865786,199,'11:20:38','11:24:34',29123,478,65,'CNF');
select * from Ticket;
insert into Passenger values(822,'Pepper',28,'Female',543,2146865786);
select * from Passenger;
delete from Passenger where P_ID=822;
select * from Passenger;



