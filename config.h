/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
// #define EE_HANDS
#define TAPPING_TERM 125
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define MK_KINETIC_SPEED
#define MOUSEKEY_MOVE_DELTA 24
#define MOUSEKEY_INITIAL_SPEED 350
#define MOUSEKEY_DELAY 5
#define MOUSEKEY_BASE_SPEED 1500
#define MOUSEKEY_ACCELERATED_SPEED 1500
#define LEADER_PER_KEY_TIMING 125
#define LEADER_NO_TIMEOUT
#define LAYOUT_PRINTER
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX