// https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vasilyev Boris <1024sparrow@gmail.com>");
MODULE_DESCRIPTION("Codongo devices: virtual keyboard and codongo input device.");
MODULE_VERSION("0.01");

/* Read-Only Device */
#define MICE_DEVICE_NAME "codongo_virtual_mouse"
/* Read-Only Device */
#define VKB_DEVICE_NAME "codongo_virtual_keyboard"
/* Write-Only Device */
#define INPUT_DEVICE_NAME "codongo_input_device"

#define EXAMPLE_MSG "Hello, World!\n"
#define MSG_BUFFER_LEN 15/* Prototypes for device functions */

static int mice_open(struct inode *, struct file *);
static int mice_release(struct inode *, struct file *);
static ssize_t mice_read(struct file *, char *, size_t, loff_t *);
static ssize_t mice_write(struct file *, const char *, size_t, loff_t *);

static int vkb_open(struct inode *, struct file *);
static int vkb_release(struct inode *, struct file *);
static ssize_t vkb_read(struct file *, char *, size_t, loff_t *);
static ssize_t vkb_write(struct file *, const char *, size_t, loff_t *);

static int input_open(struct inode *, struct file *);
static int input_release(struct inode *, struct file *);
static ssize_t input_read(struct file *, char *, size_t, loff_t *);
static ssize_t input_write(struct file *, const char *, size_t, loff_t *);

static int
	mice_major_num,
	vkb_major_num,
	input_major_num
;
static int
	mice_open_count = 0,
	vkb_open_count = 0,
	input_open_count = 0
;
static char msg_buffer[MSG_BUFFER_LEN];
static char *msg_ptr;

/* This structure points to all of the device functions */
static struct file_operations mice_file_ops = {
	.read = mice_read,
	.write = mice_write,
	.open = mice_open,
	.release = mice_release
};

/* This structure points to all of the device functions */
static struct file_operations vkb_file_ops = {
	.read = vkb_read,
	.write = vkb_write,
	.open = vkb_open,
	.release = vkb_release
};

/* This structure points to all of the device functions */
static struct file_operations input_file_ops = {
	.read = input_read,
	.write = input_write,
	.open = input_open,
	.release = input_release
};

/* When a process reads from our device, this gets called. */
static ssize_t mice_read(struct file *flip, char *buffer, size_t len, loff_t *offset) {
	int bytes_read = 0;
	/* If we’re at the end, loop back to the beginning */
	if (*msg_ptr == 0)
	{
		msg_ptr = msg_buffer;
	}
	/* Put data in the buffer */
	while (len && *msg_ptr)
	{
		/* Buffer is in user data, not kernel, so you can’t just reference
		* with a pointer. The function put_user handles this for us */
		put_user(*(msg_ptr++), buffer++);
		len--;
		bytes_read++;
	}
	return bytes_read;
}

/* When a process reads from our device, this gets called. */
static ssize_t vkb_read(struct file *flip, char *buffer, size_t len, loff_t *offset)
{
	int bytes_read = 0;
	/* If we’re at the end, loop back to the beginning */
	if (*msg_ptr == 0)
	{
		msg_ptr = msg_buffer;
	}
	/* Put data in the buffer */
	while (len && *msg_ptr)
	{
		/* Buffer is in user data, not kernel, so you can’t just reference
		* with a pointer. The function put_user handles this for us */
		put_user(*(msg_ptr++), buffer++);
		len--;
		bytes_read++;
	}
	return bytes_read;
}

/* When a process reads from our device, this gets called. */
static ssize_t input_read(struct file *flip, char *buffer, size_t len, loff_t *offset) {
	int bytes_read = 0;
	/* If we’re at the end, loop back to the beginning */
	if (*msg_ptr == 0)
	{
		msg_ptr = msg_buffer;
	}
	/* Put data in the buffer */
	while (len && *msg_ptr)
	{
		/* Buffer is in user data, not kernel, so you can’t just reference
		* with a pointer. The function put_user handles this for us */
		put_user(*(msg_ptr++), buffer++);
		len--;
		bytes_read++;
	}
	return bytes_read;
}

/* Called when a process tries to write to our device */
static ssize_t mice_write(struct file *flip, const char *buffer, size_t len, loff_t *offset)
{
	/* This is a read-only device */
	printk(KERN_ALERT "This operation is not supported.\n");
	return -EINVAL;
}

/* Called when a process tries to write to our device */
static ssize_t vkb_write(struct file *flip, const char *buffer, size_t len, loff_t *offset)
{
	/* This is a read-only device */
	printk(KERN_ALERT "This operation is not supported.\n");
	return -EINVAL;
}

/* Called when a process tries to write to our device */
static ssize_t input_write(struct file *flip, const char *buffer, size_t len, loff_t *offset)
{
	/* This is a read-only device */
	printk(KERN_ALERT "This operation is not supported.\n");
	return -EINVAL;
}

/* Called when a process opens our device */
static int mice_open(struct inode *inode, struct file *file)
{
	/* If device is open, return busy */
	if (mice_open_count)
	{
		return -EBUSY;
	}
	mice_open_count++;
	try_module_get(THIS_MODULE);
	return 0;
}

/* Called when a process opens our device */
static int vkb_open(struct inode *inode, struct file *file)
{
	/* If device is open, return busy */
	if (vkb_open_count)
	{
		return -EBUSY;
	}
	vkb_open_count++;
	try_module_get(THIS_MODULE);
	return 0;
}

/* Called when a process opens our device */
static int input_open(struct inode *inode, struct file *file)
{
	/* If device is open, return busy */
	if (input_open_count)
	{
		return -EBUSY;
	}
	input_open_count++;
	try_module_get(THIS_MODULE);
	return 0;
}

/* Called when a process closes our device */
static int mice_release(struct inode *inode, struct file *file)
{
	/* Decrement the open counter and usage count. Without this, the module would not unload. */
	mice_open_count--;
	module_put(THIS_MODULE);
	return 0;
}

/* Called when a process closes our device */
static int vkb_release(struct inode *inode, struct file *file)
{
	/* Decrement the open counter and usage count. Without this, the module would not unload. */
	vkb_open_count--;
	module_put(THIS_MODULE);
	return 0;
}

/* Called when a process closes our device */
static int input_release(struct inode *inode, struct file *file)
{
	/* Decrement the open counter and usage count. Without this, the module would not unload. */
	input_open_count--;
	module_put(THIS_MODULE);
	return 0;
}

static int __init codongo_init(void)
{
	/* Fill buffer with our message */
	strncpy(msg_buffer, EXAMPLE_MSG, MSG_BUFFER_LEN);
	/* Set the msg_ptr to the buffer */
	msg_ptr = msg_buffer;
	/* Try to register character device */
	mice_major_num = register_chrdev(0, MICE_DEVICE_NAME, &mice_file_ops);
	if (mice_major_num < 0)
	{
		printk(KERN_ALERT "Could not register mouse device: %d\n", mice_major_num);
		return mice_major_num;
	}
	vkb_major_num = register_chrdev(0, VKB_DEVICE_NAME, &vkb_file_ops);
	if (vkb_major_num < 0)
	{
		printk(KERN_ALERT "Could not register vkb device: %d\n", vkb_major_num);
		return vkb_major_num;
	}
	input_major_num = register_chrdev(0, INPUT_DEVICE_NAME, &input_file_ops);
	if (input_major_num < 0)
	{
		printk(KERN_ALERT "Could not register input device: %d\n", input_major_num);
		return input_major_num;
	}
	printk(KERN_INFO "codongo module loaded with device major numbers: mice(%d), vkb(%d), input(%d)\n", mice_major_num, vkb_major_num, input_major_num);
	return 0;
}

static void __exit codongo_exit(void)
{
	/* Remember — we have to clean up after ourselves. Unregister the character device. */
	unregister_chrdev(mice_major_num, MICE_DEVICE_NAME);
	unregister_chrdev(vkb_major_num, VKB_DEVICE_NAME);
	unregister_chrdev(input_major_num, INPUT_DEVICE_NAME);
	printk(KERN_INFO "Codongo devices unregistered\n");
}

/* Register module functions */
module_init(codongo_init);
module_exit(codongo_exit);
