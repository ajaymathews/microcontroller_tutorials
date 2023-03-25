#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

#include<linux/kdev_t.h>
#include<linux/device.h>

dev_t maj_min_num=0;/* in this the number that is available will be given to you by the kernal itself, thus no need of assign any value */

static struct class *sample_class;/*varible to stoe the structure details*/




static int __init start_fun(void)
{	
	/*********** creating maj/min number ******************/

	if(alloc_chrdev_region(&maj_min_num,0,1, "sample_device")>=0)
	{
		printk(KERN_INFO "Major_Number and Minor_Number assigned are %d %d \n",MAJOR(maj_min_num),MINOR(maj_min_num));
		/*the major number and minumum number in the maj_min_num can be extracted seperately using this MAJOR(),MINOR() functions*/	
	}
	else
	{	printk(KERN_CRIT "Major_Minor NUmber assigning is failed\n");
		goto maj_min_fail;					      }





	/************ creating class for the device **************/

	if((sample_class = class_create( THIS_MODULE , "sample_device_class"))==NULL)
	{
	 	printk(KERN_CRIT "Device Class Creation failed \n");
	 	goto class_fail;
	}
	printk(KERN_INFO "Class for the device file is created\n");


	/************ creating device file for device ************/
	
	if((device_create(sample_class,NULL,maj_min_num,NULL,"sample_device"))==NULL)
	{
	 	printk(KERN_CRIT "Device Creation failed \n");
	 	goto device_fail;
	}
	printk(KERN_INFO "Device file is created,Check '/dev/' \n");



	printk(KERN_INFO "Module is loaded into the kernal\n");
	return 0;


	device_fail:
		class_destroy(sample_class);

	class_fail:
		unregister_chrdev_region(maj_min_num,1);

	maj_min_fail:
	  
	       return -1;
}



void __exit end_fun(void) 
{

device_destroy(sample_class,maj_min_num);/*to destroy the device file */
printk(KERN_INFO "Device file is destroyed \n");

class_destroy(sample_class);/*to destroy the class we created from the /sys/class */
printk(KERN_INFO "Class is destroyed \n");

unregister_chrdev_region(maj_min_num,1);/*first parmtr is the structure member and second is the range*/
/*this is the freeying of the allocated maj/min from the kernel*/
printk(KERN_INFO "Major/Minimum Number is Unregistered \n");


printk(KERN_INFO "Module is unloaded from the kernal\n");

}

module_init(start_fun)
module_exit(end_fun);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("@J");
MODULE_DESCRIPTION("SampleDriver");
MODULE_VERSION("1.0");
