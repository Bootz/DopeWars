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

#ifndef __DOPE_H
#define __DOPE_H

#include <fstream> 
#include <stdlib.h>
#include <cstdlib>
#include <stddef.h>
#include <iostream>
#include <sstream>

class dope
{
public:
	dope();
	dope(char *c);
	~dope();

	bool Start();
	
	void init();
	void Openfile(char *);
	void Closefile();
	void Instruction();
	void Adventure();
	void Status();
	void Detroit();
	
	double Purchase(short x, short y);
	double Sell(short a, short b);
	
	void Bank();				/* Storage place for money */
	//void W_Calc(double w);	/* Withdraw */
	void D_Calc(double d);		/* Deposit */
	void Cops(short rand);		/* Random bust */
	void Coat();				/* Allows user to view dope stats */
	void Schedule(short final);
		
protected:
	int rows, cols;
	std::fstream  ifile;
	char grid[100][100];
	char *fname;
	char final[256];
	short decision;
	short i;
	short j;
	short x;
	short y;
	short n;
	short a;
	short b;
	short life;
	short rand;
	short debt;
	float weed, weed1;
	float heroin, heroin1;
	float cocaine, cocaine1;
	float mj, mj1;
	float ecstacy, ecstacy1;
	float acid, acid1;
	float money;
	double quantity;
	double total;
	double total1;
	double d;          
	double w; 	
};


#endif		/*_DOPE_H */
