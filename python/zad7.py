from math import *
from inout import get_input
from typing import Callable

class BoundsError(Exception):
    def __init__(self, message):
        super().__init__(message)



def findZero(f: Callable[[float], float], a : float, b : float, eps : float):
    if a >= b:
        raise BoundsError('Given arguments don\'t make a range [ a>=b ]')
    x, y = f(a), f(b)
    if (x<0 and y<0) or (x>0 and y>0):
        raise BoundsError('Same sign in range ends [ f(a)*f(b) > 0 ]')

    while True:
        x = (a+b)/2
        y = f(x)

        if y == 0.0 or ((b-a)/2.0<eps and (b-a)/2.0>-eps):
            return x

        ya = f(a)
        if (y<0 and ya<0) or (y>0 and ya>0):
            a = x
        else:
            b = x


def main():
    func, a, b, epsilon = get_input(str, float, float, int)
    if func == 'test':
        epsilon = 1
        for i in range(1,9):
            epsilon *= 0.1
            print(f'10^-{i:<2} : {findZero(lambda x: cos(x/2), 2, 4, epsilon):z.{i}f}')
    else:
        print(f'{findZero(lambda x: eval(func), a, b, 10**epsilon):z.{-epsilon}f}')


if __name__ == '__main__':
    main()
