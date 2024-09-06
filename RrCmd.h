/*!
 * Ryder Robots Shared Micro-Processor
 * Copyright (C) 2024  Ryder Robots
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * =====================================================================
 * 
 * CMD is the first part of the RrOpStorage object.  It indicates an observation (expected result)
 * or action that the micro-controller must perform.
 */

#ifndef RRCMD_H
#define RRCMD_H

#include <stdint.h>

namespace rrfw
{
    // List of supported I2C addresses,  note that the I2C sensor will need to 
    // have its address pre-programmed before some addreses will work.
    enum RR_I2C : uint8_t 
    {
        RR_U8 = 0x11,
        RR_U9 = 0x12,
        RR_UA = 0x13,
        RR_UB = 0x14,
    };

    /*!
     * list of operations.
     */
    enum RR_CMD : uint8_t
    {
        // Response codes.
        RR_IO_RES_OK          = 0x00, /* successfully processed result, with return response */
        RR_IO_RES_TIMEOUT     = 0x01, /* timed out while waiting to recieve data */
        RR_IO_RES_ACTION_SENT = 0x02, /* Action was sent */
        RR_IO_RES_UNSUPPORTED = 0x03, /* An unsupported operation.*/
        RR_IO_RES_BAD_RQ      = 0x04, /* Bad request was recieved */
        RR_IO_RES_NOTREADY    = 0x0e, /* Waiting for sensor to become available */
        RR_IO_RES_READY       = 0x10, /* Ready status */
        RR_IO_RES_FAILED      = 0x11,

        // Actions
        RR_CMD_U1 = 0x05, /* command for Motor Driver A */
        RR_CMD_U2 = 0x06, /* command for Motor Driver B */
        RR_CMD_U5 = 0x07, /* Gyroscope */
        RR_CMD_U6 = 0x08, /* Accelometer  */
        RR_CMD_U7 = 0x09, /* Magnometer */
        RR_CMD_U8 = 0x0a, /* Ultra sonic forward/bow sensor */
        RR_CMD_U9 = 0x0b, /* Ultra sonic port side */
        RR_CMD_UA = 0x0c, /* Ultra sonic port starbord*/
        RR_CMD_UB = 0x0d, /* Ultra sonic bottom */

        // Synchronization.
        RR_IO_COM_READY    = 0x012,  // Ready to send recieve commands
        RR_IO_COM_COMPLETE = 0x013,  // All commands have been sent
        RR_IO_COM_TX       = 0x014,  // Sending tranasaction (replaces READY and tells MP that actions will be sent)
    };
}
#endif