/*
 * Copyright (C) 2011-2014 EMPulseGaming.LLC <http://www.empulsegaming.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include"Dope.h"

#include<iostream>

/** 
 *  Nothing to much really happens in main. I just declare
 *  a couple of functions. This is as simple as it can get. 
 */
 
void main()
{
    dope d;
    d.Openfile("Logo.txt");
    d.Start();
    d.Closefile();
    return;
}
