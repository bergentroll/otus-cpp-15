#! /usr/bin/env python3

from sys import stdin
import matplotlib.pyplot as plt
import numpy as np

colors = {0: 'red', 1: 'green', 2: 'blue'}


class Point:
    def __init__(self, cluster: int, x: int, y: int):
        self.cluster = cluster
        self.x = x
        self.y = y


if __name__ == '__main__':
    points = list()
    for line in stdin:
        args = (int(x) for x in line.rstrip().split(';'))
        points.append(Point(*args))

    ax = plt.gca().axes
    ax.xaxis.set_visible(False)
    ax.yaxis.set_visible(False)

    for p in points:
        plt.scatter(p.x, p.y, c=colors[p.cluster])

    plt.show()
