#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

#include<linux/kdev_t.h>
#include<linux/device.h>

#include<linux/fs.h> /*for function pointer, used in file operations*/
#include<linux/cdev.h>


dev_t maj_min_num=0;

static struct class *sample_class;
static struct cdev sample_cdev;/*creating the structure variable for the cdev , then only using this we can init, add, destroy the cdev,
				and only using cdev we can open/close/wrie/read any char_data file which inturns operate on the hardware. */


/********** module start/end function declaration *******/
static int __init start_fun(void);
static void __exit end_fun(void);



/***********Declaration of file Operation Functions *********/
static int sample_device_file_open(struct inode *inode, struct file *file);
static int sample_device_file_release(struct inode *inode, struct file *file);
static ssize_t sample_device_file_read(struct file *filp,char __user *buf, size_t len, loff_t * off);
static ssize_t sample_device_file_write(struct file *filp, const char *buf, size_t len, loff_t * off);




/*********** creating our own structure variables(in this functions) for file operations ********************/
/*here file_operation is already defined structure variable that contains all the file operations and here we are creating an instance of that function with file operation variables as our read/write functions*/
static struct file_operations sample_ops =
{
.owner = THIS_MODULE ,
.read  = sample_device_file_read,
.write = sample_device_file_write,
.open  = sample_device_file_open,
.release = sample_device_file_release,
};



/****Defenition of file operation functions***********/

static int sample_device_file_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "File is opened for operation");
	return 0;
}
static int sample_device_file_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "File is released");
	return 0;
}
static ssize_t sample_device_file_read(struct file *filp,char __user *buf, size_t len, loff_t *off)
{
	printk(KERN_INFO "Data from the file is read");
	return 0;
}
static ssize_t sample_device_file_write(struct file *filp, const char *buf, size_t len, loff_t *off)
{
	printk(KERN_INFO "New data is written to the file");
	return len;
}




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



	/*creating cdev structure by cdev_init()along with the file operations possible*/
	
	cdev_init(&sample_cdev,&sample_ops);




	/*adding the device to the system before the device file, by assigning it with the min/maj number*/

	if((cdev_add(&sample_cdev,maj_min_num,1))<0)
	{
		printk(KERN_CRIT "Cannot add device to system");
		goto maj_min_fail;
	}






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




	/************** In case of any failure ****************/

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

cdev_del(&sample_cdev);/*cdev created for file operation is deleted*/


unregister_chrdev_region(maj_min_num,1);/*first parmtr is the structure member and second is the range*/
/*this is the freeying of the allocated maj/min from the kernel*/
printk(KERN_INFO "Major/Minimum Number is Unregistered \n");


printk(KERN_INFO "Module is unloaded from the kernal\n");

}

module_init(start_fun);
module_exit(end_fun);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("@J");
MODULE_DESCRIPTION("SampleDriver");
MODULE_VERSION("1.0");
