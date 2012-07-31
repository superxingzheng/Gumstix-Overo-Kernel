/* linux/arch/arm/mach-exynos4/dev-tmu.c
 *
 * Copyright 2011 by SAMSUNG
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/platform_data/exynos4_tmu.h>
#include <asm/irq.h>

#include <mach/irqs.h>
#include <mach/map.h>
#include <plat/devs.h>

static struct resource exynos4_tmu_resource[] = {
	[0] = {
		.start	= EXYNOS4_PA_TMU,
		.end	= EXYNOS4_PA_TMU + 0xFFFF - 1,
		.flags	= IORESOURCE_MEM,
	},
	[1] = {
		.start	= IRQ_TMU_TRIG0,
		.end	= IRQ_TMU_TRIG0,
		.flags	= IORESOURCE_IRQ,
	},
};

static struct exynos4_tmu_platform_data default_tmu_data = {
	.threshold = 80,
	.trigger_levels[0] = 2,
	.trigger_levels[1] = 5,
	.trigger_levels[2] = 20,
	.trigger_levels[3] = 30,
	.trigger_level0_en = 1,
	.trigger_level1_en = 1,
	.trigger_level2_en = 1,
	.trigger_level3_en = 1,
	.gain = 15,
	.reference_voltage = 7,
	.cal_type = TYPE_ONE_POINT_TRIMMING,
	.freq_tab[0] = {
		.freq_clip_pctg[0] = 30,
		},
	.freq_tab[1] = {
		.freq_clip_pctg[0] = 99,
		},
	.freq_tab_count = 2,
};

struct platform_device exynos4_device_tmu = {
	.name		= "exynos4-tmu",
	.id		= -1,
	.num_resources	= ARRAY_SIZE(exynos4_tmu_resource),
	.resource	= exynos4_tmu_resource,
	.dev	= {
		.platform_data	= &default_tmu_data,
	},
};
