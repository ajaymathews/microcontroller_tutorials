#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int int_value;
/* other supported data types are*/
/*    long x; short x; Uint x;    */

module_param(int_value,int,S_IRUSR|S_IWUSR|S_IXUSR);
/*  module param must be declred befor the init function,  */

static int __init start_fun(void)
{				  
printk(KERN_INFO "Module is loaded into the kernal\n");
printk(KERN_INFO "The integer value passed at loading module is %d \n",int_value);

return 0;
}



void __exit end_fun(void)
{
printk(KERN_INFO "The value retained at unloading module is %d\n",int_value);
printk(KERN_INFO "Module is unloaded from the kernal\n");

}

module_init(start_fun);
module_exit(end_fun);





MODULE_LICENSE("GPL");
MODULE_AUTHOR("@J");
MODULE_DESCRIPTION("SampleDriver");
MODULE_VERSION("1.0");
