#! /usr/bin/env python3

from random import randrange


def generate_point():
    gen = lambda: randrange(-100, 101)
    print(f"{gen()};{gen()};")


if __name__ == '__main__':
    for i in range(200):
        generate_point()
