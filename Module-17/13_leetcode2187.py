# print(int((5/2)+0.5))==max

def hourverify(time,totaltrips,hour):
    trips = sum(hour // t for t in time)
    return trips >= totaltrips

def minimumTime(time, totalTrips):
    lo=1
    hi=int(totalTrips/min(time)+0.5)
    while(lo<hi):
        mid=(hi+lo)//2
        if(hourverify(time,totalTrips,mid)):
            hi=mid
        else:
            lo=mid+1
    return lo

            