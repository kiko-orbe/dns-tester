/*
 * Copyright (C) 1999  Internet Software Consortium.
 * 
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE
 * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#ifndef	DNS_ZT_H
#define DNS_ZT_H

#include <isc/lang.h>

#include <isc/mem.h>
#include <dns/name.h>
#include <dns/zone.h>
#include <dns/types.h>
#include <dns/rbt.h>


ISC_LANG_BEGINDECLS

dns_result_t dns_zt_create(isc_mem_t *mctx, dns_rdataclass_t rdclass,
			   dns_zt_t **zt);
/*
 * Creates a new zone table.
 *
 * Requires:
 * 	'mctx' to be initalised.
 *
 * Returns:
 *	DNS_R_SUCCESS on success.
 *	DNS_R_NOMEMORY
 */

dns_result_t dns_zt_mount(dns_zt_t *zt, dns_zone_t *zone);

/*
 * Mounts the zone on the zone table.
 *
 * Requires:
 *	'zt' to be valid
 *	'zone' to be valid
 *
 * Returns:
 *	DNS_R_SUCCESS
 *	DNS_R_EXISTS
 *	DNS_R_NOSPACE
 *	DNS_R_NOMEMORY
 */

dns_result_t dns_zt_unmount(dns_zt_t *zt, dns_zone_t *zone);

/*
 * Unmount the given zone from the table.
 *
 * Requires:
 * 	'zt' to be valid
 *	'zone' to be valid
 *
 * Returns:
 * 	DNS_R_SUCCESS
 *	DNS_R_NOTFOUND
 *	DNS_R_NOMEMORY
 */

dns_result_t dns_zt_find(dns_zt_t *zt, dns_name_t *name,
				dns_name_t *foundname, dns_zone_t **zone);

/*
 * Find the best match for 'name' in 'zt'.  If foundname is non NULL
 * then the name of the zone found is returned.
 *
 * Requires:
 *	'zt' to be valid
 *	'name' to be valid
 *	'foundname' to be initalised and associated with a fixedname or NULL
 *	'zone' to be non NULL and '*zone' to be NULL
 *
 * Returns:
 * 	DNS_R_SUCCESS
 *	DNS_R_PARTIALMATCH
 *	DNS_R_NOTFOUND
 *	DNS_R_NOSPACE
 */

void dns_zt_detach(dns_zt_t **ztp);

/*
 * Detach the give zonetable, if the reference count goes to zero the
 * zonetable will be freed.  In either case 'ztp' is set to NULL.
 *
 * Requires:
 *	'*ztp' to be valid
 */

void dns_zt_attach(dns_zt_t *zt, dns_zt_t **ztp);

/*
 * Attach 'zt' to '*ztp'.
 *
 * Requires:
 *	'zt' to be valid
 *	'*ztp' to be NULL
 */

void dns_zt_load(dns_zt_t *zt);

/*
 * Load all zones in the table.
 *
 * Requires:
 *	'zt' to be valid
 */


void dns_zt_print(dns_zt_t *zt);

/*
 * Print zones in zonetable, address, name and reference count.
 *
 * Requires
 *	'zt' to be valid.
 */

void
dns_zt_apply(dns_zt_t *zt, void (*action)(dns_zone_t *, void *), void *uap);

/*
 * Apply a given 'action' to all zone zones in the table.
 *
 * Requires:
 *	'zt' to be valid.
 *	'action' to be non NULL.
 */

ISC_LANG_ENDDECLS

#endif
