#! /usr/bin/env python

from openturns import *

TESTPREAMBLE()
RandomGenerator.SetSeed(0)

try:
    # Generate the data for the polygons to be drawn
    size = 50
    cursor = Point(2)

    data1 = Sample(size, 2)  # polygon y = 2x for x in [-25]
    data2 = Sample(size, 2)  # polygon y = x*x for x in [-11]

    for i in range(size):
        tmp = 7. * i / size + 2
        cursor[0] = tmp
        cursor[1] = 2 * tmp
        data1[i] = cursor

        tmp = 9. * i / size + 1
        cursor[0] = tmp
        cursor[1] = tmp * tmp
        data2[i] = cursor

    # Create an empty graph
    myGraph = Graph("Some polygons", "x1", "x2", True, "topright", 1.0)

    # Create the first polygon
    myPolygon1 = Polygon(data1)
    myPolygon1.setColor("blue")

    # Then, draw it
    myGraph.add(myPolygon1)

    # Check that the correct files have been generated by computing their
    # checksum

    # Create the second cloud
    myPolygon2 = Polygon(data2)
    myPolygon2.setColor("red")

    # Add it to the graph and draw everything
    myGraph.add(myPolygon2)
    for i in range(4):
        myGraph.setLogScale(i)

except:
    import sys
    print("t_Polygon_std.py", sys.exc_info()[0], sys.exc_info()[1])
