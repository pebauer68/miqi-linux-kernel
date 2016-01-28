/*
 * Copyright (C) 2012 ROCKCHIP, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/rfkill.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <asm/gpio.h>
#include <mach/iomux.h>
#include <linux/delay.h>
#include <linux/rfkill-rk.h>
#include <linux/wakelock.h>
#include <linux/interrupt.h>
#include <asm/irq.h>
#include <linux/suspend.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

void rfkill_rk_sleep_bt(bool sleep)
{
}
EXPORT_SYMBOL(rfkill_rk_sleep_bt);

static int rfkill_rk_pm_prepare(struct device *dev)
{
    return 0;
}

static void rfkill_rk_pm_complete(struct device *dev)
{
}

static int rfkill_rk_probe(struct platform_device *pdev)
{
	return 0;
}

static int rfkill_rk_remove(struct platform_device *pdev)
{
	return 0;
}

static const struct dev_pm_ops rfkill_rk_pm_ops = {
	.prepare = rfkill_rk_pm_prepare,
	.complete = rfkill_rk_pm_complete,
};

static struct platform_driver rfkill_rk_driver = {
	.probe = rfkill_rk_probe,
	.remove = __devexit_p(rfkill_rk_remove),
	.driver = {
		.name = "rfkill_rk",
		.owner = THIS_MODULE,
		.pm = &rfkill_rk_pm_ops,
	},
};

static int __init rfkill_rk_init(void)
{
	return platform_driver_register(&rfkill_rk_driver);
}

static void __exit rfkill_rk_exit(void)
{
	platform_driver_unregister(&rfkill_rk_driver);
}

module_init(rfkill_rk_init);
module_exit(rfkill_rk_exit);

MODULE_DESCRIPTION("rock-chips rfkill for Bluetooth v0.2");
MODULE_AUTHOR("cmy@rock-chips.com, cz@rock-chips.com");
MODULE_LICENSE("GPL");

