# -*- coding: utf-8 -*-
to_amount = int(raw_input('请输入   e.g 50输入5000\n'))
print hex(to_amount)
to_amount = str(hex(to_amount))
d = int(to_amount[2:4], 16)
c = int(to_amount[4:], 16)
b = c + d
a = c ^ d
e = b ^ 0xff
f = e + 2
print str(hex(a))[-2:] + str(hex(b))[-2:] + str(hex(c))[-2:] + str(hex(d))[-2:] + '00' + str(hex(e))[-2:] + '......' + str(hex(f))[-2:]
