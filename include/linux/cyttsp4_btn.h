/* < DTS2013050605374 shenjinming 20130508 begin */

/*
 * cyttsp4_btn.h
 * Cypress TrueTouch(TM) Standard Product V4 CapSense touch reports module.
 * For use with Cypress Txx4xx parts.
 * Supported parts include:
 * TMA4XX
 * TMA1036
 *
 * Copyright (C) 2012 Cypress Semiconductor
 * Copyright (C) 2011 Sony Ericsson Mobile Communications AB.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2, and only version 2, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contact Cypress Semiconductor at www.cypress.com <ttdrivers@cypress.com>
 *
 */

#ifndef _LINUX_CYTTSP4_BTN_H
#define _LINUX_CYTTSP4_BTN_H

#define CYTTSP4_BTN_NAME "cyttsp4_btn"

struct cyttsp4_btn_platform_data {
	char const *inp_dev_name;
};

#endif /* _LINUX_CYTTSP4_BTN_H */
/* DTS2013050605374 shenjinming 20130508 end > */