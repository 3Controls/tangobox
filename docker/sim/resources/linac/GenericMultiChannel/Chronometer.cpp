/**
 * File : Chronometer.cpp
 *
 * Description : Simple Chronometer utility. Actually based on gettimeofday. The
 * accuracy should be trustable up to millisecond.
 *
 * Author : B.Vedder
 *
 * Date : Tue Mar  8 10:24:48 2011
 *
 */

#include "Chronometer.h"


/**
 * Constructor.
 */
Chronometer::Chronometer()
{
        t0.tv_sec  = 0;
        t0.tv_usec = 0;
        t1.tv_sec  = 0;
        t1.tv_usec = 0;
        deltaT1T0  = 0;
}


/**
 * Get our T0 value. Note that start can be called multiple times. This will
 * only update T0 structure. No multiple measure are possible with a Chronometer.
 * Use several Chronometer if needed.
 */
void Chronometer::start()
{
        gettimeofday(&t0, NULL);
}


/**
 * Get our T1 value. Note that stop can be called multiple times. This will
 * only update T1 structure. No multiple measure are possible with a Chronometer.
 * Use several Chronometer if needed. Note that Chronometer can be stopped several
 * times without restarting, to measure (with getDelta...()) multiple duration from T0.
 */
void Chronometer::stop()
{
        gettimeofday(&t1, NULL);
}


/**
 * This method will compute the delta of time between T1 and T0, unit is microsecond.
 */
long Chronometer::getDeltaMicroseconds() const
{
        long deltaT;
        deltaT = ((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec));
        return deltaT;
}


/**
 * This method will compute the delta of time between T1 and T0, unit is millisecond.
 */
long Chronometer::getDeltaMilliseconds() const
{
        long deltaT;
        deltaT = ((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec));
        return deltaT / 1000;
}


/**
 * This method will compute the delta of time between T1 and T0, unit is second.
 */
long Chronometer::getDeltaSeconds() const
{
        long deltaT;
        deltaT = ((t1.tv_sec * 1000000 + t1.tv_usec) - (t0.tv_sec * 1000000 + t0.tv_usec));
        return deltaT / 1000000;
}


/**
 * This method will wait for the given milliseconds.
 */
void Chronometer::waitMilliseconds(long ms)
{
        struct timespec rqtp;
        rqtp.tv_sec = ms / 1000;
        rqtp.tv_nsec = (ms % 1000) * 1000000;
        nanosleep(&rqtp, NULL);	// NULL = dont care about remaining time if interrupted.
}


/**
 * This method will wait for the given microseconds.
 */
void Chronometer::waitMicroseconds(long us)
{
        struct timespec rqtp;
        rqtp.tv_sec = us / 1000000;
        rqtp.tv_nsec = (us % 1000000) * 1000;
        nanosleep(&rqtp, NULL);	// NULL = dont care about remaining time if interrupted.
}


/**
 * This method will wait for the given nanoseconds.
 */
void Chronometer::waitNanoseconds(long ns)
{
        struct timespec rqtp;
        rqtp.tv_sec = ns / 1000000000;
        rqtp.tv_nsec = (ns % 1000000000);
        nanosleep(&rqtp, NULL);	// NULL = dont care about remaining time if interrupted.
}


/**
 * Destructor.
 */
Chronometer::~Chronometer()
{
}

