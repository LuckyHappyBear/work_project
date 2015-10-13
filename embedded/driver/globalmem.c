/*************************************************************************
 Copyright (C), 2015, TP-LINK TECHNOLOGIES CO., LTD.

 File Name:    globalmem.c

 Description:  use device,bus and driver framework to complete the function

 Author:       HeXiong

 Email:        hexiong@tp-link.net

 History:

 -----------------------------------------------
 v0.1,2015-8-20,hexiong create the file and complete the function
 ************************************************************************/
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/err.h>

#define DRIVER_NAME "globalmem" /* driver name */
#define GLOBALMEM_SIZE	0x1000	/* global memory(max size is 4k) */
#define MEM_CLEAR       0x1     /* set global memory as 0 */
#define GLOBALMEM_MAJOR 200     /* globalmem's major number */


/* set up a platform_device struct */
struct platform_device globalmem_device = {
    .name       = "globalmem",
    .id         = 0,
};

/* register platform device */
int register_globalmem_platform_device(void)
{
    platform_device_register(&globalmem_device);
    return 0;
}

/* globalmem device struct */
struct globalmem_dev
{
    struct platform_device *pdev;  /* platform_device struct */
    struct cdev cdev; /* cdev struct */
    struct device dev;
    dev_t dev_num;
    unsigned char mem[GLOBALMEM_SIZE]; /* global memory */
};

struct globalmem_dev *globalmem_dev; /* device struct pointer*/

/* file open function */
int globalmem_open(struct inode *inode, struct file *filp)
{
    /* file private data pointer = device struct pointer */
    filp->private_data = globalmem_dev;
    return 0;
}

/* file release function */
int globalmem_release(struct inode *inode, struct file *filp)
{
    return 0;
}

/* ioctl device control function */
static int globalmem_ioctl(struct inode *inodep, struct file *filp, unsigned
  int cmd, unsigned long arg)
{
    /* get device struct pointer */
    struct globalmem_dev *dev = filp->private_data;

    switch (cmd)
    {
    case MEM_CLEAR:
        memset(dev->mem, 0, GLOBALMEM_SIZE);
        printk(KERN_INFO "globalmem is set to zero\n");
        break;

    default:
        return  - EINVAL;
    }
    return 0;
}

/* read function */
static ssize_t globalmem_read(struct file *filp, char __user *buf, size_t size,
  loff_t *ppos)
{
    unsigned long p =  *ppos;
    unsigned int count = size;
    int ret = 0;
    /* get device struct pointer */
    struct globalmem_dev *dev = filp->private_data;

    /* analyse and get valid write length */
    if (p >= GLOBALMEM_SIZE)
    {
        return 0;
    }
    if (count > GLOBALMEM_SIZE - p)
    {
        count = GLOBALMEM_SIZE - p;
    }

    /* kernel space->user space */
    if (copy_to_user(buf, (void*)(dev->mem + p), count))
    {
        ret =  - EFAULT;
    }
    else
    {
        *ppos += count;
        ret = count;

        printk(KERN_INFO "read %d bytes(s) from %ld\n", count, p);
    }

    return ret;
}

/* write function */
static ssize_t globalmem_write(struct file *filp, const char __user *buf,
  size_t size, loff_t *ppos)
{
    unsigned long p =  *ppos;
    unsigned int count = size;
    int ret = 0;
    /* get device struct pointer */
    struct globalmem_dev *dev = filp->private_data;

    /*analyse ane get the vaild write length */
    if (p >= GLOBALMEM_SIZE)
    {
        return count ?  - ENXIO: 0;
    }
    if (count > GLOBALMEM_SIZE - p)
    {
        count = GLOBALMEM_SIZE - p;
    }
    /* user space-> kernel space */
    if (copy_from_user(dev->mem + p, buf, count))
    {
        ret =  - EFAULT;
    }
    else
    {
        *ppos += count;
        ret = count;

        printk(KERN_INFO "written %d bytes(s) from %ld\n", count, p);
    }

    return ret;
}

/* seek file locate function */
static loff_t globalmem_llseek(struct file *filp, loff_t offset, int orig)
{
    loff_t ret = 0;
    switch (orig)
    {
    case 0:
        /* the offset count from the start position */
        if (offset < 0)
        {
            ret =  - EINVAL;
            break;
        }
        if ((unsigned int)offset > GLOBALMEM_SIZE)
        {
            ret =  - EINVAL;
            break;
        }
        filp->f_pos = (unsigned int)offset;
        ret = filp->f_pos;
        break;
    case 1:
        /* the offset count from the current position */
        if ((filp->f_pos + offset) > GLOBALMEM_SIZE)
        {
            ret =  - EINVAL;
            break;
        }
        if ((filp->f_pos + offset) < 0)
        {
            ret =  - EINVAL;
            break;
        }
        filp->f_pos += offset;
        ret = filp->f_pos;
        break;
    default:
        ret =  - EINVAL;
        break;
    }
    return ret;
}

/* file operation struct */
static const struct file_operations globalmem_fops =
{
    .owner = THIS_MODULE,
    .llseek = globalmem_llseek,
    .read = globalmem_read,
    .write = globalmem_write,
    .unlocked_ioctl = globalmem_ioctl,
    .open = globalmem_open,
    .release = globalmem_release,
};


/* This is a read method */
static ssize_t globalmem_show(struct kobject *kobj, struct kobj_attribute *attr,
                              char *buf)
{
    return snprintf(buf, "%s", globalmem_dev->mem);
}

/* This is a write method */
static ssize_t globalmem_store(struct kobject *kobj, struct kobj_attribute *attr,
                               const char *buf, size_t count)
{
    size_t length = strlen(globalmem_dev->mem);
    if (length + count >= GLOBALMEM_SIZE)
    {
        memcpy(&globalmem_dev->mem[length], buf, GLOBALMEM_SIZE - length - 1);
        globalmem_dev->mem[GLOBALMEM_SIZE - 1] = '\0';
        return GLOBALMEM_SIZE - length - 1;
    }
    else
    {
        memcpy(&globalmem_dev->mem[length], buf, count);
        globalmem_dev->mem[length + count + 1] = '\0';
        return count;
    }
}

/* create a interaface */
static struct kobj_attribute globalmem_attribute =
        __ATTR(globalmem, 0666, globalmem_show, globalmem_store);

static struct sttribute *attrs[] = {
    &globalmem_attribute.attr,
    NULL,
};

static struct attribute_group attr_group = {
    .attrs = attrs,
};

/* create a kobject variable */
static struct kobject *globalmem_kobj;

static struct class* globalmem_class;

static int globalmem_probe(struct platform_device *pdev)
{
    int rc = 0;

    globalmem_dev = kzalloc(sizeof(struct globalmem_dev), GFP_KERNEL);
    if (!globalmem_dev)
    {
        printk(KERN_ERR "CCCC %s Unable to allocate memory for struct\n",
                __func__);
        return -ENOMEM;
    }

    globalmem_dev->pdev = pdev;

    platform_set_drvdata(pdev, globalmem_dev);

    rc = alloc_chrdev_region(&globalmem_dev->dev_num, 0, 1, DRIVER_NAME);
    if (rc < 0)
    {
        printk(KERN_ERR "CCCC %s: alloc_chrdev_region Failed rc = %d\n",
                __func__, rc);
        goto error_free_globalmem;
    }

    globalmem_class = class_create(THIS_MODULE, "globalmem");
    rc = PTR_ERR(globalmem_class);
    if (IS_ERR(globalmem_class))
    {
        goto error_free_unregister_chrdev_region;
    }

    globalmem_dev->dev.parent = &pdev->dev;
    globalmem_dev->dev.class = globalmem_class;
    globalmem_dev->dev.devt = globalmem_dev->dev_num;
    dev_set_name(&globalmem_dev->dev, "globalmem");
    memset(globalmem_dev->mem, 0, GLOBALMEM_SIZE);
    rc = device_register(&globalmem_dev->dev);
    if (rc < 0)
    {
        printk(KERN_ERR "CCCC %s: device_register failed %d\n", __func__, rc);
        goto error_dev_register;
    }

    cdev_init(&globalmem_dev->cdev, &globalmem_fops);
    rc = cdev_add(&globalmem_dev->cdev,
        MKDEV(MAJOR(globalmem_dev->dev_num), 0),
                1);
    if (rc < 0)
    {
        printk(KERN_ERR "CCCC %s: cdev_add failed %d\n", __func__, rc);
        goto error_cdev_add;
    }

    pr_info("CCCC globalmem_probe done\n");
    return rc;

error_cdev_add:
    device_del(&globalmem_dev->dev);
error_dev_register:
    put_device(&globalmem_dev->dev);
    class_destroy(globalmem_class);
error_free_unregister_chrdev_region:
    unregister_chrdev_region(globalmem_dev->dev_num, 1);
error_free_globalmem:
    kfree(globalmem_dev);
    return rc;
}

static int globalmem_remove(struct platform_device *plat_dev)
{
    cdev_del(&globalmem_dev->cdev);
    device_unregister(&globalmem_dev->dev);
    class_destroy(globalmem_class);
    unregister_chrdev_region(globalmem_dev->dev_num, 1);
    kfree(globalmem_dev);
    return 0;
}

static struct platform_driver globalmem_platform_driver = {
    .probe = globalmem_probe,
    .remove = __devexit_p(globalmem_remove),
    .driver = {
        .owner = THIS_MODULE,
        .name = DRIVER_NAME
    }
};

static int globalmem_init(void)
{
    int retval;
    register_globalmem_platform_device();
    platform_driver_register(&globalmem_platform_driver);

    globalmem_kobj = kobject_create_and_add("globalmem", kernel_kobj);
    if (!globalmem_kobj)
    {
        return -ENOMEM;
    }
    /* create the file associated with this kobject */
    retval = sysfs_create_group(globalmem_kobj, &attr_group);
    if (retval)
    {
        kobject_put(globalmem_kobj);
    }
    return retval;
}

static void globalmem_exit(void)
{
    kobject_put(globalmem_kobj);
    platform_device_unregister(&globalmem_device);
    return platform_driver_unregister(&globalmem_platform_driver);
}

module_init(globalmem_init);
module_exit(globalmem_exit);

MODULE_VERSION("1.0");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Hexiong");
