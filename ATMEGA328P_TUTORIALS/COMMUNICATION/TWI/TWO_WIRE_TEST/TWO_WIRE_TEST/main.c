/*
 * TWO_WIRE_TEST.c
 *
 * Created: 05-09-2019 10:49:46
 * Author : [Developer]
 */ 
/****************NOTES*************/
/*
-using twi we could interconnect 128 devices into a cntrllr using two lines sda(for data),scl(for clock)
-we need a pull_up resistor on each lines(sda,scl) 
MASTER initiates transmission and generation of clock,
MASTER sends the START and STOP, b/w this a bus is considered busy.(Repeated trnsfer occurs when b/w this Start and Stop a start condition is again initiated
9 bit packets are passed via twi(always),(r/w bit-1 for read:0 for write, adrss bit, ack bit),when a slaves is adrssd it pullsthe SDA low in ack bit
general call is calling all the slaves, pulling all the SDA lines low by slaves.
The slave can extend the SCL line low, for more processing time or if the master clock is too fast to the slave.

It supports multi master system, but at the time of transmission, only one master takes control of the twi data bus, so when a master
takes control of the bus, the other masterm must be turned to slave to check if it is beig ADDRESSd by the mastr.

instead of using pull ups in sda,scl lines we could also enable internal pullups on that 2 pins by port,that is also applicable.
 the period of scl can be controlled by TWBR and TWSR(prescalar) in master mode, slave doesnt depend upon this.
 clockfq in slave shuld be 16times higher than SCL fq.
 eqn: scl_fq=     F_CPU / (16+2(vaue of TWBR).(prescalar value)
 TWDR contains ADDRESS or data, 












/*****************CODES****************/
#include <avr/io.h>


int main(void)
{
    
    while (1) 
    {
    }
}

