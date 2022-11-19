# Experiment No. 7 (B-01) 
# Write a program to demonstrate different types of JOIN.

create table Ticket1 (PNR int Primary key,
								Ticket_ID int,
								Trainno int);
create table Train1 (Trainno int Primary key,
								Tname varchar(50));
show tables;

insert into Ticket1 values(123456,110,12139);
insert into Ticket1 values(123478,115,12465);
insert into Ticket1 values(213445,415,21987);
select * from Ticket1;

insert into Train1 values(12139,'Sewagram Exp');
insert into Train1 values(12465,'Kamakhya Exp');
insert into Train1 values(11078,'Gorakhpur Exp');
select * from Train1;

# Equi join
select * 
from Ticket1, Train1
where Ticket1.Trainno = Train1.Trainno;

# join-on
select *
from Ticket1
inner join Train1
on Ticket1.Trainno = Train1.Trainno;

select *
from Ticket1
join Train1
on Ticket1.Trainno = Train1.Trainno;

# Natural join
select *
from Ticket1
natural join Train1;

# left join
select * 
from Ticket1 
left join Train1 
on Ticket1.Trainno = Train1.Trainno;

# Right join
select * 
from Ticket1 
right join Train1 
on Ticket1.Trainno = Train1.Trainno;

# Full join
select * 
from Ticket1 
left join Train1 
on Ticket1.Trainno = Train1.Trainno
union
select * 
from Ticket1 
right join Train1 
on Ticket1.Trainno = Train1.Trainno;





