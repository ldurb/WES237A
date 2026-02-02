//
//  main.cpp
//  Lab4
//
//  Created by Alireza on 2/14/20.
//  Copyright Â© 2020 Alireza. All rights reserved.
//

#include "main.h"
#include "cycletime.h"
#include "timer.h"
#include <unistd.h>

using namespace std;

int main(int argc, const char * argv[])
{
	float cpu_timer;
	unsigned int delay = 1;
	
	cout << "WES237A lab 4" << endl;

	char key=0;
	
	// 1 argument on command line: delay = arg
	if(argc >= 2)
	{
		delay = atoi(argv[1]);
	}

	unsigned int before_sleep, after_sleep;     //TODO: declare 2 cpu_count variables: 1 for before sleeping, 1 for after sleeping (see cpu_timer)


    init_counter(1,1);//TODO: initialize the counter

    before_sleep = get_cyclecount();//TODO: get the cyclecount before sleeping
    usleep(delay);
    after_sleep = get_cyclecount();//TODO: get the cyclecount after sleeping

    unsigned int diff = after_sleep - before_sleep;//TODO: subtract the before and after cyclecount
    cout<< "total cycles: " << diff << endl;//TODO: print the cycle count (see the print statement for the cpu_timer below)

	LinuxTimer t;
	usleep(delay);
	t.stop();
	cpu_timer = t.getElapsed();

	
	cout << "Timer: " << (double)cpu_timer/1000000000.0 << endl;

	return 0;
}

