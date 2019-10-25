/*
 * This file is part of Cockpit.
 *
 * Copyright (C) 2019 Red Hat, Inc.
 *
 * Cockpit is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * Cockpit is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Cockpit; If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/un.h>
#include <sys/types.h>
#include <time.h>

bool
get_remaining_timeout (struct timespec *start,
                       uint64_t *timeout_remaining,
                       uint64_t timeout_us);

bool
recv_alnum (int fd,
            char *buffer,
            size_t size,
            int timeout);

bool
send_all (int fd,
          const char *buffer,
          size_t size,
          int timeout);

void
sockaddr_printf (struct sockaddr_un *addr,
                 const char *format,
                 ...) __attribute__((format(printf, 2, 3)));
