
#             ____________   ___________  _________________________________  ________________   ______   _____    ______
intervals =  [[1,3], [2,4], [5,7], [6,8], [9,13], [13,15], [14,15], [14,19], [25,26], [26,27], [40,47], [50,60], [70,80]]   # Sorted based on the start time

output = []


start = intervals[0][0]
end = intervals[0][1]

for i in range(len(intervals)):

    if i == 0:
        continue

    if intervals[i][0] <= end:   # Current start < end # Intervals are overlapping

        end = max(end, intervals[i][1]) # Merge them by updating the end time

    else:  # Intervals are broken

        output.append( [start, end] )

        start = intervals[i][0]
        end = intervals[i][1]

output.append([start, end])

print(output) # [[1, 4], [5, 8], [9, 19]]

