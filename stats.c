#include "stats.h"

    struct Stats compute_statistics(const float* numberset, int setlength)
    {
        struct Stats s;
        float sum = 0;
        int i;
        
        /* average computation */
        for (i = 0; i < setlength; i++) 
        {
            sum += numberset[i];
        }
        
        float mn, mx;
        mn = mx = numberset[0];
        
        /* min max computation */
        for(i=1; i<setlength; i++)
        {
            if(numberset[i]>mx)
            {
                mx = numberset[i];
            }

            if(numberset[i]<mn)
            {
                mn = numberset[i];
            }
        }
        
        s.average = sum/setlength ;
        //if average is NaN
        if(s.average != s.average)
        {
            s.min = s.max = s.average;
        }
        else{
        s.min = mn;
        s.max = mx;
        }
        
        return s;
    }

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
