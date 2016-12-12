#!/usr/bin/env python
# -*- coding:utf-8 -*-

import os
from json import loads


class Bar(object):
    def __init__(self, x, y, w):
        self.x = x
        self.y = y
        self.w = w

    def __add__(self, x):
        if isinstance(x, Bar):
            self.x += x.x
            self.y += x.y
            self.w += x.w
            return self

    def __mul__(self, x):
        if isinstance(x, Bar):
            return self.x * x.x + self.y * x.y + self.w * x.w
        else:
            self.x *= x
            self.y *= x
            self.w *= x
            return self

    def __str__(self):
        return '(%d, %d, %d)' % (self.x, self.y, self.w)

    def __repr__(self):
        return self.__str__()


def init(w1, w2):
    with open('test2.json', 'r') as f:
        data = loads(f.read())
    for x in data['w1']:
        w1.append(Bar(x['x'], x['y'], 1))
    for x in data['w2']:
        w2.append(Bar(x['x'], x['y'], 1))
    for x in w2:
        x *= -1


def main():
    w1 = []
    w2 = []
    p = 1
    init(w1, w2)
    all_x = w1 + w2
    w = Bar(1, 1, 1)
    flag = True
    while flag:
        flag = False
        for x in all_x:
            d = w * (x * p)
            if d <= 0:
                w += x
                flag = True
    print w


if __name__ == '__main__':
    main()
