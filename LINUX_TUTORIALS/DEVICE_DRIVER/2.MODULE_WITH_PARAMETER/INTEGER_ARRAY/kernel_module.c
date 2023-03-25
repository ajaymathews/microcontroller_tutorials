#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int int_arr[10];
int count,i;

module_param_array(int_arr,int,NULL,S_IRUSR|S_IWUSR|S_IXUSR);
//module_param_array(int_arr,int,&count,S_IRUSR|S_IWUSR|S_IXUSR);
/* count recieves the number of variables passed */

static int __init start_fun(void)
{	
printk(KERN_INFO "Module is loaded into the kernal\n");
printk(KERN_INFO "The count is %d",count);
printk(KERN_INFO "The integer value passed at loading module is");
for(i=0;i<(sizeof(int_arr)/sizeof(int));i++)/*if we are using this method,then if we enter only 7 values inplace of 10, others are seened as 0 */
//for(i=0;i<count;i++) /*in this methd, eventhough we enter only less numbers, that number of elemnts will be the value of count, thus prints only entered values not zeros */
{
printk("int_arr[%d]=%d ",i,int_arr[i]);
}
printk("\n");
return 0;
}



void __exit end_fun(void)
{
printk(KERN_INFO "The value retained at unloading module is");
for(i=0;i<(sizeof(int_arr)/sizeof(int));i++)
{
printk("%d ",int_arr[i]);
}
printk("\n");
printk(KERN_INFO "Module is unloaded from the kernal\n");

}

module_init(start_fun);
module_exit(end_fun);





MODULE_LICENSE("GPL");
MODULE_AUTHOR("@J");
MODULE_DESCRIPTION("SampleDriver");
MODULE_VERSION("1.0");
