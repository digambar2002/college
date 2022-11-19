# Experiment No. 3
# Creating a sample database (Railway Management System) using any client server RDBMS package using SQL DDL queries. 
show databases;
create database RMS_2;
use RMS_2;
select database();
create table Passenger(P_ID int,
									P_name varchar(20),
                                    Age int,
                                    Gender char(10),
                                    Ticket_ID int,
                                    PNR int);
show tables;
desc Passenger;
alter table Passenger add constraint primary key(P_ID);
desc Passenger;

create table Ticket(PNR int, 
							 Ticket_ID int, 
                             Arrtime time, 
                             Deptime time, 
                             Trainno int, 
                             Tktamt int, 
                             Seat_no int, 
                             Reserve_status char(10));
show tables;
desc Ticket;
alter table Ticket add  constraint primary key(PNR);
desc Ticket;
alter table Passenger add constraint foreign key(PNR) references Ticket(PNR);
desc Passenger;
desc Ticket;

create table Train (Trainno int Primary key, 
							  Tname varchar(20), 
                              Type char(15), 
                              Class char(10), 
                              Status_ID int, 
                              Coach_ID varchar(10));
desc Train;
create table Trainstatus(Status_ID int, 
									  Trainno int, 
                                      PNR int, 
                                      Arrtime time, 
                                      Deptime time,
                                      Stncode char(10));
alter table Trainstatus add constraint primary key(Status_ID);
desc Trainstatus;

create table Route(Route_ID int, 
							 Arrtime time, 
                             Deptime time,
                             Trainno int, 
                             Srcstn char(10),
                             Deststn char(10));
alter table Route add constraint primary key(Route_ID);
desc Route;

create table Seatavailability (Coach_ID varchar(10),
											Trainno int, 
                                            Type varchar(10), 
                                            wait char(10), 
                                            avail char(10));
alter table Seatavailability add constraint primary key(Coach_ID);
desc Seatavailability;

create table Station (Stncode char(10), 
								Stn_Name varchar(15), 
                                Pltfno int);
alter table Station add constraint primary key(Stncode);
desc Station;

desc Trainstatus;
alter table Trainstatus change column Trainno Trainno int not null;
alter table Trainstatus change column Stncode Stncode char(10) not null;
desc Trainstatus;

alter table Seatavailability add constraint unique key(Type);
desc Seatavailability;

alter table Ticket add constraint chkamt check(Tktamt>0);
desc Ticket;
