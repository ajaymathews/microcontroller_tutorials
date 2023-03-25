/*
If we create a parameter then the actual file will be in the '/sys/module/pgm_name/parametrs' and when we open the file it has value that we passed or assigned initially. if we cahnge that value as a root user, the value is cahnged, but the kernal doesnt inform user about this eventhough the moodule is already insertd,
only method is printing the value at rmmod,
 if we want to get notified about the cahnge that take place , callback function is used 

struct kernel_param_ops
{
        int (*set)(const char *val, const struct kernel_param *kp);

        int (*get)(char *buffer, const struct kernel_param *kp);

        void (*free)(void *arg);
};
This function/macro is defined in the headerfiles of the kernel.

what we are trying to do is make a member for this macro by its name 'kernel_param_ops'.

Thus we create call_back_fun as its member with vaiables modified_set_int() and param_set_int()(param_set_short also applicable) adressess in the position of set() and get() like assigning a value to the structure student s={name="name",roll_no=20}.we use adress of the 2 function is because these get() and set() are function pointers.

' const struct kernel_param_ops call_back_fun = {.set = &modified_set_int,
					         .get = &param_get_int    }; '
this modified_set_int() actually calls the param_set_int(),but we need to print the new value also thats why a modified function.
param_set_int() and param_get_int() are already defined.

module_param_cb(chang_value,&call_back_fun,&chang_value,S_IRUSR|S_IWUSR|S_IXUSR);
and this macro will deine the call_back_function upon value change.
value change means that the parameter value changed after the insertion of module, by acahngi
*/


#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int chang_value=0,int_value;

int modified_set_int(const char *val, const struct kernel_param *kp)
{
int set_status=param_set_int(val,kp);
	if(set_status==0)
	{
	printk(KERN_INFO "value is changed to %d by the user \n",chang_value);
	return 0;
	}
	return -1;
}
const struct kernel_param_ops call_back_fun = { .set=&modified_set_int ,
					        .get=&param_get_int};     

/*if the param_get_int() check for the data is changed, and it is printed after if it is not used we cant even chnge the value from the parameter variable file, then if param_get_int() is not used , eventhough we change the value inside the file.after cahnging if we open the file again it still sees as empty, but the value of varaible chnged inside kernel*/
 
module_param(int_value,int,S_IRUSR|S_IWUSR|S_IXUSR);
module_param_cb(chang_value,&call_back_fun,&chang_value,S_IRUSR|S_IWUSR|S_IXUSR);

static int __init start_fun(void)
{				  
printk(KERN_CRIT "Module is loaded into the kernal\n");
printk(KERN_INFO "The value passed at loading module is %d \n",chang_value);

return 0;
}



void __exit end_fun(void)
{
printk(KERN_INFO "The int_value retained at unloading module is %d \n",int_value);
printk(KERN_INFO "The change_value retained at unloading module is %d \n",chang_value);
printk(KERN_CRIT "Module is unloaded from the kernal\n");

}

module_init(start_fun);
module_exit(end_fun);





MODULE_LICENSE("GPL");
MODULE_AUTHOR("@J");
MODULE_DESCRIPTION("SampleDriver");
MODULE_VERSION("1.0");
