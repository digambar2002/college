# Expt No. 10 (B-04)
# To understand the concepts of stored Functions.

use RMS_2;
select database();

select * from Passenger;
# Use of Stored function
delimiter $$
create function agelevel1(p_agelimit double)
returns varchar(10)
deterministic
begin
declare lvl varchar(10);
if p_agelimit>30
    then set lvl='TYPE1';
elseif(p_agelimit <=30 and p_agelimit>=25)
	then set lvl='TYPE2';
elseif p_agelimit<25
    then set lvl='TYPE3';
end if;
return(lvl);
end $$
delimiter ;
show function status;
select * 
from passenger;
select P_Name, agelevel1(Age) 
from Passenger;

# Even - odd
# Display 0 for EVEN and 1 for ODD
delimiter $$
create function isodd5(input_number int)
returns int
deterministic
begin
declare v_isodd int;
if mod(input_number,2)=0 then
set v_isodd=FALSE;   # 0 - Even, 1 - Odd
else
set v_isodd=TRUE;
end if;
return(v_isodd);
end $$
delimiter ;

select * from Passenger;
select P_name,isodd5(P_ID) from Passenger;
select P_name,isodd5(PNR) from Passenger;
select P_name,isodd5(Age) from Passenger;
select P_name,isodd5(Ticket_ID) from Passenger;