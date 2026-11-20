#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/sched.h>
#include <linux/mm.h>

static int __init hello_init(void)
{
    pr_info("hello: ===== loaded =====\n");
    pr_info("hello: UTS_RELEASE = %s\n", UTS_RELEASE);
    pr_info("hello: LINUX_VERSION_CODE = %d\n", LINUX_VERSION_CODE);
    pr_info("hello: current = %s (pid %d)\n", current->comm, current->pid);
    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("hello: ===== unloaded =====\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("YG");
MODULE_DESCRIPTION("kernel module smoke test");
