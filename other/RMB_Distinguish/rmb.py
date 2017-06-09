#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
from PIL import Image
from imghdr import what

def isImg(filename):
    try:
        if what(filename):
            return True
        else:
            return False
    except IOError:
        return False

def LoadTrainSet(path):
    trainSet = {'100': [],
                '50': [],
                '20': [],
                '10': [],
                '5': [],
                '1': []
    }
    folders = os.listdir(path)
    for folder in folders:
        p = os.path.join(path, folder)
        if os.path.isdir(p):
            files = os.listdir(p)
            for i in files:
                f = os.path.join(p, i)
                if isImg(f):
                    trainSet[folder].append(MyGary(f))
    return trainSet


def MyGary(im):
    if not isinstance(im, Image.Image):
        im = Image.open(im)
    width, hight = im.size
    #im = im.crop((width/2 - width/3, hight/2 - hight/3, width/2+width/3, hight/2 + hight/3))
    im = im.resize((8, 8), Image.ANTIALIAS)
    sum_gary = sum([float(i[0])/(i[0]+i[1]+i[2]) for i in im.getdata()])
    return sum_gary

def Compare(trainSet, img):
    img_green = MyGary(img)
    result = {'100': 0,
              '50': 0,
              '20': 0,
              '10': 0,
              '5': 0,
              '1': 0}
    for rmb in trainSet:
        try:
            result[rmb] = min([abs(img_green - i) for i in trainSet[rmb]])
        except ValueError:
            pass
    min_res = result['1']
    money = '1'
    for (key, value) in result.items():
        if value < min_res:
            min_res = value
            money = key
    print result
    print money+'元'


def main():
    trainSet = LoadTrainSet('train')
    img = Image.open('20-1.png')
    Compare(trainSet, img)

if __name__ == '__main__':
    main()
