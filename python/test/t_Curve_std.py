#! /usr/bin/env python

import openturns as ot

ot.TESTPREAMBLE()

# Generate the data for the curves to be drawn
size = 50
cursor = ot.Point(2)

# curve y = 2x for x in [-25]
data1 = ot.Sample(size, 2)
# curve y = x*x for x in [-11]
data2 = ot.Sample(size, 2)

for i in range(size):
    tmp = 7.0 * i / size + 2
    cursor[0] = tmp
    cursor[1] = 2 * tmp
    data1[i] = cursor

    tmp = 9.0 * i / size + 1
    cursor[0] = tmp
    cursor[1] = tmp * tmp - (tmp - 5) * tmp * tmp / 60
    data2[i] = cursor

# Create an empty graph
myGraph = ot.Graph("Some curves", "x1", "x2", True, "topright", 1.0, 0)

# Create the first curve
myCurve1 = ot.Curve(data1, "blue", "dashed", 2, "linear function")

# Then, draw it
myGraph.add(myCurve1)

# Check that the correct files have been generated by computing their
# checksum

# Create the second curve
myCurve2 = ot.Curve(data2, "red", "solid", 2, "polynomial function")

# Add it to the graph
myGraph.add(myCurve2)

# fill below the start of the second curve
polygon = ot.Curve.FillBetween([[data2[i][0]] for i in range(10)],
                               [[data2[0][1]] for i in range(10)],
                               [[data2[i][1]] for i in range(10)])
polygon.setColor("green")
myGraph.add(polygon)

print("myGraph = ",myGraph)

# Draw everything
for i in range(4):
    myGraph.setLogScale(i)
