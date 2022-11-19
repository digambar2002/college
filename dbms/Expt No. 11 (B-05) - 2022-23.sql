# Expt No. 11 (B-05)
# To understand the concepts of stored Procedures.

use RMS_2;
select database();
select * from Passenger;

# Create Procedure P1:-
delimiter $$
create procedure P1()
begin
	select * from Passenger;
end $$
delimiter ;
select * from Passenger;
call P1();    

# Create Procedure P2:-
delimiter $$
create procedure P2(in gnd char(10))
begin
    select * from Passenger
    where Gender=gnd;
end $$
delimiter ;
call P2 ('Male');
call P2 ('Female');

# Proceure P3 for Insert the records:-
delimiter $$
create procedure P3(in a int, in b varchar(20), in c int, in d char(10), in e int, in f int)
begin
	insert into Passenger values(a,b,c,d,e,f);   #inserting records 
end $$
delimiter ;
call P3(999,'Galvin',28,'Male',465,1975364587);   # record is inserted
select * from Passenger;

# Procedure P4 for Updating the records:-
delimiter $$
create procedure P4(in a int, in b varchar(20), in c int, in d char(10), in e int, in f int)
begin
	update Passenger
	set P_ID=a,P_name=b,Age=c,Gender=d,Ticket_ID=e,PNR=f
	where P_ID=a;
end $$
delimiter ;
call P4(999,'Godbole',58,'Mmale',865,1975364587);
select * from Passenger;

# Procedure P5 for deleting the record:-
delimiter $$
create procedure P5(in a int)
begin
    delete from Passenger
    where P_ID=a;
end $$
delimiter ;
call P5(999);
select * from Passenger;





