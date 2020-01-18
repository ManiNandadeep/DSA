import math

d=[1,2,2,2,3,3,3,4,5,5,5,6,7,8,10]
points=[]

m=len(d)
n=(int)(0.5 +math.sqrt(2*m+0.25))
points.append(0)
points.append(10)
d.pop()

def diff(points,temp):
    dif=[]
    for x in points:
        dif.append(abs(x-temp))
    return dif

def rem(d,dif):
    for x in dif:
        d.remove(x)

def add(d,dif):
    for x in dif:
        d.append(x)
    d.sort()

def check(d,arr):
    temp=d[::]
    for x in arr:
        if x not in temp:
            return False
        temp.remove(x)
    return True
        

def pike(points,d):
    if d==[]:
        return True
    else:
        temp=d[-1]
        arr1=diff(points,temp)
        print temp,arr1,points,d,check(d,arr1)
        if check(d,arr1):
            points.append(temp)
            rem(d,arr1)
            if pike(points,d):
                return True
            else:
                add(d,arr1)
                points.remove(temp)
        temp1=10-d[-1]
        arr2=diff(points,temp1)
        print temp1,arr2,points,d,check(d,arr2)
        if check(d,arr2):
            points.append(temp1)
            rem(d,arr2)
            if pike(points,d):
                return True
            else:
                add(d,arr2)
                points.remove(temp1)
    return False





if __name__=="__main__":
    pike(points,d)
    points.sort()
    print points