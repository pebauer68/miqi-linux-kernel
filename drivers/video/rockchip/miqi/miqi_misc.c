
#include <linux/module.h>
#include <linux/i2c.h>
#include <linux/bcd.h>
#include <linux/rtc.h>
#include <linux/delay.h>
#include <linux/wakelock.h>
#include <linux/slab.h>
#include <linux/of_gpio.h>
#include <linux/irqdomain.h>
#include <linux/rk_fb.h>
#include <linux/delay.h>
#include <linux/regulator/consumer.h>

static int miqi_enable_ldo()
{
	int ret = -1;
	struct regulator * ldo;

	ldo = regulator_get(NULL, "act_ldo3");
	if (ldo == NULL) {
		pr_err("\n%s get ldo3 failed\n", __func__);
	} else{
		ret = regulator_enable(ldo);
		if(ret != 0){
			pr_err("%s: faild to enable ldo3\n", __func__);
		} else {
			pr_info("%s: turn on ldo3 done.\n", __func__);
		}
	}

	ldo = regulator_get(NULL, "act_ldo4");
	if (ldo == NULL) {
		pr_err("\n%s get ldo failed\n", __func__);
	} else{
		ret = regulator_enable(ldo);
		if(ret != 0){
			pr_err("%s: faild to enable ldo4.\n", __func__);
		} else {
			pr_info("%s: turn on ldo done.\n", __func__);
	        }
	}

	ldo = regulator_get(NULL, "act_ldo2");
	if (ldo == NULL) {
		pr_err("\n%s get ldo2 failed\n", __func__);
	} else{
		ret = regulator_enable(ldo);
		if(ret != 0){
			pr_err("%s: faild to enable ldo2\n", __func__);
		} else {
			pr_info("%s: turn on ldo2 done.\n", __func__);
		}
	}

	ldo = regulator_get(NULL, "act_ldo8");
	if (ldo == NULL) {
		pr_err("\n%s get ldo8 failed\n", __func__);
	} else{
		ret = regulator_enable(ldo);
		if(ret != 0){
			pr_err("%s: faild to enable ldo8.\n", __func__);
		} else {
			pr_info("%s: turn on ldo done.\n", __func__);
		}
	}

	return 0;
}


static int __init miqi_misc_init(void)
{
	pr_info("MiQi misc driver version 1.0\n");
	return miqi_enable_ldo();
}

static void __exit miqi_misc_exit(void)
{
}

late_initcall(miqi_misc_init);
module_exit(miqi_misc_exit);

MODULE_AUTHOR("mqmaker@gmail.com");
MODULE_DESCRIPTION("MiQi misc driver");
MODULE_LICENSE("GPL");

