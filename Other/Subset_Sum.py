def sub_set_sum(SetIn, SumIn, TargetSum, Soln):
    
    if SumIn > TargetSum or not SetIn:
        return
    
    if SumIn == TargetSum:
        print(Soln)
        return
    
    for x in SetIn:
        newSetIn = SetIn[:]
        newSetIn.remove(x)
        SolnNew = Soln[:]
        SolnNew.append(x)
        sub_set_sum(newSetIn, SumIn + x, TargetSum, SolnNew)
