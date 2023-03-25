#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

dev_t maj_min_num=0;/* in this the number which is availble will be given to you by the kernal itself, thus no need of min/maj number*/

static int __init start_fun(void)
{	
	if(alloc_chrdev_region(&maj_min_num,0,1, "sample_device")>=0)
	{
		printk(KERN_INFO "Major_Number and Minor_Number assigned are %d %d \n",MAJOR(maj_min_num),MINOR(maj_min_num));
		/*the major number and minumum number in the maj_min_num can be extracted seperately using this MAJOR(),MINOR() functions*/	
	}
	else
	{
		printk(KERN_CRIT "Major_Minor NUmber assigning is failed\n");
	}
		  
	printk(KERN_CRIT "Module is loaded into the kernal\n");
	return 0;
}



void __exit end_fun(void) 
{
unregister_chrdev_region(maj_min_num,1);/*first parmtr is the structure member and second is the range*/
/*this is the freeying of the allocated maj/min from the kernel*/

printk(KERN_CRIT "Module is unloaded from the kernal\n");

}

module_init(start_fun)
module_exit(end_fun);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("@J");
MODULE_DESCRIPTION("SampleDriver");
MODULE_VERSION("1.0");
