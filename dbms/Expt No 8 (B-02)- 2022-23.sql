#Expt No. 6 (B-02)
# Write a program to demonstrate use of Trigger.

#Suppose, we have a database named ‘college_db800’ which consists of some triggers used in the existing tables. 
#Let us create a trigger for the table Emp_data in the database having fields Emp_ID, Emp_Name & 
#Emp_Salary with some records inserted as follows

show databases;
create database college_db800;
use college_db800;
select database();

create table Emp_data (Emp_ID int not null,
									Emp_Name varchar(30) not null,
									Emp_Salary varchar(30) not null,
									primary key (Emp_ID));

INSERT INTO Emp_data VALUES(10, 'Rita','5000'),
													 (11, 'Sahil','7500'),
													 (12, 'Rekha','4800'),
													 (13, 'Nikhil','7300');
select * from Emp_data;

#create another table to save the logs/message when triggers are called for query events.
CREATE TABLE Emp_logs ( Info_Update VARCHAR(255));
show tables;

#let us create a trigger first, to show the trigger procedure using the following query:
delimiter $$
CREATE TRIGGER emp_updates AFTER UPDATE 
ON Emp_data FOR EACH ROW
BEGIN
	INSERT into Emp_logs VALUES (CONCAT('Old Salary (',OLD.Emp_ID,' ',OLD.Emp_Name,' ',OLD.Emp_Salary,') 
    to New Salary (',NEW.Emp_ID,' ',NEW.Emp_Name,' ',NEW.Emp_Salary,')'));
END$$
DELIMITER ;
show triggers ;

# After the emp_updates trigger is produced, then it will be often triggered whenever an update event 
# is queried for every row in the emp_data table.
# i.e., when you update any value in the Emp_Salary column then, a new row will be 
# inserted to the emp_logs table to list the changes finished.

UPDATE Emp_data 
SET Emp_Salary = Emp_Salary + 1000 
WHERE Emp_Salary<5000; # run at shell
select * from Emp_data;

 # Again, look at Emp_logs table and check the transformation effect of AFTER UPDATE trigger 
 # using the following query.
 SELECT * FROM Emp_logs;
 
 # Other example of trigger ----Before Insert
 create table instructor1000(inst_id int,
											salary Decimal(10,2));
 show tables;
 
 delimiter $$
 create trigger trigger_BI before insert 
 on instructor1000 for each row
 begin
 set new.salary=new.salary/12;
 end $$
 delimiter ;
 
 show triggers;
 insert into instructor1000 values(201,60000),
													(219,48000),
                                                    (240,74000);
 select * from instructor1000;
 