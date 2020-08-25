#! /usr/bin/env python3

from random import randrange
from sys import argv


def generate_point():
    gen = lambda: randrange(-100, 101)
    print(f"{gen()};{gen()};")


if __name__ == '__main__':
    points_num = 200

    if len(argv) > 1:
        points_num = int(argv[1])

    for i in range(points_num):
        generate_point()
