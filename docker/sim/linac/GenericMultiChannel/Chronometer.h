/**
 * File : Chronometer.h
 *
 * Description : Simple Chronometer utility. Actually based on gettimeofday. The
 * accuracy should be trustable up to millisecond.
 *
 * Author : B.Vedder
 *
 * Date : Tue Mar  8 10:24:48 2011
 *
 */

#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <sys/time.h>
#include <math.h>
#include <iostream>

class Chronometer
{
public:
	Chronometer();
	void start();
	void restart(){start();}  // For semantic.
	void stop();
	long getDeltaMicroseconds() const;
	long getDeltaMilliseconds() const;
	long getDeltaSeconds() const;
	void waitMilliseconds(long ms);
	void waitMicroseconds(long us);
	void waitNanoseconds(long ns);
	~Chronometer();

protected:

private:
	struct timeval t0;
	struct timeval t1;
	double deltaT1T0;
};

#endif	// CHRONOMETER_H
