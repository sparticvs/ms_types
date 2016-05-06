/* @copyright
 * Copyright (c) 2016 - Charles `sparticvs` Timko
 *
 * Author(s):
 *  Charles Timko <sparticvs@popebp.com>
 *
 * Description:
 *  Return Code implementation to standardizing returns
 */

#ifndef __MST_RET_H__
#define __MST_RET_H__

typedef uint16_t ret_t;

#define RV_OK           0x0000
#define RV_UNKERR       0x0001
// All others reserved in this region
#define RV_BUILTIN_MAX  0x7FFF
#define RV_VENDOR_MIN   0x8000
// Vendor is permitted to use
#define RV_VENDOR_MAX   0xFFFF
#define RV_MAX          0xFFFF

/*
 * If two vendors both see the need for the same kind of return value, then it
 * should be proposed for standard. It's likely that if multiple vendors are
 * defining the same return value, then there is probably a solid reason to
 * include it in future releases.
 */

/*
 * Trust that a released version will never just remove a value. This is
 * partially the reason for such a large return value.
 */

#endif //__MST_RET_H__
