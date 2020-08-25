#! /usr/bin/env python3

import matplotlib.pyplot as plt

from sys import argv, stdin


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
        plt.scatter(p.x, p.y, c=f'C{p.cluster}')

    if len(argv) > 1 and argv[1] == 'show':
        plt.show()
    else:
        plt.savefig('diag.png')
