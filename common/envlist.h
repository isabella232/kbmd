/*
 * This file and its contents are supplied under the terms of the
 * Common Development and Distribution License ("CDDL"), version 1.0.
 * You may only use this file in accordance with the terms of version
 * 1.0 of the CDDL.
 *
 * A full copy of the text of the CDDL should have accompanied this
 * source.  A copy of the CDDL is also available via the Internet at
 * http://www.illumos.org/license/CDDL.
 */

/*
 * Copyright 2020 Joyent, Inc.
 */

#ifndef _ENVLIST_H
#define	_ENVLIST_H

#include <sys/types.h>
#include <libnvpair.h>
#include "pivy/errf.h"

#ifdef __cplusplus
extern "C" {
#endif

void envlist_init(void);
errf_t *envlist_alloc(nvlist_t **);
errf_t *envlist_pack(nvlist_t *, char **, size_t *);
errf_t *envlist_unpack(char *, size_t, nvlist_t **);
errf_t *envlist_add_string(nvlist_t *, const char *, const char *);
errf_t *envlist_add_boolean_value(nvlist_t *, const char *, boolean_t);
errf_t *envlist_add_int32(nvlist_t *, const char *, int32_t);
errf_t *envlist_add_uint32(nvlist_t *, const char *, uint32_t);
errf_t *envlist_add_uint8_array(nvlist_t *, const char *, const uint8_t *,
    uint_t);
errf_t *envlist_add_nvlist(nvlist_t *, const char *, const nvlist_t *);
errf_t *envlist_add_string_array(nvlist_t *, const char *, char * const *,
    uint_t);
errf_t *envlist_add_nvlist_array(nvlist_t *, const char *,
    nvlist_t * const *, uint_t);
errf_t *envlist_add_errf(nvlist_t *, const char *, const errf_t *);

errf_t *envlist_dump_json(nvlist_t *, char **);

errf_t *envlist_lookup_boolean_value(nvlist_t *, const char *,
    boolean_t *);
errf_t *envlist_lookup_int32(nvlist_t *, const char *, int32_t *);
errf_t *envlist_lookup_uint32(nvlist_t *, const char *, uint32_t *);
errf_t *envlist_lookup_string(nvlist_t *, const char *, char **);
errf_t *envlist_lookup_nvlist(nvlist_t *, const char *, nvlist_t **);
errf_t *envlist_lookup_nvlist_array(nvlist_t *, const char *, nvlist_t ***,
    uint_t *);
errf_t *envlist_lookup_uint8_array(nvlist_t *, const char *, uint8_t **,
    uint_t *);

/*
 * Yeah, this looks a bit odd, but it's for passing an errf_t across
 * a door call using an nvlist.
 */
errf_t *envlist_lookup_errf(nvlist_t *, const char *, errf_t **);

#ifdef __cplusplus
}
#endif

#endif /* _ENVLIST_H */
