#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import random

from math import pow


class coordinate(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return '(%d, %d)' % (self.x, self.y)

    def __repr__(self):
        return self.__str__()


def getCoordinate(coo):
    with open('test.txt', 'r') as f:
        for eachline in f:
            if eachline == '':
                continue
            comma = eachline.find(',')
            c = coordinate(int(eachline[:comma]), int(eachline[comma+1:]))
            coo.append(c)


def getZ1(coo):
    temp_index = random.randint(0, len(coo)-1)
    z1 = coo[temp_index]
    coo.pop(temp_index)
    return z1


def getZ(coo, weight, centers):
    dis = []
    for x in coo:
        dis.append(minDis2Center(x, centers))
    max_dis = max([x[1] for x in dis])
    for index, x in enumerate(dis):
        if x[1] == max_dis:
            temp_index = index
            break
    if len(centers) < 2 or \
       max_dis > distance(centers[0], centers[1]) * pow(weight, 2):
        centers.append(coo[temp_index])
        coo.pop(temp_index)
        return True
    else:
        return False


def minDis2Center(x, centers):
    dis = [distance(value, x) for value in centers]
    min_dis = min(dis)
    temp_index = dis.index(min_dis)
    return (x, min_dis, temp_index)


def distance(a, b):
    return pow((a.x - b.x), 2) + pow((a.y - b.y), 2)


def agg(coo, centers):
    result = []
    for center in centers:
        z = [center]
        result.append(z)
    for x in coo:
        v = minDis2Center(x, centers)
        result[v[2]].append(x)
    return result


def main():
    coo = []
    centers = []
    getCoordinate(coo)
    centers.append(getZ1(coo))
    getZ(coo, 1, centers)
    while True:
        end = getZ(coo, 0.5, centers)
        if end is False:
            break
    result = agg(coo, centers)
    for i in result:
        print i

if __name__ == '__main__':
    main()
