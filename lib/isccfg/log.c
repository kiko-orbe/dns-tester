/*
 * Copyright (C) 2001  Internet Software Consortium.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM
 * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL
 * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
 * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* $Id: log.c,v 1.1 2001/02/22 02:38:23 gson Exp $ */

#include <config.h>

#include <isc/util.h>

#include <isccfg/log.h>

/*
 * When adding a new category, be sure to add the appropriate
 * #define to <isccfg/log.h>.
 */
isc_logcategory_t isccfg_categories[] = {
	{ "config", 	0 },
	{ NULL, 	0 }
};

/*
 * When adding a new module, be sure to add the appropriate
 * #define to <isccfg/log.h>.
 */
isc_logmodule_t isccfg_modules[] = {
	{ "isccfg/parser",	 0 },
	{ NULL, 		0 }
};

void
isccfg_log_init(isc_log_t *lctx) {
	REQUIRE(lctx != NULL);

	isc_log_registercategories(lctx, isccfg_categories);
	isc_log_registermodules(lctx, isccfg_modules);
}
