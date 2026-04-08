/*
SVC HABDLER CONVERTS THE APPLICATION TASK TO THE PRIVILAGED ONES,
FOR THAT WE DOESNT DEPENT ON OS, ONLY NEEDED IS THE SVC NUMBER,
HERE 0X00,01,02,03 ETC ARE THE SVC NUMBERS.THIS NUBERS SHOULDBE CONTINUS, THUS 0,1,2,3 ..




SVC HANDLER RUN THE SVC SERVICES WITH THE ORDER AS PER THE SVC NUMBER
FROM PC WE READ THE DATA NEEDED,
FOR THAT WHEN THE EXCEPTION IS CALLED, THE LINK REG STORES THE CURRRENT RUNNING CONTEXT(DATA),
IT STORES CONTEXT TO STACK(RO,R1,R2,R3,R12,R14(LR),R15(PC)) IN THIS ORDER TO MAIN STACK OR PROCESS STACK 
THE 3RD  BIT OF LINK REG, IF 0,THEN FROM ISR, RETURN TO PROCESS STACK, IF 1 ,RETURN TO THE MAIN STACK
WE ACESS THS DATA THROGH ARGUMENT(SVC_args()) PASSED TO SVC_HANDLER().SUCH THAT RO VALUE IS STORED IN SVC_args[0]
R1 VALUE IN SVC_args[1]...PC VALUE IN SVC_args[6]


*/


int __svc(0x00) svc_service_add(int x, int y);
int __svc(0x01) svc_service_sub(int x, int y);
int __svc(0x02) svc_service_mul(int x, int y);
int __svc(0x03) svc_service_div(int x, int y);
void SVC_Handler_C(unsigned int * svc_args);

int x,y,z;
int main(void)
{
x=10,y=20;
z=svc_service_add(x,y);

x=10,y=20;
z=svc_service_sub(x,y);	

x=10,y=20;
z=svc_service_mul(x,y);	

x=10,y=20;
z=svc_service_div(x,y);		
}


//ASSEMBLY LANGUAGE CODE, TO FIND THE CORRECT STACK
__asm void SVC_Handler(void)
{
	TST LR, #4         //Ob0100 TESTS THE 3RD BIT IN THE LR IS 1 OR 0
	ITE EQ             //CHECKS LIKE AN IF CONDITION, IF TRUE OR FALSE
	MRSEQ R0, MSP      //IF MRSEQ(IF EQUAL), MRS IS A SPECIAL REGSTR,COPY THE MAIN STACK POINTER TO R0
	MRSNE R0, PSP      //IF MRSNE(NOT EQUAL), STORE DATA INTO R0 FROM PSP
                     //AFTER FINDING THE STACK, WE NEED TO DO THE PROCESS
  B  __cpp(SVC_Handler_C)  //B FOR BRANCHING TO THE SVC_HANDLER_C CODE FROM THIS(similar to goto, but to a different function)
	                   //SVC HANDLER IS STANDARDISED NAME
}

void SVC_Handler_C(unsigned int * svc_args)  //THIS ARGS IS AN ARRAY OF ARGUMENTS THAT CONTAINS THE 
{	                                           //REGISTER VALUES FROM R0 TO R15 AS MENTIONED ABOVE
unsigned int svc_number;
	svc_number =((char*)svc_args[6])[-2];   //PROGRAM COUNTER HOLDS THE ADDRESS TO BE EXECUTED,IN THIS CASE IT IS THE SVC SERVICE,
	                                       //-2 TO GET THE FIRST BYTE,WHICH REPRESENTS THE SVC NUMBER FROM SVC SERVICE
	
	switch(svc_number)
	{
		case 0:
			svc_args[0]=svc_args[0]+svc_args[1]; //R0 AND R1 HOLDS THE PARAMETER PASSED TO THE SVC_SERVICE , AND THE RETURNVALUE IS STORED IN RO ALSO
			break;                               //IF SVC_NUMBER IS 0, THAT MEANS THE ADD FUNCTION IS CALLED THUS THE PARAMETER ARE ADDED
		case 1:
			svc_args[0]=svc_args[0]-svc_args[1];
			break;	
		case 2:
			svc_args[0]=svc_args[0]*svc_args[1];
			break;
		case 3:
			svc_args[0]=svc_args[0]/svc_args[1];
			break;
		default:
			break;
    }
}
