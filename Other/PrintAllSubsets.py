def listAllSubsets(ListIn):
    
    n = len(ListIn)
    
    for i in range(2**n):
        
        j = i
        setX = []
        location = 0
        while j > 0:
            
            take = j & 1
            
            if take == 1:
                setX.append(ListIn[location])
            
            location += 1
            
            j = j >> 1
        
        print(setX)
